/* SPDX-License-Identifier: LGPL-2.1-or-later */

#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int memfd_create(const char *name, unsigned int flags) {
#if defined(__FreeBSD__)
        /* FreeBSD: use SHM_ANON via shm_open(SHM_ANON, ...) */
        int fd = shm_open(SHM_ANON, O_RDWR | O_CREAT, 0600);
        if (fd < 0)
                return -1;
        if (flags & MFD_CLOEXEC)
                fcntl(fd, F_SETFD, FD_CLOEXEC);
        return fd;
#else
        /* Other BSD / non-Linux: mkstemp + unlink */
        int fds[2] = { -1, -1 };

        if (pipe(fds) < 0)
                return -1;

        close(fds[1]);

        if (flags & MFD_CLOEXEC)
                fcntl(fds[0], F_SETFD, FD_CLOEXEC);
        if (!(flags & MFD_ALLOW_SEALING)) {
                /* Without sealing, make it writeable by reopening with /dev/fd */
                char fdpath[64];
                snprintf(fdpath, sizeof(fdpath), "/dev/fd/%d", fds[0]);
                int newfd = open(fdpath, O_RDWR);
                if (newfd >= 0) {
                        close(fds[0]);
                        fds[0] = newfd;
                }
        }

        return fds[0];
#endif
}
