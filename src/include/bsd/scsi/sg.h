/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Linux <scsi/sg.h> — SCSI generic pass-through.
 *
 * FreeBSD ships a Linux-compatible sg(4) implementation in <cam/scsi/scsi_sg.h>
 * with the same struct sg_io_hdr layout (interface_id, dxfer_direction, cmdp,
 * sbp, host_status, sb_len_wr, resid, ...) and the SG_IO / SG_DXFER_*
 * definitions, so forward to it. sys/types.h is needed for the u_int/u_char
 * typedefs used by the FreeBSD header.
 *
 * NetBSD has no Linux-compatible sg(4): its SCSI pass-through is the older
 * scsireq_t/SCIOCCOMMAND interface with a different layout, so there is no
 * equivalent shim. Define the UAPI types verbatim instead: the code compiles
 * unchanged, and SG_IO does not match any NetBSD ioctl command, so it fails
 * with ENOTTY at runtime and the callers skip the device gracefully.
 */

#include <sys/types.h>

#if defined(__FreeBSD__)

#include <cam/scsi/scsi_sg.h>

#else

#include <sys/ioctl.h>

/* Same layout as the Linux sg v3 header and the FreeBSD <cam/scsi/scsi_sg.h>
 * struct sg_io_hdr, so callers compile against either. */
struct sg_io_hdr {
        int interface_id;           /* [i] 'S' for SCSI generic */
        int dxfer_direction;        /* [i] data transfer direction */
        unsigned char cmd_len;      /* [i] SCSI command length */
        unsigned char mx_sb_len;    /* [i] max length to write to sbp */
        unsigned short iovec_count; /* [i] 0 implies no iovecs */
        unsigned int dxfer_len;     /* [i] byte count of data transfer */
        void *dxferp;               /* [i] pointer to data transfer area */
        unsigned char *cmdp;        /* [i] pointer to SCSI command */
        unsigned char *sbp;         /* [i] pointer to sense return */
        unsigned int timeout;       /* [i] the timeout in milliseconds */
        unsigned int flags;         /* [i] other flags */
        int pack_id;                /* [i][o] unique ID for packet */
        void *usr_ptr;              /* [i][o] scratch */
        unsigned char status;       /* [o] SCSI status code */
        unsigned char masked_status;/* [o] status code masked by 0x0e */
        unsigned char msg_status;   /* [o] message code */
        unsigned char sb_len_wr;    /* [o] number of sense bytes written */
        unsigned short host_status; /* [o] errors from the host code */
        unsigned short driver_status;/* [o] errors from the LLDD */
        int resid;                  /* [o] number of bytes not transferred */
        unsigned int duration;      /* [o] command duration in milliseconds */
        unsigned int info;          /* [o] additional information */
};

#define SG_DXFER_NONE        (-1) /* e.g. a SCSI Test Unit Ready command */
#define SG_DXFER_TO_DEV      (-2) /* e.g. a SCSI WRITE command */
#define SG_DXFER_FROM_DEV    (-3) /* e.g. a SCSI READ command */
#define SG_DXFER_TO_FROM_DEV (-4) /* treated like SG_DXFER_FROM_DEV */

#define SG_IO _IOWR('S', 0x23, struct sg_io_hdr)

#endif
