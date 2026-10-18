/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * NetBSD's <net/if_ether.h> is the userland header that actually *uses* the BSD forms of the LIST_*
 * macros from <sys/queue.h>: struct ethercom declares its multicast address list with
 * LIST_HEAD(, ether_multi), and the static inline ether_lookup_multi() walks it with LIST_FOREACH().
 * systemd's <list.h> defines neither — and for the macro the two do share, LIST_HEAD(), the argument
 * order is reversed — so <list.h> must not be in effect while this header is parsed.
 *
 * <sys/queue.h> itself is shielded by src/include/bsd/sys/queue.h, which restores <list.h> right
 * after including it, hence re-hand the BSD macro set out here around the real header and put the
 * previous definitions back afterwards. NetBSD's <sys/queue.h> is nothing but macro definitions, so
 * clearing its include guard to make it run a second time is safe.
 *
 * push_macro/pop_macro are understood by clang, which is what NetBSD builds with.
 */

#pragma push_macro("LIST_HEAD")
#pragma push_macro("LIST_INIT")
#pragma push_macro("LIST_INSERT_AFTER")
#pragma push_macro("LIST_INSERT_BEFORE")
#pragma push_macro("LIST_FOREACH")
#pragma push_macro("LIST_REMOVE")

#undef _SYS_QUEUE_H_
#include_next <sys/queue.h>

#include_next <net/if_ether.h>

#pragma pop_macro("LIST_REMOVE")
#pragma pop_macro("LIST_FOREACH")
#pragma pop_macro("LIST_INSERT_BEFORE")
#pragma pop_macro("LIST_INSERT_AFTER")
#pragma pop_macro("LIST_INIT")
#pragma pop_macro("LIST_HEAD")
