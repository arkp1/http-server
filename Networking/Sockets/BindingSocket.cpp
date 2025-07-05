#include "BindingSocket.hpp"

namespace HDE {

// constructor
BindingSocket::BindingSocket(int domain, int service, int protocol, int port, u_long interface)
    : SimpleSocket(domain, service, protocol, port, interface)
{
   struct sockaddr_in addr = get_address();
    int result = bind(get_sock(), (struct sockaddr*)&addr, sizeof(addr));

    test_connection(result);
    set_connection(result);
}

// override of virtual function
void BindingSocket::connect_to_network(int sock, struct sockaddr_in address)
{
    int result = bind(sock, (struct sockaddr *)&address, sizeof(address));
    test_connection(result);
    set_connection(result);
}

}
