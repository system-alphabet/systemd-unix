/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Linux <scsi/sg.h> — SCSI generic pass-through.
 * FreeBSD ships a Linux-compatible sg(4) implementation in <cam/scsi/scsi_sg.h>
 * with the same struct sg_io_hdr layout (interface_id, dxfer_direction, cmdp,
 * sbp, host_status, sb_len_wr, resid, ...) and the SG_IO / SG_DXFER_*
 * definitions, so forward to it. sys/types.h is needed for the u_int/u_char
 * typedefs used by the FreeBSD header.
 */

#include <sys/types.h>
#include <cam/scsi/scsi_sg.h>
