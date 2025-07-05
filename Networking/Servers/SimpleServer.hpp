#pragma once

#include "../hdelibc-networking.hpp"

namespace HDE {
class SimpleServer {
private:
    ListeningSocket* socket;
    virtual void acceptor() = 0;
    virtual void handler() = 0;
    virtual void responder() = 0;

public:
    SimpleServer(int domain, int service, int port, int protocol, u_long interface, int bklg);
    virtual void launch() = 0;

    ListeningSocket* get_socket();
};
}
