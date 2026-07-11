/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Minimal shim for Linux <gshadow.h> on FreeBSD.
 * Provides only the Linux-specific shadow group API types/functions,
 * WITHOUT conflicting with POSIX group functions (<grp.h>).
 */

#include <sys/types.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

struct sgrp {
        char *sg_namp;
        char *sg_passwd;
        char **sg_adm;
        char **sg_mem;
};

struct sgrp *sgetgrnam(const char *name);
struct sgrp *sgetgrent(void);
struct sgrp *fgetgrent(FILE *stream);
void setsgrent(void);
void endsgrent(void);
int putsgrent(const struct sgrp *sg, FILE *stream);

#ifdef __cplusplus
}
#endif
