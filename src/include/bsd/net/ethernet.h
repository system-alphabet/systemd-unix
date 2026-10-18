#pragma once

/*
 * Shim for <net/ethernet.h>.
 *
 * FreeBSD provides the real header, but with struct ether_addr using the
 * BSD member name 'octet' where Linux uses 'ether_addr_octet'.
 *
 * OpenBSD has no <net/ethernet.h> whatsoever. Its <netinet/if_ether.h> defines
 * the very same struct ether_addr and ETHER_ADDR_LEN, already under the Linux
 * member name, so nothing has to be aliased there. That header is not
 * self-contained either, hence the prerequisites below.
 */

#include <sys/socket.h>

#if defined(__has_include_next) && __has_include_next(<net/ethernet.h>)
#        include_next <net/ethernet.h>

/* Provide Linux-compatible field name for struct ether_addr.
 * FreeBSD uses 'octet' while Linux uses 'ether_addr_octet'.
 * On Linux, the member is already named ether_addr_octet, so skip. */
#        ifndef __linux__
#                ifndef ether_addr_octet
#                        define ether_addr_octet octet
#                endif
#        endif
#else
#        include <sys/types.h>
#        include <net/if_arp.h>
#        include <netinet/in.h>
#        include <netinet/if_ether.h>
#endif

/* ETH_ALEN is the Linux name for ETHER_ADDR_LEN */
#ifndef ETH_ALEN
#define ETH_ALEN ETHER_ADDR_LEN
#endif
