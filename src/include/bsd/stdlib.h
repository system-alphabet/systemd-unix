#pragma once

#include_next <stdlib.h>
#include <assert.h>
#include <locale.h>

/*
 * On FreeBSD, strtod_l() and the other locale-aware conversion functions are
 * declared in <xlocale/_stdlib.h> rather than in <stdlib.h>, and that internal
 * header needs locale_t, hence <locale.h> above.
 *
 * OpenBSD has neither an <xlocale/> directory nor any _l-suffixed conversion
 * function, so emulate strtod_l() through the POSIX uselocale() interface.
 * glibc declares strtod_l() in <stdlib.h> itself and needs no help here.
 */

#if defined(__has_include) && __has_include(<xlocale/_stdlib.h>)
#        include <xlocale/_stdlib.h>
#elif defined(__OpenBSD__)
static inline double strtod_l(const char *nptr, char **endptr, locale_t loc) {
        locale_t saved = uselocale(loc);
        double r = strtod(nptr, endptr);
        if (saved)
                (void) uselocale(saved);
        return r;
}
#endif

/*
 * secure_getenv() is glibc-specific among the libcs we target — FreeBSD's <stdlib.h> declares it, NetBSD's
 * and OpenBSD's do not and their libc exports no such symbol. There is no AT_SECURE equivalent to honour
 * here anyway, so route it through getenv().
 */
#if !defined(__linux__) && !defined(__FreeBSD__) && !defined(__DragonFly__)
#ifndef secure_getenv
#define secure_getenv getenv
#endif
#endif

/*
 * qsort_r() — qsort() with a userdata pointer threaded through the comparator. glibc, FreeBSD and
 * NetBSD ≥ 11 provide it (POSIX 2024 argument order: compar before userdata, matching how the tree calls
 * it; FreeBSD additionally keeps its historical interface behind a compiler-generic macro). NetBSD < 11 and
 * OpenBSD have no such function at all, so emulate it with an in-place heapsort: worst-case O(n log n),
 * no allocation, and re-entrant — all state lives on our stack, so compar() may call qsort_r() again.
 */
#if defined(__NetBSD__)
#include <sys/param.h> /* for __NetBSD_Prereq__() */
#endif

/* __NetBSD_Prereq__() only exists on NetBSD, so it must not be referenced from a
 * preprocessor expression that is evaluated on other platforms. */
#if defined(__OpenBSD__)
#define NEED_QSORT_R 1
#elif defined(__NetBSD__)
#if !__NetBSD_Prereq__(11, 0, 0)
#define NEED_QSORT_R 1
#endif
#endif

#ifdef NEED_QSORT_R
static inline void qsort_r(void *base, size_t nmemb, size_t size,
                           int (*compar)(const void *, const void *, void *), void *arg) {
        char *b = base;

        if (nmemb <= 1)
                return;

        assert(base);

        /* Build a max-heap: sift down every non-leaf node. */
        for (size_t start = nmemb / 2; start-- > 0;) {
                size_t root = start;
                for (;;) {
                        size_t child = 2 * root + 1;
                        if (child >= nmemb)
                                break;
                        if (child + 1 < nmemb && compar(b + child * size, b + (child + 1) * size, arg) < 0)
                                child++;
                        if (compar(b + root * size, b + child * size, arg) >= 0)
                                break;
                        char *x = b + root * size, *y = b + child * size;
                        for (size_t k = 0; k < size; k++) {
                                char t = x[k];
                                x[k] = y[k];
                                y[k] = t;
                        }
                        root = child;
                }
        }

        /* Repeatedly move the max to the end and restore the heap. */
        for (size_t end = nmemb; end-- > 1;) {
                char *x = b, *y = b + end * size;
                for (size_t k = 0; k < size; k++) {
                        char t = x[k];
                        x[k] = y[k];
                        y[k] = t;
                }

                size_t root = 0;
                for (;;) {
                        size_t child = 2 * root + 1;
                        if (child >= end)
                                break;
                        if (child + 1 < end && compar(b + child * size, b + (child + 1) * size, arg) < 0)
                                child++;
                        if (compar(b + root * size, b + child * size, arg) >= 0)
                                break;
                        char *x2 = b + root * size, *y2 = b + child * size;
                        for (size_t k = 0; k < size; k++) {
                                char t = x2[k];
                                x2[k] = y2[k];
                                y2[k] = t;
                        }
                        root = child;
                }
        }
}
#endif
