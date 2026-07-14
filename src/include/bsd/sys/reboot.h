#pragma once

#include <linux/reboot.h>

/* Linux <sys/reboot.h> provides RB_* aliases for the LINUX_REBOOT_CMD_* constants.
 * FreeBSD's native <sys/reboot.h> uses different values (0x0, 0x1, 0x2), so we
 * override it entirely to match the Linux semantics used by systemd code. */

#define RB_AUTOBOOT       LINUX_REBOOT_CMD_RESTART
#define RB_HALT_SYSTEM    LINUX_REBOOT_CMD_HALT
#define RB_POWER_OFF      LINUX_REBOOT_CMD_POWER_OFF
#define RB_ENABLE_CAD     LINUX_REBOOT_CMD_CAD_ON
#define RB_DISABLE_CAD    LINUX_REBOOT_CMD_CAD_OFF
#define RB_SW_SUSPEND     LINUX_REBOOT_CMD_SW_SUSPEND
#define RB_KEXEC          LINUX_REBOOT_CMD_KEXEC
#define RB_HALT           0x1
#define RB_POWEROFF       0x2
