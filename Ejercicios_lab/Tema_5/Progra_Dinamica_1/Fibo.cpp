
// Este es un ejemplo inicial para ilustrar el uso de la tabla de
// resultados en Programacion Dinamica

// Descomenta la version que quieras probar

#include <iostream>
#include <vector>

using namespace std;

/***************************************************************************
 VERSION 1: RECURSIVA, INEFICIENTE
 ***************************************************************************/

/*
long long fibonacci(int i) {

   long long resultado;

   if (i <= 1)
      resultado = i;
   else
      resultado = fibonacci(i - 1)
	          + fibonacci(i - 2);

   return resultado;

}
*/

/***************************************************************************
 VERSION 2: RECURSIVA, EFICIENTE
 ***************************************************************************/

/*
#define DESCONOCIDO -1

long long fibonacci(int i,
		    vector<long long> & resultado) {

   if (resultado[i] == DESCONOCIDO)
      if (i <= 1)
	 resultado[i] = i;
      else
	 resultado[i] = fibonacci(i - 1, resultado)
                              + fibonacci(i - 2, resultado);

   return resultado[i];

}

long long fibonacci(int n) {

   vector<long long> resultado(n + 1, DESCONOCIDO);
   return fibonacci(n, resultado);

}
*/

/***************************************************************************
 VERSION 3: NO RECURSIVA, EFICIENTE
 ***************************************************************************/

/*
long long fibonacci(int n) {

   vector<long long> resultado(n + 1);

   for (int i = 0; i <= n; i++)
      if (i <= 1)
	 resultado[i] = i;
      else
	 resultado[i] = resultado[i - 1] + resultado[i - 2];

   return resultado[n];

}
*/

/***************************************************************************
 VERSION 3.b: NO RECURSIVA, EFICIENTE, REDUCIENDO COSTE ESPACIAL
 ***************************************************************************/

/*
long long fibonacci(int n) {

   long long resultado;

   if (n <= 1)
      resultado = n;
   else {
      long long penultimo = 0,
	        ultimo = 1;
      for (int i = 2; i <= n; i++) {
	 resultado = ultimo + penultimo;
	 penultimo = ultimo;
	 ultimo = resultado;
      }
   }

   return resultado;

}
*/

/***************************************************************************
 EJEMPLO
 ***************************************************************************/

int main () {

   for (int dato = 10; dato <= 50; dato += 5) {
      cout << "Fibonacci(" << dato << ") = " << endl;
      cout << "   " << fibonacci(dato) << endl;
   }

}
