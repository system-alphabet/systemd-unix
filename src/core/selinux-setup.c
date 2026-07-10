/* SPDX-License-Identifier: LGPL-2.1-or-later */

#include "selinux-setup.h"

int mac_selinux_setup(bool *loaded_policy) {
        if (loaded_policy)
                *loaded_policy = false;
        return 0;
}
