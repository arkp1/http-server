#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <unistd.h>

namespace HDE
{
class SimpleSocket
{
private:
    struct sockaddr_in address;  
    int sock;
    int connection;

public:
//constructor
    SimpleSocket(int domain, int service, int protocol, int port, u_long interface);
    //virtual func to connect to network
    virtual void connect_to_network(int sock, struct sockaddr_in address) = 0;
    //func to test sockets and connections
    void test_connection(int);
    //getter funcs
    struct sockaddr_in get_address();
    int get_sock();
    int get_connection(); 
    
    //setter function
    void set_connection(int con);

};
}