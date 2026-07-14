/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <malloc.h>

/*
 * glibc-specific malloc extensions used by systemd.
 * Provide stubs for FreeBSD compatibility.
 */

#ifndef __linux__

#include <stddef.h>
#include <stdio.h>

struct mallinfo2 {
        size_t arena;
        size_t hblkhd;
};

static inline struct mallinfo2 mallinfo2(void) {
        struct mallinfo2 mi = { .arena = 0, .hblkhd = 0 };
        return mi;
}

static inline int malloc_trim(size_t pad) {
        (void)pad;
        /* FreeBSD's jemalloc doesn't support trimming; report success. */
#if defined(__FreeBSD__)
        return 1;
#else
        return 0;
#endif
}

int malloc_info(int options, FILE *stream);

#endif /* __linux__ */
