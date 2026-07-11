/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <stdlib.h>

/* strtod_l — glibc extension for locale-aware string-to-double conversion.
 * FreeBSD provides it in <xlocale.h> (not <stdlib.h>).  Declare it here so
 * that code which includes <stdlib.h> can use it directly. */
#include <locale.h>
double strtod_l(const char *str, char **str_end, locale_t loc);
