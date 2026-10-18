/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <sys/socket.h>
#include_next <netinet/in.h>

/*
 * Linux (and FreeBSD) expose the 32-bit view of struct in6_addr as s6_addr32. NetBSD defines those accessors
 * in <netinet6/in6.h>, but only under _KERNEL, so userspace code such as src/basic/in-addr-util.c has no way
 * to reach them. Add the missing names.
 */
#if defined(__NetBSD__) && !defined(s6_addr32)
#define s6_addr8    __u6_addr.__u6_addr8
#define s6_addr16   __u6_addr.__u6_addr16
#define s6_addr32   __u6_addr.__u6_addr32
#endif

/*
 * NetBSD implements a different IPPROTO_IP/IPPROTO_IPV6 setsockopt() number space than Linux does, and
 * the Linux numbers used below happen to land on options NetBSD does implement: 11 is IP_MULTICAST_LOOP,
 * 19 is IP_PORTRANGE, 25 is IP_PKTINFO for IPPROTO_IP and IPV6_2292PKTOPTIONS for IPPROTO_IPV6. Handing
 * them out would quietly reconfigure the socket instead of failing. None of these features exist on
 * NetBSD either way, so give them numbers outside the range NetBSD assigns (IPv4 stops at 27, IPv6 at 64)
 * and let the kernel answer ENOPROTOOPT — the honest answer for "not supported here".
 */
#if defined(__NetBSD__)
#undef IP_RECVERR
#define IP_RECVERR             100
#undef IP_TRANSPARENT
#define IP_TRANSPARENT         101
#undef IP_RECVFRAGSIZE
#define IP_RECVFRAGSIZE        102
#undef IPV6_RECVERR
#define IPV6_RECVERR           100
#endif

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
