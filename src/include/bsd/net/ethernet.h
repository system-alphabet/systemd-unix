/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * FreeBSD <net/ethernet.h> shim — ensures struct sockaddr is defined
 * (needed by <net/if_arp.h>) and provides Linux-compatible field names.
 */

#include <sys/socket.h>
#include_next <net/ethernet.h>

/* Provide Linux-compatible field name for struct ether_addr.
 * FreeBSD uses 'octet' while Linux uses 'ether_addr_octet'. */
#ifndef ether_addr_octet
#define ether_addr_octet octet
#endif

/* ETH_ALEN is the Linux name for ETHER_ADDR_LEN */
#ifndef ETH_ALEN
#define ETH_ALEN ETHER_ADDR_LEN
#endif
