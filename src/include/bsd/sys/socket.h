/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <sys/socket.h>

/* Linux-compatible struct ucred (completely different from FreeBSD's struct ucred in <sys/ucred.h>).
 * Used by socket-util.c for SO_PEERCRED. */
#if !defined(__linux__)
struct ucred {
        __pid_t pid;
        __uid_t uid;
        __gid_t gid;
};
#endif

/* Linux SOL_SOCKET-level socket options not present on FreeBSD. */
/* SO_CHAMELEON_FILTER — Linux socket filter attach/detach. */
#ifndef SO_ATTACH_FILTER
#define SO_ATTACH_FILTER 26
#endif
#ifndef SO_DETACH_FILTER
#define SO_DETACH_FILTER 27
#endif

/* SO_PASSCRED — Linux socket option for receiving SCM_CREDENTIALS. */
#ifndef SO_PASSCRED
#define SO_PASSCRED 16
#endif

#ifndef SO_PEERCRED
#define SO_PEERCRED 17
#endif
#ifndef SO_PEERSEC
#define SO_PEERSEC 31
#endif
#ifndef SO_RCVBUFFORCE
#define SO_RCVBUFFORCE 33
#endif
#ifndef SO_PEERGROUPS
#define SO_PEERGROUPS 59
#endif
#ifndef SO_PEERPIDFD
#define SO_PEERPIDFD 77
#endif
#ifndef SO_BINDTODEVICE
#define SO_BINDTODEVICE 25
#endif
#ifndef SO_BINDTOIFINDEX
#define SO_BINDTOIFINDEX 62
#endif

/* AF_PACKET — Linux address family for packet sockets. */
#ifndef AF_PACKET
#define AF_PACKET 17
#endif

/* AF_MPLS — Linux address family for MPLS. */
#ifndef AF_MPLS
#define AF_MPLS 33
#endif

/* SOL_NETLINK — socket level for netlink sockets. */
#ifndef SOL_NETLINK
#define SOL_NETLINK 270
#endif

/* CMSG_ALIGN — only defined in FreeBSD kernel space; define for userspace. */
#ifndef CMSG_ALIGN
#define CMSG_ALIGN(n) _ALIGN(n)
#endif

/* SO_SNDBUFFORCE — Linux-specific: forcibly set send buffer size. */
#ifndef SO_SNDBUFFORCE
#define SO_SNDBUFFORCE 32
#endif

/* SO_COOKIE — Linux-specific: get socket cookie. */
#ifndef SO_COOKIE
#define SO_COOKIE 57
#endif

/* SOL_PACKET — socket level for Linux AF_PACKET. */
#ifndef SOL_PACKET
#define SOL_PACKET 263
#endif

/* SCM_PIDFD — Linux cmsg type for receiving pidfd. */
#ifndef SCM_PIDFD
#define SCM_PIDFD 0x04
#endif

/* SOL_TCP level. */
#ifndef SOL_TCP
#define SOL_TCP 6
#endif

/* MSG_NOSIGNAL — suppress SIGPIPE on send (Linux-specific). On FreeBSD, SO_NOSIGPIPE is used instead. */
#ifndef MSG_NOSIGNAL
#define MSG_NOSIGNAL 0x4000
#endif

/* SOCK_DCCP — Linux-specific socket type for DCCP. */
#ifndef SOCK_DCCP
#define SOCK_DCCP 6
#endif

/* SCM_CREDENTIALS — Linux cmsg type for receiving process credentials. */
#ifndef SCM_CREDENTIALS
#define SCM_CREDENTIALS 0x02
#endif

/* SCM_MAX_FD — maximum number of FDs that can be passed in a single sendmsg.
 * FreeBSD uses a different mechanism; use Linux value (253) for cap checks. */
#ifndef SCM_MAX_FD
#define SCM_MAX_FD 253
#endif

/* SO_PASSRIGHTS — systemd-defined constant (Linux kernel v6.16+).
 * Builds outside Linux define it locally; value matches src/include/override/sys/socket.h. */
#ifndef SO_PASSRIGHTS
#define SO_PASSRIGHTS 83
#endif

/* SO_PASSPIDFD — Linux socket option. */
#ifndef SO_PASSPIDFD
#define SO_PASSPIDFD 78
#endif
