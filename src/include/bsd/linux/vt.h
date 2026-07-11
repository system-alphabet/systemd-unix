/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Linux <linux/vt.h> — virtual terminal ioctl definitions.
 * FreeBSD shim for compilation purposes.
 * Used by src/basic/terminal-util.c.
 */

#include <stdint.h>

/* VT ioctls */
#ifndef VT_OPENQRY
#define VT_OPENQRY              0x5600
#endif
#ifndef VT_GETMODE
#define VT_GETMODE              0x5601
#endif
#ifndef VT_SETMODE
#define VT_SETMODE              0x5602
#endif
#ifndef VT_GETSTATE
#define VT_GETSTATE             0x5603
#endif
#ifndef VT_SENDSIG
#define VT_SENDSIG              0x5604
#endif
#ifndef VT_RELDISP
#define VT_RELDISP              0x5605
#endif
#ifndef VT_ACTIVATE
#define VT_ACTIVATE             0x5606
#endif
#ifndef VT_WAITACTIVE
#define VT_WAITACTIVE           0x5607
#endif
#ifndef VT_DISALLOCATE
#define VT_DISALLOCATE          0x5608
#endif
#ifndef VT_RESIZE
#define VT_RESIZE               0x5609
#endif
#ifndef VT_RESIZEX
#define VT_RESIZEX              0x560A
#endif
#ifndef VT_LOCKSWITCH
#define VT_LOCKSWITCH           0x560B
#endif
#ifndef VT_UNLOCKSWITCH
#define VT_UNLOCKSWITCH         0x560C
#endif
#ifndef VT_GETHIFONTSIZE
#define VT_GETHIFONTSIZE        0x560D
#endif
#ifndef VT_SETHIFONTSIZE
#define VT_SETHIFONTSIZE        0x560E
#endif

/* VT modes */
struct vt_mode {
        char    mode;
        char    waitv;
        short   relsig;
        short   acqsig;
        short   frsig;
};

#define VT_AUTO          0x00
#define VT_PROCESS       0x01
#define VT_ACKACQ        0x02

/* VT states */
struct vt_stat {
        unsigned short v_active;
        unsigned short v_signal;
        unsigned short v_state;
};

struct vt_sizes {
        unsigned short v_rows;
        unsigned short v_cols;
        unsigned short v_scrollsize;
};

struct vt_consize {
        unsigned short v_rows;
        unsigned short v_cols;
        unsigned short v_vcol;
        unsigned short v_vrow;
};

/* Mouse and pointer interface */
#define KIOCSOUND               0x4B2F
#define KDMKTONE                0x4B30
#define KDGETLED                0x4B31
#define KDSETLED                0x4B32
#define KDGKBTYPE               0x4B33
#define KDSKBMODE               0x4B45
#define KDGKBMODE               0x4B44
#define KDSETMODE               0x4B3A
#define KDGETMODE               0x4B3B
#define KDSIGACCEPT             0x4B4E
