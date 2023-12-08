
#include <iostream>
#include <limits>
using namespace std;

#include "ColaDePrioridad.h"

ColaDePrioridad::ColaDePrioridad(int capacidad)
   : prioridad{vector<float>(capacidad, -1)},
     talla{0} {

}

void ColaDePrioridad::insertar(int identificador, float prioridadInicial) {
   // Suponemos 0 <= identificador < capacidad, prioridadInicial >= 0, y no esta dentro

   prioridad[identificador] = prioridadInicial;
   talla++;

}

void ColaDePrioridad::cambiarPrioridad(int identificador, float nuevaPrioridad) {
   // Suponemos 0 <= identificador < capacidad, nuevaPrioridad >= 0 y esta dentro

   prioridad[identificador] = nuevaPrioridad;

}

int ColaDePrioridad::eliminarMinimo() {
   // Suponemos que no se llama a este metodo con cola de prioridad vacia

   int identificadorMinimo = -1;
   for (int identificador = 0; identificador < prioridad.size(); identificador++)
      if (prioridad[identificador] != -1
	  && (identificadorMinimo == -1
	      || prioridad[identificador] < prioridad[identificadorMinimo]))
	 identificadorMinimo = identificador;
   prioridad[identificadorMinimo] = -1;
   talla--;
   return identificadorMinimo;

}

bool ColaDePrioridad::estaVacia() const {

   return talla == 0;

}