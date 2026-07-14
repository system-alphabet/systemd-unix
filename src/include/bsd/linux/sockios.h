/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Stub for Linux <linux/sockios.h> — socket I/O control definitions.
 * FreeBSD uses different mechanisms and ioctl numbers for network
 * interface configuration; these constants are not needed at compile
 * time since the code that uses them is guarded by runtime capability
 * checks or is Linux-only and compiled out on BSD.
 */

#ifndef SIOCGSKNS
#define SIOCGSKNS 0x894C
#endif
