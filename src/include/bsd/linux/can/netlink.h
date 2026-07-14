/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <stdint.h>

#define CAN_MAX_BITTIMING_CONST 32

enum {
        IFLA_CAN_UNSPEC,
        IFLA_CAN_BITTIMING,
        IFLA_CAN_BITTIMING_CONST,
        IFLA_CAN_CLOCK,
        IFLA_CAN_STATE,
        IFLA_CAN_CTRLMODE,
        IFLA_CAN_RESTART_MS,
        IFLA_CAN_RESTART,
        IFLA_CAN_BERR_COUNTER,
        IFLA_CAN_DATA_BITTIMING,
        IFLA_CAN_DATA_BITTIMING_CONST,
        IFLA_CAN_TERMINATION,
        IFLA_CAN_TERMINATION_CONST,
        IFLA_CAN_BITRATE_CONST,
        IFLA_CAN_DATA_BITRATE_CONST,
        IFLA_CAN_BITRATE_MAX,
        __IFLA_CAN_MAX,
};
#define IFLA_CAN_MAX (__IFLA_CAN_MAX - 1)

struct can_bittiming {
        uint32_t bitrate;
        uint32_t sample_point;
        uint32_t tq;
        uint32_t prop_seg;
        uint32_t phase_seg1;
        uint32_t phase_seg2;
        uint32_t sjw;
        uint32_t brp;
};

struct can_bittiming_const {
        char name[16];
        uint32_t tseg1_min;
        uint32_t tseg1_max;
        uint32_t tseg2_min;
        uint32_t tseg2_max;
        uint32_t sjw_max;
        uint32_t brp_min;
        uint32_t brp_max;
        uint32_t brp_inc;
};

struct can_clock {
        uint32_t freq;
};

struct can_ctrlmode {
        uint32_t mask;
        uint32_t flags;
};

struct can_berr_counter {
        uint16_t txerr;
        uint16_t rxerr;
};
