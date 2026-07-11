/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Linux <linux/btrfs.h> — Btrfs filesystem ioctl definitions.
 * FreeBSD shim for compilation purposes only.
 * btrfs-util.c is likely excluded from BSD builds, but if included,
 * these definitions allow it to compile.
 */

#include <stdint.h>
#include <sys/ioctl.h>

/* Btrfs ioctls */
#ifndef BTRFS_IOCTL_MAGIC
#define BTRFS_IOCTL_MAGIC       0x94
#endif

#ifndef BTRFS_IOC_SUBVOL_CREATE
#define BTRFS_IOC_SUBVOL_CREATE _IOW(BTRFS_IOCTL_MAGIC, 14, struct btrfs_ioctl_vol_args)
#endif
#ifndef BTRFS_IOC_SUBVOL_CREATE_V2
#define BTRFS_IOC_SUBVOL_CREATE_V2 _IOW(BTRFS_IOCTL_MAGIC, 24, struct btrfs_ioctl_vol_args_v2)
#endif
#ifndef BTRFS_IOC_SUBVOL_GETFLAGS
#define BTRFS_IOC_SUBVOL_GETFLAGS _IOR(BTRFS_IOCTL_MAGIC, 25, uint64_t)
#endif
#ifndef BTRFS_IOC_SUBVOL_SETFLAGS
#define BTRFS_IOC_SUBVOL_SETFLAGS _IOW(BTRFS_IOCTL_MAGIC, 26, uint64_t)
#endif
#ifndef BTRFS_IOC_SNAP_CREATE
#define BTRFS_IOC_SNAP_CREATE   _IOW(BTRFS_IOCTL_MAGIC, 1, struct btrfs_ioctl_vol_args)
#endif
#ifndef BTRFS_IOC_SNAP_CREATE_V2
#define BTRFS_IOC_SNAP_CREATE_V2 _IOW(BTRFS_IOCTL_MAGIC, 23, struct btrfs_ioctl_vol_args_v2)
#endif
#ifndef BTRFS_IOC_SNAP_DESTROY
#define BTRFS_IOC_SNAP_DESTROY  _IOW(BTRFS_IOCTL_MAGIC, 15, struct btrfs_ioctl_vol_args)
#endif
#ifndef BTRFS_IOC_DEFRAG
#define BTRFS_IOC_DEFRAG        _IOW(BTRFS_IOCTL_MAGIC, 17, struct btrfs_ioctl_vol_args)
#endif
#ifndef BTRFS_IOC_RESIZE
#define BTRFS_IOC_RESIZE        _IOW(BTRFS_IOCTL_MAGIC, 19, struct btrfs_ioctl_vol_args)
#endif
#ifndef BTRFS_IOC_SCAN_DEV
#define BTRFS_IOC_SCAN_DEV      _IOW(BTRFS_IOCTL_MAGIC, 4, struct btrfs_ioctl_vol_args)
#endif
#ifndef BTRFS_IOC_FORGET_DEV
#define BTRFS_IOC_FORGET_DEV    _IOW(BTRFS_IOCTL_MAGIC, 5, struct btrfs_ioctl_vol_args)
#endif
#ifndef BTRFS_IOC_ADD_DEV
#define BTRFS_IOC_ADD_DEV       _IOW(BTRFS_IOCTL_MAGIC, 10, struct btrfs_ioctl_vol_args)
#endif
#ifndef BTRFS_IOC_RM_DEV
#define BTRFS_IOC_RM_DEV        _IOW(BTRFS_IOCTL_MAGIC, 11, struct btrfs_ioctl_vol_args)
#endif
#ifndef BTRFS_IOC_BALANCE
#define BTRFS_IOC_BALANCE       _IOW(BTRFS_IOCTL_MAGIC, 12, struct btrfs_ioctl_vol_args)
#endif
#ifndef BTRFS_IOC_CLONE
#define BTRFS_IOC_CLONE         _IOW(BTRFS_IOCTL_MAGIC, 9, int)
#endif

/* Btrfs structures */
struct btrfs_ioctl_vol_args {
        int64_t         fd;
        char            name[4088];
};

struct btrfs_ioctl_vol_args_v2 {
        int64_t         fd;
        int64_t         transid;
        uint64_t        flags;
        union {
                struct {
                        uint64_t        size;
                        char            qgroup_inherit[40];
                };
                uint64_t        unused[4];
        };
        char            name[4088];
};

/* Flags for subvolumes */
#ifndef BTRFS_SUBVOL_RDONLY
#define BTRFS_SUBVOL_RDONLY     (1ULL << 1)
#endif

/* Btrfs feature flags */
#ifndef BTRFS_FEATURE_COMPAT_RO_FREE_SPACE_TREE
#define BTRFS_FEATURE_COMPAT_RO_FREE_SPACE_TREE 0x1
#endif
#ifndef BTRFS_FEATURE_COMPAT_RO_FREE_SPACE_TREE_VALID
#define BTRFS_FEATURE_COMPAT_RO_FREE_SPACE_TREE_VALID 0x2
#endif

/* Btrfs subvolume name max */
#ifndef BTRFS_SUBVOL_NAME_MAX
#define BTRFS_SUBVOL_NAME_MAX 4035
#endif

/* Btrfs qgroup */
#ifndef BTRFS_QGROUP_INHERIT_SET_LIMITS
#define BTRFS_QGROUP_INHERIT_SET_LIMITS (1ULL << 0)
#endif
