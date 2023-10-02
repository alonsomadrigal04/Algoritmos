

#include <iostream>
#include <string>
using namespace std;

#include "Cola.h"

Cola::Nodo::Nodo(int d) : dato{d}, siguiente{nullptr} {
}

Cola::Cola() : primero{nullptr}, ultimo{nullptr} {
}
  
void Cola::encolar(int d) {
   Nodo * nuevo = new Nodo(d);

   if (primero == nullptr) // Tambien valdria if (estaVacia()); asi nos ahorramos la llamada
      primero = nuevo;
   else
      ultimo->siguiente = nuevo;
   ultimo = nuevo;
}

void Cola::desencolar() {
   if (primero == nullptr)
      throw string("Intentando desencolar en una cola vacia");

   Nodo * aux = primero;
   primero = primero->siguiente;
   delete aux;
   if (primero == nullptr)
      ultimo = nullptr;
}

int Cola::consultarPrimero() const {
   if (primero == nullptr)
      throw string("Intentando consultar el primero en una cola vacia");
   return primero->dato;
}

void Cola::mostrar(Nodo * aux) const {
   if (aux != nullptr) {
      cout << aux->dato;
      if (aux != ultimo)
	 cout << ", ";
      mostrar(aux->siguiente);
   }
}

void Cola::mostrar() const {
   cout << "[";
   mostrar(primero);
   cout << "]";
}

bool Cola::estaVacia() const {
   return primero == nullptr;
}
