/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <linux/netlink.h>

#define NFNETLINK_V0        0
#define NFNL_SUBSYS_ID(x)   (((x) & 0xff00) >> 8)
#define NFNL_MSG_TYPE(x)    ((x) & 0x00ff)

#define NFNL_SUBSYS_NONE            0
#define NFNL_SUBSYS_CTNETLINK       1
#define NFNL_SUBSYS_CTNETLINK_EXP   2
#define NFNL_SUBSYS_QUEUE           3
#define NFNL_SUBSYS_ULOG            4
#define NFNL_SUBSYS_OSF             5
#define NFNL_SUBSYS_IPSET           6
#define NFNL_SUBSYS_ACCT            7
#define NFNL_SUBSYS_CTNETLINK_TIMEOUT 8
#define NFNL_SUBSYS_CTHELPER        9
#define NFNL_SUBSYS_NFTABLES        10
#define NFNL_SUBSYS_NFT_COMPAT      11
#define NFNL_SUBSYS_HOOK            12
#define NFNL_SUBSYS_COUNT           13

#define NFNL_MSG_BATCH_BEGIN    NLMSG_MIN_TYPE
#define NFNL_MSG_BATCH_END      (NLMSG_MIN_TYPE + 1)

#define NFNL_BATCH_UNSPEC 0
#define NFNL_BATCH_GENID 1
#define NFNL_BATCH_MAX NFNL_BATCH_GENID

struct nfgenmsg {
    uint8_t  nfgen_family;
    uint8_t  version;
    uint16_t res_id;
};
