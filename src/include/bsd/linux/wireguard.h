/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <stdint.h>

#define WG_GENL_NAME            "wireguard"
#define WG_KEY_LEN              32

enum {
        WGDEVICE_A_UNSPEC,
        WGDEVICE_A_IFINDEX,
        WGDEVICE_A_IFNAME,
        WGDEVICE_A_FLAGS,
        WGDEVICE_A_PRIVATE_KEY,
        WGDEVICE_A_LISTEN_PORT,
        WGDEVICE_A_FWMARK,
        WGDEVICE_A_PEERS,
        __WGDEVICE_A_MAX,
};
#define WGDEVICE_A_MAX (__WGDEVICE_A_MAX - 1)

enum {
        WGPEER_A_UNSPEC,
        WGPEER_A_PUBLIC_KEY,
        WGPEER_A_PRESHARED_KEY,
        WGPEER_A_FLAGS,
        WGPEER_A_ENDPOINT,
        WGPEER_A_PERSISTENT_KEEPALIVE_INTERVAL,
        WGPEER_A_LAST_HANDSHAKE_TIME,
        WGPEER_A_RX_BYTES,
        WGPEER_A_TX_BYTES,
        WGPEER_A_ALLOWEDIPS,
        WGPEER_A_PROTOCOL_VERSION,
        __WGPEER_A_MAX,
};
#define WGPEER_A_MAX (__WGPEER_A_MAX - 1)

enum {
        WGALLOWEDIP_A_UNSPEC,
        WGALLOWEDIP_A_FAMILY,
        WGALLOWEDIP_A_IPADDR,
        WGALLOWEDIP_A_CIDR_MASK,
        __WGALLOWEDIP_A_MAX,
};
#define WGALLOWEDIP_A_MAX (__WGALLOWEDIP_A_MAX - 1)
