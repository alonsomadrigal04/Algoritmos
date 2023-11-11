#include <iostream>
#include <queue>

using namespace std;

#include "Ejercicio_4_2022.h"

Conjunto::Nodo::Nodo(int valor) : dato{valor}, izquierdo{nullptr}, derecho{nullptr}, tallaDerecho{0}, tallaIzquierdo{0} {
}

Conjunto::Conjunto() : raiz{nullptr}, maximo{nullptr} {}


void Conjunto::insertar(int unDato)
{
    
}

void Conjunto::mostrar() const {
   mostrar(raiz);
   cout << endl;
}

void Conjunto::mostrar(Nodo * n) const {
   if (n != nullptr) {
      mostrar(n->izquierdo);
      cout << n->dato << " ";
      mostrar(n->derecho);
   }
}


void Conjunto::encontrarMaximo()
{
    Nodo * aux = raiz;
    while(aux->derecho != nullptr)
        aux = aux->derecho;

    maximo = aux;
}


void Conjunto::eliminarMaximo()
{
    if(raiz == nullptr)
        throw string("Intentando borrar elemento de un arbol vacio");
    

    if(raiz->derecho == nullptr && raiz->izquierdo == nullptr)
    {
        raiz = nullptr;
        delete raiz;
    }
    else if(raiz->derecho == nullptr && raiz->izquierdo != nullptr)
    {
        Nodo * basura = raiz;
        raiz = raiz->izquierdo;
        delete basura;
        encontrarMaximo();

    }
    else if(raiz->derecho != nullptr)
    {
        Nodo * basura = raiz;
        Nodo * padre = basura;
        while(basura->derecho != nullptr)
        {
            padre = basura;
            basura = basura->derecho;
        }
        if(basura->izquierdo != nullptr)
        {
            padre->derecho = nullptr;
            padre->derecho = basura->izquierdo;
            delete basura;
            maximo = nullptr;
        }
        else{
            padre->derecho = nullptr;
            delete basura;
        }

        encontrarMaximo();
    }

}



int  main()
{
    Conjunto c;
    
    c.insertar(9);
    c.insertar(7);
    c.insertar(8);

    c.eliminarMaximo();
    c.eliminarMaximo();

    c.mostrar();
    return 0;
}