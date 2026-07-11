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
#include <pthread_np.h>
#include <sys/event.h>
#include <sys/pidfd.h>
#include <sys/stat.h>
#include <sys/mount.h>
#include <dirent.h>

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

/* gettid — return thread ID (Linux style).
 * FreeBSD does not provide a public gettid() wrapper before 15;
 * we provide a stub that calls the thr_self syscall directly. */
#include <sys/thr.h>
pid_t gettid(void) {
        long tid;
        thr_self(&tid);
        return (pid_t)tid;
}

/* syncfs — Linux-specific: sync a filesystem referenced by fd.
 * FreeBSD doesn't have this syscall; emulate via fsync on the fd if it's
 * a directory or file, or simply call sync(). */
int syncfs(int fd) {
        (void)fd;
        /* FreeBSD can't sync a single filesystem by fd; do a full sync. */
        sync();
        return 0;
}

/* getdents64 — Linux getdents64 syscall wrapper.
 * FreeBSD provides getdirentries() which has a similar interface. */
ssize_t getdents64(int fd, void *dirp, size_t count) {
#if defined(__FreeBSD__)
        long base = 0;
        return getdirentries(fd, dirp, count, &base);
#else
        (void)fd;
        (void)dirp;
        (void)count;
        return errno = ENOSYS, -1;
#endif
}

/* statx — Linux statx() syscall (always fails on FreeBSD) */
int statx(int dirfd, const char *pathname, int flags,
          unsigned int mask, struct statx *statxbuf) {
        (void)dirfd;
        (void)pathname;
        (void)flags;
        (void)mask;
        (void)statxbuf;
        return errno = ENOSYS, -1;
}

/* personality — Linux process execution domain (always fails) */
int personality(unsigned long persona) {
        (void)persona;
        return errno = ENOSYS, -1;
}

/* prctl — Linux process control (always fails) */
int prctl(int option, ...) {
        (void)option;
        return errno = ENOSYS, -1;
}

/* glibc provides program_invocation_name / program_invocation_short_name
 * in <errno.h>.  FreeBSD has nothing equivalent. */
char *program_invocation_name = "";
char *program_invocation_short_name = "";

/* Linux-style mount / umount / umount2 wrappers.
 * FreeBSD's mount() has a different signature; these always fail. */
int mount_linux_shim(const char *source, const char *target,
                     const char *fstype, unsigned long flags, const void *data) {
        (void)source; (void)target; (void)fstype; (void)flags; (void)data;
        return errno = ENOSYS, -1;
}

int umount_linux_shim(const char *target) {
        (void)target;
        return errno = ENOSYS, -1;
}

int umount2_linux_shim(const char *target, int flags) {
        (void)target; (void)flags;
        return errno = ENOSYS, -1;
}
