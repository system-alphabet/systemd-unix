/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <stdint.h>

struct ifaddrlblmsg {
    uint8_t  ifal_family;
    uint8_t  __ifal_reserved;
    uint8_t  ifal_prefixlen;
    uint8_t  ifal_flags;
    uint32_t ifal_index;
    uint32_t ifal_seq;
};

#define IFAL_ADDRESS 1
#define IFAL_LABEL   2
#define IFAL_MAX     IFAL_LABEL
