
// COMPLETA LO QUE FALTA

#include <iostream>
#include <vector>

using namespace std;

/***************************************************************************
 VERSION 1: RECURSIVA, INEFICIENTE
 ***************************************************************************/


/***************************************************************************
 VERSION 2: RECURSIVA, EFICIENTE
 ***************************************************************************/


/***************************************************************************
 VERSION 3: NO RECURSIVA, EFICIENTE
 ***************************************************************************/


/***************************************************************************
 VERSION 4: NO RECURSIVA, EFICIENTE, MOSTRANDO MONEDAS ELEGIDAS
 ***************************************************************************/


/***************************************************************************
 EJEMPLOS
 ***************************************************************************/

int main () {
   vector<int> monedasMordor = {5, 21, 1, 25};
   vector<int> monedasPandora = {1, 4, 6, 10};

   int resultado;

   cout << "Probando monedas de Mordor:" << endl;
   cout << "===========================" << endl << endl;

   cout << "Deuda: 22" << endl;
   resultado = minimaCantidadMonedas(monedasMordor, 22);
   cout << "Total monedas: " << resultado << endl;
   if (resultado == 2)
      cout << "OK" << endl << endl;
   else
      cout << "MAL" << endl << endl;
   
   cout << "Deuda: 63" << endl;
   resultado = minimaCantidadMonedas(monedasMordor, 63);
   cout << "Total monedas: " << resultado << endl;
   if (resultado == 3)
      cout << "OK" << endl << endl;
   else
      cout << "MAL" << endl << endl;
   
   cout << "Deuda: 65" << endl;
   resultado = minimaCantidadMonedas(monedasMordor, 65);
   cout << "Total monedas: " << resultado << endl;
   if (resultado == 5)
      cout << "OK" << endl << endl;
   else
      cout << "MAL" << endl << endl;

   cout << "Probando monedas de Pandora:" << endl;
   cout << "============================" << endl << endl;

   cout << "Deuda: 22" << endl;
   resultado = minimaCantidadMonedas(monedasPandora, 22);
   cout << "Total monedas: " << resultado << endl;
   if (resultado == 3)
      cout << "OK" << endl << endl;
   else
      cout << "MAL" << endl << endl;
   
   cout << "Deuda: 63" << endl;
   resultado = minimaCantidadMonedas(monedasPandora, 63);
   cout << "Total monedas: " << resultado << endl;
   if (resultado == 8)
      cout << "OK" << endl << endl;
   else
      cout << "MAL" << endl << endl;
   
   cout << "Deuda: 65" << endl;
   resultado = minimaCantidadMonedas(monedasPandora, 65);
   cout << "Total monedas: " << resultado << endl;
   if (resultado == 8)
      cout << "OK" << endl << endl;
   else
      cout << "MAL" << endl << endl;

}