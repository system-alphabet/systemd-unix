/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#define FOU_ATTR_UNSPEC             0
#define FOU_ATTR_PORT               1
#define FOU_ATTR_AF                 2
#define FOU_ATTR_IPPROTO            3
#define FOU_ATTR_TYPE               4
#define FOU_ATTR_REMCSUM_NOPARTIAL  5
#define FOU_ATTR_LOCAL_V4           6
#define FOU_ATTR_LOCAL_V6           7
#define FOU_ATTR_PEER_V4            8
#define FOU_ATTR_PEER_V6            9
#define FOU_ATTR_PEER_PORT          10
#define FOU_ATTR_IFINDEX            11
#define FOU_ATTR_MAC                12

#define FOU_CMD_ADD                 1
#define FOU_CMD_DEL                 2
#define FOU_CMD_GET                 3

#define FOU_ENCAP_DIRECT            1
#define FOU_ENCAP_GUE               2

#define FOU_GENL_NAME               "fou"
#define FOU_GENL_VERSION            1
