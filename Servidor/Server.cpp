//
// Created by maesly on 21/09/18.
//
#include <cstring>
#include "Server.h"

Server::Server() {

    //Definir la direccion del socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PUERTO_SERVER);
    server_address.sin_addr.s_addr = inet_addr(DIRECCION_IP);

    //Crear el socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        std::cerr << "Error estableciendo el Socket del Servidor" << std::endl;
        exit(0);
    }

    //Bind de nuestro socket a un IP y puerto especificos
    std::cout << "Binding Server" << std::endl;
    int bind_status = bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    if (bind_status < 0) {
        std::cerr << "Error binding socket a la dirección local" << std::endl;
        exit(0);
    }

    //Escuchar por conexiones
    std::cout << "Esperando que un cliente se conecte..." << std::endl;
    listen(server_socket, 5); //El socket y cuantos sockets pueden estar conectados

    sockaddr_in newSockAddr;
    socklen_t newSockAddrSize = sizeof(newSockAddr);

    //Acepta el cliente entrante y maneja la conexion

    //Buffer para recibir mensajes
    char mensaje_cliente[300];

    //Buffer de solicitudes
    char mensaje_solicitud[1];

    //Buffer para enviar mensajes
    char mensaje_servidor[256] = "Variable creada con exito";

    for(;;) {

        int client_socket = accept(server_socket, (sockaddr *) &newSockAddr, &newSockAddrSize);
        if (client_socket < 0) {
            std::cerr << "Error aceptando la solicitud del cliente." << std::endl;
            exit(1);
        }
        std::cout << " Cliente Conectado " << std::endl;

        std::cout << " Esperando mensaje del Cliente " << std::endl;

        memset(&mensaje_cliente, 0, sizeof(mensaje_cliente)); // limpia el buffer del mensaje del cliente
        memset(&mensaje_solicitud,0, sizeof(mensaje_solicitud)); //limpia el buffer del mensaje de solicitud del clinete

        std::cout << "Recibiendo mensaje del cliente" << std::endl;
        recv(client_socket,(char*) &mensaje_solicitud, sizeof(mensaje_solicitud),0);

        if(strcmp(mensaje_solicitud, "1") == 0) recibirCliente(&client_socket);

    }
}

void Server::recibirCliente(int *socket_cliente) {

    char mensaje_cliente[300];
    memset(&mensaje_cliente, 0, sizeof(mensaje_cliente));

    send(*socket_cliente,"Ok\n", sizeof("Ok\n"),0);

    recv( *socket_cliente, (char*) &mensaje_cliente, sizeof(mensaje_cliente),0 );


}