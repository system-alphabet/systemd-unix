/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <linux/netlink.h>

/* SOCK_DIAG constants. */
#define SOCK_DIAG_BY_FAMILY     20
#define SOCK_DESTROY            21

/* SK_MEMINFO_* values. */
#define SK_MEMINFO_RMEM_ALLOC    0
#define SK_MEMINFO_RCVBUF        1
#define SK_MEMINFO_WMEM_ALLOC    2
#define SK_MEMINFO_SNDBUF        3
#define SK_MEMINFO_FWD_ALLOC     4
#define SK_MEMINFO_WMEM_QUEUED   5
#define SK_MEMINFO_OPTMEM        6
#define SK_MEMINFO_BACKLOG       7
#define SK_MEMINFO_DROPS         8

/* TCP states. */
#define TCP_ESTABLISHED  1
#define TCP_SYN_SENT     2
#define TCP_SYN_RECV     3
#define TCP_FIN_WAIT1    4
#define TCP_FIN_WAIT2    5
#define TCP_TIME_WAIT    6
#define TCP_CLOSE        7
#define TCP_CLOSE_WAIT   8
#define TCP_LAST_ACK     9
#define TCP_LISTEN       10
#define TCP_CLOSING      11

#define TCPDIAG_FAMILY   2 /* AF_INET */
