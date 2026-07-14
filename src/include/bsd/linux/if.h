/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Linux <linux/if.h> — interface name length and struct ifreq.
 * Minimal shim for FreeBSD compatibility.
 *
 * FreeBSD provides IFNAMSIZ, struct ifreq etc. via <net/if.h>.
 * This shim provides the Linux constants needed by code that includes
 * <linux/if.h> directly.
 */

#include <net/if.h>

#ifndef IFNAMSIZ
#define IFNAMSIZ 16
#endif
#ifndef ALTIFNAMSIZ
#define ALTIFNAMSIZ 128
#endif

/* IFF flags that are Linux-specific */
#ifndef IFF_LOWER_UP
#define IFF_LOWER_UP    0x10000
#endif
#ifndef IFF_DORMANT
#define IFF_DORMANT     0x20000
#endif
#ifndef IFF_ECHO
#define IFF_ECHO        0x40000
#endif

/* IF_OPER_* operational states */
#ifndef IF_OPER_UNKNOWN
#define IF_OPER_UNKNOWN      0
#endif
#ifndef IF_OPER_NOTPRESENT
#define IF_OPER_NOTPRESENT   1
#endif
#ifndef IF_OPER_DOWN
#define IF_OPER_DOWN         2
#endif
#ifndef IF_OPER_LOWERLAYERDOWN
#define IF_OPER_LOWERLAYERDOWN 3
#endif
#ifndef IF_OPER_TESTING
#define IF_OPER_TESTING      4
#endif
#ifndef IF_OPER_DORMANT
#define IF_OPER_DORMANT      5
#endif
#ifndef IF_OPER_UP
#define IF_OPER_UP           6
#endif
