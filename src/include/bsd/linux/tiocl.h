/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Linux <linux/tiocl.h> — TIOCL console ioctl definitions.
 * FreeBSD shim for compilation purposes.
 * Used by src/basic/terminal-util.c.
 */

#ifndef TIOCL_GETFGCONSOLE
#define TIOCL_GETFGCONSOLE      0x00
#endif
#ifndef TIOCL_BLANKSCREEN
#define TIOCL_BLANKSCREEN       0x20
#endif
#ifndef TIOCL_BLANKEDSCREEN
#define TIOCL_BLANKEDSCREEN     0x40
#endif
#ifndef TIOCL_UNBLANKSCREEN
#define TIOCL_UNBLANKSCREEN     0x60
#endif
#ifndef TIOCL_SETVESABLANK
#define TIOCL_SETVESABLANK      0x70
#endif
#ifndef TIOCL_GETKMSGREDIRECT
#define TIOCL_GETKMSGREDIRECT   0x80
#endif
#ifndef TIOCL_SETKMSGREDIRECT
#define TIOCL_SETKMSGREDIRECT   0x81
#endif
#ifndef TIOCL_GETFGCONSOLE_OVERSCAN
#define TIOCL_GETFGCONSOLE_OVERSCAN 0x82
#endif
#ifndef TIOCL_SETSCREENSHOT
#define TIOCL_SETSCREENSHOT     0x83
#endif

/* TIOCLINUX subcodes */
#ifndef TIOCLINUX
#define TIOCLINUX               0x541C
#endif
