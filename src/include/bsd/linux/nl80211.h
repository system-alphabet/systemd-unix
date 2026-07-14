/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/* Minimal nl80211 constants needed by wifi-util.c */

#define NL80211_GENL_NAME              "nl80211"

#define NL80211_CMD_GET_INTERFACE      5
#define NL80211_CMD_SET_INTERFACE      6
#define NL80211_CMD_NEW_INTERFACE      7
#define NL80211_CMD_DEL_INTERFACE      8
#define NL80211_CMD_GET_STATION        17
#define NL80211_CMD_GET_WIPHY          1
#define NL80211_CMD_SET_WIPHY          2
#define NL80211_CMD_NEW_WIPHY          3
#define NL80211_CMD_DEL_WIPHY          4
#define __NL80211_CMD_AFTER_LAST       100

#define NL80211_ATTR_IFINDEX           3
#define NL80211_ATTR_IFTYPE            4
#define NL80211_ATTR_SSID              6
#define NL80211_ATTR_MAC               5

enum nl80211_iftype {
        NL80211_IFTYPE_UNSPECIFIED,
        NL80211_IFTYPE_ADHOC,
        NL80211_IFTYPE_STATION,
        NL80211_IFTYPE_AP,
        NL80211_IFTYPE_AP_VLAN,
        NL80211_IFTYPE_WDS,
        NL80211_IFTYPE_MONITOR,
        NL80211_IFTYPE_MESH_POINT,
        NL80211_IFTYPE_P2P_CLIENT,
        NL80211_IFTYPE_P2P_GO,
        NL80211_IFTYPE_P2P_DEVICE,
        NL80211_IFTYPE_OCB,
        NL80211_IFTYPE_NAN,
        NUM_NL80211_IFTYPES,
        NL80211_IFTYPE_MAX = NUM_NL80211_IFTYPES - 1,
};
