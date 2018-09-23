//
// Created by maesly on 21/09/18.
//
#include <cstring>
#include <unistd.h>
#include "Server.h"


Server::Server(sockaddr_in server_addr) {
    salir = false;
}

Server::~Server() {}

void Server::iniciar() {

    server_socket = socket(AF_INET,SOCK_STREAM,0);
    ejecutar();
}

void Server::ejecutar() {

    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PUERTO_SERVER);

    int activado = 1;
    setsockopt(server_socket,SOL_SOCKET,SO_REUSEADDR, &activado, sizeof(activado));

    int bind_status = bind(server_socket,(struct sockaddr*) &server_addr, sizeof(server_addr));
    if(bind_status < 0){
        std::cerr<<"Error binding socket a la direccion local" << std::endl;
        exit(0);
    }

    std::cout << "Estoy escuchando... Estoy oyendo... Estoy sintieeeeeendo.... " << std::endl;
    listen(server_socket,SOMAXCONN);

    while (!salir){
        std::cout << "estoy aqui "<< std::endl;

        client_socket = accept(server_socket,(struct sockaddr*) &cliente_addr,&tamDirClient);

        std::cout << "Se conectó un cliente..."<< std::endl;

        send(client_socket, "Hola",bufsize,0);
        close(client_socket);
    }
    salir = true;
}