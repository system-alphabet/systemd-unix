/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Linux <linux/if_arp.h> — ARP protocol hardware type identifiers (ARPHRD_*).
 * FreeBSD provides these in <net/if_arp.h>, but we need to include
 * <sys/socket.h> first to get struct sockaddr definition.
 *
 * Note: FreeBSD's <net/if_arp.h> uses BSD-specific types (u_short, u_char)
 * and uint64_t. Ensure they're available before including it.
 */

#include <sys/types.h>
#include <stdint.h>
#include <sys/socket.h>
#include <net/if_arp.h>

/* ARPHRD_* values — FreeBSD's <net/if_arp.h> provides the standard ones.
 * Linux-only extensions are defined below. */
#ifndef ARPHRD_NETROM
#define ARPHRD_NETROM           0
#endif
#ifndef ARPHRD_ETHER
#define ARPHRD_ETHER            1
#endif
#ifndef ARPHRD_EETHER
#define ARPHRD_EETHER           2
#endif
#ifndef ARPHRD_AX25
#define ARPHRD_AX25             3
#endif
#ifndef ARPHRD_PRONET
#define ARPHRD_PRONET           4
#endif
#ifndef ARPHRD_CHAOS
#define ARPHRD_CHAOS            5
#endif
#ifndef ARPHRD_IEEE802
#define ARPHRD_IEEE802          6
#endif
#ifndef ARPHRD_ARCNET
#define ARPHRD_ARCNET           7
#endif
#ifndef ARPHRD_APPLETLK
#define ARPHRD_APPLETLK         8
#endif
#ifndef ARPHRD_DLCI
#define ARPHRD_DLCI             15
#endif
#ifndef ARPHRD_ATM
#define ARPHRD_ATM              19
#endif
#ifndef ARPHRD_METRICOM
#define ARPHRD_METRICOM         23
#endif
#ifndef ARPHRD_IEEE1394
#define ARPHRD_IEEE1394         24
#endif
#ifndef ARPHRD_EUI64
#define ARPHRD_EUI64            27
#endif
#ifndef ARPHRD_INFINIBAND
#define ARPHRD_INFINIBAND       32
#endif
#ifndef ARPHRD_SIT
#define ARPHRD_SIT              776
#endif
#ifndef ARPHRD_IPGRE
#define ARPHRD_IPGRE            778
#endif
#ifndef ARPHRD_TUNNEL
#define ARPHRD_TUNNEL           768
#endif
#ifndef ARPHRD_TUNNEL6
#define ARPHRD_TUNNEL6          769
#endif
#ifndef ARPHRD_LOOPBACK
#define ARPHRD_LOOPBACK         772
#endif
#ifndef ARPHRD_LOCALTLK
#define ARPHRD_LOCALTLK         773
#endif
#ifndef ARPHRD_PPP
#define ARPHRD_PPP              512
#endif
#ifndef ARPHRD_CISCO
#define ARPHRD_CISCO            513
#endif
#ifndef ARPHRD_RAWHDLC
#define ARPHRD_RAWHDLC          519
#endif
#ifndef ARPHRD_IP6TUNNEL
#define ARPHRD_IP6TUNNEL        775
#endif
#ifndef ARPHRD_SLIP
#define ARPHRD_SLIP             256
#endif
#ifndef ARPHRD_CSLIP
#define ARPHRD_CSLIP            257
#endif
#ifndef ARPHRD_SLIP6
#define ARPHRD_SLIP6            258
#endif
#ifndef ARPHRD_CSLIP6
#define ARPHRD_CSLIP6           259
#endif
#ifndef ARPHRD_RSRVD
#define ARPHRD_RSRVD            260
#endif
#ifndef ARPHRD_ADAPT
#define ARPHRD_ADAPT            264
#endif
#ifndef ARPHRD_ROSE
#define ARPHRD_ROSE             10
#endif
#ifndef ARPHRD_X25
#define ARPHRD_X25              11
#endif
#ifndef ARPHRD_HWX25
#define ARPHRD_HWX25            12
#endif
#ifndef ARPHRD_PIMREG
#define ARPHRD_PIMREG           104
#endif
#ifndef ARPHRD_IRDA
#define ARPHRD_IRDA             783
#endif
#ifndef ARPHRD_FCPP
#define ARPHRD_FCPP             784
#endif
#ifndef ARPHRD_FCAL
#define ARPHRD_FCAL             785
#endif
#ifndef ARPHRD_FCPL
#define ARPHRD_FCPL             786
#endif
#ifndef ARPHRD_FCFABRIC
#define ARPHRD_FCFABRIC         787
#endif
#ifndef ARPHRD_IEEE80211
#define ARPHRD_IEEE80211        801
#endif
#ifndef ARPHRD_IEEE80211_PRISM
#define ARPHRD_IEEE80211_PRISM  802
#endif
#ifndef ARPHRD_IEEE80211_RADIOTAP
#define ARPHRD_IEEE80211_RADIOTAP 803
#endif
#ifndef ARPHRD_IEEE802154
#define ARPHRD_IEEE802154       804
#endif
#ifndef ARPHRD_IEEE802154_MONITOR
#define ARPHRD_IEEE802154_MONITOR 805
#endif
#ifndef ARPHRD_PHONET
#define ARPHRD_PHONET           820
#endif
#ifndef ARPHRD_PHONET_PIPE
#define ARPHRD_PHONET_PIPE      821
#endif
#ifndef ARPHRD_CAIF
#define ARPHRD_CAIF             822
#endif
#ifndef ARPHRD_IP6GRE
#define ARPHRD_IP6GRE           823
#endif
#ifndef ARPHRD_NETLINK
#define ARPHRD_NETLINK          824
#endif
#ifndef ARPHRD_6LOWPAN
#define ARPHRD_6LOWPAN          825
#endif
#ifndef ARPHRD_VSOCKMON
#define ARPHRD_VSOCKMON         826
#endif
#ifndef ARPHRD_MACSEC
#define ARPHRD_MACSEC           827
#endif
#ifndef ARPHRD_NONE
#define ARPHRD_NONE             65534
#endif
#ifndef ARPHRD_VOID
#define ARPHRD_VOID             0xFFFF
#endif
