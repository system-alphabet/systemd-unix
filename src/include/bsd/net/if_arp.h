/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * FreeBSD <net/if_arp.h> needs struct sockaddr to be defined.
 * Ensure <sys/socket.h> is included first.
 *
 * NetBSD's <net/if_arp.h> is likewise not self-contained: it uses uint16_t and NULL without pulling in
 * <stdint.h>/<stddef.h> itself.
 */

#include <stddef.h>             /* NULL */
#include <stdint.h>             /* uint16_t */
#include <sys/socket.h>
#include_next <net/if_arp.h>

/*
 * Linux ARPHRD_* values not present in NetBSD's <net/if_arp.h> (which only
 * carries a small hand-picked set).
 */
#ifndef ARPHRD_INFINIBAND
#define ARPHRD_INFINIBAND      32      /* InfiniBand */
#endif
