/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <termios.h>

/*
 * Linux termios flags not present on FreeBSD.
 */

#ifndef IUCLC
#define IUCLC   0x0200
#endif
