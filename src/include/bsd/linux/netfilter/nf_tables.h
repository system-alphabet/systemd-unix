/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Linux <linux/netfilter/nf_tables.h> — netfilter nf_tables definitions.
 * Minimal FreeBSD shim — provides NFT_* constants used by parse-util.c.
 */

#include <stdint.h>

/* Userdata types */
enum nft_rule_attributes {
        NFTA_RULE_UNSPEC,
        NFTA_RULE_TABLE,
        NFTA_RULE_CHAIN,
        NFTA_RULE_HANDLE,
        NFTA_RULE_EXPRESSIONS,
        NFTA_RULE_COMPAT,
        NFTA_RULE_POSITION,
        NFTA_RULE_USERDATA,
        NFTA_RULE_ID,
        NFTA_RULE_POSITION_ID,
        NFTA_RULE_OWNER,
        __NFTA_RULE_MAX,
};
#define NFTA_RULE_MAX           (__NFTA_RULE_MAX - 1)

/* Expression types */
enum nft_expr_attributes {
        NFTA_EXPR_UNSPEC,
        NFTA_EXPR_NAME,
        NFTA_EXPR_DATA,
        __NFTA_EXPR_MAX,
};
#define NFTA_EXPR_MAX           (__NFTA_EXPR_MAX - 1)

/* Data types */
enum nft_data_types {
        NFT_DATA_VALUE,
        NFT_DATA_VERDICT,
        NFT_DATA_GPRS,
        __NFT_DATA_MAX,
};
#define NFT_DATA_MAX            (__NFT_DATA_MAX - 1)

/* Data attributes */
enum nft_data_attributes {
        NFTA_DATA_UNSPEC,
        NFTA_DATA_VALUE,
        NFTA_DATA_VERDICT,
        __NFTA_DATA_MAX,
};
#define NFTA_DATA_MAX           (__NFTA_DATA_MAX - 1)

/* Verdict types */
enum nft_verdicts_attributes {
        NFTA_VERDICT_UNSPEC,
        NFTA_VERDICT_CODE,
        NFTA_VERDICT_CHAIN,
        NFTA_VERDICT_CHAIN_ID,
        __NFTA_VERDICT_MAX,
};
#define NFTA_VERDICT_MAX        (__NFTA_VERDICT_MAX - 1)

/* Payload base */
enum nft_payload_bases {
        NFT_PAYLOAD_LL_HEADER,
        NFT_PAYLOAD_NETWORK_HEADER,
        NFT_PAYLOAD_TRANSPORT_HEADER,
        NFT_PAYLOAD_INNER_HEADER,
};

/* Payload attributes */
enum nft_payload_attributes {
        NFTA_PAYLOAD_UNSPEC,
        NFTA_PAYLOAD_DREG,
        NFTA_PAYLOAD_BASE,
        NFTA_PAYLOAD_OFFSET,
        NFTA_PAYLOAD_LEN,
        NFTA_PAYLOAD_SREG,
        NFTA_PAYLOAD_CSUM_TYPE,
        NFTA_PAYLOAD_CSUM_OFFSET,
        NFTA_PAYLOAD_CSUM_FLAGS,
        __NFTA_PAYLOAD_MAX,
};
#define NFTA_PAYLOAD_MAX        (__NFTA_PAYLOAD_MAX - 1)

/* Meta keys */
enum nft_meta_keys {
        NFT_META_LEN,
        NFT_META_PROTOCOL,
        NFT_META_PRIORITY,
        NFT_META_MARK,
        NFT_META_IIF,
        NFT_META_OIF,
        NFT_META_IIFNAME,
        NFT_META_OIFNAME,
        NFT_META_IIFTYPE,
        NFT_META_OIFTYPE,
        NFT_META_SKUID,
        NFT_META_SKGID,
        NFT_META_NFTRACE,
        NFT_META_RTCLASSID,
        NFT_META_SECMARK,
        NFT_META_NFPROTO,
        NFT_META_L4PROTO,
        NFT_META_BRI_IIFNAME,
        NFT_META_BRI_OIFNAME,
        NFT_META_PKTTYPE,
        NFT_META_CPU,
        NFT_META_IIFGROUP,
        NFT_META_OIFGROUP,
        NFT_META_CGROUP,
        NFT_META_PRANDOM,
        NFT_META_SECPATH,
        NFT_META_RANDOM,
        NFT_META_TIME_NS,
        NFT_META_TIME_DAY,
        NFT_META_TIME_HOUR,
        NFT_META_SECID,
        NFT_META_IIF_KIND,
        NFT_META_OIF_KIND,
        __NFT_META_IIFTYPE,
};
#define NFT_META_MAX            (__NFT_META_IIFTYPE - 1)

/* Bitwise operations */
enum nft_bitwise_attributes {
        NFTA_BITWISE_UNSPEC,
        NFTA_BITWISE_SREG,
        NFTA_BITWISE_DREG,
        NFTA_BITWISE_LEN,
        NFTA_BITWISE_MASK,
        NFTA_BITWISE_XOR,
        NFTA_BITWISE_OP,
        __NFTA_BITWISE_MAX,
};
#define NFTA_BITWISE_MAX        (__NFTA_BITWISE_MAX - 1)

/* Cmp operations */
enum nft_cmp_ops {
        NFT_CMP_EQ,
        NFT_CMP_NEQ,
        NFT_CMP_LT,
        NFT_CMP_LTE,
        NFT_CMP_GT,
        NFT_CMP_GTE,
};

enum nft_cmp_attributes {
        NFTA_CMP_UNSPEC,
        NFTA_CMP_SREG,
        NFTA_CMP_OP,
        NFTA_CMP_DATA,
        __NFTA_CMP_MAX,
};
#define NFTA_CMP_MAX            (__NFTA_CMP_MAX - 1)

/* Range */
enum nft_range_ops {
        NFT_RANGE_EQ,
        NFT_RANGE_NEQ,
};

enum nft_range_attributes {
        NFTA_RANGE_UNSPEC,
        NFTA_RANGE_SREG,
        NFTA_RANGE_OP,
        NFTA_RANGE_FROM_DATA,
        NFTA_RANGE_TO_DATA,
        __NFTA_RANGE_MAX,
};
#define NFTA_RANGE_MAX          (__NFTA_RANGE_MAX - 1)

/* Counter */
enum nft_counter_attributes {
        NFTA_COUNTER_UNSPEC,
        NFTA_COUNTER_BYTES,
        NFTA_COUNTER_PACKETS,
        NFTA_COUNTER_PAD,
        __NFTA_COUNTER_MAX,
};
#define NFTA_COUNTER_MAX        (__NFTA_COUNTER_MAX - 1)

/* Lookup */
enum nft_lookup_attributes {
        NFTA_LOOKUP_UNSPEC,
        NFTA_LOOKUP_SET,
        NFTA_LOOKUP_SREG,
        NFTA_LOOKUP_DREG,
        NFTA_LOOKUP_SET_ID,
        NFTA_LOOKUP_FLAGS,
        __NFTA_LOOKUP_MAX,
};
#define NFTA_LOOKUP_MAX         (__NFTA_LOOKUP_MAX - 1)

/* Dynset */
enum nft_dynset_attributes {
        NFTA_DYNSET_UNSPEC,
        NFTA_DYNSET_SET_NAME,
        NFTA_DYNSET_SET_ID,
        NFTA_DYNSET_OP,
        NFTA_DYNSET_SREG_KEY,
        NFTA_DYNSET_SREG_DATA,
        NFTA_DYNSET_TIMEOUT,
        NFTA_DYNSET_EXPR,
        NFTA_DYNSET_PAD,
        NFTA_DYNSET_FLAGS,
        __NFTA_DYNSET_MAX,
};
#define NFTA_DYNSET_MAX         (__NFTA_DYNSET_MAX - 1)

enum nft_dynset_ops {
        NFT_DYNSET_OP_ADD,
        NFT_DYNSET_OP_UPDATE,
        NFT_DYNSET_OP_DELETE,
};

/* Immediate */
enum nft_immediate_attributes {
        NFTA_IMMEDIATE_UNSPEC,
        NFTA_IMMEDIATE_DREG,
        NFTA_IMMEDIATE_DATA,
        __NFTA_IMMEDIATE_MAX,
};
#define NFTA_IMMEDIATE_MAX      (__NFTA_IMMEDIATE_MAX - 1)

/* Concatenation */
enum nft_concatenation_attributes {
        NFTA_CONCAT_UNSPEC,
        NFTA_CONCAT_SREG,
        NFTA_CONCAT_DREG,
        NFTA_CONCAT_MAX_FLDS,
        __NFTA_CONCAT_MAX,
};
#define NFTA_CONCAT_MAX         (__NFTA_CONCAT_MAX - 1)

/* Limit */
enum nft_limit_attributes {
        NFTA_LIMIT_UNSPEC,
        NFTA_LIMIT_RATE,
        NFTA_LIMIT_UNIT,
        NFTA_LIMIT_BURST,
        NFTA_LIMIT_TYPE,
        NFTA_LIMIT_FLAGS,
        NFTA_LIMIT_PAD,
        __NFTA_LIMIT_MAX,
};
#define NFTA_LIMIT_MAX          (__NFTA_LIMIT_MAX - 1)

enum nft_limit_type {
        NFT_LIMIT_PKTS,
        NFT_LIMIT_PKT_BYTES,
};

#define NFT_LIMIT_F_INV         0x1

/* Quota */
enum nft_quota_attributes {
        NFTA_QUOTA_UNSPEC,
        NFTA_QUOTA_BYTES,
        NFTA_QUOTA_FLAGS,
        NFTA_QUOTA_PAD,
        NFTA_QUOTA_CONSUMED,
        __NFTA_QUOTA_MAX,
};
#define NFTA_QUOTA_MAX          (__NFTA_QUOTA_MAX - 1)

#define NFT_QUOTA_F_INV         0x1

/* Reject */
enum nft_reject_attributes {
        NFTA_REJECT_UNSPEC,
        NFTA_REJECT_TYPE,
        NFTA_REJECT_ICMP_CODE,
        __NFTA_REJECT_MAX,
};
#define NFTA_REJECT_MAX         (__NFTA_REJECT_MAX - 1)

enum nft_reject_types {
        NFT_REJECT_ICMP_UNREACH,
        NFT_REJECT_TCP_RST,
        NFT_REJECT_ICMPX_UNREACH,
};

/* NAT */
enum nft_nat_attributes {
        NFTA_NAT_UNSPEC,
        NFTA_NAT_TYPE,
        NFTA_NAT_FAMILY,
        NFTA_NAT_REG_ADDR_MIN,
        NFTA_NAT_REG_ADDR_MAX,
        NFTA_NAT_REG_PROTO_MIN,
        NFTA_NAT_REG_PROTO_MAX,
        NFTA_NAT_FLAGS,
        __NFTA_NAT_MAX,
};
#define NFTA_NAT_MAX            (__NFTA_NAT_MAX - 1)

enum nft_nat_types {
        NFT_NAT_SNAT,
        NFT_NAT_DNAT,
        NFT_NAT_REDIR,
        NFT_NAT_MASQ,
};

#define NF_NAT_RANGE_PROTO_RANDOM               0x1
#define NF_NAT_RANGE_PROTO_RANDOM_FULLY         0x2
#define NF_NAT_RANGE_PROTO_OFFSET               0x4
#define NF_NAT_RANGE_NETMAP                     0x8
#define NF_NAT_RANGE_PERSISTENT                 0x10

/* Masquerade */
enum nft_masq_attributes {
        NFTA_MASQ_UNSPEC,
        NFTA_MASQ_FLAGS,
        NFTA_MASQ_REG_PROTO_MIN,
        NFTA_MASQ_REG_PROTO_MAX,
        __NFTA_MASQ_MAX,
};
#define NFTA_MASQ_MAX           (__NFTA_MASQ_MAX - 1)

/* Redir */
enum nft_redir_attributes {
        NFTA_REDIR_UNSPEC,
        NFTA_REDIR_REG_PROTO_MIN,
        NFTA_REDIR_REG_PROTO_MAX,
        NFTA_REDIR_FLAGS,
        __NFTA_REDIR_MAX,
};
#define NFTA_REDIR_MAX          (__NFTA_REDIR_MAX - 1)

/* Dup */
enum nft_dup_attributes {
        NFTA_DUP_UNSPEC,
        NFTA_DUP_SREG_ADDR,
        NFTA_DUP_SREG_DEV,
        __NFTA_DUP_MAX,
};
#define NFTA_DUP_MAX            (__NFTA_DUP_MAX - 1)

/* Fwd */
enum nft_fwd_attributes {
        NFTA_FWD_UNSPEC,
        NFTA_FWD_SREG_DEV,
        NFTA_FWD_SREG_ADDR,
        NFTA_FWD_NFPROTO,
        __NFTA_FWD_MAX,
};
#define NFTA_FWD_MAX            (__NFTA_FWD_MAX - 1)

/* Queue */
enum nft_queue_attributes {
        NFTA_QUEUE_UNSPEC,
        NFTA_QUEUE_NUM,
        NFTA_QUEUE_TOTAL,
        NFTA_QUEUE_FLAGS,
        NFTA_QUEUE_SREG_QNUM,
        __NFTA_QUEUE_MAX,
};
#define NFTA_QUEUE_MAX          (__NFTA_QUEUE_MAX - 1)

#define NFT_QUEUE_FLAG_BYPASS   0x01
#define NFT_QUEUE_FLAG_CPU_FANOUT 0x02
#define NFT_QUEUE_FLAG_MASK     0x03

/* Log */
enum nft_log_attributes {
        NFTA_LOG_UNSPEC,
        NFTA_LOG_GROUP,
        NFTA_LOG_PREFIX,
        NFTA_LOG_SNAPLEN,
        NFTA_LOG_QTHRESHOLD,
        NFTA_LOG_LEVEL,
        NFTA_LOG_FLAGS,
        __NFTA_LOG_MAX,
};
#define NFTA_LOG_MAX            (__NFTA_LOG_MAX - 1)

enum nft_log_level {
        NFT_LOGLEVEL_EMERG,
        NFT_LOGLEVEL_ALERT,
        NFT_LOGLEVEL_CRIT,
        NFT_LOGLEVEL_ERR,
        NFT_LOGLEVEL_WARNING,
        NFT_LOGLEVEL_NOTICE,
        NFT_LOGLEVEL_INFO,
        NFT_LOGLEVEL_DEBUG,
        NFT_LOGLEVEL_AUDIT,
};
#define NFT_LOGLEVEL_KERN       NFT_LOGLEVEL_EMERG

/* Object */
enum nft_object_attributes {
        NFTA_OBJ_UNSPEC,
        NFTA_OBJ_TABLE,
        NFTA_OBJ_NAME,
        NFTA_OBJ_TYPE,
        NFTA_OBJ_DATA,
        NFTA_OBJ_USE,
        NFTA_OBJ_HANDLE,
        NFTA_OBJ_PAD,
        __NFTA_OBJ_MAX,
};
#define NFTA_OBJ_MAX            (__NFTA_OBJ_MAX - 1)

/* Flowtable */
enum nft_flowtable_attributes {
        NFTA_FLOWTABLE_UNSPEC,
        NFTA_FLOWTABLE_TABLE,
        NFTA_FLOWTABLE_NAME,
        NFTA_FLOWTABLE_HOOK,
        NFTA_FLOWTABLE_USE,
        NFTA_FLOWTABLE_HANDLE,
        NFTA_FLOWTABLE_PAD,
        __NFTA_FLOWTABLE_MAX,
};
#define NFTA_FLOWTABLE_MAX      (__NFTA_FLOWTABLE_MAX - 1)

/* Chain hook numbers */
enum nft_chain_hook_attributes {
        NFTA_HOOK_UNSPEC,
        NFTA_HOOK_HOOKNUM,
        NFTA_HOOK_PRIORITY,
        NFTA_HOOK_DEV,
        NFTA_HOOK_PAD,
        __NFTA_HOOK_MAX,
};
#define NFTA_HOOK_MAX           (__NFTA_HOOK_MAX - 1)

enum nf_tables_msg_types {
        NFT_MSG_NEWTABLE,
        NFT_MSG_GETTABLE,
        NFT_MSG_DELTABLE,
        NFT_MSG_NEWCHAIN,
        NFT_MSG_GETCHAIN,
        NFT_MSG_DELCHAIN,
        NFT_MSG_NEWRULE,
        NFT_MSG_GETRULE,
        NFT_MSG_DELRULE,
        NFT_MSG_NEWSET,
        NFT_MSG_GETSET,
        NFT_MSG_DELSET,
        NFT_MSG_NEWSETELEM,
        NFT_MSG_GETSETELEM,
        NFT_MSG_DELSETELEM,
        NFT_MSG_NEWGEN,
        NFT_MSG_GETGEN,
        NFT_MSG_TRACE,
        NFT_MSG_NEWOBJ,
        NFT_MSG_GETOBJ,
        NFT_MSG_DELOBJ,
        NFT_MSG_GETOBJ_RESET,
        NFT_MSG_NEWFLOWTABLE,
        NFT_MSG_GETFLOWTABLE,
        NFT_MSG_DELFLOWTABLE,
        NFT_MSG_GETRULE_RESET,
        NFT_MSG_DESTROYTABLE,
        NFT_MSG_DESTROYCHAIN,
        NFT_MSG_DESTROYRULE,
        NFT_MSG_DESTROYSET,
        NFT_MSG_DESTROYSETELEM,
        NFT_MSG_DESTROYOBJ,
        NFT_MSG_DESTROYFLOWTABLE,
        __NFT_MSG_MAX,
};
#define NFT_MSG_MAX             (__NFT_MSG_MAX - 1)

enum nft_rule_compat_attributes {
        NFTA_RULE_COMPAT_UNSPEC,
        NFTA_RULE_COMPAT_PROTO,
        NFTA_RULE_COMPAT_FLAGS,
        __NFTA_RULE_COMPAT_MAX,
};
#define NFTA_RULE_COMPAT_MAX    (__NFTA_RULE_COMPAT_MAX - 1)

enum nft_set_attributes {
        NFTA_SET_UNSPEC,
        NFTA_SET_TABLE,
        NFTA_SET_NAME,
        NFTA_SET_FLAGS,
        NFTA_SET_KEY_TYPE,
        NFTA_SET_KEY_LEN,
        NFTA_SET_DATA_TYPE,
        NFTA_SET_DATA_LEN,
        NFTA_SET_POLICY,
        NFTA_SET_DESC,
        NFTA_SET_ID,
        NFTA_SET_TIMEOUT,
        NFTA_SET_GC_INTERVAL,
        NFTA_SET_USERDATA,
        NFTA_SET_PAD,
        NFTA_SET_OBJ_TYPE,
        NFTA_SET_HANDLE,
        NFTA_SET_EXPR,
        NFTA_SET_EXPRESSIONS,
        __NFTA_SET_MAX,
};
#define NFTA_SET_MAX            (__NFTA_SET_MAX - 1)

enum nft_set_elem_attributes {
        NFTA_SET_ELEM_UNSPEC,
        NFTA_SET_ELEM_KEY,
        NFTA_SET_ELEM_DATA,
        NFTA_SET_ELEM_FLAGS,
        NFTA_SET_ELEM_TIMEOUT,
        NFTA_SET_ELEM_EXPIRATION,
        NFTA_SET_ELEM_USERDATA,
        NFTA_SET_ELEM_EXPR,
        NFTA_SET_ELEM_PAD,
        NFTA_SET_ELEM_OBJREF,
        NFTA_SET_ELEM_KEY_END,
        __NFTA_SET_ELEM_MAX,
};
#define NFTA_SET_ELEM_MAX       (__NFTA_SET_ELEM_MAX - 1)

enum nft_set_elem_flags {
        NFT_SET_ELEM_INTERVAL_END = 0x1,
};

enum nft_set_flags {
        NFT_SET_ANONYMOUS       = 0x1,
        NFT_SET_CONSTANT        = 0x2,
        NFT_SET_INTERVAL        = 0x4,
        NFT_SET_MAP             = 0x8,
        NFT_SET_TIMEOUT         = 0x10,
        NFT_SET_EVAL            = 0x20,
        NFT_SET_OBJECT          = 0x40,
        NFT_SET_CONCAT          = 0x80,
        NFT_SET_EXPR            = 0x100,
};

enum nft_set_policies {
        NFT_SET_POL_PERFORMANCE,
        NFT_SET_POL_MEMORY,
};

enum nft_set_desc_attributes {
        NFTA_SET_DESC_UNSPEC,
        NFTA_SET_DESC_SIZE,
        NFTA_SET_DESC_CONCAT,
        __NFTA_SET_DESC_MAX,
};
#define NFTA_SET_DESC_MAX       (__NFTA_SET_DESC_MAX - 1)

#define NFT_SET_MAXANONLEN      16
#define NFT_SET_MAXSETNAMELEN   64
#ifndef NFT_NAME_MAXLEN
#define NFT_NAME_MAXLEN         256
#endif
