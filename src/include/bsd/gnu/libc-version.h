/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <string.h>

static inline const char *gnu_get_libc_version(void) {
        return "glibc-compat";
}

static inline const char *gnu_get_libc_release(void) {
        return "stable";
}
