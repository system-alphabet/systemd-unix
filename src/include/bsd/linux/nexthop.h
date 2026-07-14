/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <stdint.h>

/* Next hop attributes (netlink). */
#define NHA_UNSPEC              0
#define NHA_ID                  1
#define NHA_GROUP               2
#define NHA_GROUP_TYPE          3
#define NHA_BLACKHOLE           4
#define NHA_OID                 5
#define NHA_RES_GROUP           6
#define NHA_RES_BUCKET          7
#define NHA_ENCAP_TYPE          8
#define NHA_ENCAP               9
#define NHA_FDB                 10
#define NHA_MASTER              11
#define NHA_IIF                 12
#define NHA_OIF                 13
#define NHA_GATEWAY             14
#define NHA_VIA                 15

/* Next hop group attributes. */
#define NHA_GROUP_ENTRY_UNSPEC  0
#define NHA_GROUP_ENTRY_ID      1
#define NHA_GROUP_ENTRY_WEIGHT  2
#define NHA_GROUP_ENTRY_ADDR    3
#define NHA_GROUP_ENTRY_PAD     4
#define NHA_GROUP_ENTRY_FDB     5
#define NHA_GROUP_ENTRY_EXT_NH_ID 6

/* Next hop group types. */
#define NEXTHOP_GRP_TYPE_MPATH  0
#define NEXTHOP_GRP_TYPE_RES    1

/* Next hop res bucket attributes. */
#define NHA_RES_BUCKET_UNSPEC   0
#define NHA_RES_BUCKET_NH_ID    1
#define NHA_RES_BUCKET_INDEX    2
#define NHA_RES_BUCKET_IDLE     3

struct nhmsg {
    unsigned char nh_family;
    unsigned char nh_scope;
    unsigned char nh_protocol;
    unsigned char nh_flags;
    unsigned int  nh_ifindex;
};
