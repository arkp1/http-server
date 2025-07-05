#include "TestServer.hpp"
#include <unistd.h>     
#include <cstring>       
#include <iostream>      
#include <sys/socket.h> 

namespace HDE {

TestServer::TestServer()
    : SimpleServer(AF_INET, SOCK_STREAM, 0, 8082, INADDR_ANY, 10)
{
    launch();
}

void TestServer::acceptor()
{
    struct sockaddr_in address = get_socket()->get_address();
    socklen_t addrlen = sizeof(address);
    new_socket = accept(get_socket()->get_sock(), (struct sockaddr *)&address, &addrlen);
    read(new_socket, buffer, sizeof(buffer));
}

void TestServer::handler()
{
    std::cout << std::string(buffer) << std::flush;
}


void TestServer::responder()
{
const char *hello = 
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/plain\r\n"
    "Content-Length: 17\r\n"
    "\r\n"
    "Hello from server";

;
    write(new_socket, hello, strlen(hello));
    close(new_socket);
}

void TestServer::launch()
{
    while (true)
    {
        std::cout << "===== Waiting =====" << std::endl;
        acceptor();
        handler();
        responder();
        std::cout << "===== Done =====" << std::endl;
    }
}

}
