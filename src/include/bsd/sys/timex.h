/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * FreeBSD and glibc ship a self-contained <sys/timex.h>. NetBSD's is not: it reaches for sys/cdefs.h and
 * sys/time.h types without including them itself, which makes compile-time probes such as meson's
 * SIZEOF_TIMEX_MEMBER fail. Pull the prerequisites in first — harmless on the libcs that already do it.
 */

#include <sys/cdefs.h>
#include <sys/time.h>

#include_next <sys/timex.h>
