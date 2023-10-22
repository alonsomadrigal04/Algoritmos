
#include <iostream>
using namespace std;

#include "Conjunto.h"

Conjunto::Nodo::Nodo(int elDato) : dato{elDato}, izquierdo{nullptr}, derecho{nullptr} {
}

Conjunto::Conjunto() : raiz{nullptr} {
}
  
void Conjunto::insertar(int unDato) {
   insertar(unDato, raiz);
}

void Conjunto::insertar(int unDato, Nodo * & n) {
   if (n == nullptr)
      n = new Nodo(unDato);
   else if (unDato < n->dato)
      insertar(unDato, n->izquierdo);
   else if (unDato > n->dato)
      insertar(unDato, n->derecho);
   // No insertamos duplicados
}

int Conjunto::minimoEnSubarbol(Nodo * n) const { // Sabiendo que n != nullptr
   if (n->izquierdo == nullptr)
      return n->dato;
   return minimoEnSubarbol(n->izquierdo);
}

void Conjunto::eliminar(int unDato) {
   eliminar(unDato, raiz);
}

void Conjunto::eliminar(int unDato, Nodo * & n) {
   if (n == nullptr)
      return;
   if (unDato < n->dato)
      eliminar(unDato, n->izquierdo);
   else if (unDato > n->dato)
      eliminar(unDato, n->derecho);
   else if (n->izquierdo != nullptr && n->derecho != nullptr) {
      n->dato = minimoEnSubarbol(n->derecho);
      eliminar(n->dato, n->derecho);
   } else {
      Nodo * basura = n;
      if (n->izquierdo != nullptr)
	 n = n->izquierdo;
      else
	 n = n->derecho;
      delete basura;
   }
}

bool Conjunto::buscar(int unDato) const {
   Nodo * n = raiz;
   while (n != nullptr)
      if (unDato < n->dato)
	 n = n->izquierdo;
      else if (unDato > n->dato)
	 n = n->derecho;
      else
	 return true;
   return false;
}

int Conjunto::sumarRecursivo() const
{
    return sumarRecursivo(raiz);
}

int Conjunto::sumarRecursivo(Nodo * n) const
{
    if(n == nullptr)
        return 0;
    else
        return n->dato + sumarRecursivo(n->izquierdo) + sumarRecursivo(n->derecho);
}

void Conjunto::incrementarTodos()
{
    return incrementarTodos(raiz);
}

void Conjunto::incrementarTodos(Nodo * n)
{
    if(n == nullptr)
        return;
    else
    {
        n->dato++;
        incrementarTodos(n->derecho);
        incrementarTodos(n->izquierdo);
    }
}

int Conjunto::altura() const
{
    return altura(raiz);
}

int Conjunto::altura(Nodo* n) const
{
    if(n == nullptr) return -1;
    if (altura(n->izquierdo) > altura(n->derecho))
        return altura(n->izquierdo) + 1;
    else
        return altura(n->derecho) + 1;
}


/*

int Conjunto::altura() const {
   return altura(raiz);
}

int Conjunto::altura(Nodo * n) const {
   if (n == nullptr)
      return -1;
   return 1 + max(altura(n->izquierdo), altura(n->derecho));
}

*/

bool Conjunto::noHayHijosSinHermanos() const
{
    return noHayHijosSinHermanos(raiz);
}

bool Conjunto::noHayHijosSinHermanos(Nodo * n) const
{
    if(n->derecho != nullptr && n->izquierdo != nullptr) return noHayHijosSinHermanos(n->izquierdo) && noHayHijosSinHermanos(n->derecho);
    return (n->derecho == nullptr && n->izquierdo == nullptr);
    return false;
        
}

bool Conjunto::arbolesIguales(const Conjunto & otro ) const
{
    return arbolesIguales(raiz, otro.raiz);
}

bool Conjunto::arbolesIguales(Nodo * n1, Nodo* n2) const
{
    if (n1->dato != n2->dato) return false;
    return arbolesIguales(n1->derecho, n2->derecho) && arbolesIguales(n1->izquierdo, n2->izquierdo);
}


