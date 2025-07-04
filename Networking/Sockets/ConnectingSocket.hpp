#include <stdio.h>
#include "SimpleSocket.hpp"

namespace HDE
{
    class ConnectingSocket: public SimpleSocket 
    {
        public:
        //constructor
        ConnectingSocket(int domain, int service, int port, int protocol, 
            u_long interface) : SimpleSocket(domain, service, protocol, port, interface);
            //virtual function from parent
            int connect_to_network(int sock, struct sockaddr_in address); 
        }
}


