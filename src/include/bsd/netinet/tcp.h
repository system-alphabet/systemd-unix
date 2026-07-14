#pragma once

/* TCP FSM states (from Linux / glibc <netinet/tcp.h>) */
#define TCP_ESTABLISHED  1
#define TCP_SYN_SENT     2
#define TCP_SYN_RECV     3
#define TCP_FIN_WAIT1    4
#define TCP_FIN_WAIT2    5
#define TCP_TIME_WAIT    6
#define TCP_CLOSE        7
#define TCP_CLOSE_WAIT   8
#define TCP_LAST_ACK     9
#define TCP_LISTEN       10
#define TCP_CLOSING      11

/* Include the real FreeBSD <netinet/tcp.h> for the actual TCP protocol defines */
#if __has_include_next(<netinet/tcp.h>)
#include_next <netinet/tcp.h>
#endif
