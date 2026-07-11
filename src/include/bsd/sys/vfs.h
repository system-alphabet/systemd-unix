/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/* FreeBSD exposes struct statfs via <sys/mount.h>, not <sys/vfs.h>.
 * This shim redirects to the correct header. */
#include <sys/param.h>
#include <sys/mount.h>
