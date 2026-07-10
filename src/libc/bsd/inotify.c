/* SPDX-License-Identifier: LGPL-2.1-or-later */

#include "sys/inotify.h"
#include <sys/types.h>
#include <sys/event.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <limits.h>

#define MAX_INOTIFY_FDS 32
#define MAX_WATCHES 256
#define MAX_PATH_LEN 4096

struct watch {
        int wd;
        int dir_fd;
        int fd; /* kqueue fd */
        uint32_t mask;
        char path[MAX_PATH_LEN];
        int used;
};

struct inotify_info {
        int read_fd;
        int write_fd;
        int kqueue_fd;
        struct watch watches[MAX_WATCHES];
        int next_wd;
        int used;
        pthread_t thread;
        int stop;
        pthread_mutex_t lock;
};

static struct inotify_info g_inotify[MAX_INOTIFY_FDS];
static pthread_mutex_t g_lock = PTHREAD_MUTEX_INITIALIZER;

static uint32_t note_to_inotify(uint32_t fflags) {
        uint32_t mask = 0;
        if (fflags & NOTE_DELETE)   mask |= IN_DELETE;
        if (fflags & NOTE_WRITE)    mask |= IN_MODIFY;
        if (fflags & NOTE_EXTEND)   mask |= IN_MODIFY;
        if (fflags & NOTE_ATTRIB)   mask |= IN_ATTRIB;
        if (fflags & NOTE_LINK)     mask |= IN_ATTRIB;
        if (fflags & NOTE_RENAME)   mask |= IN_MOVED_FROM | IN_MOVED_TO;
        if (fflags & NOTE_REVOKE)   mask |= IN_DELETE_SELF;
        return mask;
}

static uint32_t inotify_to_note(uint32_t mask) {
        uint32_t fflags = 0;
        if (mask & IN_MODIFY)       fflags |= NOTE_WRITE | NOTE_EXTEND;
        if (mask & IN_ATTRIB)       fflags |= NOTE_ATTRIB | NOTE_LINK;
        if (mask & IN_DELETE)       fflags |= NOTE_DELETE;
        if (mask & IN_MOVED_FROM)   fflags |= NOTE_RENAME;
        if (mask & IN_MOVED_TO)     fflags |= NOTE_RENAME;
        if (mask & IN_DELETE_SELF)  fflags |= NOTE_REVOKE;
        return fflags;
}

static void* inotify_thread(void *arg) {
        struct inotify_info *ii = arg;
        struct kevent evlist[MAX_WATCHES];

        while (!ii->stop) {
                struct timespec ts = { .tv_sec = 1, .tv_nsec = 0 };
                int n = kevent(ii->kqueue_fd, NULL, 0, evlist, MAX_WATCHES, &ts);
                if (n < 0) break;
                if (n == 0) continue;

                pthread_mutex_lock(&ii->lock);
                for (int i = 0; i < n; i++) {
                        int fd = (int)(uintptr_t)evlist[i].ident;
                        uint32_t mask = note_to_inotify(evlist[i].fflags);

                        struct watch *w = NULL;
                        for (int j = 0; j < MAX_WATCHES; j++) {
                                if (ii->watches[j].used && ii->watches[j].dir_fd == fd) {
                                        w = &ii->watches[j];
                                        break;
                                }
                        }
                        if (!w) continue;

                        if (mask & w->mask) {
                                uint32_t event_mask = mask & w->mask;
                                struct inotify_event ev;
                                memset(&ev, 0, sizeof(ev));
                                ev.wd = w->wd;
                                ev.mask = event_mask;
                                ev.len = 0;
                                write(ii->write_fd, &ev, sizeof(ev));

                                if (w->mask & IN_ONESHOT) {
                                        w->mask = 0;
                                }
                        }

                        /* Re-arm EVFILT_VNODE (one-shot by default on some BSDs) */
                        struct kevent kev;
                        EV_SET(&kev, fd, EVFILT_VNODE, EV_ADD | EV_CLEAR | EV_ENABLE,
                               inotify_to_note(w->mask), 0, (void*)(uintptr_t)fd);
                        kevent(ii->kqueue_fd, &kev, 1, NULL, 0, NULL);
                }
                pthread_mutex_unlock(&ii->lock);
        }
        return NULL;
}

int inotify_init(void) {
        return inotify_init1(0);
}

int inotify_init1(int flags) {
        int pfd[2], kq, slot;

        if (flags & ~(IN_CLOEXEC | IN_NONBLOCK))
                return errno = EINVAL, -1;

        if (pipe(pfd) < 0)
                return -1;

        kq = kqueue();
        if (kq < 0) {
                close(pfd[0]); close(pfd[1]);
                return -1;
        }

        if (flags & IN_CLOEXEC) {
                fcntl(pfd[0], F_SETFD, FD_CLOEXEC);
                fcntl(pfd[1], F_SETFD, FD_CLOEXEC);
                fcntl(kq, F_SETFD, FD_CLOEXEC);
        }
        if (flags & IN_NONBLOCK) {
                int fl = fcntl(pfd[0], F_GETFL);
                fcntl(pfd[0], F_SETFL, fl | O_NONBLOCK);
        }

        pthread_mutex_lock(&g_lock);
        slot = -1;
        for (int i = 0; i < MAX_INOTIFY_FDS; i++)
                if (!g_inotify[i].used) { slot = i; break; }
        if (slot < 0) {
                pthread_mutex_unlock(&g_lock);
                close(pfd[0]); close(pfd[1]); close(kq);
                return errno = ENOMEM, -1;
        }

        g_inotify[slot].read_fd = pfd[0];
        g_inotify[slot].write_fd = pfd[1];
        g_inotify[slot].kqueue_fd = kq;
        g_inotify[slot].next_wd = 1;
        g_inotify[slot].used = 1;
        g_inotify[slot].stop = 0;
        memset(g_inotify[slot].watches, 0, sizeof(g_inotify[slot].watches));
        pthread_mutex_init(&g_inotify[slot].lock, NULL);

        int r = pthread_create(&g_inotify[slot].thread, NULL, inotify_thread, &g_inotify[slot]);
        if (r != 0) {
                g_inotify[slot].used = 0;
                pthread_mutex_unlock(&g_lock);
                close(pfd[0]); close(pfd[1]); close(kq);
                return errno = r, -1;
        }
        pthread_detach(g_inotify[slot].thread);

        pthread_mutex_unlock(&g_lock);
        return pfd[0];
}

int inotify_add_watch(int fd, const char *pathname, uint32_t mask) {
        pthread_mutex_lock(&g_lock);
        struct inotify_info *ii = NULL;
        for (int i = 0; i < MAX_INOTIFY_FDS; i++)
                if (g_inotify[i].used && g_inotify[i].read_fd == fd) { ii = &g_inotify[i]; break; }
        if (!ii) { pthread_mutex_unlock(&g_lock); return errno = EBADF, -1; }
        pthread_mutex_unlock(&g_lock);

        if (mask & IN_MASK_ADD)
                return errno = EINVAL, -1;

        pthread_mutex_lock(&ii->lock);
        int dir_fd = -1;

        /* Check if already watched */
        for (int i = 0; i < MAX_WATCHES; i++) {
                if (ii->watches[i].used && strcmp(ii->watches[i].path, pathname) == 0) {
                        ii->watches[i].mask = mask & ~IN_MASK_ADD;
                        int wd = ii->watches[i].wd;
                        pthread_mutex_unlock(&ii->lock);
                        return wd;
                }
        }

        dir_fd = open(pathname, O_RDONLY | O_NONBLOCK | O_DIRECTORY);
        if (dir_fd < 0) {
                if (errno == ENOTDIR) {
                        dir_fd = open(pathname, O_RDONLY | O_NONBLOCK);
                }
                if (dir_fd < 0) {
                        pthread_mutex_unlock(&ii->lock);
                        return -1;
                }
        }

        /* Find free slot */
        int slot = -1;
        for (int i = 0; i < MAX_WATCHES; i++)
                if (!ii->watches[i].used) { slot = i; break; }
        if (slot < 0) {
                close(dir_fd);
                pthread_mutex_unlock(&ii->lock);
                return errno = ENOSPC, -1;
        }

        int wd = ii->next_wd++;
        ii->watches[slot].wd = wd;
        ii->watches[slot].dir_fd = dir_fd;
        ii->watches[slot].mask = mask;
        ii->watches[slot].used = 1;
        strncpy(ii->watches[slot].path, pathname, MAX_PATH_LEN - 1);

        struct kevent kev;
        EV_SET(&kev, dir_fd, EVFILT_VNODE, EV_ADD | EV_CLEAR | EV_ENABLE,
               inotify_to_note(mask), 0, (void*)(uintptr_t)dir_fd);
        kevent(ii->kqueue_fd, &kev, 1, NULL, 0, NULL);

        pthread_mutex_unlock(&ii->lock);
        return wd;
}

int inotify_rm_watch(int fd, int wd) {
        pthread_mutex_lock(&g_lock);
        struct inotify_info *ii = NULL;
        for (int i = 0; i < MAX_INOTIFY_FDS; i++)
                if (g_inotify[i].used && g_inotify[i].read_fd == fd) { ii = &g_inotify[i]; break; }
        if (!ii) { pthread_mutex_unlock(&g_lock); return errno = EBADF, -1; }
        pthread_mutex_unlock(&g_lock);

        pthread_mutex_lock(&ii->lock);
        for (int i = 0; i < MAX_WATCHES; i++) {
                if (ii->watches[i].used && ii->watches[i].wd == wd) {
                        struct kevent kev;
                        EV_SET(&kev, ii->watches[i].dir_fd, EVFILT_VNODE, EV_DELETE, 0, 0, NULL);
                        kevent(ii->kqueue_fd, &kev, 1, NULL, 0, NULL);
                        close(ii->watches[i].dir_fd);
                        ii->watches[i].used = 0;
                        pthread_mutex_unlock(&ii->lock);
                        return 0;
                }
        }
        pthread_mutex_unlock(&ii->lock);
        return errno = EINVAL, -1;
}
