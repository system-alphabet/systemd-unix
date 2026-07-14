/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <sys/socket.h>
#include_next <netinet/in.h>

/*
 * Linux IP-level socket option constants not available on FreeBSD.
 */
#ifndef IP_RECVERR
#define IP_RECVERR              11
#endif
#ifndef IPV6_RECVERR
#define IPV6_RECVERR            25
#endif
#ifndef IP_FREEBIND
#define IP_FREEBIND             15
#endif
#ifndef IPV6_FREEBIND
#define IPV6_FREEBIND           78
#endif
#ifndef IP_TRANSPARENT
#define IP_TRANSPARENT          19
#endif
#ifndef IPV6_TRANSPARENT
#define IPV6_TRANSPARENT        75
#endif
#ifndef IP_RECVFRAGSIZE
#define IP_RECVFRAGSIZE         25
#endif
#ifndef IPV6_RECVFRAGSIZE
#define IPV6_RECVFRAGSIZE       73
#endif
#ifndef IP_RECVTTL
#define IP_RECVTTL              12
#endif
#ifndef IPV6_RECVHOPLIMIT
#define IPV6_RECVHOPLIMIT       37
#endif
#ifndef IP_TTL
#define IP_TTL                  2
#endif
#ifndef IPV6_UNICAST_HOPS
#define IPV6_UNICAST_HOPS       4
#endif
#ifndef IPV6_MIN_MTU
#define IPV6_MIN_MTU            1280
#endif
#ifndef IP_PKTINFO
#define IP_PKTINFO              8
#endif
#ifndef IP_UNICAST_IF
#define IP_UNICAST_IF           50
#endif
#ifndef IPV6_UNICAST_IF
#define IPV6_UNICAST_IF         76
#endif
#ifndef IP_MTU
#define IP_MTU                  14
#endif
#ifndef IPV6_MTU
#define IPV6_MTU                71
#endif

/*
 * FreeBSD defines IPPROTO_IPIP as an alias for IPPROTO_IPV4 (=4), but
 * Linux defines it as 94 (IP-in-IP encapsulation). Fix the value.
 * FreeBSD also defines IPPROTO_OLD_DIVERT (=254) which doesn't exist
 * on Linux, causing duplicate with IPPROTO_RESERVED_254. Undefine it.
 * Similarly, IPPROTO_HOPOPTS (=0) duplicates IPPROTO_IP (=0), and
 * IPPROTO_IPEIP (=94) duplicates the (redefined) IPPROTO_IPIP (=94).
 */
#ifdef IPPROTO_IPIP
#undef IPPROTO_IPIP
#define IPPROTO_IPIP            94
#endif

#ifdef IPPROTO_OLD_DIVERT
#undef IPPROTO_OLD_DIVERT
#endif

#ifdef IPPROTO_HOPOPTS
#undef IPPROTO_HOPOPTS
#endif

#ifdef IPPROTO_IPEIP
#undef IPPROTO_IPEIP
#endif

/* Linux IP protocols not available on FreeBSD */
#ifndef IPPROTO_MPTCP
#define IPPROTO_MPTCP           262
#endif
