#pragma once

#include <linux/types.h>
#include <stdint.h>

/* UNIX_DIAG_* constants */
#define UDIAG_SHOW_RQLEN   0x00000400
#define UDIAG_SHOW_NAME    0x00000002
#define UDIAG_SHOW_VFS     0x00000008

#define UNIX_DIAG_NAME     0x00000000
#define UNIX_DIAG_PEER     0x00000001
#define UNIX_DIAG_RQLEN    0x00000008
#define UNIX_DIAG_VFS      0x00000009

struct unix_diag_req {
        uint8_t  sdiag_family;
        uint8_t  sdiag_protocol;
        uint16_t pad;
        uint32_t udiag_states;
        uint32_t udiag_ino;
        uint32_t udiag_show;
        uint32_t udiag_cookie[2];
};

struct unix_diag_msg {
        uint8_t  udiag_family;
        uint8_t  udiag_type;
        uint8_t  udiag_state;
        uint8_t  pad;
        uint32_t udiag_ino;
        uint32_t udiag_cookie[2];
};

struct unix_diag_vfs {
        uint32_t udiag_vfs_dev;
        uint32_t udiag_vfs_ino;
};

struct unix_diag_rqlen {
        uint32_t udiag_rqueue;
        uint32_t udiag_wqueue;
};
