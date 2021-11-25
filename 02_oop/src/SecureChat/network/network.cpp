#include "network.h"

#ifdef linux

#include <errno.h>

int networkStartUp()
{
    return 0;
}

int networkClose()
{
    return 0;
}

int networkGetLastError()
{
    return errno;
}


#elif WIN32

#include <winsock2.h>

int networkStartUp()
{
	WSADATA wsaData;
	return WSAStartup(MAKEWORD(2, 2), &wsaData);
}

int networkClose()
{
	return WSACleanup();
}

int networkGetLastError()
{
    return WSAGetLastError();
}

#endif
