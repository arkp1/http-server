#include "ListeningSocket.hpp"
#include <sys/socket.h> 
HDE::ListeningSocket::ListeningSocket(int domain, int service, int port, int protocol, u_long interface, int bklg)
    : BindingSocket(domain, service, protocol, port, interface), backlog(bklg), listening(0) {
    
    start_listening();
    test_connection(listening); 
}

void HDE::ListeningSocket::start_listening() {
    listening = listen(get_sock(), backlog);
}
