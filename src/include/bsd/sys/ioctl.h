/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <sys/ioctl.h>

/*
 * Linux-specific TIOC ioctls not present on FreeBSD.
 * Used by src/basic/terminal-util.c.
 */

#ifndef TIOCVHANGUP
#define TIOCVHANGUP     0x5437
#endif
#ifndef TIOCGPKT
#define TIOCGPKT        0x80045438
#endif
#ifndef TIOCGPTPEER
#define TIOCGPTPEER     0x5441
#endif
#ifndef TIOCGPTN
/* Linux TIOCGPTN — query the number of a devpts pty. NetBSD has no devpts (and
 * no TIOCGPTN), so ptsname_namespace() gets ENOTTY from this ioctl and reports
 * the error; the value is only defined to make the code compile. Type 'T'
 * number 0x30 collides with no existing NetBSD ioctl. */
#define TIOCGPTN        0x80045430
#endif
#ifndef TIOCINQ
#include <sys/filio.h>
#define TIOCINQ         FIONREAD
#endif
