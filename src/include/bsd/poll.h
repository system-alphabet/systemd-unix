/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <poll.h>

/*
 * Linux <poll.h> flags not present on the BSDs.
 */

#ifndef POLLRDHUP
/* Peer closed the connection — Linux 2.6.17. FreeBSD's <sys/poll.h> also
 * defines POLLRDHUP as 0x4000; NetBSD has no such flag at all, and 0x2000 is
 * unused in its poll event mask (which only spans 0x0001-0x0100 plus the
 * 0x0008/0x0010/0x0020 error bits). io-util.c converts between POLL* and
 * EPOLL* masks through dedicated helpers, so a faithful value matters. */
#define POLLRDHUP 0x2000
#endif
