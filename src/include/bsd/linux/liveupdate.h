/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <linux/types.h>

#define LIVEUPDATE_IOCTL_TYPE   0xF6
#define LIVEUPDATE_SESSION_NAME_LENGTH 64

enum {
        LIVEUPDATE_CMD_CREATE_SESSION = 0x40,
        LIVEUPDATE_CMD_RETRIEVE_SESSION = 0x41,
        LIVEUPDATE_CMD_SESSION_PRESERVE_FD = 0x42,
        LIVEUPDATE_CMD_SESSION_RETRIEVE_FD = 0x43,
        LIVEUPDATE_CMD_SESSION_FINISH = 0x44,
        LIVEUPDATE_CMD_SESSION_GET_NAME = 0x45,
};

struct liveupdate_ioctl_create_session {
        __u32           size;
        __s32           fd;
        __u8            name[LIVEUPDATE_SESSION_NAME_LENGTH];
};

#define LIVEUPDATE_IOCTL_CREATE_SESSION \
        _IO(LIVEUPDATE_IOCTL_TYPE, LIVEUPDATE_CMD_CREATE_SESSION)

struct liveupdate_ioctl_retrieve_session {
        __u32           size;
        __s32           fd;
        __u8            name[LIVEUPDATE_SESSION_NAME_LENGTH];
};

#define LIVEUPDATE_IOCTL_RETRIEVE_SESSION \
        _IO(LIVEUPDATE_IOCTL_TYPE, LIVEUPDATE_CMD_RETRIEVE_SESSION)

struct liveupdate_session_preserve_fd {
        __u32           size;
        __s32           fd;
        __u64           token;
};

#define LIVEUPDATE_SESSION_PRESERVE_FD \
        _IO(LIVEUPDATE_IOCTL_TYPE, LIVEUPDATE_CMD_SESSION_PRESERVE_FD)

struct liveupdate_session_retrieve_fd {
        __u32           size;
        __s32           fd;
        __u64           token;
};

#define LIVEUPDATE_SESSION_RETRIEVE_FD \
        _IO(LIVEUPDATE_IOCTL_TYPE, LIVEUPDATE_CMD_SESSION_RETRIEVE_FD)

struct liveupdate_session_finish {
        __u32           size;
};

#define LIVEUPDATE_SESSION_FINISH \
        _IO(LIVEUPDATE_IOCTL_TYPE, LIVEUPDATE_CMD_SESSION_FINISH)

struct liveupdate_session_get_name {
        __u32           size;
        __u8            name[LIVEUPDATE_SESSION_NAME_LENGTH];
};

#define LIVEUPDATE_SESSION_GET_NAME \
        _IO(LIVEUPDATE_IOCTL_TYPE, LIVEUPDATE_CMD_SESSION_GET_NAME)
