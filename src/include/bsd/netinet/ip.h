/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <netinet/ip.h>

/*
 * Linux <netinet/ip.h> provides struct iphdr (raw IPv4 header).
 * FreeBSD provides struct ip (BSD-style) in <netinet/ip.h>.
 * Add the Linux struct iphdr for compatibility.
 */
#ifndef HAVE_STRUCT_IPHDR
#define HAVE_STRUCT_IPHDR
struct iphdr {
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        unsigned int ihl:4;
        unsigned int version:4;
#else
        unsigned int version:4;
        unsigned int ihl:4;
#endif
        uint8_t tos;
        uint16_t tot_len;
        uint16_t id;
        uint16_t frag_off;
        uint8_t ttl;
        uint8_t protocol;
        uint16_t check;
        uint32_t saddr;
        uint32_t daddr;
};
#endif

/* IP type-of-service constants. */
#ifndef IPTOS_LOWDELAY
#define IPTOS_LOWDELAY          0x10
#endif
#ifndef IPTOS_THROUGHPUT
#define IPTOS_THROUGHPUT        0x08
#endif
#ifndef IPTOS_RELIABILITY
#define IPTOS_RELIABILITY       0x04
#endif
#ifndef IPTOS_LOWCOST
#define IPTOS_LOWCOST           0x02
#endif

/* IP TOS/DSCP class constants */
#ifndef IPTOS_CLASS_CS0
#define IPTOS_CLASS_CS0         0x00
#endif
#ifndef IPTOS_CLASS_CS1
#define IPTOS_CLASS_CS1         0x20
#endif
#ifndef IPTOS_CLASS_CS2
#define IPTOS_CLASS_CS2         0x40
#endif
#ifndef IPTOS_CLASS_CS3
#define IPTOS_CLASS_CS3         0x60
#endif
#ifndef IPTOS_CLASS_CS4
#define IPTOS_CLASS_CS4         0x80
#endif
#ifndef IPTOS_CLASS_CS5
#define IPTOS_CLASS_CS5         0xa0
#endif
#ifndef IPTOS_CLASS_CS6
#define IPTOS_CLASS_CS6         0xc0
#endif
#ifndef IPTOS_CLASS_CS7
#define IPTOS_CLASS_CS7         0xe0
#endif

/* IP precedence macros. */
#ifndef IPTOS_PREC
#define IPTOS_PREC(tos)         ((tos) & 0xE0)
#endif
#ifndef IPTOS_PREC_NETCONTROL
#define IPTOS_PREC_NETCONTROL          0xC0
#endif
#ifndef IPTOS_PREC_INTERNETCONTROL
#define IPTOS_PREC_INTERNETCONTROL     0xE0
#endif
#ifndef IPTOS_PREC_CRITIC_ECP
#define IPTOS_PREC_CRITIC_ECP          0xA0
#endif
