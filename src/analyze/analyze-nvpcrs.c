/* SPDX-License-Identifier: LGPL-2.1-or-later */

#include "alloc-util.h"
#include "analyze-nvpcrs.h"
#include "analyze.h"
#include "conf-files.h"
#include "constants.h"
#include "format-table.h"
#include "hexdecoct.h"
#include "strv.h"

int verb_nvpcrs(int argc, char *argv[], uintptr_t _data, void *userdata) {
        return log_error_errno(SYNTHETIC_ERRNO(EOPNOTSUPP), "TPM2 support not enabled at build time.");
}
