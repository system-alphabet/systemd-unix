/* SPDX-License-Identifier: LGPL-2.1-or-later */

#include <unistd.h>

#include "alloc-util.h"
#include "analyze.h"
#include "analyze-pcrs.h"
#include "ansi-color.h"
#include "fileio.h"
#include "format-table.h"
#include "hexdecoct.h"
#include "log.h"
#include "strv.h"

int verb_pcrs(int argc, char *argv[], uintptr_t _data, void *userdata) {
        return log_error_errno(SYNTHETIC_ERRNO(EOPNOTSUPP), "TPM2 support not enabled at build time.");
}
