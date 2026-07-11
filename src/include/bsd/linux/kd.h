/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/* Linux keyboard/console ioctl definitions.
 * Used by src/basic/terminal-util.c. */

#ifndef KDGETLED
#define KDGETLED        0x4B31
#endif
#ifndef KDSETLED
#define KDSETLED        0x4B32
#endif
#ifndef KDGKBTYPE
#define KDGKBTYPE       0x4B33
#endif
#ifndef KDSKBMODE
#define KDSKBMODE       0x4B45
#endif
#ifndef KDGKBMODE
#define KDGKBMODE       0x4B44
#endif
#ifndef KDSETMODE
#define KDSETMODE       0x4B3A
#endif
#ifndef KDGETMODE
#define KDGETMODE       0x4B3B
#endif
#ifndef KDMKTONE
#define KDMKTONE        0x4B30
#endif
#ifndef KDGKBSENT
#define KDGKBSENT       0x4B48
#endif
#ifndef KDSKBSENT
#define KDSKBSENT       0x4B49
#endif
#ifndef KDGKBDIACR
#define KDGKBDIACR      0x4B4A
#endif
#ifndef KDSKBDIACR
#define KDSKBDIACR      0x4B4B
#endif
#ifndef KDADDIO
#define KDADDIO         0x4B34
#endif
#ifndef KDDELIO
#define KDDELIO         0x4B35
#endif
#ifndef KDENABIO
#define KDENABIO        0x4B36
#endif
#ifndef KDDISABIO
#define KDDISABIO       0x4B37
#endif
#ifndef KDSETRAD
#define KDSETRAD        0x4B40
#endif
#ifndef KDGKBRAD
#define KDGKBRAD        0x4B41
#endif
#ifndef KDSIGACCEPT
#define KDSIGACCEPT     0x4B4E
#endif

/* Keyboard modes */
#ifndef K_RAW
#define K_RAW           0x00
#endif
#ifndef K_XLATE
#define K_XLATE         0x01
#endif
#ifndef K_MEDIUMRAW
#define K_MEDIUMRAW     0x02
#endif
#ifndef K_UNICODE
#define K_UNICODE       0x03
#endif
#ifndef K_OFF
#define K_OFF           0x04
#endif

/* Keyboard types */
#ifndef KB_84
#define KB_84           0x01
#endif
#ifndef KB_101
#define KB_101          0x02
#endif
#ifndef KB_OTHER
#define KB_OTHER        0x03
#endif

/* LED bits */
#ifndef LED_CAP
#define LED_CAP         0x04
#endif
#ifndef LED_NUM
#define LED_NUM         0x02
#endif
#ifndef LED_SCR
#define LED_SCR         0x01
#endif
