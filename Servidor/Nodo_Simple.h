#include <clocale>

//
// Created by maesly on 24/09/18.
//

#include <string>

#ifndef MPOINTERSERVER_NODO_SIMPLE_H
#define MPOINTERSERVER_NODO_SIMPLE_H
class Nodo{

private:

    int ID = 0;
    Nodo* enlace;
    int* offset;
    int length;
public:

    Nodo(int id,int* offset, int length){

        this->ID = id;
        this->offset = offset;
        this->length = length;
        this->enlace = NULL;

    }

    Dato  getID() const{
        return ID;
    }

    Nodo* sigNodo() const {
        return enlace;
    }

    void setSigNodo(Nodo* siguiente){
        this->enlace = siguiente;
    }

    char setOffset(int* offset){
        this->offset = offset;
    }

    friend class Lista_Enlazada_Simple;

};

#endif //MPOINTERSERVER_NODO_SIMPLE_H
