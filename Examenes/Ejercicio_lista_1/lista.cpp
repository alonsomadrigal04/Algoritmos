#include <iostream>
#include "lista.h"

using namespace std;

Conjunto::Nodo::Nodo(int valor) : dato{valor}, siguiente{nullptr} {}

Conjunto::Conjunto() : talla{0}, primero{nullptr} {}

void Conjunto::insertar(float valor, int i, Nodo* n)
{
    if(i == 0)
    {
        Nodo * nuevo = new Nodo(valor);
        nuevo->siguiente = n;
        primero = nuevo;
        talla++;
    }
    else if(i == 1)
    {
        Nodo * nuevo = new Nodo(valor);
        nuevo->siguiente = n->siguiente;
        n->siguiente = nuevo;
        talla++;
    }
    else if (n != nullptr)
    {
        insertar(valor, i - 1, n->siguiente);
    }
}

void Conjunto::insertar(float valor, int i)
{
    if (i > talla)
    {
        return;
    }
    insertar(valor, i, primero);
}

void Conjunto::mostrar(Nodo * n)
{
    if (n != nullptr)
    {
        cout << n->dato << endl;
        mostrar(n->siguiente);
    }
}

void Conjunto::mostrar()
{
    mostrar(primero);
}

int main()
{
    // Ejemplo de uso
    Conjunto conjunto;
    conjunto.insertar(10, 0);
    conjunto.insertar(20, 1);
    conjunto.insertar(30, 1);
    conjunto.insertar(40, 0);
    conjunto.insertar(50, 2);

    conjunto.mostrar();

    return 0;
}
