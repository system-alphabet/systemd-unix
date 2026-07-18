/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <errno.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "sd-id128.h"
#include "forward.h"

#include "copy.h"
#include "../basic/btrfs-util.h"      /* IWYU pragma: export */

typedef struct BtrfsSubvolInfo {
        uint64_t subvol_id;
        usec_t otime; /* creation time */
        usec_t ctime; /* change time */

        sd_id128_t uuid;
        sd_id128_t parent_uuid;

        bool read_only;
} BtrfsSubvolInfo;

typedef struct BtrfsQuotaInfo {
        uint64_t referenced;
        uint64_t exclusive;
        uint64_t referenced_max;
        uint64_t exclusive_max;
} BtrfsQuotaInfo;

typedef enum BtrfsSnapshotFlags {
        BTRFS_SNAPSHOT_FALLBACK_COPY      = 1 << 0, /* If the source isn't a subvolume, reflink everything */
        BTRFS_SNAPSHOT_READ_ONLY          = 1 << 1,
        BTRFS_SNAPSHOT_RECURSIVE          = 1 << 2,
        BTRFS_SNAPSHOT_QUOTA              = 1 << 3,
        BTRFS_SNAPSHOT_FALLBACK_DIRECTORY = 1 << 4, /* If the destination doesn't support subvolumes, reflink/copy instead */
        BTRFS_SNAPSHOT_FALLBACK_IMMUTABLE = 1 << 5, /* When we can't create a subvolume, use the FS_IMMUTABLE attribute for indicating read-only */
        BTRFS_SNAPSHOT_SIGINT             = 1 << 6, /* Check for SIGINT regularly, and return EINTR if seen */
        BTRFS_SNAPSHOT_SIGTERM            = 1 << 7, /* Ditto, but for SIGTERM */
        BTRFS_SNAPSHOT_LOCK_BSD           = 1 << 8, /* Return a BSD exclusively locked file descriptor referring to snapshot subvolume/directory. */
} BtrfsSnapshotFlags;

typedef enum BtrfsRemoveFlags {
        BTRFS_REMOVE_RECURSIVE = 1 << 0,
        BTRFS_REMOVE_QUOTA     = 1 << 1,
} BtrfsRemoveFlags;

static inline int btrfs_is_subvol_at(int dir_fd, const char *path) {
        return 0;
}
static inline int btrfs_is_subvol_fd(int fd) {
        return 0;
}
static inline int btrfs_is_subvol(const char *path) {
        return 0;
}

static inline int btrfs_get_block_device_at_full(int dir_fd, const char *path, uint64_t *ret_devid, char **ret_path, dev_t *ret) {
        return -ENOTTY;
}
static inline int btrfs_get_block_device_at(int dir_fd, const char *path, dev_t *ret) {
        return -ENOTTY;
}
static inline int btrfs_get_block_device(const char *path, dev_t *ret) {
        return -ENOTTY;
}
static inline int btrfs_get_block_device_fd(int fd, dev_t *ret) {
        return -ENOTTY;
}

static inline int btrfs_defrag_fd(int fd) {
        return -ENOTTY;
}
static inline int btrfs_defrag(const char *p) {
        return -ENOTTY;
}

static inline int btrfs_quota_enable_fd(int fd, bool b) {
        return -ENOTTY;
}
static inline int btrfs_quota_enable(const char *path, bool b) {
        return -ENOTTY;
}

static inline int btrfs_quota_scan_start(int fd) {
        return -ENOTTY;
}
static inline int btrfs_quota_scan_wait(int fd) {
        return -ENOTTY;
}
static inline int btrfs_quota_scan_ongoing(int fd) {
        return false;
}

static inline int btrfs_subvol_snapshot_at_full(
                int dir_fdf, const char *from,
                int dir_fdt, const char *to,
                BtrfsSnapshotFlags flags,
                copy_progress_path_t progress_path,
                copy_progress_bytes_t progress_bytes,
                void *userdata) {

        if (!(flags & (BTRFS_SNAPSHOT_FALLBACK_COPY | BTRFS_SNAPSHOT_FALLBACK_DIRECTORY)))
                return -ENOTTY;

        CopyFlags copy_flags = COPY_SAME_MOUNT | COPY_HARDLINKS | COPY_ALL_XATTRS |
                (FLAGS_SET(flags, BTRFS_SNAPSHOT_SIGINT) ? COPY_SIGINT : 0) |
                (FLAGS_SET(flags, BTRFS_SNAPSHOT_SIGTERM) ? COPY_SIGTERM : 0);

        return copy_tree_at_full(dir_fdf, from, dir_fdt, to,
                                 UID_INVALID, UID_INVALID, copy_flags,
                                 NULL, NULL, progress_path, progress_bytes, userdata);
}
static inline int btrfs_subvol_snapshot_at(int dir_fdf, const char *from, int dir_fdt, const char *to, BtrfsSnapshotFlags flags) {
        return btrfs_subvol_snapshot_at_full(dir_fdf, from, dir_fdt, to, flags, NULL, NULL, NULL);
}

static inline int btrfs_subvol_remove_at(int dir_fd, const char *path, BtrfsRemoveFlags flags) {
        return -ENOTTY;
}
static inline int btrfs_subvol_remove(const char *path, BtrfsRemoveFlags flags) {
        return -ENOTTY;
}

static inline int btrfs_subvol_set_read_only_at(int dir_fd, const char *path, bool b) {
        return -ENOTTY;
}
static inline int btrfs_subvol_set_read_only_fd(int fd, bool b) {
        return -ENOTTY;
}
static inline int btrfs_subvol_set_read_only(const char *path, bool b) {
        return -ENOTTY;
}

static inline int btrfs_subvol_get_read_only_fd(int fd) {
        return -ENOTTY;
}

static inline int btrfs_subvol_get_id(int fd, const char *subvolume, uint64_t *ret) {
        return -ENOTTY;
}
static inline int btrfs_subvol_get_id_fd(int fd, uint64_t *ret) {
        return -ENOTTY;
}
static inline int btrfs_subvol_get_parent(int fd, uint64_t subvol_id, uint64_t *ret) {
        return -ENOTTY;
}

static inline int btrfs_subvol_get_info_fd(int fd, uint64_t subvol_id, BtrfsSubvolInfo *ret) {
        return -ENOTTY;
}

static inline int btrfs_subvol_find_subtree_qgroup(int fd, uint64_t subvol_id, uint64_t *ret) {
        return -ENOTTY;
}

static inline int btrfs_subvol_get_subtree_quota(const char *path, uint64_t subvol_id, BtrfsQuotaInfo *ret) {
        return -ENOTTY;
}
static inline int btrfs_subvol_get_subtree_quota_fd(int fd, uint64_t subvol_id, BtrfsQuotaInfo *ret) {
        return -ENOTTY;
}

static inline int btrfs_subvol_set_subtree_quota_limit(const char *path, uint64_t subvol_id, uint64_t referenced_max) {
        return -ENOTTY;
}
static inline int btrfs_subvol_set_subtree_quota_limit_fd(int fd, uint64_t subvol_id, uint64_t referenced_max) {
        return -ENOTTY;
}

static inline int btrfs_subvol_auto_qgroup_fd(int fd, uint64_t subvol_id, bool insert_intermediary_qgroup) {
        return -ENOTTY;
}
static inline int btrfs_subvol_auto_qgroup(const char *path, uint64_t subvol_id, bool create_intermediary_qgroup) {
        return -ENOTTY;
}

static inline int btrfs_subvol_make_default(const char *path) {
        return -ENOSYS;
}

static inline int btrfs_qgroupid_make(uint64_t level, uint64_t id, uint64_t *ret) {
        return -ENOTTY;
}
static inline int btrfs_qgroupid_split(uint64_t qgroupid, uint64_t *level, uint64_t *id) {
        return -ENOTTY;
}

static inline int btrfs_qgroup_create(int fd, uint64_t qgroupid) {
        return -ENOTTY;
}
static inline int btrfs_qgroup_destroy(int fd, uint64_t qgroupid) {
        return -ENOTTY;
}
static inline int btrfs_qgroup_destroy_recursive(int fd, uint64_t qgroupid) {
        return -ENOTTY;
}

static inline int btrfs_qgroup_set_limit_fd(int fd, uint64_t qgroupid, uint64_t referenced_max) {
        return -ENOTTY;
}
static inline int btrfs_qgroup_set_limit(const char *path, uint64_t qgroupid, uint64_t referenced_max) {
        return -ENOTTY;
}

static inline int btrfs_qgroup_copy_limits(int fd, uint64_t old_qgroupid, uint64_t new_qgroupid) {
        return -ENOTTY;
}

static inline int btrfs_qgroup_assign(int fd, uint64_t child, uint64_t parent) {
        return -ENOTTY;
}
static inline int btrfs_qgroup_unassign(int fd, uint64_t child, uint64_t parent) {
        return -ENOTTY;
}

static inline int btrfs_qgroup_find_parents(int fd, uint64_t qgroupid, uint64_t **ret) {
        return -ENOTTY;
}

static inline int btrfs_qgroup_get_quota_fd(int fd, uint64_t qgroupid, BtrfsQuotaInfo *ret) {
        return -ENOTTY;
}
static inline int btrfs_qgroup_get_quota(const char *path, uint64_t qgroupid, BtrfsQuotaInfo *ret) {
        return -ENOTTY;
}

static inline int btrfs_log_dev_root(int level, int ret, const char *p) {
        return -ENOTTY;
}

static inline bool btrfs_might_be_subvol(const struct stat *st) {
        return false;
}

static inline int btrfs_forget_device(const char *path) {
        return -ENOTTY;
}

static inline int btrfs_get_file_physical_offset_fd(int fd, uint64_t *ret) {
        return -ENOTTY;
}

static inline int btrfs_replace(int fdmntpnt, uint64_t device_id, const char *target) {
        return -ENOTTY;
}
static inline int btrfs_resize_max(int fdmntpnt, uint64_t devid) {
        return -ENOTTY;
}
