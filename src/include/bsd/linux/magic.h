/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Linux <linux/magic.h> — filesystem magic numbers.
 * Only the constants needed by files in src/basic/ that are compiled for BSD.
 */

#ifndef AUTOFS_SUPER_MAGIC
#define AUTOFS_SUPER_MAGIC      0x0187
#endif
#ifndef NSFS_MAGIC
#define NSFS_MAGIC              0x6E736364
#endif
#ifndef PID_FS_MAGIC
#define PID_FS_MAGIC            0x50494446
#endif
#ifndef PROC_SUPER_MAGIC
#define PROC_SUPER_MAGIC        0x9FA0
#endif
#ifndef DEVPTS_SUPER_MAGIC
#define DEVPTS_SUPER_MAGIC      0x1CD1
#endif
