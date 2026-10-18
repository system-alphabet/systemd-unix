/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <dirent.h>

/*
 * FreeBSD does not define struct dirent64 — it exists only on Linux.
 * Since systemd requires _FILE_OFFSET_BITS=64, FreeBSD's struct dirent
 * already uses 64-bit fields (d_fileno is __ino_t = uint64_t), so it
 * matches the layout of Linux's struct dirent64.
 *
 * Provide struct dirent64 with the same layout so assert_cc checks in
 * dirent-util.h can compile.  Note that FreeBSD's struct dirent uses
 * d_fileno for the inode number, but #defines d_ino as its alias.
 *
 * On Linux, <bits/dirent.h> already defines struct dirent64,
 * so guard this to avoid redefinition.
 */

#ifndef __linux__
#ifndef HAVE_STRUCT_DIRENT64
#define HAVE_STRUCT_DIRENT64 1

#if defined(__NetBSD__)
/*
 * NetBSD orders its dirent fields differently (d_fileno, d_reclen, d_namlen, d_type, d_name) and gives
 * d_name 512 bytes instead of FreeBSD's 256, so mirror that layout. NetBSD also has no d_off member at
 * all; <dirent-util.h> only ever takes its offset and size, and both are those of the inode field that
 * d_ino already maps onto, so alias it there rather than inventing a field that readdir() never fills.
 */
#ifndef d_off
#define d_off d_fileno
#endif

struct dirent64 {
        unsigned long long d_fileno;   /* inode number, aliased by d_ino and d_off */
        unsigned short     d_reclen;   /* length of this record */
        unsigned short     d_namlen;   /* length of string in d_name */
        unsigned char      d_type;     /* file type */
        char               d_name[512];
};
#else
/* FreeBSD fields: d_fileno(uint64), d_off(int64), d_reclen(uint16),
 * d_type(uint8), d_pad0(uint8), d_namlen(uint16), d_pad1(uint16),
 * d_name[256] */
struct dirent64 {
        unsigned long long d_ino;       /* inode number */
        long long          d_off;       /* directory offset */
        unsigned short     d_reclen;    /* length of this record */
        unsigned char      d_type;      /* file type */
        unsigned char      __d_pad0;
        unsigned short     d_namlen;    /* length of string in d_name */
        unsigned short     __d_pad1;
        char               d_name[256];
};
#endif
#endif
#endif
