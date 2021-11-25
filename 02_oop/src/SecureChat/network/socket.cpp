#include "socket.h"

#ifdef linux

#elif defined(WIN32)

#include <winsock.h>

#endif

Socket::Socket()
{
    socket_descriptor = INVALID_SOCKET;
}

Socket::Socket(int domain, int type, int protocol)
{
    socket_descriptor = socket(domain, type, protocol);
}

int Socket::bind(const struct sockaddr *address, const int address_length) const
{
    return ::bind(socket_descriptor, address, address_length);
}

int Socket::listen(const int backlog) const
{
    return ::listen(socket_descriptor, backlog);
}

int Socket::accept(void *client_address, socklen_t *address_length) const
{
    return ::accept(socket_descriptor, (struct sockaddr*)client_address, address_length);
}

int Socket::connect(const struct sockaddr *server_address, const int address_length) const
{
    return ::connect(socket_descriptor, server_address, address_length);
}

int Socket::sendAll(char *message, const int length, const int flags) const
{
    int totalSentBytesNumber = 0;
    int lastSentBytesNumber;

    while(totalSentBytesNumber < length)
    {
        lastSentBytesNumber = send(message + totalSentBytesNumber, length - totalSentBytesNumber, flags);
        if(lastSentBytesNumber == -1)
            break;
        totalSentBytesNumber += lastSentBytesNumber;
    }

    return (lastSentBytesNumber == -1 ? -1 : totalSentBytesNumber);
}

int Socket::receiveAll(void *buffer, const int length, const int flags) const
{
    int bytesReceived = 0;
    while(bytesReceived < length)
    {
        bytesReceived = receive(buffer, length, flags);
        if(bytesReceived == 0)
            break;
    }
    return bytesReceived;
}

int Socket::shutdown(const int how) const
{
    return ::shutdown(socket_descriptor, how);
}

int Socket::getSocketDescriptor() const
{
    return socket_descriptor;
}

void Socket::setSocketDescriptor(const SOCKET new_descriptor)
{
    socket_descriptor = new_descriptor;
}

bool Socket::isValid()
{
    return socket_descriptor != INVALID_SOCKET;
}

void Socket::setInvalid()
{
    socket_descriptor = INVALID_SOCKET;
}

#ifdef linux

int Socket::send(const void* message, const int length, const int flags) const
{
    return ::send(socket_descriptor, message, length, flags);
}

int Socket::receive(void* buffer, const int length, const int flags) const
{
    return ::recv(socket_descriptor, buffer, length, flags);
}

int Socket::close() const
{
    return ::close(socket_descriptor);
}

#elif defined(WIN32)

int Socket::send(const void* message, const int length, const int flags) const
{
    return ::send(socket_descriptor, (const char*)message, length, flags);
}

int Socket::receive(void* buffer, const int length, const int flags) const
{
    return ::recv(socket_descriptor, (char*)buffer, length, flags);
}

int Socket::close() const
{
    return ::closesocket(socket_descriptor);
}

#endif


