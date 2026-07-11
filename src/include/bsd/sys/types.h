/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * BSD shim for <sys/types.h>.
 * FreeBSD defines mode_t as unsigned short (2 bytes).  Linux defines it as
 * unsigned int (4 bytes).  The narrower type triggers integer promotions in
 * expressions like st->st_mode & 07777, which become int rather than
 * unsigned int, causing -Wformat-signedness errors when passed to %04o.
 *
 * Revert to the Linux-wide unsigned int so that systemd compiles cleanly.
 * This is safe for a compile-only cross-build since we never link against
 * FreeBSD libc that inspects the typedef width.
 */

#include_next <sys/types.h>

#include <stdint.h>

#undef mode_t
#define mode_t uint32_t
