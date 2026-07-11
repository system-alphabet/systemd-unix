/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * FreeBSD provides strtod_l() in <xlocale.h>, but the systemd code
 * does not include <xlocale.h> directly.  Ensure strtod_l is declared
 * by having <stdlib.h> included before pulling in the FreeBSD header.
 */
#include <stdlib.h>
#include_next <xlocale.h>
