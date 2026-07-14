#pragma once

#include <linux/ioctl.h>

/* Keyboard mode constants */
#define K_XLATE         0x01
#define K_MEDIUMRAW     0x02
#define K_RAW           0x03
#define K_UNICODE       0x0B
#define K_OFF           0x0C

/* Keyboard actions */
#define KDSKBMODE       0x4B45
#define KDSETMODE       0x4B3A
#define KD_TEXT         0x00
#define KD_GRAPHICS     0x01
#define KD_ADD_MULTI     0x4B55
#define KD_MAP_DISP      0x4B57
#define KD_UNMAP_DISP    0x4B58
#define KIOCSOUND       0x4B2F
#define KDMKTONE        0x4B30

/* Keyboard LED ioctls */
#define KDSETLED        0x4B32
#define KDGETLED        0x4B31
#define LED_SCR         0x01
#define LED_NUM         0x02
#define LED_CAP         0x04

/* Console font operations */
struct console_font_op {
        unsigned int op;
        unsigned int flags;
        unsigned int width;
        unsigned int height;
        unsigned int charcount;
        unsigned char *data;
};

#define KD_FONT_OP_GET          0x01
#define KD_FONT_OP_SET          0x02
#define KD_FONT_OP_SET_DEFAULT  0x03
#define KD_FONT_OP_COPY         0x04

#define KDFONTOP        _IOWR('K', 0x4B, struct console_font_op)

/* Unicode map structures */
struct unimapinit {
        unsigned short advised_hash_size;
        unsigned short advised_hash_step;
        unsigned short advised_hash_level;
};

struct unipair {
        unsigned short unicode;
        unsigned short fontpos;
};

struct unimapdesc {
        unsigned short entry_ct;
        struct unipair *entries;
};

/* Unicode map ioctls */
#define GIO_UNIMAP      0x4B66
#define PIO_UNIMAP      0x4B67
#define PIO_UNIMAPCLR   0x4B68

/* Font ioctls */
#define PIO_FONT        0x4B60
#define GIO_FONT        0x4B61
#define PIO_CMAP        0x4B70
#define GIO_CMAP        0x4B71
#define KD_FONT_FLAG_OLD 0x80000000
#define KD_FONT_FLAG_DONT_RECALC 1
