/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * BSD shim for <printf.h>.
 * FreeBSD does not provide glibc's printf format parsing extensions.
 */

#include <stddef.h>

/* parse_printf_format — glibc extension.  Unused on FreeBSD. */
typedef enum {
        PA_INT,
        PA_CHAR,
        PA_WCHAR,
        PA_STRING,
        PA_WSTRING,
        PA_POINTER,
        PA_FLOAT,
        PA_DOUBLE,
        PA_LAST
} printf_arginfo_type;

/* PA_FLAG_* bit flags (from glibc's <printf.h>) are OR'd into the type. */
#define PA_FLAG_PTR           (1 << 5)
#define PA_FLAG_SHORT         (1 << 6)
#define PA_FLAG_LONG          (1 << 7)
#define PA_FLAG_LONG_LONG     (1 << 8)
#define PA_FLAG_LONG_DOUBLE   (1 << 9)
#define PA_FLAG_WIDTH         (1 << 10)
#define PA_FLAG_PREC          (1 << 11)
#define PA_FLAG_PREC_ARG      (1 << 12)
#define PA_FLAG_WIDE          (1 << 13)
#define PA_FLAG_CONST         (1 << 14)
#define PA_FLAG_INT           (1 << 15)

unsigned int parse_printf_format(const char *fmt, size_t n, int *argtypes);
