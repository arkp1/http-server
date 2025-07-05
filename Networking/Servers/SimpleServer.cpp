#include "SimpleServer.hpp"
#include "../Sockets/ListeningSocket.hpp" 

namespace HDE {

SimpleServer::SimpleServer(int domain, int service, int port, int protocol, u_long interface, int bklg)
{
    socket = new ListeningSocket(domain, service, protocol, port, interface, bklg);
}

ListeningSocket* SimpleServer::get_socket()
{
    return socket;
}

}
