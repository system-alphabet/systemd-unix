/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <stdint.h>

/*
 * Linux <linux/time_types.h> — kernel time types.
 * FreeBSD has no linux/time_types.h, so provide a minimal shim.
 */

#ifndef __kernel_time64_t_defined
#define __kernel_time64_t_defined
typedef int64_t __kernel_time64_t;
#endif

struct __kernel_timespec {
        __kernel_time64_t tv_sec;   /* seconds */
        long long        tv_nsec;   /* nanoseconds */
};
