
#include <iostream>
#include <string>
using namespace std;

#include "ColaDePrioridad.h"

ColaDePrioridad::Nodo::Nodo(int laPrioridad, Nodo * elSiguiente)
   : prioridad{laPrioridad}, siguiente{elSiguiente} {
}

ColaDePrioridad::ColaDePrioridad() : primero{nullptr}, minimo{nullptr} {
}
  
void ColaDePrioridad::insertar(int prioridad) {
   primero = new Nodo(prioridad, primero);

   if (minimo == nullptr || primero->prioridad < minimo->prioridad)
      minimo = primero;
}

int ColaDePrioridad::consultarMinimo() const {
   if (minimo == nullptr)
      throw string("Intentando consultar el minimo en una cola de prioridad vacia");

   return minimo->prioridad;
}

void ColaDePrioridad::eliminarMinimo() {
   if (primero == nullptr)
      throw string("Intentando eliminar el minimo en una cola de prioridad vacia");

   if (minimo == primero)
      primero = primero->siguiente;
   else {
      Nodo * anterior;
      for (anterior = primero; anterior->siguiente != minimo; anterior = anterior->siguiente) {
      }
      anterior->siguiente = minimo->siguiente;
   }
   delete minimo;
   minimo = nullptr;
   for (Nodo * actual = primero; actual != nullptr; actual = actual->siguiente)
      if (minimo == nullptr || actual->prioridad < minimo->prioridad)
	 minimo = actual;
}

/* Otra version con el mismo coste, combinando los dos bucles en uno:
void ColaDePrioridad::eliminarMinimo() {
   if (primero == nullptr)
      throw string("Intentando eliminar el minimo en una cola de prioridad vacia");

   Nodo * nuevoMinimo = nullptr, * anterior = nullptr;
   for (Nodo * actual = primero; actual != nullptr; actual = actual->siguiente) {
      if (actual == minimo) {
	 if (anterior == nullptr) {
	    primero = minimo->siguiente;
	 } else {
	    anterior->siguiente = minimo->siguiente;
	 }
      } else {
	 if (nuevoMinimo == nullptr || actual->prioridad < nuevoMinimo->prioridad) {
	    nuevoMinimo = actual;
	 }
      }
      anterior = actual;
   }
   delete minimo;
   minimo = nuevoMinimo;
}
*/

bool ColaDePrioridad::estaVacia() const {
   return primero == nullptr;
}

void ColaDePrioridad::mostrar() const {
   cout << "[";
   for (Nodo * actual = primero; actual != nullptr; actual = actual->siguiente) {
      cout << actual->prioridad;
      if (actual->siguiente != nullptr)
	 cout << ", ";
   }
   cout << "]";
}


int main()
{
    ColaDePrioridad cola;
    
    cola.insertar(7);
    cola.insertar(6);
    cola.insertar(10);

    cola.mostrar();


    return 0;
}