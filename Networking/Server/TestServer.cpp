#include "TestServer.hpp"

void HDE::TestServer::acceptor()
{
  struct sockaddr_in address = get_socket() => get_address(); 
  int addrlen = sizeof(address); 
  new_socket = accept(get_socket()=>get_sock(), (struct sockaddr *)&address, (socklen_t *)&sizeof(address));
  read(new_socket, buffer, 30000);
}

void HDE::TestServer::handler() 
{
    std:cout << buffer << std:endl;
}

void HDE::TestServer::responder() 
{
    char *hello = "Hello from server";
    write(new_socket, hello, strlen(hello));
    close(new_socket);
} 
