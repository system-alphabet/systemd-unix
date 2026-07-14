/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <stdint.h>

#define SIOCGETTUNNEL   (0x89F0)
#define SIOCADDTUNNEL   (0x89F1)
#define SIOCDELTUNNEL   (0x89F2)
#define SIOCCHGTUNNEL   (0x89F3)
#define SIOCGETPRL      (0x89F4)
#define SIOCADDPRL      (0x89F5)
#define SIOCDELPRL      (0x89F6)
#define SIOCCHGPRL      (0x89F7)
#define SIOCGET6RD      (0x89F8)
#define SIOCADD6RD      (0x89F9)
#define SIOCDEL6RD      (0x89FA)
#define SIOCCHG6RD      (0x89FB)

#define GRE_CSUM        0x8000
#define GRE_ROUTING     0x4000
#define GRE_KEY         0x2000
#define GRE_SEQ         0x1000
#define GRE_STRICT      0x0800
#define GRE_REC         0x0700
#define GRE_FLAGS       0x00F8
#define GRE_VERSION     0x0007

#define GRETUN_CSUM     0x8000
#define GRETUN_KEY      0x2000
#define GRETUN_SEQ      0x1000

#define TUNNEL_CSUM     0x0001
#define TUNNEL_ROUTING  0x0002
#define TUNNEL_KEY      0x0004
#define TUNNEL_SEQ      0x0008
#define TUNNEL_STRICT   0x0010
#define TUNNEL_REC      0x0020
#define TUNNEL_FLAGS    0x0040
#define TUNNEL_OPTIONS  0x0080
#define TUNNEL_ERSPAN_OPT 0x0100
#define TUNNEL_VXLAN_OPT  0x0200
#define TUNNEL_GENEVE_OPT 0x0400

#define IP_TUNNEL_INFO_TX     0
#define IP_TUNNEL_INFO_IPV6   1

/* GENEVE DF modes */
#define GENEVE_DF_UNSET                0
#define GENEVE_DF_SET                  1
#define GENEVE_DF_INHERIT              2
