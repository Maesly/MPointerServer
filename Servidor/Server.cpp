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

    client_socket = socket(AF_INET,SOCK_STREAM,0);
    memoria_init('1024');
    ejecutar();
}

void Server::ejecutar() {

    if (client_socket  < 0){
        std::cout << "Error estableciendo el socket del cliente."<< std::endl;
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(PUERTO_SERVER);

    if((bind( client_socket, (struct sockaddr*) &server_addr, sizeof(server_addr))) < 0 ){
        std::cout << "Error enlazando la conexion, la conexion ya ha sido creada "<< std::endl;
    }
    size = sizeof(server_addr);

    std::cout << "Estoy escuchando clientes... " << std::endl;
    listen(client_socket,SOMAXCONN);

    int clienteEstado;

    while (!salir){
        std::cout << "Estoy Aquí "<< std::endl;
        char* buffer = (char *) calloc(1, 1024);
        char* bufferEnvio = (char *) calloc(1, 1024);

        int solicitud = 0;

        server_socket = accept(client_socket,(struct sockaddr*) &server_addr,&size);
        std::cout << "Se conectó un cliente..."<< std::endl;

        recv(server_socket,buffer,bufsize,0);
        printf("%s\n", buffer);
        strcpy(bufferEnvio, "Este mensaje fue enviado desde el SERVIDOR");
        send( server_socket, bufferEnvio, 1024, 0);
        clienteEstado = 0;

        while(clienteEstado == 0){


            recv(server_socket,buffer,1024,0);
            strcpy(bufferEnvio,"Mensaje recibido\n");
            send(server_socket,bufferEnvio,1024,0);


            json solicitudCliente = json::parse(buffer);
            solicitud = solicitudCliente["Solicitud"];


            if( solicitud == 1 ){

                memoriaServer[0] = 45;
                std::cout << libre() << std::endl;
                // Ingresa a la lista el ID del cliente
                head_map->insertEnd(contID,libre(),1);
                head_map->imprimirList();

                // envia el ID en Json
                json enviarID;
                enviarID["ID"] = contID;

                std::string stringEnviar = enviarID.dump();
                char *mensajejsonchar = &stringEnviar[0u];
                std::cout << "Mpointer ingresado en memoria"<< std::endl;

                strcpy(bufferEnvio,"Ingresado\n");
                send(server_socket,mensajejsonchar,1024,0);
                contID++;
                clienteEstado = 1;

            }

            if( solicitud == 2 ){
                recv(server_socket, buffer, 1024, 0);
                printf("%s\n", buffer);

                json ingresarElemento = json::parse(buffer);
                int id = ingresarElemento["ID"];
                int valor = ingresarElemento["ValorIngresar"];

                ingresarMemoria(head_map->obteneroffset(id), valor);

                std::cout << "Mpointer ingresado en memoria"<< std::endl;

                std::cout << "Valor ingresado en memoria"<< std::endl;
                strcpy(bufferEnvio,"Modificado\n");
                send(server_socket,"Ingresado isdafafv",1024,0);
                clienteEstado = 1;


            }

            if( solicitud == 4 ){
                std::cout << "Elemento liberado de la memoria"<< std::endl;
                strcpy(bufferEnvio,"Liberado\n");
                send(server_socket,bufferEnvio,1024,0);
                clienteEstado = 1;
            }
      }
        close(server_socket);
        free(buffer);
        free(bufferEnvio);
        std::cout << "Se cerró el socket del cliente" << std::endl;
    }
}

void Server::memoria_init(char bytes) {

    memoriaServer = (int*)calloc(bytes, sizeof(int));
    std::cout << "Se creó la memoria del server" << std::endl;


}

int* Server::ingresarMemoria(int* offset, int valor) {

    for (int i = 0; i < sizeof(memoriaServer); ++i) {
        if(memoriaServer[*offset] == 1){
            memoriaServer[*offset] = valor;

            return &memoriaServer[i];
        }
    }
}
int* Server::libre() {

    for(int i = 0; i < sizeof(memoriaServer);i++){
        if(memoriaServer[i]== 0){
            memoriaServer[i] = 1;
            return &memoriaServer[i];
        }
    }


}
