/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#define BOND_MODE_ROUNDROBIN  0
#define BOND_MODE_ACTIVEBACKUP 1
#define BOND_MODE_XOR         2
#define BOND_MODE_BROADCAST   3
#define BOND_MODE_8023AD      4
#define BOND_MODE_TLB         5
#define BOND_MODE_ALB         6

#define BOND_XMIT_POLICY_LAYER2   0
#define BOND_XMIT_POLICY_LAYER34  1
#define BOND_XMIT_POLICY_LAYER23  2
#define BOND_XMIT_POLICY_ENCAP23  3
#define BOND_XMIT_POLICY_ENCAP34  4
