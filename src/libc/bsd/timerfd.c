/* SPDX-License-Identifier: LGPL-2.1-or-later */

#include "sys/timerfd.h"
#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <signal.h>

#ifndef CLOCK_BOOTTIME
#define CLOCK_BOOTTIME CLOCK_MONOTONIC
#endif
#ifndef CLOCK_REALTIME_ALARM
#define CLOCK_REALTIME_ALARM CLOCK_REALTIME
#endif
#ifndef CLOCK_BOOTTIME_ALARM
#define CLOCK_BOOTTIME_ALARM CLOCK_MONOTONIC
#endif

#define MAX_TIMER_FDS 128

struct timerfd_info {
        int read_fd;
        int write_fd;
        int kqueue_fd;
        int clockid;
        struct itimerspec value;
        int used;
        pthread_t thread;
        int stop;
        pthread_mutex_t lock;
        pthread_cond_t cond;
};

static struct timerfd_info g_timers[MAX_TIMER_FDS];
static pthread_mutex_t g_lock = PTHREAD_MUTEX_INITIALIZER;

static void* timer_thread(void *arg) {
        struct timerfd_info *ti = arg;
        struct kevent ev;
        struct timespec ts;

        pthread_mutex_lock(&ti->lock);
        while (!ti->stop) {
                if (ti->value.it_value.tv_sec == 0 && ti->value.it_value.tv_nsec == 0) {
                        pthread_cond_wait(&ti->cond, &ti->lock);
                        continue;
                }
                clock_gettime(ti->clockid, &ts);
                struct timespec deadline = ti->value.it_value;
                struct timespec now;
                clock_gettime(ti->clockid, &now);
                if (now.tv_sec > deadline.tv_sec ||
                    (now.tv_sec == deadline.tv_sec && now.tv_nsec >= deadline.tv_nsec)) {
                        uint64_t exp = 1;
                        write(ti->write_fd, &exp, sizeof(exp));
                        if (ti->value.it_interval.tv_sec > 0 || ti->value.it_interval.tv_nsec > 0) {
                                ti->value.it_value = ti->value.it_interval;
                        } else {
                                ti->value.it_value.tv_sec = 0;
                                ti->value.it_value.tv_nsec = 0;
                        }
                        continue;
                }
                struct timespec wait;
                wait.tv_sec = deadline.tv_sec - now.tv_sec;
                wait.tv_nsec = deadline.tv_nsec - now.tv_nsec;
                if (wait.tv_nsec < 0) {
                        wait.tv_sec--;
                        wait.tv_nsec += 1000000000L;
                }
                struct timespec abs_wait;
                clock_gettime(CLOCK_REALTIME, &abs_wait);
                abs_wait.tv_sec += wait.tv_sec;
                abs_wait.tv_nsec += wait.tv_nsec;
                if (abs_wait.tv_nsec >= 1000000000L) {
                        abs_wait.tv_sec++;
                        abs_wait.tv_nsec -= 1000000000L;
                }
                pthread_cond_timedwait(&ti->cond, &ti->lock, &abs_wait);
        }
        pthread_mutex_unlock(&ti->lock);
        return NULL;
}

int timerfd_create(int clockid, int flags) {
        int r, pfd[2], slot;

        if (flags & ~(TFD_CLOEXEC | TFD_NONBLOCK))
                return errno = EINVAL, -1;

        if (clockid != CLOCK_REALTIME && clockid != CLOCK_MONOTONIC &&
            clockid != CLOCK_BOOTTIME && clockid != CLOCK_REALTIME_ALARM &&
            clockid != CLOCK_BOOTTIME_ALARM)
                return errno = EINVAL, -1;

        if (clockid == CLOCK_REALTIME_ALARM || clockid == CLOCK_BOOTTIME_ALARM)
                clockid = CLOCK_REALTIME;

        if (pipe(pfd) < 0)
                return -1;

        if (flags & TFD_CLOEXEC) {
                fcntl(pfd[0], F_SETFD, FD_CLOEXEC);
                fcntl(pfd[1], F_SETFD, FD_CLOEXEC);
        }
        if (flags & TFD_NONBLOCK) {
                int fl = fcntl(pfd[0], F_GETFL);
                fcntl(pfd[0], F_SETFL, fl | O_NONBLOCK);
        }

        pthread_mutex_lock(&g_lock);
        slot = -1;
        for (int i = 0; i < MAX_TIMER_FDS; i++)
                if (!g_timers[i].used) { slot = i; break; }
        if (slot < 0) {
                pthread_mutex_unlock(&g_lock);
                close(pfd[0]); close(pfd[1]);
                return errno = ENOMEM, -1;
        }

        g_timers[slot].read_fd = pfd[0];
        g_timers[slot].write_fd = pfd[1];
        g_timers[slot].clockid = clockid;
        g_timers[slot].used = 1;
        g_timers[slot].stop = 0;
        memset(&g_timers[slot].value, 0, sizeof(struct itimerspec));
        pthread_mutex_init(&g_timers[slot].lock, NULL);
        pthread_cond_init(&g_timers[slot].cond, NULL);
        g_timers[slot].kqueue_fd = -1;
        pthread_mutex_unlock(&g_lock);

        r = pthread_create(&g_timers[slot].thread, NULL, timer_thread, &g_timers[slot]);
        if (r != 0) {
                pthread_mutex_lock(&g_lock);
                g_timers[slot].used = 0;
                pthread_mutex_unlock(&g_lock);
                close(pfd[0]); close(pfd[1]);
                return errno = r, -1;
        }
        pthread_detach(g_timers[slot].thread);

        return pfd[0];
}

int timerfd_settime(int fd, int flags, const struct itimerspec *new_value, struct itimerspec *old_value) {
        pthread_mutex_lock(&g_lock);
        for (int i = 0; i < MAX_TIMER_FDS; i++) {
                if (g_timers[i].used && g_timers[i].read_fd == fd) {
                        struct timerfd_info *ti = &g_timers[i];
                        pthread_mutex_unlock(&g_lock);

                        pthread_mutex_lock(&ti->lock);
                        if (old_value)
                                *old_value = ti->value;
                        if (flags & TFD_TIMER_ABSTIME) {
                                ti->value = *new_value;
                        } else {
                                struct timespec now;
                                clock_gettime(ti->clockid, &now);
                                ti->value.it_value.tv_sec = now.tv_sec + new_value->it_value.tv_sec;
                                ti->value.it_value.tv_nsec = now.tv_nsec + new_value->it_value.tv_nsec;
                                if (ti->value.it_value.tv_nsec >= 1000000000L) {
                                        ti->value.it_value.tv_sec++;
                                        ti->value.it_value.tv_nsec -= 1000000000L;
                                }
                                ti->value.it_interval = new_value->it_interval;
                        }
                        pthread_cond_signal(&ti->cond);
                        pthread_mutex_unlock(&ti->lock);
                        return 0;
                }
        }
        pthread_mutex_unlock(&g_lock);
        return errno = EBADF, -1;
}

int timerfd_gettime(int fd, struct itimerspec *curr_value) {
        pthread_mutex_lock(&g_lock);
        for (int i = 0; i < MAX_TIMER_FDS; i++) {
                if (g_timers[i].used && g_timers[i].read_fd == fd) {
                        struct timerfd_info *ti = &g_timers[i];
                        pthread_mutex_unlock(&g_lock);
                        pthread_mutex_lock(&ti->lock);
                        if (ti->value.it_value.tv_sec == 0 && ti->value.it_value.tv_nsec == 0) {
                                memset(curr_value, 0, sizeof(*curr_value));
                        } else {
                                struct timespec now;
                                clock_gettime(ti->clockid, &now);
                                curr_value->it_interval = ti->value.it_interval;
                                curr_value->it_value.tv_sec = ti->value.it_value.tv_sec - now.tv_sec;
                                curr_value->it_value.tv_nsec = ti->value.it_value.tv_nsec - now.tv_nsec;
                                if (curr_value->it_value.tv_nsec < 0) {
                                        curr_value->it_value.tv_sec--;
                                        curr_value->it_value.tv_nsec += 1000000000L;
                                }
                                if (curr_value->it_value.tv_sec < 0) {
                                        memset(curr_value, 0, sizeof(*curr_value));
                                }
                        }
                        pthread_mutex_unlock(&ti->lock);
                        return 0;
                }
        }
        pthread_mutex_unlock(&g_lock);
        return errno = EBADF, -1;
}
