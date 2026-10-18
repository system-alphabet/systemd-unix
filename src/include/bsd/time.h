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

#else /* !__linux__ */

/*
 * Neither FreeBSD nor NetBSD has a CLOCK_BOOTTIME, and switch statements over clock ids expect it to be a
 * constant of its own. Give it a value the platform does not use for anything else and let the BSD compat
 * layer map it to CLOCK_MONOTONIC before calling clock_gettime().
 *
 * The value cannot be shared: FreeBSD's clock ids run 0-6 plus 17/18, so it uses 3, whereas NetBSD's are
 * CLOCK_REALTIME 0, CLOCK_VIRTUAL 1, CLOCK_PROF 2 and CLOCK_MONOTONIC 3 — reusing 3 there produced a
 * "duplicate case value" against CLOCK_MONOTONIC.
 */
#undef CLOCK_BOOTTIME
#if defined(__NetBSD__)
#define CLOCK_BOOTTIME  4
#else
#define CLOCK_BOOTTIME  3
#endif

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

#endif /* !__linux__ */
