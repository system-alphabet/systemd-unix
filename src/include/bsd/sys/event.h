/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <sys/types.h>
#include <stdint.h>
#include <time.h>
#include <signal.h>

#ifdef __cplusplus
extern "C" {
#endif

#define EVFILT_READ        (-1)
#define EVFILT_WRITE       (-2)
#define EVFILT_AIO         (-3)
#define EVFILT_VNODE       (-4)
#define EVFILT_PROC        (-5)
#define EVFILT_SIGNAL      (-6)
#define EVFILT_TIMER       (-7)
#define EVFILT_PROCDESC    (-8)
#define EVFILT_FS          (-9)
#define EVFILT_LIO         (-10)
#define EVFILT_USER        (-11)
#define EVFILT_SENDFILE    (-12)
#define EVFILT_EMPTY       (-13)
#define EVFILT_SYSCOUNT    13

#define EV_ADD              0x0001
#define EV_DELETE           0x0002
#define EV_ENABLE           0x0004
#define EV_DISABLE          0x0008
#define EV_ONESHOT          0x0010
#define EV_CLEAR            0x0020
#define EV_RECEIPT          0x0040
#define EV_DISPATCH         0x0080
#define EV_UDATA_SPECIFIC   0x0100
#define EV_DISPATCH2        0x0200
#define EVFILT__NLEVENT     0x0400

#define EV_EOF              0x8000
#define EV_ERROR            0x4000
#define EV_OOBAND           0x2000
#define EV_HUP              0x1000
#define EV_FLAG1             0x2000
#define EV_FLAG2             0x4000

#define NOTE_FFNOP          0x00000000
#define NOTE_FFAND          0x40000000
#define NOTE_FFOR           0x80000000
#define NOTE_FFCOPY         0xc0000000
#define NOTE_FFCTRLMASK     0xc0000000
#define NOTE_FFLAGSMASK     0x00ffffff

#define NOTE_TRIGGER        0x01000000
#define NOTE_FFLAGSMASK     0x00ffffff

#define NOTE_EOF            0x00000001
#define NOTE_DELETE         0x00000001
#define NOTE_WRITE          0x00000002
#define NOTE_EXTEND         0x00000004
#define NOTE_ATTRIB         0x00000008
#define NOTE_LINK           0x00000010
#define NOTE_RENAME         0x00000020
#define NOTE_REVOKE         0x00000040
#define NOTE_OPEN           0x00000080
#define NOTE_CLOSE          0x00000100
#define NOTE_CLOSE_WRITE    0x00000200
#define NOTE_READ           0x00000400

#define NOTE_EXIT           0x80000000
#define NOTE_FORK           0x40000000
#define NOTE_EXEC           0x20000000
#define NOTE_TRACK          0x00000001
#define NOTE_TRACKERR       0x00000002
#define NOTE_CHILD          0x00000004

#define NOTE_SECONDS        0x00000001
#define NOTE_MSECONDS       0x00000002
#define NOTE_USECONDS       0x00000004
#define NOTE_NSECONDS       0x00000008
#define NOTE_ABSOLUTE       0x00000010
#define NOTE_ABSTIME        0x00000010

struct kevent {
        uintptr_t ident;
        int16_t   filter;
        uint16_t  flags;
        uint32_t  fflags;
        intptr_t  data;
        void     *udata;
};

int kqueue(void);
int kevent(int kq, const struct kevent *changelist, int nchanges,
           struct kevent *eventlist, int nevents,
           const struct timespec *timeout);
void EV_SET(struct kevent *kev, uintptr_t ident, int16_t filter,
            uint16_t flags, uint32_t fflags, intptr_t data, void *udata);

#ifdef __cplusplus
}
#endif
