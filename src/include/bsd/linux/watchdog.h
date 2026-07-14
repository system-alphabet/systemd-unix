/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <linux/types.h>
#include <sys/ioccom.h>

/* Linux watchdog driver ioctls — not available on FreeBSD */
#define WDIOC_GETSUPPORT  _IOR('W', 0x00, struct watchdog_info)
#define WDIOC_SETOPTIONS  _IOR('W', 0x04, int)
#define WDIOC_KEEPALIVE   _IOR('W', 0x05, int)
#define WDIOC_GETTIMEOUT  _IOR('W', 0x07, int)
#define WDIOC_SETTIMEOUT  _IOWR('W', 0x06, int)
#define WDIOC_GETPRETIMEOUT _IOR('W', 0x09, int)
#define WDIOC_SETPRETIMEOUT _IOWR('W', 0x08, int)

/* Watchdog options */
#define WDIOS_ENABLECARD  0x0001
#define WDIOS_DISABLECARD 0x0002

/* Watchdog status flags */
#define WDIOF_SETTIMEOUT  0x0002
#define WDIOF_MAGICCLOSE  0x0004
#define WDIOF_PRETIMEOUT  0x0100
#define WDIOF_ALARMONLY   0x0200
#define WDIOF_CARDRESET   0x1000

struct watchdog_info {
        __u32 options;
        __u32 firmware_version;
        __u8  identity[32];
};
