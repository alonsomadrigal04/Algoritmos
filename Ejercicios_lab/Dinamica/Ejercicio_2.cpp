
// COMPLETA LO QUE FALTA
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/***************************************************************************
 VERSION 1: RECURSIVA, INEFICIENTE
 ***************************************************************************/

float minimoCostePaseo(vector<float>& pesoCorto, vector<float>& pesoLargo, int aldea)
{
    float resultado;

    if(aldea == pesoCorto.size())
        resultado = 0;
    else if(aldea == pesoCorto.size() - 1)
        resultado = pesoCorto[aldea];
    else{
        resultado = min(pesoCorto[aldea] + minimoCostePaseo(pesoCorto, pesoLargo, aldea + 1), pesoLargo[aldea] + 
        minimoCostePaseo(pesoCorto, pesoLargo, aldea + 2));
    }

    return resultado;

}

float minimoCostePaseo(vector<float>& pesoCorto, vector<float>& pesoLargo)
{
    return minimoCostePaseo(pesoCorto, pesoLargo, 0);
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

int main() {

   // Este ejemplo corresponde a un rio con n = 7 aldeas numeradas de 0 a 6
   // El paseo corto esta disponible en las aldeas 0 a 5
   // El paseo largo esta disponible en las aldeas 0 a 4

   vector<float> ejemploPaseoCorto = {80, 20,  60,  50, 90, 10};
   vector<float> ejemploPaseoLargo = {70, 30, 100, 110, 40};

   float resultado = minimoCostePaseo(ejemploPaseoCorto, ejemploPaseoLargo);
   cout << "Minimo coste paseo: " << resultado << endl;
   if (resultado == 200)
      cout << "OK" << endl;
   else
      cout << "MAL" << endl;

}