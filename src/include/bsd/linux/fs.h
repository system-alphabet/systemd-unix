/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Linux <linux/fs.h> — file system ioctls, inode flags, and seal types.
 * Minimal shim for FreeBSD compatibility.
 */

#include <stdint.h>
#include <sys/ioctl.h>
#include <linux/falloc.h>
#include <linux/types.h>

#ifndef BLKGETDISKSEQ
#define BLKGETDISKSEQ _IO(0x12, 128)
#endif
#ifndef BLKROGET
#define BLKROGET       0x0000125E
#endif
#ifndef BLKROSET
#define BLKROSET       0x0000125D
#endif

/* Inode flags (FS_IOC_GETFLAGS / FS_IOC_SETFLAGS) */
#ifndef FS_SECRM_FL
#define FS_SECRM_FL             0x00000001
#endif
#ifndef FS_UNRM_FL
#define FS_UNRM_FL              0x00000002
#endif
#ifndef FS_COMPR_FL
#define FS_COMPR_FL             0x00000004
#endif
#ifndef FS_SYNC_FL
#define FS_SYNC_FL              0x00000008
#endif
#ifndef FS_IMMUTABLE_FL
#define FS_IMMUTABLE_FL         0x00000010
#endif
#ifndef FS_APPEND_FL
#define FS_APPEND_FL            0x00000020
#endif
#ifndef FS_NODUMP_FL
#define FS_NODUMP_FL            0x00000040
#endif
#ifndef FS_NOATIME_FL
#define FS_NOATIME_FL           0x00000080
#endif
#ifndef FS_DIRSYNC_FL
#define FS_DIRSYNC_FL           0x00000100
#endif
#ifndef FS_PROJINHERIT_FL
#define FS_PROJINHERIT_FL       0x00000200
#endif
#ifndef FS_VERITY_FL
#define FS_VERITY_FL            0x00100000
#endif
#ifndef FS_NOCOW_FL
#define FS_NOCOW_FL             0x00800000
#endif
#ifndef FS_CASEFOLD_FL
#define FS_CASEFOLD_FL          0x40000000
#endif
#ifndef FS_NOCOMP_FL
#define FS_NOCOMP_FL            0x00000400
#endif
#ifndef FS_EXTENT_FL
#define FS_EXTENT_FL            0x00080000
#endif
#ifndef FS_JOURNAL_DATA_FL
#define FS_JOURNAL_DATA_FL      0x00004000
#endif
#ifndef FS_NOTAIL_FL
#define FS_NOTAIL_FL            0x00008000
#endif
#ifndef FS_TOPDIR_FL
#define FS_TOPDIR_FL            0x00020000
#endif

/* FS_XFLAG_* flags for FS_IOC_FSGETXATTR/FSSETXATTR */
#ifndef FS_XFLAG_PROJINHERIT
#define FS_XFLAG_PROJINHERIT    0x00000200
#endif

/* FS_IOC_GETFLAGS / FS_IOC_SETFLAGS ioctl numbers */
#ifndef FS_IOC_GETFLAGS
#define FS_IOC_GETFLAGS         _IOR('f', 1, long)
#endif
#ifndef FS_IOC_SETFLAGS
#define FS_IOC_SETFLAGS         _IOW('f', 2, long)
#endif
#ifndef FS_IOC_GETVERSION
#define FS_IOC_GETVERSION       _IOR('v', 1, long)
#endif
#ifndef FS_IOC_SETVERSION
#define FS_IOC_SETVERSION       _IOW('v', 2, long)
#endif
#ifndef FS_IOC_FSGETXATTR
#define FS_IOC_FSGETXATTR       _IOR('X', 31, struct fsxattr)
#endif
#ifndef FS_IOC_FSSETXATTR
#define FS_IOC_FSSETXATTR       _IOW('X', 32, struct fsxattr)
#endif

/* File seal types (memfd_create / F_ADD_SEALS) */
#ifndef F_SEAL_SEAL
#define F_SEAL_SEAL             0x0001
#endif
#ifndef F_SEAL_SHRINK
#define F_SEAL_SHRINK           0x0002
#endif
#ifndef F_SEAL_GROW
#define F_SEAL_GROW             0x0004
#endif
#ifndef F_SEAL_WRITE
#define F_SEAL_WRITE            0x0008
#endif
#ifndef F_SEAL_EXEC
#define F_SEAL_EXEC             0x0010
#endif
#ifndef F_SEAL_FUTURE_EXEC
#define F_SEAL_FUTURE_EXEC      0x0020
#endif

/* OFD lock commands */
#ifndef F_OFD_SETLK
#define F_OFD_SETLK             37
#endif
#ifndef F_OFD_SETLKW
#define F_OFD_SETLKW            38
#endif
#ifndef F_OFD_GETLK
#define F_OFD_GETLK             36
#endif

/* Inline encryption */
#ifndef FS_KEY_DESCRIPTOR_SIZE
#define FS_KEY_DESCRIPTOR_SIZE  8
#endif

/* RENAME_* flags (used by renameat2) */
#ifndef RENAME_NOREPLACE
#define RENAME_NOREPLACE        (1 << 0)
#endif
#ifndef RENAME_EXCHANGE
#define RENAME_EXCHANGE         (1 << 1)
#endif
#ifndef RENAME_WHITEOUT
#define RENAME_WHITEOUT         (1 << 2)
#endif

/* struct fsxattr for FS_IOC_FSGETXATTR/FSSETXATTR */
#ifndef HAVE_FSXATTR
struct fsxattr {
        uint32_t        fsx_xflags;
        uint32_t        fsx_extsize;
        uint32_t        fsx_nextents;
        uint32_t        fsx_projid;
        uint32_t        fsx_cowextsize;
        unsigned char   fsx_pad[8];
};
#endif

/* File handle types for name_to_handle_at / open_by_handle_at */
#ifndef FILEID_KERNFS
#define FILEID_KERNFS 0xfe
#endif
#ifndef FILEID_NSFS
#define FILEID_NSFS 0xf1
#endif

/* Block device ioctls */
#ifndef BLKSSZGET
#define BLKSSZGET       0x00001268
#endif
#ifndef BLKGETSIZE64
#define BLKGETSIZE64    0x00001204
#endif
#ifndef BLKDISCARD
#define BLKDISCARD      0x00001277
#endif
#ifndef BLKZEROOUT
#define BLKZEROOUT      0x0000127F
#endif
#ifndef BLKRRPART
#define BLKRRPART       _IO(0x12, 95)
#endif
#ifndef EXT4_IOC_RESIZE_FS
#define EXT4_IOC_RESIZE_FS      _IOW('f', 16, __u64)
#endif
