#pragma once
#include "SimpleSocket.hpp"

namespace HDE {
class BindingSocket : public SimpleSocket {
public:
    // constructor
    BindingSocket(int domain, int service, int protocol, int port, u_long interface);

    // override virtual function from parent
    void connect_to_network(int sock, struct sockaddr_in address) override;
};
};
