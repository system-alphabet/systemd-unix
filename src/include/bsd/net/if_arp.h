/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * FreeBSD <net/if_arp.h> needs struct sockaddr to be defined.
 * Ensure <sys/socket.h> is included first.
 */

#include <sys/socket.h>
#include_next <net/if_arp.h>
