/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/* OOM score adjustment constants for Linux /proc/self/oom_score_adj.
 * Used by src/basic/process-util.c. */

#ifndef OOM_SCORE_ADJ_MIN
#define OOM_SCORE_ADJ_MIN (-1000)
#endif
#ifndef OOM_SCORE_ADJ_MAX
#define OOM_SCORE_ADJ_MAX 1000
#endif
