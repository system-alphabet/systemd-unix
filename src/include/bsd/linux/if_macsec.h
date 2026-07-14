/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <stdint.h>

#define MACSEC_GENL_NAME        "macsec"
#define MACSEC_KEYID_LEN        8
#define MACSEC_MAX_KEY_LEN      128

enum {
        MACSEC_ATTR_UNSPEC,
        MACSEC_ATTR_IFINDEX,
        MACSEC_ATTR_RXSC_CONFIG,
        MACSEC_ATTR_SA_CONFIG,
        __MACSEC_ATTR_MAX,
};
#define MACSEC_ATTR_MAX (__MACSEC_ATTR_MAX - 1)

enum {
        MACSEC_RXSC_ATTR_UNSPEC,
        MACSEC_RXSC_ATTR_SCI,
        __MACSEC_RXSC_ATTR_MAX,
};
#define MACSEC_RXSC_ATTR_MAX (__MACSEC_RXSC_ATTR_MAX - 1)

enum {
        MACSEC_SA_ATTR_UNSPEC,
        MACSEC_SA_ATTR_AN,
        MACSEC_SA_ATTR_ACTIVE,
        MACSEC_SA_ATTR_PN,
        MACSEC_SA_ATTR_KEY,
        MACSEC_SA_ATTR_KEYID,
        __MACSEC_SA_ATTR_MAX,
};
#define MACSEC_SA_ATTR_MAX (__MACSEC_SA_ATTR_MAX - 1)
