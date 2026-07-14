/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <time.h>

#ifdef __linux__
/* On Linux builds, simply provide missing ALARM clock definitions and
 * MONOTONIC_RAW.  CLOCK_BOOTTIME is already correct on Linux. */

#ifndef CLOCK_MONOTONIC_RAW
#define CLOCK_MONOTONIC_RAW     4
#endif

#ifndef CLOCK_REALTIME_ALARM
#define CLOCK_REALTIME_ALARM    8
#endif
#ifndef CLOCK_BOOTTIME_ALARM
#define CLOCK_BOOTTIME_ALARM    9
#endif

#else /* !__linux__ — FreeBSD */

/*
 * On FreeBSD, CLOCK_MONOTONIC (=4) already includes suspend time, so
 * CLOCK_BOOTTIME is defined as CLOCK_MONOTONIC.  systemd switch statements
 * expect CLOCK_BOOTTIME to be a distinct constant, so we redefine it to
 * an unused value (3).  The BSD compat layer maps it to CLOCK_MONOTONIC
 * before calling clock_gettime().
 */

/*
 * FreeBSD defines CLOCK_BOOTTIME as CLOCK_MONOTONIC, which causes duplicate
 * case-label errors in switch statements.  Undefine it and give it a
 * distinct value (3, unused by FreeBSD).
 */
#undef CLOCK_BOOTTIME
#define CLOCK_BOOTTIME  3

#ifndef CLOCK_MONOTONIC_RAW
#define CLOCK_MONOTONIC_RAW     6
#endif

/* ALARM variants — only used as switch-case labels; mapped by map_clock_id(). */
#ifndef CLOCK_REALTIME_ALARM
#define CLOCK_REALTIME_ALARM    17
#endif
#ifndef CLOCK_BOOTTIME_ALARM
#define CLOCK_BOOTTIME_ALARM    18
#endif

#endif /* __linux__ */
