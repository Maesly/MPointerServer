#include <iostream>
#include "Servidor/Server.h"
int main() {

    Server* server = new Server(sockaddr_in());
    server->iniciar();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}