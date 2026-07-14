/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <stdint.h>
#include <linux/types.h>

/* Minimal Linux audit subsystem stub for FreeBSD compatibility. */

#define AUDIT_SYSCALL          1300
#define AUDIT_ANOM_ABEND       1701
#define AUDIT_USER_CMD         2100

#define AUDIT_FILTER_USER      0x00
#define AUDIT_FILTER_TASK      0x01
#define AUDIT_FILTER_ENTRY     0x02
#define AUDIT_FILTER_WATCH     0x03
#define AUDIT_FILTER_EXIT      0x04
#define AUDIT_FILTER_EXCLUDE   0x05

#define AUDIT_NEVER            0
#define AUDIT_POSSIBLE         1
#define AUDIT_ALWAYS           2

#define AUDIT_STATUS_ENABLED           0x0001
#define AUDIT_STATUS_FAILURE           0x0010
#define AUDIT_STATUS_PID               0x0020
#define AUDIT_STATUS_RATE_LIMIT        0x0040
#define AUDIT_STATUS_BACKLOG_LIMIT     0x0080

#define AUDIT_FEATURE_BITMAP_BACKLOG_LIMIT 0x01

struct audit_status {
        uint32_t mask;
        uint32_t enabled;
        uint32_t failure;
        uint32_t pid;
        uint32_t rate_limit;
        uint32_t backlog_limit;
        uint32_t lost;
        uint32_t backlog;
        uint32_t feature_bitmap;
};

#define AUDIT_ARCH_X86_64       (62 | (1 << 8))  /* EM_X86_64 */

#define AUDIT_RULE_ADD          1
#define AUDIT_DEL               2
#define AUDIT_LIST              3
#define AUDIT_ADD_RULE          11
#define AUDIT_DEL_RULE          12
#define AUDIT_LIST_RULES        13
#define AUDIT_GET_FEATURE       20
#define AUDIT_SET_FEATURE       21

#define AUDIT_MAX_FIELDS        64

#define AUDIT_EQUAL             0
#define AUDIT_NOT_EQUAL         1
#define AUDIT_BIT_MASK          2
#define AUDIT_LESS_THAN         3
#define AUDIT_GREATER_THAN      4
#define AUDIT_NEGATE            0x80000000

#define AUDIT_UID               5003
#define AUDIT_GID               5004
#define AUDIT_LOGINUID          5005
#define AUDIT_SUBJ_USER         5012
#define AUDIT_SUBJ_ROLE         5013
#define AUDIT_SUBJ_TYPE         5014
#define AUDIT_SUBJ_SEN          5015
#define AUDIT_SUBJ_CLR          5016
#define AUDIT_OBJ_USER          5017
#define AUDIT_OBJ_ROLE          5018
#define AUDIT_OBJ_TYPE          5019
#define AUDIT_OBJ_LEV_LOW       5020
#define AUDIT_OBJ_LEV_HIGH      5021
#define AUDIT_MSGTYPE           5030
#define AUDIT_EXE               5040

#define AUDIT_PERS              9000
#define AUDIT_ARCH              9001
#define AUDIT_MSGTYPE           5030
#define AUDIT_SUCCESS           9002
#define AUDIT_INODE             9003
#define AUDIT_EXIT              9004
#define AUDIT_SYSCALL           9005
#define AUDIT_A0                9006
#define AUDIT_A1                9007
#define AUDIT_A2                9008
#define AUDIT_A3                9009

#define AUDIT_KEY               10000
#define AUDIT_FIELD_COMPARE     11000

#define AUDIT_COMPARE_UID_TO_OBJ_UID    1
#define AUDIT_COMPARE_GID_TO_OBJ_GID    2
#define AUDIT_COMPARE_EUID_TO_OBJ_UID   3
#define AUDIT_COMPARE_EGID_TO_OBJ_GID   4
#define AUDIT_COMPARE_AUID_TO_OBJ_UID   5
#define AUDIT_COMPARE_SUID_TO_OBJ_UID   6
#define AUDIT_COMPARE_SGID_TO_OBJ_GID   7
#define AUDIT_COMPARE_AUID_TO_SUBJ_UID  8
#define AUDIT_COMPARE_AUID_TO_OBJ_UID   9

#define AUDIT_BITMASK_SIZE 64

struct audit_rule_data {
        uint32_t flags;
        uint32_t action;
        uint32_t field_count;
        uint32_t mask[AUDIT_BITMASK_SIZE];
        uint32_t fields[AUDIT_MAX_FIELDS];
        uint32_t values[AUDIT_MAX_FIELDS];
        uint32_t fieldflags[AUDIT_MAX_FIELDS];
        uint32_t buflen;
        char     buf[0];
};
