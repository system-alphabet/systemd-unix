/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Linux <linux/nvme_ioctl.h> — NVMe admin/IO pass-through ioctl UAPI.
 *
 * FreeBSD's nvme(4) exposes a different pass-through interface (NVME_PASSTHROUGH_CMD
 * with struct nvme_pt_command in <dev/nvme/nvme.h>) that does not transfer log-page
 * data to userspace, so there is no equivalent shim for the Linux ioctl. Reuse the
 * vendored UAPI definitions instead: the code compiles unchanged and the ioctl
 * request number simply does not match any FreeBSD command, so it fails with ENOTTY
 * at runtime and the caller skips the device gracefully.
 */

#include "../../uapi/linux/nvme_ioctl.h"
