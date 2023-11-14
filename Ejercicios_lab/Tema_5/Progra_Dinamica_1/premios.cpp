#include <iostream>
#include <vector>

using namespace std;

struct Partida {
   int   inicio;
   int   final;
   float premio;
   int   primeraPosterior;
};

float maximoPremio(vector<Partida>& , int , vector<float>&);
float maximoPremio(vector<Partida>&);



/***************************************************************************
 VERSION 1: RECURSIVA, INEFICIENTE
 ***************************************************************************/


// float maximoPremio(vector<Partida>& partidas, int i)
// {
//     float res;
    
//     if(i == partidas.size() - 1)
//         res = partidas[i].premio;
//     else if(i < partidas.size() - 1 && partidas[i].primeraPosterior == -1)
//         res = max(partidas[i].premio, maximoPremio(partidas, i + 1));
//     else
//         res = max(partidas[i].premio + maximoPremio(partidas, partidas[i].primeraPosterior), maximoPremio(partidas, i+1));

//     return res;
// }

// float maximoPremio(vector<Partida>& partidas)
// {
//     return maximoPremio(partidas , 0);
// }

/***************************************************************************
 VERSION 2: RECURSIVA, EFICIENTE
 ***************************************************************************/
/*

#define DESCONOCIDO -1

float maximoPremio(vector<Partida>& partidas, int i, vector<float>& resultado)
{    
    if (resultado[i] == DESCONOCIDO)
    {
        if(i == partidas.size() - 1)
            resultado[i] = partidas[i].premio;
        else if(i < partidas.size() - 1 && partidas[i].primeraPosterior == -1)
            resultado[i] = max(partidas[i].premio, maximoPremio(partidas, i + 1, resultado));
        else
            resultado[i] = max(partidas[i].premio + maximoPremio(partidas, partidas[i].primeraPosterior, resultado), maximoPremio(partidas, i+1, resultado), resultado);

        return resultado[i];
    }
}

float maximoPremsio(vector<Partida>& partidas)
{
    vector<float> resultado(partidas.size() + 1, DESCONOCIDO);
    return maximoPremio(partidas , 0, resultado);
}

*/

/***************************************************************************
 VERSION 3: NO RECURSIVA, EFICIENTE
 ***************************************************************************/

#define DESCONOCIDO -1

float maximoPremio(vector<Partida>& partidas, int i, vector<float>& resultado)
{    
    if (resultado[i] == DESCONOCIDO)
    {
        if(i == partidas.size() - 1)
            resultado[i] = partidas[i].premio;
        else if(i < partidas.size() - 1 && partidas[i].primeraPosterior == -1)
            resultado[i] = max(partidas[i].premio, maximoPremio(partidas, i + 1, resultado));
        else
            resultado[i] = max(partidas[i].premio + maximoPremio(partidas, partidas[i].primeraPosterior, resultado), maximoPremio(partidas, i+1, resultado), resultado);

        return resultado[i];
    }
}

float maximoPremsio(vector<Partida>& partidas)
{
    vector<float> resultado(partidas.size() + 1, DESCONOCIDO);
    return maximoPremio(partidas , 0, resultado);
}

/***************************************************************************
 EJEMPLO
 ***************************************************************************/

int main () {

   vector<Partida> ejemploCompeticion1 = { {10, 14, 7000, 3},
				 	   {11, 12, 3000, 2},
				 	   {13, 17, 9000, 5},
					   {15, 17, 5000, 5},
					   {16, 19, 8000, -1},
					   {17, 18, 2000, -1}
   };

   float resultado;

   resultado = maximoPremio(ejemploCompeticion1);
   cout << "Maximo premio: " << resultado << endl;
   if (resultado == 15000)
      cout << "OK" << endl;
   else
      cout << "MAL" << endl;

   vector<Partida> ejemploCompeticion2 = { {10, 14, 7000, 3},
				 	   {11, 18, 3000, 7},
				 	   {13, 17, 9000, 5},
					   {15, 17, 5000, 5},
					   {16, 19, 8000, -1},
					   {17, 19, 2000, -1},
					   {17, 18, 4000, 7},
					   {18, 19, 10000, -1},
					   {18, 19, 6000, -1}
   };

   resultado = maximoPremio(ejemploCompeticion2);
   cout << "Maximo premio: " << resultado << endl;
   if (resultado == 26000)
      cout << "OK" << endl;
   else
      cout << "MAL" << endl;

}