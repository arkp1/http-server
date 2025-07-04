#include "SimpleSocket.hpp"

HDE::SimpleSocket::SimpleSocket(int domain, int service, int protocol,
     int port, u_long interface, ) 
{
    //defining address structure
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);
    //establish socket
    sock = socket(domain, service, protocol);
    test_connection(sock);
}

//test connection virtual function
void HDE::SimpleSocket::test_connection(int item_to_test) 
{
    //confirm that the sokcet or connecion is properly established
    if(item_to_test < 0) 
    {
        perror("Failed to connect!...");
        exit(EXIT_FAILURE);
    }
}

//Getter fucntions

struct sockaddr_in HDE::SimpleSocket::get_address()
{
    return address;
}

int HDE::SimpleSocket::get_sock()
{
    return sock;
}

int HDE::SimpleSocket::get_connection()
{
    return connection;
}

int HDE::SimpleSocket::set_connection(int con)
{
    connection = con;
}


