
// COMPLETA LO QUE FALTA

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/***************************************************************************
 VERSION 1: RECURSIVA, INEFICIENTE
 ***************************************************************************/
float minimoCostePintura(const vector<vector<float> > & costePintura,
			 int colorProhibido,
			 int casa) {
   
   // Minimo coste de pintar desde esa casa hasta la ultima si en esa casa NO SE PUEDE USAR ese color
   
   int casas = costePintura[0].size();

   float resultado;
   
   if (casa == casas)
      resultado = 0;
   else  if (colorProhibido == 0)
      resultado = min(costePintura[1][casa] + minimoCostePintura(costePintura, 1, casa + 1),
		      costePintura[2][casa] + minimoCostePintura(costePintura, 2, casa + 1));
   else if (colorProhibido == 1)
      resultado = min(costePintura[0][casa] + minimoCostePintura(costePintura, 0, casa + 1),
		      costePintura[2][casa] + minimoCostePintura(costePintura, 2, casa + 1));
   else
      resultado = min(costePintura[0][casa] + minimoCostePintura(costePintura, 0, casa + 1),
		      costePintura[1][casa] + minimoCostePintura(costePintura, 1, casa + 1));
   
   return resultado;

}


float minimoCostePintura(const vector<vector<float> > & costePintura) {
   
   return min({costePintura[0][0] + minimoCostePintura(costePintura, 0, 1),
	       costePintura[1][0] + minimoCostePintura(costePintura, 1, 1),
	       costePintura[2][0] + minimoCostePintura(costePintura, 2, 1)
              });
   
}

/***************************************************************************
 VERSION 2: RECURSIVA, EFICIENTE
 ***************************************************************************/


/***************************************************************************
 VERSION 3: NO RECURSIVA, EFICIENTE
 ***************************************************************************/


/***************************************************************************
 EJEMPLO
 ***************************************************************************/

int main () {

   vector<vector<float> > ejemploCostePintura = { {300, 600,  200, 1000, 1500, 500, 900},
                                                  {400, 1600, 400, 700,  1200, 400, 200},
                                                  {500, 1300, 600, 100,  300,  500, 800} };

   float resultado = minimoCostePintura(ejemploCostePintura);
   cout << "Minimo coste pintura: " << resultado << endl;
   if (resultado == 3300)
      cout << "OK" << endl;
   else
      cout << "MAL" << endl;

}