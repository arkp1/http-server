#include "ListeningSocket.hpp"


HDE::ListeningSocket::ListeningSocket(int domain, int service, int port, int protocol. u_long interface, int bklg) :
BindingSocket(domain, service, port, protocol, interface)

{
    backlog = bklg;
    start_listening();
    test_connection(listening());
}

void HDE::ListeningSocket::start_listening()
{
    listening = listen(get_sock(), backlog);
}