/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <time.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Clock identifiers for timerfd */
#define TFD_TIMER_ABSTIME (1 << 0)
#define TFD_TIMER_CANCEL_ON_SET (1 << 1)

/* Flags */
#define TFD_CLOEXEC 02000000
#define TFD_NONBLOCK 00004000

int timerfd_create(int clockid, int flags);
int timerfd_settime(int fd, int flags, const struct itimerspec *new_value, struct itimerspec *old_value);
int timerfd_gettime(int fd, struct itimerspec *curr_value);

#ifdef __cplusplus
}
#endif
