#include <iostream>
#include <string>

using namespace std;

#include "CDPDF.h"

CDPDF::Nodo::Nodo(int p) : prioridad{p}, siguiente{nullptr}, anterior{nullptr} {}

CDPDF::CDPDF() : primero{nullptr}, ultimo{nullptr}  /*talla{0}*/ {}


void CDPDF::mostrar() const
{
    cout << "[";
    mostrar(primero);
    cout << "]";
}

void CDPDF::mostrar(Nodo * aux) const
{
    if(aux != nullptr)
    {
        cout << aux->prioridad;
        if(aux != ultimo)
            cout << ", ";
        mostrar(aux->siguiente);
    }
}

void CDPDF::insertar(int prior)
{
    Nodo* nuevo = new Nodo(prior);

    if (primero == nullptr)
    {
        primero = nuevo;
        ultimo = nuevo;
    }
    else if(ultimo->prioridad < nuevo->prioridad)
    {
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
        ultimo = nuevo;
    }
    else if(primero->prioridad > nuevo->prioridad)
    {
        primero->anterior = nuevo;
        nuevo->siguiente = primero;
        primero = nuevo;
    }
    else
    {
        for (Nodo* aux = primero; aux != nullptr; aux = aux->siguiente)
        {
            if (aux->prioridad > prior)
            {
                nuevo->siguiente = aux;
                nuevo->anterior = aux->anterior;
                aux->anterior = nuevo;
                return;
            }
        }
    }

}

void CDPDF::insertarRecursivo(int prior)
{
    insertarRecursivo(prior, primero);
}

void CDPDF::insertarRecursivo(int prior, Nodo* aux)
{
    if(aux == nullptr)
    {
        Nodo* nuevo = new Nodo(prior);
        primero = nuevo;
        ultimo = primero;
    }
    else if(aux == ultimo && aux->prioridad < prior)
    {
        Nodo* nuevo = new Nodo(prior);
        ultimo->siguiente = nuevo;
        nuevo->anterior = aux;
        ultimo = nuevo;
    }
    else if(aux == primero && aux->prioridad > prior)
    {
        Nodo* nuevo = new Nodo(prior);
        nuevo->siguiente = aux;
        aux->anterior = nuevo;
        primero = nuevo;
    }
    else if(aux->prioridad > prior)
    {
        Nodo* nuevo = new Nodo(prior);
        nuevo->siguiente = aux;
        aux->anterior->siguiente = nuevo;
        nuevo->anterior = aux->anterior;
        aux->anterior = nuevo;
    }
    else
    {
        insertarRecursivo(prior, aux->siguiente);
    }
}


void CDPDF::eliminar(int prior)
{
    if(primero == nullptr)
    {
        throw string("Intentando borrar elemento de lista vacía");
    }
    else if(primero->prioridad == prior)
    {
        primero = primero->siguiente;
        primero->anterior = nullptr;
    }
    else if(ultimo->prioridad == prior)
    {
        ultimo->anterior->siguiente = nullptr;
        ultimo = ultimo->anterior;
    }
    else
    {
        for(Nodo* n = primero; n != nullptr; n = n->siguiente)
        {
            if(n->prioridad == prior)
            {
                n->anterior->siguiente = n->siguiente;
                n->siguiente->anterior = n->anterior;
                delete n;
                return;
            }
        }
        throw string("Intentando borrar un elemento no existente");
    }

}


int main()
{
    CDPDF cola;
    cola.insertarRecursivo(3);
    cola.insertarRecursivo(2);
    cola.insertarRecursivo(1);
    cola.insertarRecursivo(4);
    cola.insertarRecursivo(5);
    cola.insertarRecursivo(0);
    cola.eliminar(5);
    cola.mostrar();

    return 0;
}
