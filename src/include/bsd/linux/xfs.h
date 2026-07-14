/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/* Minimal stub for Linux XFS filesystem definitions.
 * XFS is Linux-specific; FreeBSD has UFS/ZFS instead. */

#include <stdint.h>
#include <linux/types.h>

#define XFS_IOC_FSGEOMETRY       _IOR('X', 125, struct xfs_fsop_geom)
#define XFS_IOC_FSGROWFSDATA     _IOW('X', 110, struct xfs_growfs_data)

struct xfs_fsop_geom {
        uint32_t blocksize;
        uint32_t rtextsize;
        uint32_t agblocks;
        uint32_t agcount;
        uint32_t logblocks;
        uint32_t sectsize;
        uint32_t inodesize;
        uint32_t imaxpct;
        uint64_t datablocks;
        uint64_t rtblocks;
        uint64_t rtextents;
        uint64_t logstart;
        unsigned char uuid[16];
        uint32_t sunit;
        uint32_t swidth;
        int32_t version;
        uint32_t flags;
        uint32_t logsectsize;
        uint32_t rtsectsize;
        uint32_t dirblocksize;
        uint32_t logsunit;
};

typedef struct xfs_fsop_geom xfs_fsop_geom_t;

struct xfs_growfs_data {
        uint64_t newblocks;
        uint32_t imaxpct;
};

typedef struct xfs_growfs_data xfs_growfs_data_t;
