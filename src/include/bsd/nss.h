/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Minimal <nss.h> for FreeBSD — provides the glibc NSS types used by
 * systemd's nss-myhostname module and its test.
 *
 * On FreeBSD, there is no glibc-style Name Service Switch.
 */

#include <stdint.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Possible results of lookup using a nss_* function.  */
enum nss_status {
        NSS_STATUS_TRYAGAIN = -2,
        NSS_STATUS_UNAVAIL,
        NSS_STATUS_NOTFOUND,
        NSS_STATUS_SUCCESS,
        NSS_STATUS_RETURN
};

/* Data structure used for the 'gethostbyname4_r' function.  */
struct gaih_addrtuple {
        struct gaih_addrtuple *next;
        char *name;
        int family;
        uint32_t addr[4];
        uint32_t scopeid;
};

#ifdef __cplusplus
}
#endif
