
#include <iostream>
using namespace std;

#include "Conjuntok.h"

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


int Conjunto::buscarKesimo(int k) const
{
      Nodo * n = raiz;
      while (n != nullptr)
         if (k < n->indice)
            n = n->izquierdo;
         else if (k > n->dato)
            n = n->derecho;
         else
	 return true;
   return false;
}



