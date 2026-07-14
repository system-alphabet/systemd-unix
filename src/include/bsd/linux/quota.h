/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <stdint.h>

/* Minimal Linux quota types — used by quota-util.c for dqblk fields */

/* linux/quota.h: QIF_* flags */
#define QIF_BLIMITS     (1 << 0)
#define QIF_SPACE       (1 << 1)
#define QIF_ILIMITS     (1 << 2)
#define QIF_INODES      (1 << 3)
#define QIF_BTIME       (1 << 4)
#define QIF_ITIME       (1 << 5)
#define QIF_LIMITS      (QIF_BLIMITS | QIF_ILIMITS)
#define QIF_USAGE       (QIF_SPACE | QIF_INODES)
#define QIF_TIMES       (QIF_BTIME | QIF_ITIME)
#define QIF_ALL         (QIF_LIMITS | QIF_USAGE | QIF_TIMES)

struct dqblk {
        uint64_t dqb_bhardlimit;
        uint64_t dqb_bsoftlimit;
        uint64_t dqb_curspace;
        uint64_t dqb_ihardlimit;
        uint64_t dqb_isoftlimit;
        uint64_t dqb_curinodes;
        uint64_t dqb_btime;
        uint64_t dqb_itime;
        uint32_t dqb_valid;
};
