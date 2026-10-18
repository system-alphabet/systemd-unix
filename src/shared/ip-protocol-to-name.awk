# SPDX-License-Identifier: LGPL-2.1-or-later

# Emit the ip-protocol-to-name table: one entry per protocol NAME collected in
# ip-protocol-list.txt. On the BSDs <netinet/in.h> additionally defines a few
# alias macros for protocol numbers that Linux spells differently (or not at
# all): IPPROTO_IPV6_ICMP next to IPPROTO_ICMPV6 (both 58), and IPPROTO_CARP
# next to IPPROTO_VRRP (both 112). The designated-initializer table cannot
# carry two entries for the same number (-Winitializer-overrides), so emit only
# the preferred name of each alias group — the one Linux uses, keeping the
# table consistent across platforms. The from-name table keeps every alias, so
# parsing either spelling still works.

BEGIN{
        n = 0
}
!/HOPOPTS/ {
        seen[$1] = 1
        names[++n] = $1
}
END{
        print "static const char* const ip_protocol_names[] = { "
        for (i = 1; i <= n; i++) {
                nm = names[i]
                if (nm == "IPV6_ICMP" && ("ICMPV6" in seen))
                        continue
                if (nm == "CARP" && ("VRRP" in seen))
                        continue
                printf "        [IPPROTO_%s] = \"%s\",\n", nm, tolower(nm)
        }
        print "};"
}
