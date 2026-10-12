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
        size_t arena;    /* non-mmapped space allocated from the system */
        size_t ordblks;  /* number of free chunks */
        size_t smblks;   /* number of free fastbins */
        size_t hblkhd;   /* space in mmapped regions */
        size_t usmblks;  /* always 0, preserved for backwards compatibility */
        size_t fsmblks;  /* number of free fastbins */
        size_t uordblks; /* total allocated space */
        size_t fordblks; /* total free space */
        size_t keepcost; /* top-most, releasable (via malloc_trim) space */
};

static inline struct mallinfo2 mallinfo2(void) {
        /* jemalloc has no equivalent, report zeroes. */
        struct mallinfo2 mi = {
                .arena = 0, .ordblks = 0, .smblks = 0, .hblkhd = 0,
                .usmblks = 0, .fsmblks = 0, .uordblks = 0, .fordblks = 0,
                .keepcost = 0,
        };
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
