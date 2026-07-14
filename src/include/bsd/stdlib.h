#pragma once

#include_next <stdlib.h>
#include <assert.h>

/* On FreeBSD, strtod_l() and other locale-aware functions are declared in
 * <xlocale/_stdlib.h> instead of <stdlib.h>. The internal FreeBSD header
 * has a dependency on locale_t that must be satisfied first. */
#include <locale.h>
#include <xlocale/_stdlib.h>
