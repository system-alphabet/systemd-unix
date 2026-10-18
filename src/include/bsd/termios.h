/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <termios.h>

/*
 * Linux termios flags not present on FreeBSD.
 */

#ifndef IUCLC
#if defined(__NetBSD__)
/* NetBSD's c_iflag has no lowcase bit, and 0x0200 is IXON there — a clear-mask
 * mentioning IUCLC must not clobber flow control, so use an input bit the
 * kernel never sets. */
#define IUCLC   0x1000
#else
#define IUCLC   0x0200
#endif
#endif

#ifndef IUTF8
/* Linux IUTF8 (enable UTF-8 input processing) — absent from NetBSD's termios;
 * 0x4000 is unused in NetBSD's c_iflag (IMAXBEL is 0x2000). */
#define IUTF8   0x4000
#endif
