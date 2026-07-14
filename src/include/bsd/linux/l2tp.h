/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <stdint.h>

#define L2TP_GENL_NAME          "l2tp"

enum {
        L2TP_ATTR_NONE,
        L2TP_ATTR_PW_TYPE,
        L2TP_ATTR_ENCAP_TYPE,
        L2TP_ATTR_OFFSET,
        L2TP_ATTR_DATA_SEQ,
        L2TP_ATTR_L2SPEC_TYPE,
        L2TP_ATTR_L2SPEC_LEN,
        L2TP_ATTR_PROTO_VERSION,
        L2TP_ATTR_IFNAME,
        L2TP_ATTR_CONN_ID,
        L2TP_ATTR_PEER_CONN_ID,
        L2TP_ATTR_SESSION_ID,
        L2TP_ATTR_PEER_SESSION_ID,
        L2TP_ATTR_UDP_CSUM,
        L2TP_ATTR_VLAN_ID,
        L2TP_ATTR_RECV_SEQ,
        L2TP_ATTR_SEND_SEQ,
        L2TP_ATTR_LNS_MODE,
        L2TP_ATTR_USING_IPSEC,
        L2TP_ATTR_FD,
        L2TP_ATTR_IP_SADDR,
        L2TP_ATTR_IP_DADDR,
        L2TP_ATTR_UDP_SPORT,
        L2TP_ATTR_UDP_DPORT,
        L2TP_ATTR_IP6_SADDR,
        L2TP_ATTR_IP6_DADDR,
        L2TP_ATTR_UDP_ZERO_CSUM6_TX,
        L2TP_ATTR_UDP_ZERO_CSUM6_RX,
        __L2TP_ATTR_MAX,
};
#define L2TP_ATTR_MAX (__L2TP_ATTR_MAX - 1)
