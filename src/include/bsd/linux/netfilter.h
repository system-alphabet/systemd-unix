/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/* Netfilter protocol families. */
#define NFPROTO_UNSPEC  0
#define NFPROTO_INET    1
#define NFPROTO_IPV4    2
#define NFPROTO_ARP     3
#define NFPROTO_NETDEV  5
#define NFPROTO_BRIDGE  7
#define NFPROTO_IPV6    10

/* NF_* netfilter verdicts. */
#define NF_DROP         0
#define NF_ACCEPT       1
#define NF_STOLEN       2
#define NF_QUEUE        3
#define NF_REPEAT       4
#define NF_STOP         5
