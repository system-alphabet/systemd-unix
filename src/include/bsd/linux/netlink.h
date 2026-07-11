/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Linux <linux/netlink.h> — Netlink socket definitions.
 * Minimal FreeBSD shim for compilation purposes.
 * Used by src/basic/socket-util.h.
 */

#include <stdint.h>
#include <sys/socket.h>

#ifndef NETLINK_ROUTE
#define NETLINK_ROUTE           0
#endif
#ifndef NETLINK_FIREWALL
#define NETLINK_FIREWALL        3
#endif
#ifndef NETLINK_NETFILTER
#define NETLINK_NETFILTER       12
#endif
#ifndef NETLINK_GENERIC
#define NETLINK_GENERIC         16
#endif
#ifndef NETLINK_KOBJECT_UEVENT
#define NETLINK_KOBJECT_UEVENT  15
#endif
#ifndef NETLINK_AUDIT
#define NETLINK_AUDIT           9
#endif
#ifndef NETLINK_SELINUX
#define NETLINK_SELINUX         7
#endif
#ifndef NETLINK_ISCSI
#define NETLINK_ISCSI           8
#endif
#ifndef NETLINK_FIB_LOOKUP
#define NETLINK_FIB_LOOKUP      10
#endif
#ifndef NETLINK_CONNECTOR
#define NETLINK_CONNECTOR       11
#endif
#ifndef NETLINK_SCSITRANSPORT
#define NETLINK_SCSITRANSPORT   18
#endif
#ifndef NETLINK_RDMA
#define NETLINK_RDMA            20
#endif
#ifndef NETLINK_CRYPTO
#define NETLINK_CRYPTO          21
#endif
#ifndef NETLINK_SMC
#define NETLINK_SMC             22
#endif

#define NLMSG_ALIGNTO           4
#define NLMSG_ALIGN(len)        (((len) + NLMSG_ALIGNTO - 1) & ~(NLMSG_ALIGNTO - 1))
#define NLMSG_HDRLEN            ((int)NLMSG_ALIGN(sizeof(struct nlmsghdr)))
#define NLMSG_LENGTH(len)       ((len) + NLMSG_HDRLEN)
#define NLMSG_SPACE(len)        NLMSG_ALIGN(NLMSG_LENGTH(len))
#define NLMSG_DATA(nlh)         ((void *)(((char *)nlh) + NLMSG_LENGTH(0)))
#define NLMSG_NEXT(nlh, len)    ((len) -= NLMSG_ALIGN((nlh)->nlmsg_len), \
                                 (struct nlmsghdr *)(((char *)(nlh)) + NLMSG_ALIGN((nlh)->nlmsg_len)))
#define NLMSG_OK(nlh, len)      ((len) >= (int)sizeof(struct nlmsghdr) && \
                                 (nlh)->nlmsg_len >= sizeof(struct nlmsghdr) && \
                                 (nlh)->nlmsg_len <= (len))
#define NLMSG_PAYLOAD(nlh, len) ((nlh)->nlmsg_len - NLMSG_SPACE((len)))

#define NLM_F_REQUEST           0x01
#define NLM_F_MULTI             0x02
#define NLM_F_ACK               0x04
#define NLM_F_ECHO              0x08
#define NLM_F_DUMP_INTR         0x10
#define NLM_F_DUMP_FILTERED     0x20
#define NLM_F_ROOT              0x100
#define NLM_F_MATCH             0x200
#define NLM_F_ATOMIC            0x400
#define NLM_F_DUMP              (NLM_F_ROOT | NLM_F_MATCH)
#define NLM_F_REPLACE           0x100
#define NLM_F_EXCL              0x200
#define NLM_F_CREATE            0x400
#define NLM_F_APPEND            0x800

#define NLMSG_NOOP              0x1
#define NLMSG_ERROR             0x2
#define NLMSG_DONE              0x3
#define NLMSG_OVERRUN           0x4
#define NLMSG_MIN_TYPE          0x10

struct sockaddr_nl {
        sa_family_t     nl_family;
        unsigned short  nl_pad;
        uint32_t        nl_pid;
        uint32_t        nl_groups;
};

struct nlmsghdr {
        uint32_t        nlmsg_len;
        uint16_t        nlmsg_type;
        uint16_t        nlmsg_flags;
        uint32_t        nlmsg_seq;
        uint32_t        nlmsg_pid;
};

struct nlmsgerr {
        int             error;
        struct nlmsghdr msg;
};

struct nlmsgerr_attrs {
        uint8_t         attrs[];
};

struct genlmsghdr {
        uint8_t         cmd;
        uint8_t         version;
        uint16_t        reserved;
};

#define NETLINK_ADD_MEMBERSHIP         1
#define NETLINK_DROP_MEMBERSHIP        2
#define NETLINK_PKTINFO                3
#define NETLINK_BROADCAST_ERROR        4
#define NETLINK_NO_ENOBUFS             5
#define NETLINK_RX_RING                6
#define NETLINK_TX_RING                7
#define NETLINK_LISTEN_ALL_NSID        8
#define NETLINK_LIST_MEMBERSHIPS       9
#define NETLINK_CAP_ACK                10
#define NETLINK_EXT_ACK                11
#define NETLINK_GET_STRICT_CHK         12

struct nl_pktinfo {
        uint32_t        group;
};

struct nl_mmap_req {
        unsigned int    nm_block_size;
        unsigned int    nm_block_nr;
        unsigned int    nm_frame_size;
        unsigned int    nm_frame_nr;
};

struct nl_mmap_hdr {
        unsigned int    nm_status;
        unsigned int    nm_len;
        uint32_t        nm_group;
        uint32_t        nm_pid;
        uint32_t        nm_uid;
        uint32_t        nm_gid;
};

enum nl_mmap_status {
        NL_MMAP_STATUS_UNUSED,
        NL_MMAP_STATUS_RESERVED,
        NL_MMAP_STATUS_VALID,
        NL_MMAP_STATUS_COPY,
        NL_MMAP_STATUS_SKIP,
};

#define NL_MMAP_MSG_ALIGNMENT          NLMSG_ALIGNTO
#define NL_MMAP_MSG_HEADER_SIZE        NLMSG_ALIGN(sizeof(struct nl_mmap_hdr))

#define NETLINK_MMAP_RX                0x01
#define NETLINK_MMAP_TX                0x02
#define NETLINK_MMAP_MASK              0x03

#define NETLINK_MMAP_AVAILABLE         0x10
#define NETLINK_MMAP_ABS_AVAILABLE     0x20
