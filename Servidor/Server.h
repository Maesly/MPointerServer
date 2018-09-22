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

public:

    Server();
    void recibirCliente(int* socket_cliente);
    void Buscar_Cliente(int* socket_cliente);
};


#endif //MPOINTER_SERVER_H
