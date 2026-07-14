/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/* Linux reboot() system call flags */
#define LINUX_REBOOT_MAGIC1     0xfee1dead
#define LINUX_REBOOT_MAGIC2     0x28121969
#define LINUX_REBOOT_CMD_RESTART        0x1234567
#define LINUX_REBOOT_CMD_HALT           0xCDEF0123
#define LINUX_REBOOT_CMD_POWER_OFF      0x4321FEDC
#define LINUX_REBOOT_CMD_RESTART2       0xA1B2C3D4
#define LINUX_REBOOT_CMD_SW_SUSPEND     0xD000FCE2
#define LINUX_REBOOT_CMD_CAD_ON         0x89ABCDEF
#define LINUX_REBOOT_CMD_CAD_OFF        0x00000000
#define LINUX_REBOOT_CMD_KEXEC          0x45584543

/* Reboot() for FreeBSD - we don't have Linux reboot, but define for compilation */
#define RB_AUTOBOOT     0x0
#define RB_HALT         0x1
#define RB_POWEROFF     0x2
