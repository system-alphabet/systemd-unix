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
#ifndef TIOCINQ
#include <sys/filio.h>
#define TIOCINQ         FIONREAD
#endif
