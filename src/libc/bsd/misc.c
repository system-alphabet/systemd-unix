/* SPDX-License-Identifier: LGPL-2.1-or-later */

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <signal.h>
#include <sys/pidfd.h>

/* close_range - close all fds from first to last */
int close_range(unsigned int first, unsigned int last, int flags) {
        (void)flags;
        if (last == UINT_MAX) {
                /* close from first to max, get max fd from sysconf */
                long max = sysconf(_SC_OPEN_MAX);
                if (max < 0) max = 1024;
                for (long i = first; i <= max && i <= last; i++)
                        close(i);
        } else {
                for (unsigned int i = first; i <= last; i++)
                        close(i);
        }
        return 0;
}

/* getrandom - read random bytes */
ssize_t getrandom(void *buf, size_t buflen, unsigned int flags) {
        (void)flags;
        FILE *f;
        size_t n;
        int saved_errno;

        f = fopen("/dev/urandom", "re");
        if (!f)
                f = fopen("/dev/random", "re");
        if (!f)
                return errno = ENOSYS, -1;
        n = fread(buf, 1, buflen, f);
        saved_errno = errno;
        fclose(f);
        errno = saved_errno;
        if (n != buflen)
                return -1;
        return (ssize_t)n;
}

/* renameat2 - Linux extension */
int renameat2(int olddirfd, const char *oldpath, int newdirfd, const char *newpath, unsigned int flags) {
        if (flags == 0)
                return renameat(olddirfd, oldpath, newdirfd, newpath);

        if (flags == RENAME_NOREPLACE) {
                int fd = openat(newdirfd, newpath, O_RDONLY | O_CREAT | O_EXCL, 0);
                if (fd < 0)
                        return -1;
                close(fd);
                /* Now do the rename (newpath was just created empty) */
                return renameat(olddirfd, oldpath, newdirfd, newpath);
        }

        return errno = EOPNOTSUPP, -1;
}

/* pidfd_open - return pidfd (Linux-specific) */
int pidfd_open(pid_t pid, unsigned int flags) {
#if defined(__FreeBSD__)
        (void)flags;
        /* FreeBSD: use kqueue to monitor process exit */
        int kq = kqueue();
        if (kq < 0)
                return -1;
        struct kevent kev;
        EV_SET(&kev, pid, EVFILT_PROC, EV_ADD, NOTE_EXIT, 0, NULL);
        int r = kevent(kq, &kev, 1, NULL, 0, NULL);
        if (r < 0) {
                close(kq);
                return -1;
        }
        if (flags & O_CLOEXEC)
                fcntl(kq, F_SETFD, FD_CLOEXEC);
        return kq;
#else
        (void)pid;
        (void)flags;
        return errno = ENOSYS, -1;
#endif
}

/* pidfd_send_signal - send signal via pidfd */
int pidfd_send_signal(int pidfd, int sig, siginfo_t *info, unsigned int flags) {
        (void)pidfd;
        (void)sig;
        (void)info;
        (void)flags;
        return errno = ENOSYS, -1;
}
