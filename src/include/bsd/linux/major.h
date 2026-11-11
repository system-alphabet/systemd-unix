/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Linux <linux/major.h> — block device major numbers.
 * FreeBSD has no equivalent header; the values match Linux for reference, but they are only used for
 * comparisons against device numbers obtained from Linux-specific ioctls, which fail on FreeBSD anyway.
 */

#ifndef LOOP_MAJOR
#define LOOP_MAJOR 7
#endif
#ifndef MD_MAJOR
#define MD_MAJOR 9
#endif
