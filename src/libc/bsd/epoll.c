/* SPDX-License-Identifier: LGPL-2.1-or-later */

#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <pthread.h>

#include "sys/epoll.h"

/*
 * Per-(epfd, fd) tracking entry.
 *
 * kqueue uses separate filter entries for each event type (EVFILT_READ,
 * EVFILT_WRITE, etc), while epoll stores ONE event per fd with a combined
 * events bitmask.  We keep the combined mask + user data in this hash-free
 * dynamic array and fan out to separate kqueue filters on registration.
 */
struct epoll_entry {
        int fd;
        uint32_t events;
        epoll_data_t data;
};

/*
 * Per-epfd tracking table.
 *
 * The epfd IS the kqueue fd returned by kqueue().  Every operation on an
 * epoll fd locks *only* its own table lock so that different epoll instances
 * do not contend on each other.  The global lock is only taken for the brief
 * table-lookup window.
 */
struct epoll_fd_table {
        int epfd;
        struct epoll_entry *entries;
        size_t n_entries, capacity;
        pthread_mutex_t lock;
};

/* Global registry:  epfd -> struct epoll_fd_table */
static struct epoll_fd_table **epoll_tables;
static size_t epoll_n_tables, epoll_tables_cap;
static pthread_mutex_t epoll_global_lock = PTHREAD_MUTEX_INITIALIZER;

/* ------------------------------------------------------------------ */
/*  internal helpers                                                   */
/* ------------------------------------------------------------------ */

static struct epoll_fd_table *epoll_find_table(int epfd) {
        for (size_t i = 0; i < epoll_n_tables; i++)
                if (epoll_tables[i]->epfd == epfd)
                        return epoll_tables[i];
        return NULL;
}

static struct epoll_entry *epoll_find_entry(struct epoll_fd_table *tbl, int fd) {
        for (size_t i = 0; i < tbl->n_entries; i++)
                if (tbl->entries[i].fd == fd)
                        return &tbl->entries[i];
        return NULL;
}

static int epoll_add_entry(struct epoll_fd_table *tbl, int fd, uint32_t events, epoll_data_t data) {
        if (tbl->n_entries >= tbl->capacity) {
                size_t new_cap = tbl->capacity ? tbl->capacity * 2 : 8;
                struct epoll_entry *new_entries =
                        realloc(tbl->entries, new_cap * sizeof(*new_entries));
                if (!new_entries)
                        return -1;
                tbl->entries  = new_entries;
                tbl->capacity = new_cap;
        }
        tbl->entries[tbl->n_entries].fd     = fd;
        tbl->entries[tbl->n_entries].events = events;
        tbl->entries[tbl->n_entries].data   = data;
        tbl->n_entries++;
        return 0;
}

/* Remove the entry at idx by swapping in the last element (order does not matter). */
static void epoll_remove_entry(struct epoll_fd_table *tbl, size_t idx) {
        tbl->n_entries--;
        if (idx < tbl->n_entries)
                tbl->entries[idx] = tbl->entries[tbl->n_entries];
}

/* ------------------------------------------------------------------ */
/*  kqueue filter helpers                                              */
/* ------------------------------------------------------------------ */

/*
 * Register kqueue filters for the given epoll event mask.
 *
 * Returns 0 on success.  On failure errno is set and any filters that may
 * have been registered before the error are rolled back so that the kqueue
 * interest list stays in a consistent state.
 */
static int epoll_register_kevents(int epfd, int fd, uint32_t events) {
        struct kevent kev[3];
        struct kevent err_ev[3];
        int n = 0;

        if (events & (EPOLLIN | EPOLLRDNORM))
                EV_SET(&kev[n++], fd, EVFILT_READ,
                       EV_ADD
                       | (events & EPOLLET ? EV_CLEAR : 0)
                       | (events & EPOLLONESHOT ? EV_ONESHOT : 0),
                       0, 0, NULL);
        if (events & (EPOLLOUT | EPOLLWRNORM))
                EV_SET(&kev[n++], fd, EVFILT_WRITE,
                       EV_ADD
                       | (events & EPOLLET ? EV_CLEAR : 0)
                       | (events & EPOLLONESHOT ? EV_ONESHOT : 0),
                       0, 0, NULL);
#ifdef EVFILT_EXCEPT
        if (events & EPOLLPRI)
                EV_SET(&kev[n++], fd, EVFILT_EXCEPT,
                       EV_ADD
                       | (events & EPOLLET ? EV_CLEAR : 0)
                       | (events & EPOLLONESHOT ? EV_ONESHOT : 0),
                       0, 0, NULL);
#endif

        if (n == 0)
                return 0;

        struct timespec ts = { .tv_sec = 0, .tv_nsec = 0 };
        int ret = kevent(epfd, kev, n, err_ev, n, &ts);
        if (ret < 0)
                return -1;

        for (int i = 0; i < ret; i++) {
                if (err_ev[i].flags & EV_ERROR) {
                        /* Roll back any filters that were added before the error. */
                        int saved_ident[3];
                        short saved_filter[3];
                        for (int j = 0; j < n; j++) {
                                saved_ident[j]  = (int)kev[j].ident;
                                saved_filter[j] = kev[j].filter;
                        }
                        for (int j = 0; j < n; j++)
                                EV_SET(&kev[j], saved_ident[j], saved_filter[j],
                                       EV_DELETE, 0, 0, NULL);
                        (void)kevent(epfd, kev, n, NULL, 0, &ts);

                        errno = (int)err_ev[i].data;
                        return -1;
                }
        }

        return 0;
}

/*
 * Unregister kqueue filters for the given event mask.  Errors are silently
 * ignored — the fd may have been closed by another thread and that is fine.
 */
static void epoll_unregister_kevents(int epfd, int fd, uint32_t events) {
        struct kevent kev[3];
        int n = 0;

        if (events & (EPOLLIN | EPOLLRDNORM))
                EV_SET(&kev[n++], fd, EVFILT_READ, EV_DELETE, 0, 0, NULL);
        if (events & (EPOLLOUT | EPOLLWRNORM))
                EV_SET(&kev[n++], fd, EVFILT_WRITE, EV_DELETE, 0, 0, NULL);
#ifdef EVFILT_EXCEPT
        if (events & EPOLLPRI)
                EV_SET(&kev[n++], fd, EVFILT_EXCEPT, EV_DELETE, 0, 0, NULL);
#endif

        if (n == 0)
                return;

        (void)kevent(epfd, kev, n, NULL, 0, NULL);
}

/* ------------------------------------------------------------------ */
/*  public API                                                         */
/* ------------------------------------------------------------------ */

int epoll_create(int size) {
        (void)size;

        int epfd = kqueue();
        if (epfd < 0)
                return -1;

        struct epoll_fd_table *tbl = calloc(1, sizeof(*tbl));
        if (!tbl) {
                close(epfd);
                errno = ENOMEM;
                return -1;
        }

        tbl->epfd = epfd;
        pthread_mutex_init(&tbl->lock, NULL);

        pthread_mutex_lock(&epoll_global_lock);

        if (epoll_n_tables >= epoll_tables_cap) {
                size_t new_cap = epoll_tables_cap ? epoll_tables_cap * 2 : 8;
                struct epoll_fd_table **new_tables =
                        realloc(epoll_tables, new_cap * sizeof(*new_tables));
                if (!new_tables) {
                        pthread_mutex_unlock(&epoll_global_lock);
                        pthread_mutex_destroy(&tbl->lock);
                        free(tbl);
                        close(epfd);
                        errno = ENOMEM;
                        return -1;
                }
                epoll_tables     = new_tables;
                epoll_tables_cap = new_cap;
        }

        epoll_tables[epoll_n_tables++] = tbl;
        pthread_mutex_unlock(&epoll_global_lock);

        return epfd;
}

int epoll_create1(int flags) {
        /* Only EPOLL_CLOEXEC is valid; reject anything else. */
        if (flags & ~EPOLL_CLOEXEC) {
                errno = EINVAL;
                return -1;
        }

        int epfd = epoll_create(0);
        if (epfd < 0)
                return -1;

        if (flags & EPOLL_CLOEXEC) {
                if (fcntl(epfd, F_SETFD, FD_CLOEXEC) < 0) {
                        close(epfd);
                        return -1;
                }
        }

        return epfd;
}

int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event) {
        if (op != EPOLL_CTL_DEL && !event) {
                errno = EFAULT;
                return -1;
        }

        pthread_mutex_lock(&epoll_global_lock);
        struct epoll_fd_table *tbl = epoll_find_table(epfd);
        if (!tbl) {
                pthread_mutex_unlock(&epoll_global_lock);
                errno = EBADF;
                return -1;
        }
        pthread_mutex_lock(&tbl->lock);
        pthread_mutex_unlock(&epoll_global_lock);

        struct epoll_entry *entry = epoll_find_entry(tbl, fd);
        int ret = 0;

        switch (op) {
        case EPOLL_CTL_ADD:
                if (entry) {
                        ret = -1;
                        errno = EEXIST;
                        goto out;
                }

                if (epoll_register_kevents(epfd, fd, event->events) < 0) {
                        ret = -1;
                        goto out;
                }

                if (epoll_add_entry(tbl, fd, event->events, event->data) < 0) {
                        epoll_unregister_kevents(epfd, fd, event->events);
                        errno = ENOMEM;
                        ret   = -1;
                        goto out;
                }
                break;

        case EPOLL_CTL_MOD:
                if (!entry) {
                        ret = -1;
                        errno = ENOENT;
                        goto out;
                }

                epoll_unregister_kevents(epfd, fd, entry->events);

                if (epoll_register_kevents(epfd, fd, event->events) < 0) {
                        /*
                         * Registration failed; the old filters have already
                         * been deleted so the fd is no longer tracked.
                         * Remove it from the table to keep internal state
                         * consistent.  The caller will see EPOLL_CTL_MOD
                         * return -1 and can re-add if needed.
                         */
                        size_t idx = entry - tbl->entries;
                        epoll_remove_entry(tbl, idx);
                        ret = -1;
                        goto out;
                }

                entry->events = event->events;
                entry->data   = event->data;
                break;

        case EPOLL_CTL_DEL: {
                if (!entry) {
                        ret = -1;
                        errno = ENOENT;
                        goto out;
                }

                epoll_unregister_kevents(epfd, fd, entry->events);

                size_t idx = entry - tbl->entries;
                epoll_remove_entry(tbl, idx);
                break;
        }

        default:
                ret = -1;
                errno = EINVAL;
                goto out;
        }

out:
        pthread_mutex_unlock(&tbl->lock);
        return ret;
}

int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout) {
        struct timespec ts;
        const struct timespec *tsp;

        if (timeout < 0) {
                tsp = NULL;
        } else {
                ts.tv_sec  = timeout / 1000;
                ts.tv_nsec = (long)(timeout % 1000) * 1000000L;
                tsp = &ts;
        }

        return epoll_pwait2(epfd, events, maxevents, tsp, NULL);
}

int epoll_pwait2(int epfd, struct epoll_event *events, int maxevents,
                 const struct timespec *timeout, const sigset_t *sigmask) {

        if (maxevents <= 0) {
                errno = EINVAL;
                return -1;
        }

        pthread_mutex_lock(&epoll_global_lock);
        struct epoll_fd_table *tbl = epoll_find_table(epfd);
        if (!tbl) {
                pthread_mutex_unlock(&epoll_global_lock);
                errno = EBADF;
                return -1;
        }
        pthread_mutex_lock(&tbl->lock);
        pthread_mutex_unlock(&epoll_global_lock);

        /*
         * Allocate temporary buffers.  Each fd can produce up to three
         * kevents (read, write, except), so allow for that many.
         */
        size_t kev_cap = (size_t)maxevents * 3;
        struct kevent *kev_buf = malloc(kev_cap * sizeof(*kev_buf));
        int *fd_map = malloc((size_t)maxevents * sizeof(*fd_map));
        if (!kev_buf || !fd_map) {
                free(kev_buf);
                free(fd_map);
                pthread_mutex_unlock(&tbl->lock);
                errno = ENOMEM;
                return -1;
        }

        /*
         * Emulate sigmask atomiciy: we cannot make kevent() itself atomic
         * with respect to signal delivery, so we approximate with
         * pthread_sigmask around the syscall.  This is the same approach
         * libc uses for pselect() on platforms without ppoll().
         */
        sigset_t oldmask;
        int sigmask_set = 0;
        if (sigmask) {
                sigmask_set = 1;
                pthread_sigmask(SIG_SETMASK, sigmask, &oldmask);
        }

        int n_kev = kevent(epfd, NULL, 0, kev_buf, (int)kev_cap, timeout);

        if (sigmask_set)
                pthread_sigmask(SIG_SETMASK, &oldmask, NULL);

        if (n_kev < 0) {
                free(kev_buf);
                free(fd_map);
                pthread_mutex_unlock(&tbl->lock);
                return -1;
        }

        /*
         * kqueue returns separate events per filter.  Group them by fd so
         * that one fd with both read and write readiness produces a single
         * epoll_event with combined EPOLLIN | EPOLLOUT.
         */
        int n_epoll = 0;
        for (int i = 0; i < n_kev; i++) {
                int fd = (int)kev_buf[i].ident;
                uint32_t ep_ev = 0;

                if (kev_buf[i].filter == EVFILT_READ) {
                        ep_ev |= EPOLLIN;
                        if (kev_buf[i].flags & EV_EOF)
                                ep_ev |= EPOLLRDHUP;
                }
                if (kev_buf[i].filter == EVFILT_WRITE)
                        ep_ev |= EPOLLOUT;
#ifdef EVFILT_EXCEPT
                if (kev_buf[i].filter == EVFILT_EXCEPT)
                        ep_ev |= EPOLLPRI;
#endif
                if (kev_buf[i].flags & EV_EOF)
                        ep_ev |= EPOLLHUP;
                if (kev_buf[i].flags & EV_ERROR)
                        ep_ev |= EPOLLERR;

                /* Check whether this fd already has an output slot. */
                int idx = -1;
                for (int j = 0; j < n_epoll; j++) {
                        if (fd_map[j] == fd) {
                                idx = j;
                                break;
                        }
                }

                if (idx >= 0) {
                        events[idx].events |= ep_ev;
                } else if (n_epoll < maxevents) {
                        events[n_epoll].events = ep_ev;
                        fd_map[n_epoll]        = fd;

                        struct epoll_entry *entry = epoll_find_entry(tbl, fd);
                        if (entry)
                                events[n_epoll].data = entry->data;
                        else
                                memset(&events[n_epoll].data, 0,
                                       sizeof(epoll_data_t));

                        n_epoll++;
                }
        }

        free(kev_buf);
        free(fd_map);
        pthread_mutex_unlock(&tbl->lock);
        return n_epoll;
}

/* BSD has no direct epoll_pwait2 syscall; route through the kqueue shim. */
int missing_epoll_pwait2(int fd, struct epoll_event *events, int maxevents,
                         const struct timespec *timeout, const sigset_t *sigmask) {
        return epoll_pwait2(fd, events, maxevents, timeout, sigmask);
}
