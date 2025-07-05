#include <stdio.h>
#include "SimpleServer.hpp"

HDE::SimpleServer::SimpleServer(int domain, int service, int port, int protocol, u_long interface, int bklg);

    {
        socket = new ListeningSocket(domain, service, protocol, port, interface, bklg);
        delete socket;
    }

    HDE::ListeningSocket * HDE::SimpleServer::get_socket()
    {
        return socket;
    }
