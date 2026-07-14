/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <linux/netlink.h>
#include <stdint.h>

/* Netlink routing attribute (struct rtattr). */
struct rtattr {
        unsigned short rta_len;
        unsigned short rta_type;
};

/* RTA alignment and access macros. */
#define RTA_ALIGNTO     4
#define RTA_ALIGN(len)  (((len) + RTA_ALIGNTO - 1) & ~(RTA_ALIGNTO - 1))
#define RTA_LENGTH(len) (RTA_ALIGN(sizeof(struct rtattr)) + (len))
#define RTA_SPACE(len)  RTA_ALIGN(RTA_LENGTH(len))
#define RTA_DATA(rta)   ((void *)(((char *)(rta)) + RTA_LENGTH(0)))
#define RTA_PAYLOAD(rta) ((int)((rta)->rta_len) - RTA_LENGTH(0))
#define RTA_OK(rta, len) ((len) >= (int)sizeof(struct rtattr) && \
                          (rta)->rta_len >= sizeof(struct rtattr) && \
                          (rta)->rta_len <= (len))
#define RTA_NEXT(rta, attrlen) ((attrlen) -= RTA_ALIGN((rta)->rta_len), \
                                (struct rtattr *)(((char *)(rta)) + RTA_ALIGN((rta)->rta_len)))

/* Routing next hop (struct rtnexthop). */
struct rtnexthop {
        unsigned short rtnh_len;
        unsigned char  rtnh_flags;
        unsigned char  rtnh_hops;
        int            rtnh_ifindex;
};

#define RTNH_ALIGNTO     4
#define RTNH_ALIGN(len)  (((len) + RTNH_ALIGNTO - 1) & ~(RTNH_ALIGNTO - 1))
#define RTNH_LENGTH(len) (RTNH_ALIGN(sizeof(struct rtnexthop)) + (len))
#define RTNH_SPACE(len)  RTNH_ALIGN(RTNH_LENGTH(len))
#define RTNH_DATA(rtnh)  ((struct rtattr *)(((char *)(rtnh)) + RTNH_ALIGN(sizeof(struct rtnexthop))))
#define RTNH_NEXT(rtnh)  ((struct rtnexthop *)(((char *)(rtnh)) + RTNH_ALIGN((rtnh)->rtnh_len)))

/* Routing tables */
#define RT_TABLE_UNSPEC   0
#define RT_TABLE_MAIN     254
#define RT_TABLE_LOCAL    255

/* NLA flags (from <linux/nlattr.h>). */
#define NLA_F_NESTED        0x8000
#define NLA_F_NET_BYTEORDER 0x4000
#define NLA_TYPE_MASK       (~(NLA_F_NESTED | NLA_F_NET_BYTEORDER))

/* struct ifa_cacheinfo (address cache info). */
struct ifa_cacheinfo {
        uint32_t ifa_prefered;
        uint32_t ifa_valid;
        uint32_t cstamp;
        uint32_t tstamp;
};

/* struct rtgenmsg (generic routing netlink message). */
struct rtgenmsg {
        unsigned char rtgen_family;
};

/* struct tcmsg (traffic control message). */
struct tcmsg {
        unsigned char tcm_family;
        unsigned char tcm__pad1;
        unsigned short tcm__pad2;
        int            tcm_ifindex;
        unsigned int   tcm_handle;
        unsigned int   tcm_parent;
        unsigned int   tcm_info;
};

/* Routing protocol identifiers. */
#define RTPROT_UNSPEC           0
#define RTPROT_REDIRECT         1
#define RTPROT_KERNEL           2
#define RTPROT_BOOT             3
#define RTPROT_STATIC           4
#define RTPROT_DHCP             16
#define RTPROT_RA               9
#define RTPROT_OPENR            99
#define RTPROT_BABEL            42
#define RTPROT_BGP              186
#define RTPROT_ISIS             187
#define RTPROT_OSPF             188
#define RTPROT_RIP              189
#define RTPROT_EIGRP            192
#define RTPROT_BIRD             200
#define RTPROT_MRT              200
#define RTPROT_ZEBRA            200
#define RTPROT_KEEPALIVED       201
#define RTPROT_NHRP             202

/* Route scopes. */
#define RT_SCOPE_UNIVERSE       0
#define RT_SCOPE_SITE           200
#define RT_SCOPE_LINK           253
#define RT_SCOPE_HOST           254
#define RT_SCOPE_NOWHERE        255

/* RTM_* message types — only those referenced in the codebase. */
#define RTM_NEWLINK      16
#define RTM_DELLINK      17
#define RTM_GETLINK      18
#define RTM_SETLINK      19
#define RTM_NEWADDR      20
#define RTM_DELADDR      21
#define RTM_GETADDR      22
#define RTM_NEWROUTE     24
#define RTM_DELROUTE     25
#define RTM_GETROUTE     26
#define RTM_NEWNEIGH     28
#define RTM_DELNEIGH     29
#define RTM_GETNEIGH     30
#define RTM_NEWRULE      32
#define RTM_DELRULE      33
#define RTM_GETRULE      34
#define RTM_NEWQDISC     36
#define RTM_DELQDISC     37
#define RTM_GETQDISC     38
#define RTM_NEWTCLASS    40
#define RTM_DELTCLASS    41
#define RTM_GETTCLASS    42
#define RTM_NEWADDRLABEL 72
#define RTM_DELADDRLABEL 73
#define RTM_GETADDRLABEL 74
#define RTM_NEWNEXTHOP   104
#define RTM_DELNEXTHOP   105
#define RTM_GETNEXTHOP   106
#define RTM_NEWLINKPROP  108
#define RTM_DELLINKPROP  109
#define RTM_GETLINKPROP  110
#define RTM_NEWMDB       112
#define RTM_DELMDB       113
#define RTM_GETMDB       114
#define RTM_NEWNSID      116
#define RTM_DELNSID      117
#define RTM_GETNSID      118

/* RTN_* route types */
#define RTN_UNSPEC       0
#define RTN_UNICAST      1
#define RTN_LOCAL        2
#define RTN_BROADCAST    3
#define RTN_ANYCAST      4
#define RTN_MULTICAST    5
#define RTN_BLACKHOLE    6
#define RTN_UNREACHABLE  7
#define RTN_PROHIBIT     8
#define RTN_THROW        9
#define RTN_NAT          10
#define RTN_XRESOLVE     11

/* RTM_F_* flags */
#define RTM_F_NOTIFY     0x100
#define RTM_F_FIB_MATCH  0x200

/* IFLA_* link attributes */
#define IFLA_UNSPEC       0
#define IFLA_ADDRESS      1
#define IFLA_BROADCAST    2
#define IFLA_IFNAME       3
#define IFLA_MTU          4
#define IFLA_LINK         5
#define IFLA_QDISC        6
#define IFLA_STATS        7
#define IFLA_COST         8
#define IFLA_PRIORITY     9
#define IFLA_MASTER       10
#define IFLA_WIRELESS     11
#define IFLA_PROTINFO     12
#define IFLA_TXQLEN       13
#define IFLA_MAP          14
#define IFLA_WEIGHT       15
#define IFLA_OPERSTATE    16
#define IFLA_LINKMODE     17
#define IFLA_LINKINFO     18
#define IFLA_NET_NS_PID   19
#define IFLA_IFALIAS      20
#define IFLA_NUM_VF       21
#define IFLA_VFINFO_LIST  22
#define IFLA_STATS64      23
#define IFLA_VF_PORTS     24
#define IFLA_PORT_SELF    25
#define IFLA_AF_SPEC      26
#define IFLA_GROUP        27
#define IFLA_NET_NS_FD    28
#define IFLA_EXT_MASK     29
#define IFLA_PROMISCUITY  30
#define IFLA_NUM_TX_QUEUES 31
#define IFLA_NUM_RX_QUEUES 32
#define IFLA_CARRIER      33
#define IFLA_PHYS_PORT_ID 34
#define IFLA_CARRIER_CHANGES 35
#define IFLA_PHYS_SWITCH_ID 36
#define IFLA_LINK_NETNSID 37
#define IFLA_PHYS_PORT_NAME 38
#define IFLA_PROTO_DOWN   39
#define IFLA_GSO_MAX_SEGS 40
#define IFLA_GSO_MAX_SIZE 41
#define IFLA_PAD          42
#define IFLA_XDP          43
#define IFLA_EVENT        44
#define IFLA_NEW_NETNSID  45
#define IFLA_IF_NETNSID   46
#define IFLA_TARGET_NETNSID 47
#define IFLA_CARRIER_UP_COUNT 48
#define IFLA_CARRIER_DOWN_COUNT 49
#define IFLA_NEW_IFINDEX  50
#define IFLA_MIN_MTU      51
#define IFLA_MAX_MTU      52
#define IFLA_PROP_LIST    53
#define IFLA_ALT_IFNAME   54
#define IFLA_PERM_ADDRESS 55
#define IFLA_PROTO_DOWN_REASON 56
#define IFLA_PARENT_DEV_NAME 57
#define IFLA_PARENT_DEV_BUS_NAME 58
#define IFLA_GRO_MAX_SIZE 59
#define IFLA_TSO_MAX_SIZE 60
#define IFLA_TSO_MAX_SEGS 61
#define IFLA_ALLMULTI     62

/* IFA_* address attributes */
#define IFA_UNSPEC        0
#define IFA_ADDRESS       1
#define IFA_LOCAL         2
#define IFA_LABEL         3
#define IFA_BROADCAST     4
#define IFA_ANYCAST       5
#define IFA_CACHEINFO     6
#define IFA_MULTICAST     7
#define IFA_FLAGS         8

/* RTA_* route attributes */
#define RTA_UNSPEC        0
#define RTA_DST           1
#define RTA_SRC           2
#define RTA_IIF           3
#define RTA_OIF           4
#define RTA_GATEWAY       5
#define RTA_PRIORITY      6
#define RTA_PREFSRC       7
#define RTA_METRICS       8
#define RTA_MULTIPATH     9
#define RTA_PROTOINFO     10
#define RTA_FLOW          11
#define RTA_CACHEINFO     12
#define RTA_SESSION       13
#define RTA_MP_ALGO       14
#define RTA_TABLE         15
#define RTA_MARK          16
#define RTA_MFC_STATS     17
#define RTA_VIA           18
#define RTA_NEWDST        19
#define RTA_PREF          20
#define RTA_ENCAP_TYPE    21
#define RTA_ENCAP         22
#define RTA_EXPIRES       23
#define RTA_PAD           24
#define RTA_UID           25
#define RTA_TTL_PROPAGATE 26
#define RTA_IP_PROTO      27
#define RTA_SPORT         28
#define RTA_DPORT         29
#define RTA_NH_ID         30

/* NDA_* neighbour attributes */
#define NDA_UNSPEC        0
#define NDA_DST           1
#define NDA_LLADDR        2
#define NDA_STATE         3
#define NDA_CACHEINFO     4
#define NDA_IFINDEX       5
#define NDA_MASTER        6
#define NDA_LINK_NETNSID  7
#define NDA_VNI           8
#define NDA_PROTOCOL      9
#define NDA_NH_ID         10
#define NDA_FDB_EXT_ATTRS 11
#define NDA_FLAGS_EXT     12

/* NTF_* neighbour flags */
#define NTF_USE           0x01
#define NTF_SELF          0x02
#define NTF_MASTER        0x04
#define NTF_PROXY         0x08
#define NTF_EXT_LEARNED   0x10
#define NTF_OFFLOADED     0x20
#define NTF_STICKY        0x40
#define NTF_ROUTER        0x80

#define NUD_INCOMPLETE    0x01
#define NUD_REACHABLE     0x02
#define NUD_STALE         0x04
#define NUD_DELAY         0x08
#define NUD_PROBE         0x10
#define NUD_FAILED        0x20
#define NUD_NOARP         0x40
#define NUD_PERMANENT     0x80

/* IFA_FLAGS values */
#ifndef IFA_F_SECONDARY
#define IFA_F_SECONDARY   0x01
#define IFA_F_TEMPORARY   IFA_F_SECONDARY
#define IFA_F_NODAD       0x02
#define IFA_F_OPTIMISTIC  0x04
#define IFA_F_DADFAILED   0x08
#define IFA_F_HOMEADDRESS 0x10
#define IFA_F_DEPRECATED  0x20
#define IFA_F_TENTATIVE   0x40
#define IFA_F_PERMANENT   0x80
#define IFA_F_MANAGETEMPADDR 0x100
#define IFA_F_NOPREFIXROUTE 0x200
#define IFA_F_MCAUTOJOIN  0x400
#define IFA_F_STABLE_PRIVACY 0x800
#endif

/* struct definitions */
struct ifinfomsg {
    unsigned char  ifi_family;
    unsigned short ifi_type;
    int            ifi_index;
    unsigned       ifi_flags;
    unsigned       ifi_change;
};

struct ifaddrmsg {
    unsigned char  ifa_family;
    unsigned char  ifa_prefixlen;
    unsigned char  ifa_flags;
    unsigned char  ifa_scope;
    int            ifa_index;
};

struct rtmsg {
    unsigned char  rtm_family;
    unsigned char  rtm_dst_len;
    unsigned char  rtm_src_len;
    unsigned char  rtm_tos;
    unsigned char  rtm_table;
    unsigned char  rtm_protocol;
    unsigned char  rtm_scope;
    unsigned char  rtm_type;
    unsigned       rtm_flags;
};

struct ndmsg {
    unsigned char  ndm_family;
    unsigned char  ndm_pad1;
    unsigned short ndm_pad2;
    int            ndm_ifindex;
    unsigned short ndm_state;
    unsigned char  ndm_flags;
    unsigned char  ndm_type;
};

#define RTM_BASE    16
#define RTM_NR_MSGTYPES  (RTM_NEWNSID + 3 - RTM_BASE)
