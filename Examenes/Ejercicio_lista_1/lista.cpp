#include <iostream>
#include "lista.h"

using namespace std;

Conjunto::Nodo::Nodo(int valor) : dato{valor}, siguiente{nullptr} {}

Conjunto::Conjunto() : talla{0}, primero{nullptr} {}

void Conjunto::insertar(int valor, int i)
{
    if (i > talla)
        return;
    insertar(valor, i, primero);
}

void Conjunto::insertar(float valor, int i, Nodo* n)
{

}