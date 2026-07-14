/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Linux <sys/bpf.h> — glibc wrapper for the bpf() syscall.
 * On FreeBSD, <sys/bpf.h> is the Berkeley Packet Filter (different API).
 * This shim shadows the FreeBSD header and provides only the Linux
 * bpf() function declaration needed by systemd's bpf-program.c.
 */

#include <linux/bpf.h>
