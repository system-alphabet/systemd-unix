/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <stdint.h>
#include <stddef.h>

/* Classic BPF instruction classes (from <linux/bpf_common.h>). */
#define BPF_LD          0x00
#define BPF_LDX         0x01
#define BPF_ALU         0x04
#define BPF_JMP         0x05
#define BPF_RET         0x06
#define BPF_ALU64       0x07
#define BPF_W           0x00
#define BPF_K           0x00
#define BPF_MOV         0xb0
#define BPF_EXIT        0x90

/* BPF program types. */
#define BPF_PROG_TYPE_UNSPEC          0
#define BPF_PROG_TYPE_CGROUP_SKB      7
#define BPF_PROG_TYPE_CGROUP_SOCK_ADDR 11
#define BPF_PROG_TYPE_CGROUP_DEVICE   13

/* BPF map types. */
enum bpf_map_type {
        BPF_MAP_TYPE_UNSPEC,
        BPF_MAP_TYPE_HASH,
        BPF_MAP_TYPE_ARRAY,
        BPF_MAP_TYPE_PROG_ARRAY,
        BPF_MAP_TYPE_PERF_EVENT_ARRAY,
        BPF_MAP_TYPE_PERCPU_HASH,
        BPF_MAP_TYPE_PERCPU_ARRAY,
        BPF_MAP_TYPE_STACK_TRACE,
        BPF_MAP_TYPE_CGROUP_ARRAY,
        BPF_MAP_TYPE_LRU_HASH,
        BPF_MAP_TYPE_LRU_PERCPU_HASH,
        BPF_MAP_TYPE_LPM_TRIE,
        BPF_MAP_TYPE_ARRAY_OF_MAPS,
        BPF_MAP_TYPE_HASH_OF_MAPS,
        BPF_MAP_TYPE_DEVMAP,
        BPF_MAP_TYPE_SOCKMAP,
        BPF_MAP_TYPE_CPUMAP,
        BPF_MAP_TYPE_XSKMAP,
        BPF_MAP_TYPE_SOCKHASH,
        BPF_MAP_TYPE_CGROUP_STORAGE_DEPRECATED,
        BPF_MAP_TYPE_CGROUP_STORAGE = BPF_MAP_TYPE_CGROUP_STORAGE_DEPRECATED,
        BPF_MAP_TYPE_REUSEPORT_SOCKARRAY,
        BPF_MAP_TYPE_PERCPU_CGROUP_STORAGE,
        BPF_MAP_TYPE_QUEUE,
        BPF_MAP_TYPE_STACK,
        BPF_MAP_TYPE_SK_STORAGE,
        BPF_MAP_TYPE_DEVMAP_HASH,
        BPF_MAP_TYPE_STRUCT_OPS,
        BPF_MAP_TYPE_RINGBUF,
        BPF_MAP_TYPE_INODE_STORAGE,
        BPF_MAP_TYPE_TASK_STORAGE,
        BPF_MAP_TYPE_BLOOM_FILTER,
        BPF_MAP_TYPE_USER_RINGBUF,
};

/* BPF attach types. */
#define BPF_CGROUP_INET_INGRESS       0
#define BPF_CGROUP_INET_EGRESS        1
#define BPF_CGROUP_INET_SOCK_CREATE   2
#define BPF_CGROUP_SOCK_OPS           3
#define BPF_CGROUP_DEVICE             4
#define BPF_CGROUP_INET4_BIND         5
#define BPF_CGROUP_INET6_BIND         6
#define BPF_CGROUP_INET4_CONNECT      7
#define BPF_CGROUP_INET6_CONNECT      8
#define BPF_CGROUP_INET4_POST_BIND    9
#define BPF_CGROUP_INET6_POST_BIND    10
#define BPF_CGROUP_UDP4_SENDMSG       11
#define BPF_CGROUP_UDP6_SENDMSG       12
#define BPF_CGROUP_SYSCTL             13
#define BPF_CGROUP_UDP4_RECVMSG       14
#define BPF_CGROUP_UDP6_RECVMSG       15
#define BPF_CGROUP_GETSOCKOPT         16
#define BPF_CGROUP_SETSOCKOPT         17
#define __MAX_BPF_ATTACH_TYPE         18

/* BPF commands. */
#define BPF_MAP_CREATE                0
#define BPF_MAP_LOOKUP_ELEM           1
#define BPF_MAP_UPDATE_ELEM           2
#define BPF_PROG_LOAD                 5
#define BPF_OBJ_PIN                   6
#define BPF_OBJ_GET                   7
#define BPF_PROG_ATTACH               8
#define BPF_PROG_DETACH               9
#define BPF_OBJ_GET_INFO_BY_FD        17

/* BPF flags. */
#define BPF_F_ALLOW_OVERRIDE          1
#define BPF_F_ALLOW_MULTI             2

/* BPF object name length. */
#define BPF_OBJ_NAME_LEN              16

/* struct bpf_prog_info */
struct bpf_prog_info {
        uint32_t type;
        uint32_t id;
        uint8_t  tag[8];
        uint32_t jited_prog_len;
        uint32_t xlated_prog_len;
        uint64_t jited_prog_insns;
        uint64_t xlated_prog_insns;
        uint64_t load_time;
        uint32_t created_by_uid;
        uint32_t nr_map_ids;
        uint64_t map_ids;
        uint32_t nr_jited_ksyms;
        uint32_t nr_jited_func_lens;
        uint64_t jited_ksyms;
        uint64_t jited_func_lens;
        uint64_t btf_id;
        uint64_t func_info_rec_size;
        uint64_t func_info;
        uint32_t nr_func_info;
        uint32_t nr_line_info;
        uint64_t line_info;
        uint64_t line_info_rec_size;
        uint32_t nr_jited_line_info;
        uint32_t jited_line_info_rec_size;
        uint64_t jited_line_info;
        uint32_t nr_prog_tags;
        uint64_t prog_tags;
        uint64_t run_time_ns;
        uint64_t run_cnt;
        uint64_t (*run_time_ns)[];
        uint64_t (*run_cnt)[];
        uint64_t recursion_misses;
        uint32_t verified_insns;
};

/* BPF instruction helpers. */
#define BPF_REG_0                     0

struct bpf_insn {
    uint8_t  code;
    uint8_t  dst_reg : 4;
    uint8_t  src_reg : 4;
    int16_t  off;
    int32_t  imm;
};

#define BPF_MOV64_IMM(dst, imm) \
    ((struct bpf_insn) { .code = BPF_ALU64 | BPF_MOV | BPF_K, \
                         .dst_reg = dst, .src_reg = 0, .off = 0, .imm = imm })
#define BPF_EXIT_INSN() \
    ((struct bpf_insn) { .code = BPF_JMP | BPF_EXIT, \
                         .dst_reg = 0, .src_reg = 0, .off = 0, .imm = 0 })

/* union bpf_attr */
union bpf_attr {
        struct {
                uint32_t map_type;
                uint32_t key_size;
                uint32_t value_size;
                uint32_t max_entries;
                uint32_t map_flags;
                uint32_t inner_map_fd;
                uint32_t numa_node;
                char     map_name[BPF_OBJ_NAME_LEN];
                uint32_t map_ifindex;
                uint32_t btf_fd;
                uint32_t btf_key_type_id;
                uint32_t btf_value_type_id;
                uint64_t btf_vmlinux_value_type_id;
                uint64_t map_extra;
        } __attribute__((unused));
        struct {
                uint64_t pathname;
                uint32_t bpf_fd;
                uint32_t file_flags;
        } __attribute__((unused));
        struct {
                uint32_t target_fd;
                uint32_t attach_bpf_fd;
                uint32_t attach_type;
                uint32_t attach_flags;
        } __attribute__((unused));
        struct {
                uint32_t prog_type;
                uint32_t insn_cnt;
                uint64_t insns;
                uint64_t license;
                uint32_t log_level;
                uint32_t log_size;
                uint64_t log_buf;
                uint32_t kern_version;
                uint32_t prog_flags;
                char     prog_name[BPF_OBJ_NAME_LEN];
                uint32_t prog_ifindex;
                uint32_t expected_attach_type;
                uint32_t prog_btf_fd;
                uint64_t func_info_rec_size;
                uint64_t func_info;
                uint64_t line_info_rec_size;
                uint64_t line_info;
                uint32_t core_relo_cnt;
                uint64_t core_relos;
        } __attribute__((unused));
        struct {
                uint64_t key;
                uint64_t value;
                uint64_t next_key;
                uint32_t map_fd;
        } __attribute__((unused));
        struct {
                uint32_t bpf_fd;
                uint32_t info_len;
                uint64_t info;
        } __attribute__((unused));
        struct {
                uint32_t btf;
                uint64_t btf_log_buf;
                uint32_t btf_log_size;
                uint32_t btf_log_level;
        } __attribute__((unused));
        struct {
                uint32_t link_create;
                uint32_t target_fd;
                uint32_t attach_type;
                uint32_t flags;
        } __attribute__((unused));
        struct {
                uint32_t link_update;
        } __attribute__((unused));
};

int bpf(int cmd, union bpf_attr *attr, unsigned int size);
