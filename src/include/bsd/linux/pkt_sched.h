/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Linux <linux/pkt_sched.h> — packet scheduling constants.
 * FreeBSD shim providing only TCA_* constants used by socket-util.c.
 */

#ifndef TCA_ORPHAN_MARK
#define TCA_ORPHAN_MARK         32
#endif
#ifndef TCA_PAD
#define TCA_PAD                 33
#endif
#ifndef TCA_INGRESS_BLOCK
#define TCA_INGRESS_BLOCK       34
#endif
#ifndef TCA_EGRESS_BLOCK
#define TCA_EGRESS_BLOCK        35
#endif
#ifndef TCA_DUMP_FLAGS
#define TCA_DUMP_FLAGS          36
#endif
#ifndef TCA_EXT_WARN_MSG
#define TCA_EXT_WARN_MSG        37
#endif
#ifndef TCA_CHAIN
#define TCA_CHAIN               38
#endif
#ifndef TCA_HW_OFFLOAD
#define TCA_HW_OFFLOAD          39
#endif
#ifndef TCA_STATS
#define TCA_STATS               40
#endif
#ifndef TCA_XSTATS
#define TCA_XSTATS              41
#endif
#ifndef TCA_BASIC_TCN
#define TCA_BASIC_TCN           42
#endif
#ifndef TCA_BASIC_HW_FLAGS
#define TCA_BASIC_HW_FLAGS      43
#endif
#ifndef TCA_STAB
#define TCA_STAB                44
#endif

/* TC_H_MAJ / TC_H_MIN */
#ifndef TC_H_MAJ_MASK
#define TC_H_MAJ_MASK   0xFFFF0000
#endif
#ifndef TC_H_MIN_MASK
#define TC_H_MIN_MASK   0x0000FFFF
#endif
#ifndef TC_H_MAJ
#define TC_H_MAJ(h)     ((h) & TC_H_MAJ_MASK)
#endif
#ifndef TC_H_MIN
#define TC_H_MIN(h)     ((h) & TC_H_MIN_MASK)
#endif
#ifndef TC_H_UNSPEC
#define TC_H_UNSPEC     0
#endif
#ifndef TC_H_ROOT
#define TC_H_ROOT       0xFFFFFFFF
#endif
#ifndef TC_H_INGRESS
#define TC_H_INGRESS    0xFFFFFFF1
#endif
#ifndef TC_H_CLSACT
#define TC_H_CLSACT     TC_H_INGRESS
#endif
