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
#ifndef CGROUP2_SUPER_MAGIC
#define CGROUP2_SUPER_MAGIC     0x63677270
#endif
#ifndef BTRFS_SUPER_MAGIC
#define BTRFS_SUPER_MAGIC       0x9123683E
#endif
#ifndef SYSFS_MAGIC
#define SYSFS_MAGIC             0x62656572
#endif
#ifndef BINFMTFS_MAGIC
#define BINFMTFS_MAGIC          0x42494e4d
#endif
#ifndef TMPFS_MAGIC
#define TMPFS_MAGIC             0x01021994
#endif
#ifndef MSDOS_SUPER_MAGIC
#define MSDOS_SUPER_MAGIC       0x4d44
#endif
#ifndef ANON_INODE_FS_MAGIC
#define ANON_INODE_FS_MAGIC     0x09041934
#endif
#ifndef EXT4_SUPER_MAGIC
#define EXT4_SUPER_MAGIC        0xEF53
#endif
#ifndef XFS_SUPER_MAGIC
#define XFS_SUPER_MAGIC         0x58465342
#endif
#ifndef CGROUP_SUPER_MAGIC
#define CGROUP_SUPER_MAGIC      0x27e0eb
#endif
#ifndef DEBUGFS_MAGIC
#define DEBUGFS_MAGIC           0x64626720
#endif
#ifndef EFIVARFS_MAGIC
#define EFIVARFS_MAGIC          0xde5e81e4
#endif
#ifndef HUGETLBFS_MAGIC
#define HUGETLBFS_MAGIC         0x958458f6
#endif
#ifndef MQUEUE_MAGIC
#define MQUEUE_MAGIC            0x19800202
#endif
#ifndef PSTOREFS_MAGIC
#define PSTOREFS_MAGIC          0x6165676c
#endif
#ifndef SELINUX_MAGIC
#define SELINUX_MAGIC           0xf97cff8c
#endif
#ifndef SMACK_MAGIC
#define SMACK_MAGIC             0x43415d53
#endif
#ifndef SECURITYFS_MAGIC
#define SECURITYFS_MAGIC        0x73636630
#endif
#ifndef BPF_FS_MAGIC
#define BPF_FS_MAGIC            0xcafe4a11
#endif
#ifndef TRACEFS_MAGIC
#define TRACEFS_MAGIC           0x74726163
#endif
#ifndef OVERLAYFS_SUPER_MAGIC
#define OVERLAYFS_SUPER_MAGIC   0x794c7630
#endif
