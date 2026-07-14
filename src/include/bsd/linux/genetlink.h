/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <linux/netlink.h>
#include <stdint.h>

/* Generic Netlink constants. */
#define GENL_ID_CTRL         NLMSG_MIN_TYPE
#define GENL_MIN_ID          NLMSG_MIN_TYPE
#define GENL_MAX_ID          1023
#define GENL_NAMSIZ          16

/* Controller commands. */
#define CTRL_CMD_UNSPEC       0
#define CTRL_CMD_NEWFAMILY    1
#define CTRL_CMD_DELFAMILY    2
#define CTRL_CMD_GETFAMILY    3
#define CTRL_CMD_NEWOPS       4
#define CTRL_CMD_DELOPS       5
#define CTRL_CMD_GETOPS       6
#define CTRL_CMD_NEWMCAST_GRP 7
#define CTRL_CMD_DELMCAST_GRP 8
#define CTRL_CMD_GETMCAST_GRP 9
#define CTRL_CMD_GETPOLICY    10

/* Controller attributes (top-level). */
#define CTRL_ATTR_UNSPEC        0
#define CTRL_ATTR_FAMILY_ID     1
#define CTRL_ATTR_FAMILY_NAME   2
#define CTRL_ATTR_VERSION       3
#define CTRL_ATTR_HDRSIZE       4
#define CTRL_ATTR_MAXATTR       5
#define CTRL_ATTR_OPS           6
#define CTRL_ATTR_MCAST_GROUPS  7
#define CTRL_ATTR_POLICY        8
#define CTRL_ATTR_OP_POLICY     9
#define CTRL_ATTR_OP            10

/* Controller mcast group sub-attributes. */
#define CTRL_ATTR_MCAST_GRP_UNSPEC   0
#define CTRL_ATTR_MCAST_GRP_NAME     1
#define CTRL_ATTR_MCAST_GRP_ID       2

/* Controller op sub-attributes. */
#define CTRL_ATTR_OP_UNSPEC   0
#define CTRL_ATTR_OP_ID       1
#define CTRL_ATTR_OP_FLAGS    2

#define GENL_CTRL_VERSION 1

struct genlmsghdr {
    uint8_t cmd;
    uint8_t version;
    uint16_t reserved;
};

#define GENL_HDRLEN NLMSG_ALIGN(sizeof(struct genlmsghdr))
