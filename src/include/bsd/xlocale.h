#pragma once

/*
 * Convenience umbrella for FreeBSD's internal <xlocale/> headers.
 *
 * Nothing in the tree includes this file, and OpenBSD has no <xlocale/>
 * directory at all, so only expand it when the real headers are present.
 * Each individual header is checked because FreeBSD's set is not uniform:
 * it has no xlocale/_wctype.h, for instance.
 */

#if defined(__has_include)
#        if __has_include(<xlocale/_stdlib.h>)
#                include <xlocale/_stdlib.h>
#        endif
#        if __has_include(<xlocale/_ctype.h>)
#                include <xlocale/_ctype.h>
#        endif
#        if __has_include(<xlocale/_string.h>)
#                include <xlocale/_string.h>
#        endif
#        if __has_include(<xlocale/_inttypes.h>)
#                include <xlocale/_inttypes.h>
#        endif
#        if __has_include(<xlocale/_monetary.h>)
#                include <xlocale/_monetary.h>
#        endif
#        if __has_include(<xlocale/_time.h>)
#                include <xlocale/_time.h>
#        endif
#        if __has_include(<xlocale/_wchar.h>)
#                include <xlocale/_wchar.h>
#        endif
#        if __has_include(<xlocale/_wctype.h>)
#                include <xlocale/_wctype.h>
#        endif
#endif
