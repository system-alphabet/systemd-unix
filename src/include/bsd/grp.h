/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <stdio.h>
#include_next <grp.h>

/*
 * Linux-specific group functions not present on FreeBSD.
 * Used by src/basic/user-util.c.
 */

#ifndef __linux__
struct group *fgetgrent(FILE *stream);
int putgrent(const struct group *g, FILE *stream);
#endif
