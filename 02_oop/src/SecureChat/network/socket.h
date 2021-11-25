#ifndef SOCKET_H
#define SOCKET_H

#include <NetworkDefinitions.h>

#ifdef linux

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>

#elif defined(WIN32)

#include <WS2tcpip.h>

#endif

class Socket
{
public:
    Socket();
    Socket(const int domain, const int type, const int protocol);
    int bind(const struct sockaddr *address, const int address_length) const;
    int listen(const int backlog) const;
    int accept(void *client_address, socklen_t *address_length) const;
    int connect(const struct sockaddr *server_address, const int address_length) const;
    int send(const void *message, const int length, const int flags) const;
    int sendAll(char *message, const int length, const int flags) const;
    int receive(void *buf, const int length, const int flags) const;
    int receiveAll(void *buf, const int length, const int flags) const;
    int close() const;
    int shutdown(const int how) const;
    int getSocketDescriptor() const;
    void setSocketDescriptor(const SOCKET new_descriptor);
    bool isValid();
    void setInvalid();
private:
    SOCKET socket_descriptor;
};

#endif // SOCKET_H
