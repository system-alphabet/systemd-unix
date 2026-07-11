/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * FreeBSD <netinet/in.h> does not include <sys/socket.h>.
 * systemd code expects AF_INET/AF_INET6 to be available after
 * including <netinet/in.h>. Include <sys/socket.h> first.
 */

#include <sys/socket.h>
#include_next <netinet/in.h>

/* Linux IP socket option constants not present on FreeBSD. */
#ifndef IP_RECVERR
#define IP_RECVERR 11
#endif
#ifndef IPV6_RECVERR
#define IPV6_RECVERR 75
#endif
#ifndef IP_FREEBIND
#define IP_FREEBIND 15
#endif
#ifndef IPV6_FREEBIND
#define IPV6_FREEBIND 78
#endif
#ifndef IP_TRANSPARENT
#define IP_TRANSPARENT 19
#endif
#ifndef IPV6_TRANSPARENT
#define IPV6_TRANSPARENT 75
#endif
#ifndef IP_RECVFRAGSIZE
#define IP_RECVFRAGSIZE 25
#endif
#ifndef IPV6_RECVFRAGSIZE
#define IPV6_RECVFRAGSIZE 77
#endif
#ifndef IP_RECVTTL
#define IP_RECVTTL 12
#endif
#ifndef IPV6_RECVHOPLIMIT
#define IPV6_RECVHOPLIMIT 37
#endif
#ifndef IP_TTL
#define IP_TTL 4
#endif
#ifndef IPV6_UNICAST_HOPS
#define IPV6_UNICAST_HOPS 4
#endif
#ifndef IPV6_MIN_MTU
#define IPV6_MIN_MTU 1280
#endif
