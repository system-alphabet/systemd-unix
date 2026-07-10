/* SPDX-License-Identifier: LGPL-2.1-or-later */

/* Stub implementations for kqueue/kevent/EV_SET.
 * On a real BSD system these are provided by libc. These stubs exist only so that
 * the code compiles on Linux when -Dlibc=bsd is used for build validation. */

#include <sys/types.h>
#include <stdint.h>
#include <errno.h>
#include <sys/event.h>

int kqueue(void) {
        return errno = ENOSYS, -1;
}

int kevent(int kq, const struct kevent *changelist, int nchanges,
           struct kevent *eventlist, int nevents,
           const struct timespec *timeout) {
        (void)kq; (void)changelist; (void)nchanges;
        (void)eventlist; (void)nevents; (void)timeout;
        return errno = ENOSYS, -1;
}

void EV_SET(struct kevent *kev, uintptr_t ident, int16_t filter,
            uint16_t flags, uint32_t fflags, intptr_t data, void *udata) {
        (void)kev; (void)ident; (void)filter;
        (void)flags; (void)fflags; (void)data; (void)udata;
}
