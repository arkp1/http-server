#include "ConnectingSocket.hpp"
#include <sys/socket.h>

namespace HDE {
ConnectingSocket::ConnectingSocket(int domain, int service, int protocol, int port, u_long interface)
    : SimpleSocket(domain, service, protocol, port, interface)
{
    connect_to_network(get_sock(), get_address());
}

void ConnectingSocket::connect_to_network(int sock, struct sockaddr_in address)
{
    int result = ::connect(sock, (struct sockaddr *)&address, sizeof(address));
    set_connection(result);
}
}
