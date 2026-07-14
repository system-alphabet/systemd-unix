/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

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
