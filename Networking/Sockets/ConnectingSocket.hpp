#pragma once
#include "SimpleSocket.hpp"

namespace HDE {
class ConnectingSocket : public SimpleSocket {
public:
    ConnectingSocket(int domain, int service, int port, int protocol, u_long interface);
    void connect_to_network(int sock, struct sockaddr_in address) override;
};
}
