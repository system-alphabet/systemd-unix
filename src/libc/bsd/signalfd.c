/* SPDX-License-Identifier: LGPL-2.1-or-later */

#include "sys/signalfd.h"
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_SIGNAL_FDS 64

struct signalfd_info {
        int read_fd;
        int write_fd;
        sigset_t mask;
        int used;
};

static struct signalfd_info g_fds[MAX_SIGNAL_FDS];
static pthread_mutex_t g_lock = PTHREAD_MUTEX_INITIALIZER;
static struct sigaction g_old_actions[NSIG];

static void sigfd_handler(int sig, siginfo_t *info, void *ctx) {
        struct signalfd_siginfo si;
        (void)ctx;

        memset(&si, 0, sizeof(si));
        si.ssi_signo = sig;
        si.ssi_errno = info->si_errno;
        si.ssi_code  = info->si_code;
        si.ssi_pid   = (uint32_t)info->si_pid;
        si.ssi_uid   = (uint32_t)info->si_uid;
        si.ssi_status = info->si_status;
        si.ssi_int   = info->si_value.sival_int;
        si.ssi_ptr   = (uint64_t)(uintptr_t)info->si_value.sival_ptr;
        si.ssi_band  = (uint32_t)info->si_band;

        pthread_mutex_lock(&g_lock);
        for (int i = 0; i < MAX_SIGNAL_FDS; i++)
                if (g_fds[i].used && sigismember(&g_fds[i].mask, sig) == 1)
                        write(g_fds[i].write_fd, &si, sizeof(si));
        pthread_mutex_unlock(&g_lock);
}

static int install_handler(int sig) {
        struct sigaction sa;
        memset(&sa, 0, sizeof(sa));
        sa.sa_sigaction = sigfd_handler;
        sa.sa_flags = SA_SIGINFO | SA_NODEFER;
        sigemptyset(&sa.sa_mask);
        return sigaction(sig, &sa, &g_old_actions[sig]);
}

static void restore_handler(int sig) {
        sigaction(sig, &g_old_actions[sig], NULL);
}

int signalfd(int fd, const sigset_t *mask, int flags) {
        int r, pfd[2], read_fd, write_fd;

        if (flags & ~(SFD_CLOEXEC | SFD_NONBLOCK))
                return errno = EINVAL, -1;

        if (fd >= 0) {
                /* Update existing signalfd mask */
                pthread_mutex_lock(&g_lock);
                for (int i = 0; i < MAX_SIGNAL_FDS; i++) {
                        if (g_fds[i].used && g_fds[i].read_fd == fd) {
                                sigset_t old = g_fds[i].mask;
                                g_fds[i].mask = *mask;
                                pthread_mutex_unlock(&g_lock);

                                /* install handlers for new signals, restore for removed */
                                for (int s = 1; s < NSIG; s++) {
                                        int was = sigismember(&old, s) == 1;
                                        int now = sigismember(mask, s) == 1;
                                        if (!was && now) install_handler(s);
                                        if (was && !now) {
                                                /* Only restore if no other signalfd needs it */
                                                pthread_mutex_lock(&g_lock);
                                                int needed = 0;
                                                for (int j = 0; j < MAX_SIGNAL_FDS; j++)
                                                        if (g_fds[j].used && g_fds[j].read_fd != fd &&
                                                            sigismember(&g_fds[j].mask, s) == 1)
                                                                needed = 1;
                                                pthread_mutex_unlock(&g_lock);
                                                if (!needed) restore_handler(s);
                                        }
                                }
                                return fd;
                        }
                }
                return errno = EINVAL, -1;
        }

        /* Create new signalfd */
        if (pipe(pfd) < 0)
                return -1;

        read_fd = pfd[0];
        write_fd = pfd[1];

        if (flags & SFD_CLOEXEC) {
                fcntl(read_fd, F_SETFD, FD_CLOEXEC);
                fcntl(write_fd, F_SETFD, FD_CLOEXEC);
        }
        if (flags & SFD_NONBLOCK) {
                int fl = fcntl(read_fd, F_GETFL);
                fcntl(read_fd, F_SETFL, fl | O_NONBLOCK);
        }

        pthread_mutex_lock(&g_lock);
        int slot = -1;
        for (int i = 0; i < MAX_SIGNAL_FDS; i++) {
                if (!g_fds[i].used) { slot = i; break; }
        }
        if (slot < 0) {
                pthread_mutex_unlock(&g_lock);
                close(read_fd);
                close(write_fd);
                return errno = ENOMEM, -1;
        }

        g_fds[slot].read_fd = read_fd;
        g_fds[slot].write_fd = write_fd;
        g_fds[slot].mask = *mask;
        g_fds[slot].used = 1;
        pthread_mutex_unlock(&g_lock);

        for (int s = 1; s < NSIG; s++) {
                if (sigismember(mask, s) == 1) {
                        r = install_handler(s);
                        if (r < 0) {
                                /* roll back */
                                for (int t = 1; t < s; t++)
                                        if (sigismember(mask, t) == 1) restore_handler(t);
                                pthread_mutex_lock(&g_lock);
                                g_fds[slot].used = 0;
                                pthread_mutex_unlock(&g_lock);
                                close(read_fd);
                                close(write_fd);
                                return -1;
                        }
                }
        }

        return read_fd;
}
