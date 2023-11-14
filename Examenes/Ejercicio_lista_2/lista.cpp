#include <iostream>
#include "lista.h"

using namespace std;

Conjunto::Nodo::Nodo(float valor) : dato{valor}, siguiente{nullptr} {}

Conjunto::Conjunto() : primero {nullptr} {}

// O(n)
bool Conjunto::buscar(float dato) const {
    Nodo* actual = primero;
    while (actual) {
        if (actual->dato == dato) {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

// O(1)
void Conjunto::Insertar(float dato) {
    // Verificar si el dato ya está en el conjunto
    if (!buscar(dato)) {
        Nodo* nuevoNodo = new Nodo(dato);
        nuevoNodo->siguiente = primero;
        primero = nuevoNodo;
    }
}


// O(n)
void Conjunto::Eliminar(float dato) {
    Nodo* actual = primero;
    Nodo* anterior = nullptr;

    while (actual) {
        if (actual->dato == dato) {
            if (anterior) {
                anterior->siguiente = actual->siguiente;
            } else {
                primero = actual->siguiente;
            }
            delete actual;
            return;
        }

        anterior = actual;
        actual = actual->siguiente;
    }
}

void Conjunto::eliminarComunes(const Conjunto & v2)
{
    Nodo * n1 = primero;
    Nodo * n2 = v2.primero;

    while(n1 != nullptr)
    {
        if(n1->dato == n2->dato)
        {
            Eliminar(n1->dato);
            n1 = n1->siguiente;
            n2 = n2->siguiente;
        }
        else 
        {
            n2 = n2->siguiente;
        }

        if (n2 == nullptr)
        {
            n2 = v2.primero;
            n1 = n1->siguiente;
        }
    }
}

void Conjunto::mostrar(Nodo * n) const
{
    if (n != nullptr)
    {
        cout << n->dato << endl;
        mostrar(n->siguiente);
    }
}

void Conjunto::mostrar() const
{
    mostrar(primero);
}


// Ejemplo de uso:
int main() {
    Conjunto c1;
    c1.Insertar(1);
    c1.Insertar(2);
    c1.Insertar(3);

    Conjunto c2;
    c2.Insertar(2);
    c2.Insertar(4);

    c1.eliminarComunes(c2);
    c1.mostrar();

    return 0;
}