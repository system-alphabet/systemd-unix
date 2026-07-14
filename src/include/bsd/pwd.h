/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <stdio.h>
#include_next <pwd.h>

/*
 * Linux-specific passwd functions not present on FreeBSD.
 * Used by src/basic/user-util.c.
 */

#ifndef __linux__
int putpwent(const struct passwd *p, FILE *stream);
struct passwd *fgetpwent(FILE *stream);
#endif
