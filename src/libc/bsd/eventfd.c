/* SPDX-License-Identifier: LGPL-2.1-or-later */

#include "sys/eventfd.h"
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int eventfd(unsigned int initval, int flags) {
        int pfd[2], r, read_fd;

        if (flags & ~(EFD_SEMAPHORE | EFD_CLOEXEC | EFD_NONBLOCK))
                return errno = EINVAL, -1;

        r = pipe(pfd);
        if (r < 0)
                return -1;

        read_fd = pfd[0];

        if (flags & EFD_CLOEXEC) {
                fcntl(read_fd, F_SETFD, FD_CLOEXEC);
                fcntl(pfd[1], F_SETFD, FD_CLOEXEC);
        }
        if (flags & EFD_NONBLOCK) {
                int fl = fcntl(read_fd, F_GETFL);
                fcntl(read_fd, F_SETFL, fl | O_NONBLOCK);
        }

        /* Write initial value */
        eventfd_t val = initval;
        write(pfd[1], &val, sizeof(val));

        return read_fd;
}

int eventfd_read(int fd, eventfd_t *value) {
        ssize_t n = read(fd, value, sizeof(*value));
        if (n < 0)
                return -1;
        if (n != sizeof(*value))
                return errno = EINVAL, -1;
        return 0;
}

int eventfd_write(int fd, eventfd_t value) {
        ssize_t n = write(fd, &value, sizeof(value));
        if (n < 0)
                return -1;
        return 0;
}
