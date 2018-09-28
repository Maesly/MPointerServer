//
// Created by maesly on 24/09/18.
//

#include "Lista_Enlazada_Simple.h"

bool Lista_Enlazada_Simple::esVacia() {
    return head == NULL;
}
void Lista_Enlazada_Simple::insertEnd(int id, int* offset, int length) {
    Nodo* temp = head;
    Nodo* nuevo = new Nodo(id,offset,length);

    if(temp == head){
        head = nuevo;

    }else{
        while(temp->sigNodo() != NULL){
            temp = temp->sigNodo();
        }
        temp->setSigNodo(nuevo);
        nuevo->setSigNodo(NULL);

    }
    cantNodos++;
}

void Lista_Enlazada_Simple::deletePosicion(int posicion) {

    Nodo* anterior = head;
    Nodo* siguiente = head->sigNodo();
    int cont = 0;
    if(esVacia()){
        std::cout << "No hay elementos en la lista" << std::endl;
    }else if(posicion > cantNodos -1){
        std::cout << "Error de indice" << std::endl;
    }
    else{
        while( cont < posicion-1 ){
            anterior = anterior->sigNodo();
            siguiente = siguiente->sigNodo();
            cont++;
        }
        anterior->setSigNodo(siguiente->sigNodo());
        cantNodos--;
        delete(siguiente);
    }
}


int* Lista_Enlazada_Simple::obteneroffset(int id) {

    Nodo* temp = head;
    int cont = 0;

    if(esVacia()) {
        std::cout << "No hay elementos en la lista" << std::endl;
    }else{
        while ((temp->sigNodo() != NULL) && (temp->ID != id)){
            temp = temp->sigNodo();
            cont++;
        }
        if(temp->ID == id){
            std::cout << "\n El elemento " << id << "esta en la posicion: " << cont << std::endl;
            return temp->offset;
        }else{
            std::cout << "El elemento no se encuentra en la lista " << std::endl;
            return nullptr;
        }
    }

}

void Lista_Enlazada_Simple::imprimirList() {

    Nodo* n = head;      //Crea un puntero y lo posiciona en la cabeza de la lista

    if( esVacia()){    // Valida si l lista esta vacía
        std::cout << "La lista se encuentra vacía\n" << std::endl;
    }
    while(n != NULL){ // Ciclo que recorre la lista e imprime cada elemento

        std::cout << "ID: " << n->getID() <<"\t";
        std::cout << "Offset: " << n->offset <<"\t";
        std::cout << "length: " << n->length <<"\t";
        n = n->sigNodo();
    }
    std::cout << "\nCantidad de nodos en la lista: " << cantNodos << std::endl;
}