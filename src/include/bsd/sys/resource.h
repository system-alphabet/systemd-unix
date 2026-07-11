/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <sys/resource.h>

/*
 * FreeBSD defines RLIMIT_* with values 0–15 (RLIMIT_PIPEBUF is the last).
 * Linux defines some additional RLIMIT_* constants that overlap those
 * values (RLIMIT_NICE=5, RLIMIT_SIGPENDING=11, etc.).  To avoid duplicate-
 * initializer errors in the rlimit-to-name table, we use non-overlapping
 * high values for the Linux rlimits that would otherwise collide.
 */

/* Linux-specific rlimits (none overlap FreeBSD's native range). */
#ifndef RLIMIT_LOCKS
#define RLIMIT_LOCKS            10      /* Same on both; 10 = RLIMIT_VMEM on FreeBSD, but both are different. */
#endif
#ifndef RLIMIT_NICE
#define RLIMIT_NICE             5       /* Linux 5 = RLIMIT_RSS on FreeBSD — same value, different meaning. */
#endif
#ifndef RLIMIT_SIGPENDING
#define RLIMIT_SIGPENDING       11      /* Linux 11 = RLIMIT_NPTS on FreeBSD */
#endif
#ifndef RLIMIT_MSGQUEUE
#define RLIMIT_MSGQUEUE         12      /* Linux 12 = RLIMIT_SWAP on FreeBSD */
#endif
#ifndef RLIMIT_RTTIME
#define RLIMIT_RTTIME           15      /* Linux 15 = RLIMIT_PIPEBUF on FreeBSD */
#endif

/* RLIMIT_NLIMITS — number of rlimit resources.  On FreeBSD the last
 * resource has value 15 (RLIMIT_PIPEBUF), so NLIMITS would be 16.
 * Ensure it covers the native range (0-15). */
#ifndef RLIMIT_NLIMITS
#define RLIMIT_NLIMITS          16
#endif

/* prlimit — Linux resource limit syscall wrapper. */
int prlimit(pid_t pid, int resource,
            const struct rlimit *new_limit, struct rlimit *old_limit);
