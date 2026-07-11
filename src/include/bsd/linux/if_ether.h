/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Linux <linux/if_ether.h> — Ethernet protocol constants.
 * FreeBSD provides ETHERTYPE_* in <net/ethernet.h>.
 */

#include <stdint.h>
#include <net/ethernet.h>

/* ETH_P_* protocol numbers (Linux names) */
#ifndef ETH_P_IP
#define ETH_P_IP        0x0800
#endif
#ifndef ETH_P_IPV6
#define ETH_P_IPV6      0x86DD
#endif
#ifndef ETH_P_ARP
#define ETH_P_ARP       0x0806
#endif
#ifndef ETH_P_ALL
#define ETH_P_ALL       0x0003
#endif
#ifndef ETH_P_8021Q
#define ETH_P_8021Q     0x8100
#endif
#ifndef ETH_P_8021AD
#define ETH_P_8021AD    0x88A8
#endif
#ifndef ETH_P_LLDP
#define ETH_P_LLDP      0x88CC
#endif
#ifndef ETH_P_MRP
#define ETH_P_MRP       0x88E3
#endif
#ifndef ETH_P_LOOP
#define ETH_P_LOOP      0x0060
#endif
#ifndef ETH_P_TEB
#define ETH_P_TEB       0x6558
#endif
#ifndef ETH_P_PPP_DISC
#define ETH_P_PPP_DISC  0x8863
#endif
#ifndef ETH_P_PPP_SES
#define ETH_P_PPP_SES   0x8864
#endif
#ifndef ETH_P_MPLS_UC
#define ETH_P_MPLS_UC   0x8847
#endif
#ifndef ETH_P_MPLS_MC
#define ETH_P_MPLS_MC   0x8848
#endif
#ifndef ETH_P_ATMMPOA
#define ETH_P_ATMMPOA   0x884C
#endif
#ifndef ETH_P_ATMFATE
#define ETH_P_ATMFATE   0x8884
#endif
#ifndef ETH_P_PAE
#define ETH_P_PAE       0x888E
#endif
#ifndef ETH_P_SLOW
#define ETH_P_SLOW      0x8809
#endif
#ifndef ETH_P_TIPC
#define ETH_P_TIPC      0x88CA
#endif
#ifndef ETH_P_MACSEC
#define ETH_P_MACSEC    0x88E5
#endif
#ifndef ETH_P_BATMAN
#define ETH_P_BATMAN    0x4305
#endif
#ifndef ETH_P_PRP
#define ETH_P_PRP       0x88FB
#endif
#ifndef ETH_P_HSR
#define ETH_P_HSR       0x892F
#endif
#ifndef ETH_P_NSH
#define ETH_P_NSH       0x894F
#endif
#ifndef ETH_P_1588
#define ETH_P_1588      0x88F7
#endif
#ifndef ETH_P_FCOE
#define ETH_P_FCOE      0x8906
#endif
#ifndef ETH_P_IBOE
#define ETH_P_IBOE      0x8915
#endif
#ifndef ETH_P_TDLS
#define ETH_P_TDLS      0x890D
#endif
#ifndef ETH_P_DN
#define ETH_P_DN        0x0019
#endif
#ifndef ETH_P_AF_IUCV
#define ETH_P_AF_IUCV   0xFBFB
#endif
#ifndef ETH_P_80221
#define ETH_P_80221     0x8917
#endif
#ifndef ETH_P_HSR_0
#define ETH_P_HSR_0     0x892F
#endif
#ifndef ETH_P_HSR_1
#define ETH_P_HSR_1     0x8930
#endif
#ifndef ETH_P_CAN
#define ETH_P_CAN       0x000C
#endif
#ifndef ETH_P_CANFD
#define ETH_P_CANFD     0x000D
#endif
#ifndef ETH_P_MAP
#define ETH_P_MAP       0x00F9
#endif
#ifndef ETH_P_QINQ1
#define ETH_P_QINQ1     0x9100
#endif
#ifndef ETH_P_QINQ2
#define ETH_P_QINQ2     0x9200
#endif
#ifndef ETH_P_QINQ3
#define ETH_P_QINQ3     0x9300
#endif
#ifndef ETH_P_EDSA
#define ETH_P_EDSA      0xDADA
#endif
#ifndef ETH_P_EXT
#define ETH_P_EXT       0x88B5
#endif
#ifndef ETH_P_X25
#define ETH_P_X25       0x0805
#endif
#ifndef ETH_P_WSUM
#define ETH_P_WSUM      0x88E0
#endif
#ifndef ETH_P_DSA_8021Q
#define ETH_P_DSA_8021Q 0x88B9
#endif
#ifndef ETH_P_IFE
#define ETH_P_IFE       0xED3E
#endif

/* Ethernet address length */
#ifndef ETH_ALEN
#define ETH_ALEN        6
#endif

#ifndef ETH_HLEN
#define ETH_HLEN        14
#endif

#ifndef ETH_ZLEN
#define ETH_ZLEN        60
#endif

#ifndef ETH_DATA_LEN
#define ETH_DATA_LEN    1500
#endif

#ifndef ETH_FRAME_LEN
#define ETH_FRAME_LEN   1514
#endif

#ifndef ETH_FCS_LEN
#define ETH_FCS_LEN     4
#endif

#ifndef ETH_MIN_MTU
#define ETH_MIN_MTU     68
#endif

#ifndef ETH_MAX_MTU
#define ETH_MAX_MTU     0x3C00
#endif

/* struct ethhdr */
struct ethhdr {
        unsigned char   h_dest[ETH_ALEN];
        unsigned char   h_source[ETH_ALEN];
        uint16_t        h_proto;
} __attribute__((packed));
