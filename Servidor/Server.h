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
#include "JSON/json.hpp"
#include "Lista_Enlazada_Simple.h"

struct vectorNodosEliminados{
    int ID = 0;
    int* ptr = NULL;
};

class Server {

private:
    using json = nlohmann::json;
    int client_socket, server_socket;
    bool salir;
    int bufsize = 1024;
    struct sockaddr_in server_addr = { AF_INET, htons(PUERTO_SERVER) } ;
    struct sockaddr_in cliente_addr;
    socklen_t size;
    int contID = 0;
    int* memoriaServer;

    Lista_Enlazada_Simple *head_map = new Lista_Enlazada_Simple();

public:

    Server(sockaddr_in server_addr);
    ~Server();
    void detener();
    void ejecutar();
    void iniciar();
    void memoria_init(char bytes);
    int* ingresarMemoria(int* offset, int valor);
    int* offsetMemoria();
    int* libre();
    int generarID();
};
#endif //MPOINTER_SERVER_H
