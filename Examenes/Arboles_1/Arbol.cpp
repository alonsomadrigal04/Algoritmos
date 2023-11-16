#include <iostream>
#include <string>
using namespace std;

#include "Arbol.h"


Conjunto::Nodo::Nodo(float valor) : dato{valor}, derecha{nullptr}, izquierda{nullptr} {}

Conjunto::Conjunto() : raiz{nullptr} {}


int Conjunto::consultarProfundidad(float valor) const
{
    int i = 0;
    if(valor == raiz->dato)
        return i;
    return consultarProfundidad(valor, raiz, i);
}

int Conjunto::consultarProfundidad(float valor, Nodo * n, int i) const
{
    if(n == nullptr)
        return -1;
    else if(valor < n->dato)
        return consultarProfundidad(valor, n->izquierda, ++i); // no i++
    else if(valor > n->dato)
        return consultarProfundidad(valor, n->derecha, ++i); // no i++
    else{
        return i;
    }
}

void Conjunto::mostrar() const {
   mostrar(raiz);
   cout << endl;
}

void Conjunto::mostrar(Nodo * n) const {
   if (n != nullptr) {
      mostrar(n->izquierda);
      cout << n->dato <<  " ";
      mostrar(n->derecha);
   }
}

void Conjunto::insertar(int unDato) {
   insertar(unDato, raiz);
}

void Conjunto::insertar(int unDato, Nodo * & n) {
   if (n == nullptr)
      n = new Nodo(unDato);
   else if (unDato < n->dato)
      insertar(unDato, n->izquierda);
   else if (unDato > n->dato)
      insertar(unDato, n->derecha);
   // No insertamos duplicados
}

void Conjunto::eliminarMaximo()
{
    if(raiz->derecha == nullptr && raiz->izquierda != nullptr)
    {
        Nodo * basura = raiz;
        raiz = raiz->izquierda;
        delete basura;
    }
    else if(raiz->derecha == nullptr && raiz->izquierda == nullptr)
    {
        raiz = nullptr;
        delete raiz;
    }
    else if(raiz == nullptr)
        throw string("Intentando borrar elementos de un arbol VACIO");
    else
    {

        eliminarMaximo(raiz);
    }
}

void Conjunto::eliminarMaximo(Nodo * & n)
{
    if(n->derecha == nullptr && n->izquierda == nullptr)
    {
        n = nullptr;
        delete n;
    }
    else if(n->derecha == nullptr && n->izquierda != nullptr)
    {
        Nodo * basura = n;
        n = n->izquierda;
        delete basura;
    }
    else
    {
        eliminarMaximo(n->derecha);
    }
}

int main()
{
    Conjunto c;

    c.insertar(9);
    c.insertar(7);
    c.insertar(8);

    c.eliminarMaximo();
    c.mostrar();


    return 0;
}
