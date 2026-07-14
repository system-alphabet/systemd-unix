/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <stdint.h>
#include <linux/types.h>

/* FS_IOC_ENABLE_VERITY */
#define FS_IOC_ENABLE_VERITY     _IOW('f', 133, struct fsverity_enable_arg)

/* FS_IOC_READ_VERITY_METADATA */
#define FS_IOC_READ_VERITY_METADATA _IOWR('f', 134, struct fsverity_read_metadata_arg)

/* FS_IOC_MEASURE_VERITY */
#define FS_IOC_MEASURE_VERITY    _IOR('f', 135, struct fsverity_digest)

/* Verity metadata types */
#define FS_VERITY_METADATA_TYPE_DESCRIPTOR 1

/* Merkle tree block size */
#define FS_VERITY_HASH_ALG_SHA256 1
#define FS_VERITY_HASH_ALG_SHA512 2

/* struct fsverity_enable_arg */
struct fsverity_enable_arg {
        uint32_t version;
        uint32_t hash_algorithm;
        uint32_t block_size;
        uint32_t salt_size;
        uint64_t salt_ptr;
        uint32_t sig_size;
        uint32_t reserved;
        uint64_t sig_ptr;
};

/* struct fsverity_read_metadata_arg */
struct fsverity_read_metadata_arg {
        uint64_t metadata_type;
        uint64_t offset;
        uint64_t length;
        uint64_t buf_ptr;
        uint64_t reserved;
};

/* struct fsverity_digest */
struct fsverity_digest {
        uint16_t digest_algorithm;
        uint16_t digest_size;
        uint8_t  digest[];
};

/* struct fsverity_descriptor */
struct fsverity_descriptor {
        uint8_t  version;
        uint8_t  hash_algorithm;
        uint8_t  log_blocksize;
        uint8_t  salt_size;
        uint32_t __reserved0;
        uint64_t data_size;
        uint8_t  root_hash[64];
        uint8_t  salt[32];
        uint8_t  __reserved1[144];
};
