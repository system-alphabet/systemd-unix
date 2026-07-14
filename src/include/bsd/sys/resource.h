/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * BSD shim for <sys/resource.h>.
 *
 * FreeBSD and Linux define different RLIMIT_* value sets with overlapping
 * numbers.  We wrap FreeBSD's <sys/resource.h> and then override the RLIMIT
 * constants so that Linux code using them (rlimit-util.c et al.) sees the
 * correct (Linux) values.  The FreeBSD-native RLIMIT constants that have no
 * Linux counterpart (e.g. RLIMIT_SBSIZE, RLIMIT_NPTS) are undefined here;
 * they are not used by systemd anyway.
 *
 * At runtime, getrlimit()/setrlimit() calls will use Linux-numbered
 * resources, which FreeBSD's kernel does not understand; those calls will
 * fail with EINVAL unless a dedicated translation shim is in place.
 */

#include_next <sys/resource.h>
#include <sys/types.h>

/* Undefine FreeBSD constants that would collide with Linux values */
#ifdef RLIMIT_MEMLOCK
#undef RLIMIT_MEMLOCK
#endif
#ifdef RLIMIT_NPROC
#undef RLIMIT_NPROC
#endif
#ifdef RLIMIT_NOFILE
#undef RLIMIT_NOFILE
#endif
#ifdef RLIMIT_AS
#undef RLIMIT_AS
#endif

/* Now define all Linux RLIMIT_* values */
#define RLIMIT_CPU              0
#define RLIMIT_FSIZE            1
#define RLIMIT_DATA             2
#define RLIMIT_STACK            3
#define RLIMIT_CORE             4
#define RLIMIT_RSS              5
#define RLIMIT_NPROC            6
#define RLIMIT_NOFILE           7
#define RLIMIT_MEMLOCK          8
#define RLIMIT_AS               9
#define RLIMIT_LOCKS            10
#define RLIMIT_SIGPENDING       11
#define RLIMIT_MSGQUEUE         12
#define RLIMIT_NICE             13
#define RLIMIT_RTPRIO           14
#define RLIMIT_RTTIME           15
#define RLIMIT_NLIMITS          16

/* prlimit — Linux resource limit syscall wrapper.
 * On Linux, the system header already provides the declaration with
 * a different signature (enum __rlimit_resource vs int), so skip. */
#ifndef __linux__
int prlimit(pid_t pid, int resource,
            const struct rlimit *new_limit, struct rlimit *old_limit);
#endif
