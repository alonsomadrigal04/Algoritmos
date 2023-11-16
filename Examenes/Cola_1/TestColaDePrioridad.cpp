
#include <iostream>
using namespace std;

#include <cstdlib>   // rand

#include "ColaDePrioridad.h"

int main () {
   ColaDePrioridad cola;
   int i;

   for (i = 55; i < 100; i += 11) {
      cola.insertar(i);
      cola.insertar(i);
   }

   cout << "Cola=";
   cola.mostrar();
   cout << endl;

   while ( ! cola.estaVacia()) {
      cout << "Eliminando " << cola.consultarMinimo() << ": Cola=";
      cola.eliminarMinimo();
      cola.mostrar();
      cout << endl;

      int unDatoCualquiera = rand() % 100;
      cout << "Insertando " << unDatoCualquiera << ": Cola=";
      cola.insertar(unDatoCualquiera);
      cola.mostrar();
      cout << endl;

      cout << "Eliminando " << cola.consultarMinimo() << ": Cola=";
      cola.eliminarMinimo();
      cola.mostrar();
      cout << endl;
   }

}
