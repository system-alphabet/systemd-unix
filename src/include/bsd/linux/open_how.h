/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Linux struct open_how (openat2).
 * Minimal FreeBSD shim.
 */

#include <stdint.h>

struct open_how {
        uint64_t  flags;
        uint64_t  mode;
        uint64_t  resolve;
};
