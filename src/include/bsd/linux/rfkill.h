#pragma once

#include <linux/ioctl.h>
#include <stdint.h>

enum rfkill_type {
        RFKILL_TYPE_ALL = 0,
        RFKILL_TYPE_WLAN,
        RFKILL_TYPE_BLUETOOTH,
        RFKILL_TYPE_UWB,
        RFKILL_TYPE_WIMAX,
        RFKILL_TYPE_WWAN,
        RFKILL_TYPE_GPS,
        RFKILL_TYPE_FM,
        RFKILL_TYPE_NFC,
        NUM_RFKILL_TYPES,
};

enum rfkill_operation {
        RFKILL_OP_ADD = 0,
        RFKILL_OP_DEL,
        RFKILL_OP_CHANGE,
        RFKILL_OP_CHANGE_ALL,
};

enum rfkill_hard_block_reasons {
        RFKILL_HARD_BLOCK_REASON_RFKILL  = (1 << 0),
        RFKILL_HARD_BLOCK_REASON_EXPEDITED_SUSPEND     = (1 << 1),
        RFKILL_HARD_BLOCK_REASON_SLEEP_SUSPEND = (1 << 2),
        RFKILL_HARD_BLOCK_REASON_BTC0_INTERFERENCE = (1 << 3),
};

struct rfkill_event {
        uint32_t idx;
        uint8_t  type;
        uint8_t  op;
        uint8_t  soft;
        uint8_t  hard;
};

#define RFKILL_EVENT_SIZE_V1    8
#define RFKILL_IOC_MAGIC        'R'
#define RFKILL_IOC_NOINPUT      30
#define RFKILL_IOCTL_NOINPUT    _IO(RFKILL_IOC_MAGIC, RFKILL_IOC_NOINPUT)

struct rfkill_event_ext {
        uint32_t idx;
        uint8_t  type;
        uint8_t  op;
        uint8_t  soft;
        uint8_t  hard;
        uint32_t hard_block_reasons;
};
