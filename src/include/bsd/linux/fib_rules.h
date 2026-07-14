/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/* FRA_* routing rule attributes */
#define FRA_UNSPEC              0
#define FRA_DST                 1
#define FRA_SRC                 2
#define FRA_IIFNAME             3
#define FRA_GOTO                4
#define FRA_UNUSED5             5
#define FRA_FWMARK              6
#define FRA_FLOW                7
#define FRA_UNUSED8             8
#define FRA_TABLE               9
#define FRA_FWMASK              10
#define FRA_OIFNAME             11
#define FRA_PRIORITY            12
#define FRA_PREF                13
#define FRA_IP_PROTO            14
#define FRA_SPORT_RANGE         15
#define FRA_DPORT_RANGE         16
#define FRA_PROTOCOL            17
#define FRA_UID_START           18
#define FRA_UID_END             19
#define FRA_L3MDEV              20
#define FRA_UID_RANGE           FRA_UID_START
#define FRA_DST_IS_PREFIX       18
#define FRA_DST_IS_PREFIX_LEN   0

/* FR_ACT_* rule actions */
#define FR_ACT_TO_TBL           1
#define FR_ACT_GOTO             2
#define FR_ACT_NOP              3
#define FR_ACT_RES3             4
#define FR_ACT_RES4             5
#define FR_ACT_BLACKHOLE        6
#define FR_ACT_UNREACHABLE      7
#define FR_ACT_PROHIBIT         8

/* FIB rule flags */
#define FIB_RULE_PERMANENT      1
#define FIB_RULE_INVERT         2
#define FIB_RULE_UNRESOLVED     4
#define FIB_RULE_IIF_DETACHED   8
#define FIB_RULE_DEV_DETACHED   FIB_RULE_IIF_DETACHED
#define FIB_RULE_OIF_DETACHED   16

/* FIB rule table */
#define RT_TABLE_UNSPEC         0
#define RT_TABLE_COMPAT         252
#define RT_TABLE_DEFAULT        253
#define RT_TABLE_MAIN           254
#define RT_TABLE_LOCAL          255
#define RT_TABLE_MAX            0xFFFFFFFF

struct fib_rule_hdr {
    unsigned char family;
    unsigned char dst_len;
    unsigned char src_len;
    unsigned char tos;
    unsigned char table;
    unsigned char res1;
    unsigned char res2;
    unsigned char action;
    unsigned int  flags;
};
