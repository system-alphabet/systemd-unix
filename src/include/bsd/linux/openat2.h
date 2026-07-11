/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Linux <linux/openat2.h> — openat2 syscall definitions.
 * FreeBSD shim for compilation purposes.
 */

#include <stddef.h>
#include <linux/open_how.h>

int openat2(int dfd, const char *filename, const struct open_how *how, size_t usize);
