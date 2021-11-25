#ifndef NETWORK_DEFINITIONS_H
#define NETWORK_DEFINITIONS_H

#ifdef linux

#include <sys/socket.h>

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define SD_RECEIVE SHUT_RD
#define SD_SEND SHUT_WR
#define SD_BOTH SHUT_RDWR
typedef int SOCKET;


#elif defined(WIN32)

#define WIN32_LEAN_AND_MEAN

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#endif // WIN32

#endif // NETWORK_DEFINITIONS_H
