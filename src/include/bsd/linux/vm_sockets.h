/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Linux <linux/vm_sockets.h> — VM Sockets (AF_VSOCK) definitions.
 * Minimal FreeBSD shim for compilation purposes.
 * Used by src/basic/socket-util.h.
 */

#include <stdint.h>

#ifndef VMADDR_PORT_ANY
#define VMADDR_PORT_ANY          ((unsigned int)-1)
#endif

#ifndef VMADDR_CID_ANY
#define VMADDR_CID_ANY           0xFFFFFFFF
#endif
#ifndef VMADDR_CID_HYPERVISOR
#define VMADDR_CID_HYPERVISOR    0
#endif
#ifndef VMADDR_CID_LOCAL
#define VMADDR_CID_LOCAL         1
#endif
#ifndef VMADDR_CID_HOST
#define VMADDR_CID_HOST          2
#endif
#ifndef VMADDR_CID_PARENT
#define VMADDR_CID_PARENT        3
#endif
#ifndef VMADDR_CID_RESERVED
#define VMADDR_CID_RESERVED      0
#endif

#ifndef VM_SOCKETS_INVALID_VERSION
#define VM_SOCKETS_INVALID_VERSION 0xFFFFFFFF
#endif

#ifndef SO_VM_SOCKETS_BUFFER_SIZE
#define SO_VM_SOCKETS_BUFFER_SIZE       0
#endif
#ifndef SO_VM_SOCKETS_BUFFER_MIN_SIZE
#define SO_VM_SOCKETS_BUFFER_MIN_SIZE   1
#endif
#ifndef SO_VM_SOCKETS_BUFFER_MAX_SIZE
#define SO_VM_SOCKETS_BUFFER_MAX_SIZE   2
#endif
#ifndef SO_VM_SOCKETS_PEER_HOST_VM_ID
#define SO_VM_SOCKETS_PEER_HOST_VM_ID   3
#endif
#ifndef SO_VM_SOCKETS_TRUSTED
#define SO_VM_SOCKETS_TRUSTED           5
#endif
#ifndef SO_VM_SOCKETS_CONNECT_TIMEOUT
#define SO_VM_SOCKETS_CONNECT_TIMEOUT   6
#endif
#ifndef SO_VM_SOCKETS_NONBLOCK_TXRX
#define SO_VM_SOCKETS_NONBLOCK_TXRX     7
#endif
#ifndef SO_VM_SOCKETS_PEER_CID
#define SO_VM_SOCKETS_PEER_CID          8
#endif
#ifndef SO_VM_SOCKETS_PEER_FLAGS
#define SO_VM_SOCKETS_PEER_FLAGS        9
#endif

#ifndef AF_VSOCK
#define AF_VSOCK                40
#endif
#ifndef PF_VSOCK
#define PF_VSOCK                AF_VSOCK
#endif

struct sockaddr_vm {
        unsigned short  svm_family;
        unsigned short  svm_reserved1;
        unsigned int    svm_port;
        unsigned int    svm_cid;
        unsigned char   svm_zero[4];
};

/* IOCTL for VM Sockets */
#ifndef IOCTL_VM_SOCKETS_GET_LOCAL_CID
#define IOCTL_VM_SOCKETS_GET_LOCAL_CID  _IO(7, 0xb9)
#endif
