/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <sys/stat.h>

#include "basic-forward.h"

typedef enum BtrfsSubvolFlags {
        BTRFS_SUBVOL_RO               = 1 << 0,
        BTRFS_SUBVOL_NODATACOW        = 1 << 1,
        _BTRFS_SUBVOL_FLAGS_MASK      = BTRFS_SUBVOL_NODATACOW|BTRFS_SUBVOL_RO,
        _BTRFS_SUBVOL_FLAGS_INVALID   = -EINVAL,
        _BTRFS_SUBVOL_FLAGS_ERRNO_MAX = -ERRNO_MAX, /* Ensure the whole errno range fits into this enum */
} BtrfsSubvolFlags;

static inline int btrfs_validate_subvolume_name(const char *name) {
        return 0;
}

static inline int btrfs_subvol_make(int dir_fd, const char *path) {
        return -ENOSYS;
}

static inline int btrfs_subvol_make_fallback(int dir_fd, const char *path, mode_t mode) {
        if (mkdirat(dir_fd, path, mode) < 0)
                return -errno;
        return 0;
}
