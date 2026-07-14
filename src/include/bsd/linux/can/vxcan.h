/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

enum {
        VXCAN_INFO_UNSPEC,
        VXCAN_INFO_PEER,
        __VXCAN_INFO_MAX,
};
#define VXCAN_INFO_MAX (__VXCAN_INFO_MAX - 1)
