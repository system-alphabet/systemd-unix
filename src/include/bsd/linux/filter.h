/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Linux <linux/filter.h> — BPF socket filter definitions.
 * FreeBSD provides <net/bpf.h> but with different structures.
 * Minimal shim providing only what systemd needs for SO_ATTACH_FILTER.
 */

#include <stdint.h>

/* BPF instruction */
struct sock_filter {
        uint16_t        code;
        uint8_t         jt;
        uint8_t         jf;
        uint32_t        k;
};

/* BPF program */
struct sock_fprog {
        unsigned short          len;
        struct sock_filter     *filter;
};
