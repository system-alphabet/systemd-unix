/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/* Minimal stub for Linux netfilter IPv4 header. */

#define NF_IP_PRI_FIRST         (-2147483648)
#define NF_IP_PRI_RAW           (-300)
#define NF_IP_PRI_MANGLE        (-150)
#define NF_IP_PRI_NAT_DST       (-100)
#define NF_IP_PRI_FILTER        0
#define NF_IP_PRI_SECURITY      50
#define NF_IP_PRI_NAT_SRC       100
#define NF_IP_PRI_LAST          2147483647

enum nf_ip_hook_priorities {
        NF_IP_PRI_FIRST_CONNTRACK = NF_IP_PRI_RAW,
};
