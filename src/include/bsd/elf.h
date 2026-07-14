/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <elf.h>

#ifndef AT_SECURE
#define AT_SECURE 23
#endif
