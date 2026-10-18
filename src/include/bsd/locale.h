/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <locale.h>

#if defined(__NetBSD__)
/* NetBSD's <locale.h> declares newlocale()/freelocale() but not uselocale(),
 * and libc exports no such symbol either. Model it as a no-op that reports the
 * global locale as current — the same value glibc uses for LC_GLOBAL_LOCALE —
 * and ignore requests to switch; NetBSD's printf already formats according to
 * the initial C locale for our purposes. The stub lives in
 * src/libc/bsd/misc.c. */
locale_t uselocale(locale_t newloc);
#endif
