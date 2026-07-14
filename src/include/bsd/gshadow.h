/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <errno.h>
#include <stddef.h>
#include <shadow.h>

struct sgrp {
        char *sg_namp;
        char *sg_passwd;
        char **sg_adm;
        char **sg_mem;
};

static inline int getsgnam_r(
                const char *__name,
                struct sgrp *__result_buf,
                char *__buffer,
                size_t __buflen,
                struct sgrp **__result) {
        return EOPNOTSUPP;
}

/* Non-reentrant group shadow functions with stub implementations in misc.c */
int putsgent(const struct sgrp *sg, FILE *stream);
struct sgrp *fgetsgent(FILE *stream);
