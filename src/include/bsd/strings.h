/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * NetBSD's <strings.h> declares popcount() (and its long/long-long variants),
 * but systemd's fundamental/logarithm.h defines popcount() as a function-like
 * macro. If the macro is in scope while <strings.h> is parsed, the declaration
 * is mangled by its expansion ("expected identifier or '('"). Hide the macro
 * across the real header and restore it afterwards; push_macro/pop_macro
 * preserve even the "was never defined" state, so this is safe when the macro
 * is absent.
 */

#pragma push_macro("popcount")
#undef popcount

#include_next <strings.h>

#pragma pop_macro("popcount")
