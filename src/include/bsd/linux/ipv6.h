/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Linux <linux/ipv6.h> — IPv6 header structure.
 * Used by src/basic/parse-util.c for address parsing.
 */

#include <stdint.h>
#include <netinet/in.h>

#ifndef HAVE_LINUX_IPV6_HDR
struct ipv6hdr {
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
        uint8_t  priority:4,
                 version:4;
#else
        uint8_t  version:4,
                 priority:4;
#endif
        uint8_t  flow_lbl[3];
        uint16_t payload_len;
        uint8_t  nexthdr;
        uint8_t  hop_limit;
        struct in6_addr saddr;
        struct in6_addr daddr;
};
#endif
