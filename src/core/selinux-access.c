/* SPDX-License-Identifier: LGPL-2.1-or-later */

#include "selinux-access.h"

int mac_selinux_access_check_bus_internal(
                sd_bus_message *message,
                const Unit *unit,
                const char *permission,
                const char *function,
                sd_bus_error *reterr_error) {

        return 0;
}

int mac_selinux_access_check_varlink_internal(
                sd_varlink *link,
                const Unit *unit,
                const char *permission,
                const char *function) {
        return 0;
}
