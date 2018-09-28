//
// Created by maesly on 24/09/18.
//

#ifndef MPOINTERSERVER_LISTA_ENLAZADA_SIMPLE_H
#define MPOINTERSERVER_LISTA_ENLAZADA_SIMPLE_H

typedef int Dato;
#include "Nodo_Simple.h"
#include <iostream>

class Lista_Enlazada_Simple {

protected:

    Nodo* head;
    int cantNodos;

public:

    Lista_Enlazada_Simple(){
        head = NULL;
        cantNodos = 0;
    }

    bool esVacia();
    void insertEnd(int id, int* offset, int length);
    void deletePosicion(int id);
    int* obteneroffset(int id);

    int cantNodosLista(){
        return cantNodos;
    }

    void imprimirList();


};


#endif //MPOINTERSERVER_LISTA_ENLAZADA_SIMPLE_H
