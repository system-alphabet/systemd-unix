/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * glibc and FreeBSD declare fputc_unlocked()/fputs_unlocked() in <stdio.h>; NetBSD's and OpenBSD's do not,
 * and their libc exports no such symbol. The "unlocked" variants only exist to skip per-stream locking for
 * code that already holds the lock — on these libcs plain fputc()/fputs() are the same call minus the
 * optimization, so route them there.
 */

#include_next <stdio.h>

#ifndef fputc_unlocked
#define fputc_unlocked(c, f) fputc(c, f)
#endif
#ifndef fputs_unlocked
#define fputs_unlocked(s, f) fputs(s, f)
#endif
#ifndef fwrite_unlocked
#define fwrite_unlocked(p, sz, n, f) fwrite(p, sz, n, f)
#endif
