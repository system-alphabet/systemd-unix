/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <stdint.h>
#include <linux/types.h>
#include <linux/if_tunnel.h>
#include <linux/if_macvlan.h>
#include <linux/if_ether.h>

/* IFLA_INFO_* — top-level link info attributes */
enum {
        IFLA_INFO_UNSPEC,
        IFLA_INFO_KIND,
        IFLA_INFO_DATA,
        IFLA_INFO_XSTATS,
        IFLA_INFO_SLAVE_KIND,
        IFLA_INFO_SLAVE_DATA,
        __IFLA_INFO_MAX,
};
#define IFLA_INFO_MAX (__IFLA_INFO_MAX - 1)

/* IFLA_VLAN_* */
enum {
        IFLA_VLAN_UNSPEC,
        IFLA_VLAN_ID,
        IFLA_VLAN_FLAGS,
        IFLA_VLAN_EGRESS_QOS,
        IFLA_VLAN_INGRESS_QOS,
        IFLA_VLAN_PROTOCOL,
        __IFLA_VLAN_MAX,
};
#define IFLA_VLAN_MAX (__IFLA_VLAN_MAX - 1)

struct ifla_vlan_flags {
        uint32_t flags;
        uint32_t mask;
};

/* IFLA_BOND_* */
enum {
        IFLA_BOND_UNSPEC,
        IFLA_BOND_MODE,
        IFLA_BOND_ACTIVE_SLAVE,
        IFLA_BOND_MIIMON,
        IFLA_BOND_UPDELAY,
        IFLA_BOND_DOWNDELAY,
        __IFLA_BOND_MAX,
};
#define IFLA_BOND_MAX (__IFLA_BOND_MAX - 1)

#define BOND_MODE_ROUNDROBIN      0
#define BOND_MODE_ACTIVEBACKUP    1

/* IFLA_VRF_* */
enum {
        IFLA_VRF_UNSPEC,
        IFLA_VRF_TABLE,
        __IFLA_VRF_MAX,
};
#define IFLA_VRF_MAX (__IFLA_VRF_MAX - 1)

/* IFLA_GENEVE_* */
enum {
        IFLA_GENEVE_UNSPEC,
        IFLA_GENEVE_ID,
        IFLA_GENEVE_REMOTE,
        __IFLA_GENEVE_MAX,
};
#define IFLA_GENEVE_MAX (__IFLA_GENEVE_MAX - 1)

/* IFLA_GRE_* */
enum {
        IFLA_GRE_UNSPEC,
        IFLA_GRE_LINK,
        IFLA_GRE_IFLAGS,
        IFLA_GRE_OFLAGS,
        IFLA_GRE_IKEY,
        IFLA_GRE_OKEY,
        IFLA_GRE_LOCAL,
        IFLA_GRE_REMOTE,
        IFLA_GRE_TTL,
        IFLA_GRE_TOS,
        IFLA_GRE_PMTUDISC,
        __IFLA_GRE_MAX,
};
#define IFLA_GRE_MAX (__IFLA_GRE_MAX - 1)

/* IFLA_VTI_* */
enum {
        IFLA_VTI_UNSPEC,
        IFLA_VTI_LINK,
        IFLA_VTI_IKEY,
        IFLA_VTI_OKEY,
        IFLA_VTI_LOCAL,
        IFLA_VTI_REMOTE,
        __IFLA_VTI_MAX,
};
#define IFLA_VTI_MAX (__IFLA_VTI_MAX - 1)

/* IFLA_IPIP_* */
enum {
        IFLA_IPIP_UNSPEC,
        IFLA_IPIP_LINK,
        IFLA_IPIP_LOCAL,
        IFLA_IPIP_REMOTE,
        IFLA_IPIP_TTL,
        IFLA_IPIP_TOS,
        IFLA_IPIP_PMTUDISC,
        __IFLA_IPIP_MAX,
};
#define IFLA_IPIP_MAX (__IFLA_IPIP_MAX - 1)

/* IFLA_IPOIB_* */
enum {
        IFLA_IPOIB_UNSPEC,
        IFLA_IPOIB_PKEY,
        IFLA_IPOIB_MODE,
        IFLA_IPOIB_UMCAST,
        __IFLA_IPOIB_MAX,
};
#define IFLA_IPOIB_MAX (__IFLA_IPOIB_MAX - 1)

/* IFLA_WIREGUARD_* */
enum {
        IFLA_WIREGUARD_UNSPEC,
        IFLA_WIREGUARD_DEVICE_ID,
        IFLA_WIREGUARD_PRIVATE_KEY,
        IFLA_WIREGUARD_PUBLIC_KEY,
        IFLA_WIREGUARD_LISTEN_PORT,
        IFLA_WIREGUARD_FWMARK,
        IFLA_WIREGUARD_PEERS,
        __IFLA_WIREGUARD_MAX,
};
#define IFLA_WIREGUARD_MAX (__IFLA_WIREGUARD_MAX - 1)

/* BareUDP */
#define IFLA_BAREUDP_UNSPEC 0
#define IFLA_BAREUDP_PORT 1
#define IFLA_BAREUDP_VXLAN 2
#define __IFLA_BAREUDP_MAX 3
#define IFLA_BAREUDP_MAX (__IFLA_BAREUDP_MAX - 1)

/* BatADV */
#define IFLA_BATADV_UNSPEC 0
#define IFLA_BATADV_ALGO_NAME 1
#define __IFLA_BATADV_MAX 2
#define IFLA_BATADV_MAX (__IFLA_BATADV_MAX - 1)

/* Bond (extended) */
#define IFLA_BOND_MODE 1
#define IFLA_BOND_ACTIVE_SLAVE 2
#define IFLA_BOND_MIIMON 3
#define IFLA_BOND_UPDELAY 4
#define IFLA_BOND_DOWNDELAY 5
#define IFLA_BOND_USE_CARRIER 6
#define IFLA_BOND_ARP_INTERVAL 7
#define IFLA_BOND_ARP_IP_TARGET 8
#define IFLA_BOND_ARP_VALIDATE 9
#define IFLA_BOND_ARP_ALL_TARGETS 10
#define IFLA_BOND_PRIMARY 11
#define IFLA_BOND_PRIMARY_RESELECT 12
#define IFLA_BOND_FAIL_OVER_MAC 13
#define IFLA_BOND_XMIT_HASH_POLICY 14
#define IFLA_BOND_RESEND_IGMP 15
#define IFLA_BOND_NUM_PEER_NOTIF 16
#define IFLA_BOND_ALL_SLAVES_ACTIVE 17
#define IFLA_BOND_MIN_LINKS 18
#define IFLA_BOND_LP_INTERVAL 19
#define IFLA_BOND_PACKETS_PER_SLAVE 20
#define IFLA_BOND_AD_LACP_ACTIVE 21
#define IFLA_BOND_AD_LACP_TIMEOUT 22
#define IFLA_BOND_AD_AGGREGATOR 23
#define IFLA_BOND_AD_ACTOR_SYS_PRIO 24
#define IFLA_BOND_AD_USER_PORT_KEY 25
#define IFLA_BOND_AD_ACTOR_SYSTEM 26
#define IFLA_BOND_AD_SELECT 27
#define IFLA_BOND_AD_INFO 28
#define IFLA_BOND_AD_INFO_AGGREGATOR 1
#define IFLA_BOND_AD_INFO_NUM_PORTS 2
#define IFLA_BOND_AD_INFO_ACTOR_KEY 3
#define IFLA_BOND_AD_INFO_PARTNER_KEY 4
#define IFLA_BOND_AD_INFO_PARTNER_MAC 5
#define BOND_MODE_XOR 2
#define BOND_MODE_BROADCAST 3
#define BOND_MODE_8023AD 4
#define BOND_MODE_TLB 5
#define BOND_MODE_ALB 6

/* Geneve (extended) */
#define IFLA_GENEVE_TTL 3
#define IFLA_GENEVE_TOS 4
#define IFLA_GENEVE_PORT 5
#define IFLA_GENEVE_COLLECT_METADATA 6

/* GRE (extended) */
#define IFLA_GRE_ENCAP_LIMIT 11
#define IFLA_GRE_ENCAP_TYPE 12
#define IFLA_GRE_ENCAP_FLAGS 13
#define IFLA_GRE_ENCAP_SPORT 14
#define IFLA_GRE_ENCAP_DPORT 15
#define IFLA_GRE_COLLECT_METADATA 16
#define IFLA_GRE_IGNORE_DF 17
#define IFLA_GRE_FWMARK 18
#define IFLA_GRE_ERSPAN_INDEX 19
#define IFLA_GRE_ERSPAN_VER 20
#define IFLA_GRE_ERSPAN_DIR 21
#define IFLA_GRE_ERSPAN_HWID 22

/* HSR */
#define IFLA_HSR_UNSPEC 0
#define IFLA_HSR_SLAVE1 1
#define IFLA_HSR_SLAVE2 2
#define IFLA_HSR_MULTICAST_SPEC 3
#define IFLA_HSR_SUPERVISION_ADDR 4
#define IFLA_HSR_SEQ_NR 5
#define IFLA_HSR_VERSION 6
#define __IFLA_HSR_MAX 7
#define IFLA_HSR_MAX (__IFLA_HSR_MAX - 1)

/* IPTUN (IPIP alias) */
#define IFLA_IPTUN_UNSPEC 0
#define IFLA_IPTUN_LINK 1
#define IFLA_IPTUN_LOCAL 2
#define IFLA_IPTUN_REMOTE 3
#define IFLA_IPTUN_TTL 4
#define IFLA_IPTUN_TOS 5
#define IFLA_IPTUN_ENCAP_LIMIT 6
#define IFLA_IPTUN_FLOWINFO 7
#define IFLA_IPTUN_FLAGS 8
#define IFLA_IPTUN_PROTO 9
#define IFLA_IPTUN_PMTUDISC 10
#define IFLA_IPTUN_6RD_PREFIX 11
#define IFLA_IPTUN_6RD_RELAY_PREFIX 12
#define IFLA_IPTUN_6RD_PREFIXLEN 13
#define IFLA_IPTUN_6RD_RELAY_PREFIXLEN 14
#define __IFLA_IPTUN_MAX 15
#define IFLA_IPTUN_MAX (__IFLA_IPTUN_MAX - 1)

/* IPoIB (extended) */
#define IFLA_IPOIB_PKEY 1
#define IFLA_IPOIB_MODE 2
#define IFLA_IPOIB_UMCAST 3

/* VTI */
#define IFLA_VTI_UNSPEC 0
#define IFLA_VTI_LINK 1
#define IFLA_VTI_IKEY 2
#define IFLA_VTI_OKEY 3
#define IFLA_VTI_LOCAL 4
#define IFLA_VTI_REMOTE 5
#define __IFLA_VTI_MAX 6
#define IFLA_VTI_MAX (__IFLA_VTI_MAX - 1)

/* VRF */
#define IFLA_VRF_UNSPEC 0
#define IFLA_VRF_TABLE 1
#define __IFLA_VRF_MAX 2
#define IFLA_VRF_MAX (__IFLA_VRF_MAX - 1)

/* VLAN */
#define IFLA_VLAN_UNSPEC 0
#define IFLA_VLAN_ID 1
#define IFLA_VLAN_FLAGS 2
#define IFLA_VLAN_EGRESS_QOS 3
#define IFLA_VLAN_INGRESS_QOS 4
#define IFLA_VLAN_PROTOCOL 5
#define __IFLA_VLAN_MAX 6
#define IFLA_VLAN_MAX (__IFLA_VLAN_MAX - 1)

/* WireGuard */
#define IFLA_WG_UNSPEC 0
#define IFLA_WG_DEVICE_ID 1
#define IFLA_WG_PRIVATE_KEY 2
#define IFLA_WG_PUBLIC_KEY 3
#define IFLA_WG_LISTEN_PORT 4
#define IFLA_WG_FWMARK 5
#define IFLA_WG_PEERS 6
#define __IFLA_WG_MAX 7
#define IFLA_WG_MAX (__IFLA_WG_MAX - 1)

/* IP tunnel info */
#define IP_TUNNEL_INFO_TX 1
#define IP_TUNNEL_INFO_RX 2

/* BareUDP extended */
#define IFLA_BAREUDP_ETHERTYPE 3

/* IPVLAN */
#define IFLA_IPVLAN_UNSPEC 0
#define IFLA_IPVLAN_MODE 1
#define IFLA_IPVLAN_FLAGS 2
#define __IFLA_IPVLAN_MAX 3
#define IFLA_IPVLAN_MAX (__IFLA_IPVLAN_MAX - 1)

/* IPVLAN mode values */
#define IPVLAN_MODE_L2   0
#define IPVLAN_MODE_L3   1
#define IPVLAN_MODE_L3S  2

/* IPVLAN flags */
#define IPVLAN_F_PRIVATE 0x01
#define IPVLAN_F_VEPA    0x02

/* MACVLAN */
#define IFLA_MACVLAN_UNSPEC 0
#define IFLA_MACVLAN_MODE 1
#define IFLA_MACVLAN_FLAGS 2
#define IFLA_MACVLAN_MACADDR_MODE 3
#define IFLA_MACVLAN_MACADDR 4
#define IFLA_MACVLAN_MACADDR_DATA 5
#define IFLA_MACVLAN_MACADDR_COUNT 6
#define __IFLA_MACVLAN_MAX 7
#define IFLA_MACVLAN_MAX (__IFLA_MACVLAN_MAX - 1)

/* Bond AD LACP rate */
#define IFLA_BOND_AD_LACP_RATE 29

/* Geneve extended */
#define IFLA_GENEVE_REMOTE6 7
#define IFLA_GENEVE_UDP_CSUM 8
#define IFLA_GENEVE_UDP_ZERO_CSUM6_TX 9

/* GRE extended */
#define IFLA_GRE_FLOWINFO 23
#define IFLA_GRE_FLAGS 24
#define IFLA_GRE_ENCAP_TYPE 12

/* HSR extended */
#define IFLA_HSR_PROTOCOL 7

/* IPTUN extended */
#define IFLA_IPTUN_ENCAP_TYPE 15

/* MACSEC link attributes */
#define IFLA_MACSEC_UNSPEC 0
#define IFLA_MACSEC_SCI 1
#define IFLA_MACSEC_PORT 2
#define IFLA_MACSEC_ICV_LEN 3
#define IFLA_MACSEC_CIPHER_SUITE 4
#define IFLA_MACSEC_WINDOW 5
#define IFLA_MACSEC_ENCODING_SA 6
#define IFLA_MACSEC_ENCRYPT 7
#define IFLA_MACSEC_PROTECT 8
#define IFLA_MACSEC_INC_SCI 9
#define IFLA_MACSEC_ES 10
#define IFLA_MACSEC_SCB 11
#define IFLA_MACSEC_REPLAY_PROTECT 12
#define IFLA_MACSEC_VALIDATION 13
#define IFLA_MACSEC_PAD 14
#define __IFLA_MACSEC_MAX 15
#define IFLA_MACSEC_MAX (__IFLA_MACSEC_MAX - 1)

/* IFLA_VF_* — SR-IOV Virtual Function attributes */
enum {
        IFLA_VF_UNSPEC,
        IFLA_VF_MAC,
        IFLA_VF_VLAN,
        IFLA_VF_TX_RATE,
        IFLA_VF_SPOOFCHK,
        IFLA_VF_RATE,
        IFLA_VF_LINK_STATE,
        IFLA_VF_RSS_QUERY_EN,
        IFLA_VF_STATS,
        IFLA_VF_TRUST,
        IFLA_VF_IB_NODE_GUID,
        IFLA_VF_IB_PORT_GUID,
        IFLA_VF_VLAN_LIST,
        IFLA_VF_BROADCAST,
        __IFLA_VF_MAX,
};
#define IFLA_VF_MAX (__IFLA_VF_MAX - 1)

struct ifla_vf_mac {
        __u32 vf;
        __u8  mac[32];
};

struct ifla_vf_vlan {
        __u32 vf;
        __u32 vlan;
        __u32 qos;
};

struct ifla_vf_tx_rate {
        __u32 vf;
        __u32 rate;
};

struct ifla_vf_spoofchk {
        __u32 vf;
        __u32 setting;
};

struct ifla_vf_rate {
        __u32 vf;
        __u32 min_tx_rate;
        __u32 max_tx_rate;
};

struct ifla_vf_link_state {
        __u32 vf;
        __u32 link_state;
};

struct ifla_vf_rss_query_en {
        __u32 vf;
        __u32 setting;
};

struct ifla_vf_trust {
        __u32 vf;
        __u32 setting;
};

struct ifla_vf_vlan_info {
        __u32 vf;
        __u32 vlan;
        __u32 qos;
        __u16 vlan_proto;
};

/* IFLA_VF_VLAN_INFO */
#define IFLA_VF_VLAN_INFO 1

/* IFLA_VF_LINK_STATE_* */
#define IFLA_VF_LINK_STATE_AUTO   0
#define IFLA_VF_LINK_STATE_ENABLE 1
#define IFLA_VF_LINK_STATE_DISABLE 2

/* IFLA_VF_INFO nested attribute */
#define IFLA_VF_INFO 1
#define IFLA_VF_INFO_MAX 1

/* IFLA_INFO_* nested for IFLA_VF_PORT */
#define IFLA_VF_PORT_MAX 1
