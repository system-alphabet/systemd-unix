/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#define IOPRIO_CLASS_NONE      0
#define IOPRIO_CLASS_RT        1
#define IOPRIO_CLASS_BE        2
#define IOPRIO_CLASS_IDLE      3
#define IOPRIO_NR_CLASSES      4

#define IOPRIO_PRIO_MASK       ((1UL << 13) - 1)
#define IOPRIO_PRIO_CLASS(mask) ((mask) >> 13)
#define IOPRIO_PRIO_DATA(mask)  ((mask) & IOPRIO_PRIO_MASK)
#define IOPRIO_PRIO_VALUE(class, data)  (((class) << 13) | (data))

#define IOPRIO_PRIO_LEVEL(prio)  ((prio) & 7)
#define IOPRIO_PRIO_HINT(prio)   (((prio) >> 3) & 0x3f)
#define IOPRIO_PRIO_VALUE_HINT(class, level, hint) \
        (((class) << 13) | ((hint) << 3) | (level))

#define IOPRIO_NR_LEVELS  8
#define IOPRIO_LEVEL_MULTIPLIER  (1 << 3)

#define IOPRIO_WHO_PROCESS    0
#define IOPRIO_WHO_PGRP       1
#define IOPRIO_WHO_USER       2
