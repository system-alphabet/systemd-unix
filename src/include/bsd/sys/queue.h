/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#if defined(__NetBSD__)
/*
 * NetBSD's <net/if.h> and <net/if_ether.h> are written against the full BSD <sys/queue.h>: they use
 * LIST_HEAD/LIST_ENTRY (and SIMPLEQ_HEAD) to declare their interface and multicast lists, whereas
 * FreeBSD's networking headers never mention LIST_* at all — which is why the hand-written subset below
 * was enough there. On NetBSD hand the real header through instead of keeping a second copy of it in sync.
 *
 * Six of the BSD macro names — LIST_HEAD, LIST_INIT, LIST_INSERT_AFTER, LIST_INSERT_BEFORE, LIST_FOREACH
 * and LIST_REMOVE — are also defined by systemd's <list.h>, and LIST_HEAD does not even agree on the
 * argument order (systemd spells it LIST_HEAD(type, name), BSD LIST_HEAD(name, type)). Because this file
 * sits on the include path as -isystem, clang suppresses -Wmacro-redefined for both it and the system
 * <sys/queue.h>, so the redefinition is never reported and whichever header came last silently wins.
 *
 * Shield those six names around the include instead: what <sys/queue.h> wants to set them to is dropped
 * again right away, so systemd's <list.h> definitions — or nothing at all, when <list.h> has not been
 * included yet — survive for the rest of the translation unit. The BSD forms are only needed while a
 * NetBSD header that actually uses them is being parsed, and those headers are wrapped where required
 * (see src/include/bsd/net/if_ether.h).
 *
 * The remaining BSD macros (LIST_ENTRY, SIMPLEQ_*, TAILQ_*, SLIST_*, ...) have no counterpart in
 * systemd's <list.h>, so they are left defined: <net/if.h> and <sys/mount.h> declare their interface
 * lists with LIST_ENTRY() and would not compile without it.
 *
 * push_macro/pop_macro are not understood by GCC, but this branch only exists on NetBSD, whose toolchain
 * is clang.
 */
#  pragma push_macro("LIST_HEAD")
#  pragma push_macro("LIST_INIT")
#  pragma push_macro("LIST_INSERT_AFTER")
#  pragma push_macro("LIST_INSERT_BEFORE")
#  pragma push_macro("LIST_FOREACH")
#  pragma push_macro("LIST_REMOVE")
#  include_next <sys/queue.h>
#  pragma pop_macro("LIST_REMOVE")
#  pragma pop_macro("LIST_FOREACH")
#  pragma pop_macro("LIST_INSERT_BEFORE")
#  pragma pop_macro("LIST_INSERT_AFTER")
#  pragma pop_macro("LIST_INIT")
#  pragma pop_macro("LIST_HEAD")
#else

/*
 * We shadow FreeBSD's <sys/queue.h> to avoid conflicting LIST_* macro
 * definitions (FreeBSD uses different signatures than systemd's <list.h>).
 *
 * Only provide the TAILQ_*, SLIST_*, STAILQ_* macros that FreeBSD system
 * headers (e.g., <aio.h>, <sys/bio.h>) actually need.  LIST_*, CIRCLEQ_*
 * are omitted — systemd provides its own via <list.h>.
 */

/*
 * SLIST — singly-linked list
 */
#define SLIST_HEAD(name, type)                                          \
struct name {                                                           \
        struct type *slh_first;                                         \
}

#define SLIST_ENTRY(type)                                               \
struct {                                                                \
        struct type *sle_next;                                          \
}

/*
 * STAILQ — singly-linked tail queue (minimal stub)
 */
#define STAILQ_HEAD(name, type)                                         \
struct name {                                                           \
        struct type *stqh_first;                                        \
        struct type **stqh_last;                                        \
}

#define STAILQ_ENTRY(type)                                              \
struct {                                                                \
        struct type *stqe_next;                                         \
}

/*
 * TAILQ — tail queue (used by <aio.h>, <sys/bio.h>, etc.)
 */
#define TAILQ_HEAD(name, type)                                          \
struct name {                                                           \
        struct type *tqh_first;                                         \
        struct type **tqh_last;                                         \
}

#define TAILQ_ENTRY(type)                                               \
struct {                                                                \
        struct type *tqe_next;                                          \
        struct type **tqe_prev;                                         \
}

#define TAILQ_FIRST(head)       ((head)->tqh_first)
#define TAILQ_NEXT(elm, field)  ((elm)->field.tqe_next)
#define TAILQ_INIT(head)        do { (head)->tqh_first = NULL; (head)->tqh_last = &(head)->tqh_first; } while (0)

/* LIST_* macros intentionally omitted — use systemd's <list.h> instead. */

#endif /* !__NetBSD__ */
