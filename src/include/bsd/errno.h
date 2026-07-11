/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <errno.h>

/* Linux-specific errno values not present on FreeBSD.
 * Use values that avoid conflicts with existing FreeBSD errnos. */
#ifndef ENONET
#define ENONET 200
#endif
#ifndef ENOMEDIUM
#define ENOMEDIUM 123
#endif
#ifndef EBADFD
#define EBADFD 124
#endif
#ifndef ENODATA
#define ENODATA 201
#endif
#ifndef ESTRPIPE
#define ESTRPIPE 202
#endif
#ifndef EKEYREJECTED
#define EKEYREJECTED 203
#endif
#ifndef EBADR
#define EBADR 204
#endif
#ifndef ENOKEY
#define ENOKEY 205
#endif
#ifndef EUCLEAN
#define EUCLEAN 206
#endif
#ifndef EBADSLT
#define EBADSLT 207
#endif
#ifndef ENOANO
#define ENOANO 208
#endif
#ifndef ERFKILL
#define ERFKILL 209
#endif
#ifndef EMEDIUMTYPE
#define EMEDIUMTYPE 210
#endif
#ifndef ENOCSI
#define ENOCSI 211
#endif
#ifndef ENOSTR
#define ENOSTR 212
#endif
#ifndef EREMOTEIO
#define EREMOTEIO 213
#endif
#ifndef EUNATCH
#define EUNATCH 214
#endif
#ifndef ELIBBAD
#define ELIBBAD 215
#endif
#ifndef ENOPKG
#define ENOPKG 216
#endif
#ifndef ETIME
#define ETIME 217
#endif
#ifndef ECHRNG
#define ECHRNG 218
#endif
#ifndef ENOTUNIQ
#define ENOTUNIQ 220
#endif

/* FreeBSD defines ELAST == EINTEGRITY == 97, which causes duplicate
 * initializer errors in the errno-name table when combined with our
 * Linux errno shims.  Move ELAST past the highest value we define. */
#undef ELAST
#define ELAST 219

/* glibc provides program_invocation_short_name in <errno.h>. */
extern char *program_invocation_name;
extern char *program_invocation_short_name;
