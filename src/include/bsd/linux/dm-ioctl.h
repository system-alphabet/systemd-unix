/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <stdint.h>
#include <linux/types.h>

/* Device-mapper ioctl structures and constants (minimal stub). */

#define DM_MAX_TYPE_NAME 16

#define DM_DEV_CREATE     _IO(0xfd, 0)
#define DM_DEV_REMOVE     _IO(0xfd, 1)
#define DM_DEV_STATUS     _IO(0xfd, 7)
#define DM_TABLE_LOAD     _IO(0xfd, 9)
#define DM_TABLE_STATUS   _IO(0xfd, 10)
#define DM_DEV_SUSPEND    _IO(0xfd, 11)
#define DM_DEV_WAIT       _IO(0xfd, 13)
#define DM_TABLE_DEPS     _IO(0xfd, 14)
#define DM_TABLE_CLEAR    _IO(0xfd, 16)
#define DM_LIST_DEVICES   _IO(0xfd, 17)
#define DM_DEV_SET_GEOMETRY _IO(0xfd, 18)
#define DM_DEV_RENAME     _IO(0xfd, 21)
#define DM_DEV_ARM_POLL   _IO(0xfd, 24)

#define DM_EXISTS_FLAG            (1 << 0)
#define DM_PERSISTENT_DEV_FLAG    (1 << 3)
#define DM_READONLY_FLAG          (1 << 4)
#define DM_SUSPEND_FLAG           (1 << 5)

struct dm_ioctl {
        uint32_t version[3];
        uint32_t data_size;
        uint32_t data_start;
        uint32_t target_count;
        int32_t  open_count;
        uint32_t flags;
        uint32_t event_nr;
        uint32_t padding;
        uint64_t dev;
        char     name[DM_MAX_TYPE_NAME];
        char     uuid[DM_MAX_TYPE_NAME + 1];
        char     data[0];
};

struct dm_target_spec {
        uint64_t sector_start;
        uint64_t length;
        int32_t  status;
        uint32_t next;
        char     target_type[DM_MAX_TYPE_NAME];
};

struct dm_target_deps {
        uint32_t count;
        uint32_t padding;
        uint64_t dev[0];
};

struct dm_name_list {
        uint64_t dev;
        uint32_t next;
        char     name[0];
};

struct dm_target_msg {
        uint64_t sector;
        char     message[0];
};

#define DM_VERSION_MAJOR    4
#define DM_VERSION_MINOR    0
#define DM_VERSION_PATCHLEVEL 0
#define DM_TARGET_MSG       _IO(0xfd, 23)
