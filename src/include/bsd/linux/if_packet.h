/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Linux <linux/if_packet.h> — AF_PACKET socket address structure.
 * Used by src/basic/socket-util.h.
 */

#include <sys/socket.h>
#include <stdint.h>
#include <net/if.h>

#ifndef PACKET_HOST
#define PACKET_HOST              0
#endif
#ifndef PACKET_BROADCAST
#define PACKET_BROADCAST         1
#endif
#ifndef PACKET_MULTICAST
#define PACKET_MULTICAST         2
#endif
#ifndef PACKET_OTHERHOST
#define PACKET_OTHERHOST         3
#endif
#ifndef PACKET_OUTGOING
#define PACKET_OUTGOING          4
#endif
#ifndef PACKET_LOOPBACK
#define PACKET_LOOPBACK          5
#endif
#ifndef PACKET_FASTROUTE
#define PACKET_FASTROUTE         6
#endif

struct sockaddr_ll {
        unsigned short sll_family;
        unsigned short sll_protocol;
        int            sll_ifindex;
        unsigned short sll_hatype;
        unsigned char  sll_pkttype;
        unsigned char  sll_halen;
        unsigned char  sll_addr[8];
};
