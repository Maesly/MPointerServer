//
// Created by maesly on 21/09/18.
//

#ifndef MPOINTER_SERVER_H
#define MPOINTER_SERVER_H

#include <stdio.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <iostream>
#include "../DEFINITIONS.h"

class Server {
private:
    int client_socket, server_socket;
    bool salir;
    int bufsize = 1024;
    char* buffer = new char(bufsize);

    struct sockaddr_in server_addr;
    struct sockaddr_in cliente_addr;
    socklen_t size;

    unsigned int tamDirClient;


public:

    Server(sockaddr_in server_addr);
    ~Server();
    void detener();
    void ejecutar();
    void iniciar();
};


#endif //MPOINTER_SERVER_H
