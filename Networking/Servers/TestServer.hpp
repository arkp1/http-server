#pragma once

#include "SimpleServer.hpp"

namespace HDE {
class TestServer : public SimpleServer {
private:
    char buffer[30000] = {0};
    int new_socket;          
    void acceptor() override;
    void handler() override;
    void responder() override;

public:
    TestServer();
    void launch() override;
};
}
