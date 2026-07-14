/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <stdint.h>

struct blkpg_ioctl_arg {
    int op;
    int flags;
    int datalen;
    void *data;
};

struct blkpg_partition {
    int64_t start;
    int64_t length;
    int pno;
    char devname[64];
    char volname[64];
};

#define BLKPG_ADD_PARTITION 1
#define BLKPG_DEL_PARTITION 2
#define BLKPG_RESIZE_PARTITION 3

#define BLKPG 0x1269
