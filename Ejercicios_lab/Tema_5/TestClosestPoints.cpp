 
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>

using namespace std;

typedef pair<float, float> Punto;



float distanciaMinima(const vector<Punto> matriz)
{
    vector<Punto> copia = matriz;
    sort(copia.begin(), copia.end());

}





void ver(const vector<Punto> & puntos) {

   for (const auto & p : puntos)
      cout << "( " << p.first << " , " << p.second << " )";

}

int main () {

   cout << "Primera prueba: con puntos elegidos" << endl;
   cout << "===================================" << endl;
   
   vector<Punto> puntos = {Punto(2, 3), Punto(5,7), Punto(3, 4), Punto(4, 4), Punto(4, 4), Punto(5,7)};

   while (puntos.size() >= 2) {
      cout << "Puntos: ";
      ver(puntos);
      cout << " ---> Distancia minima: " << distanciaMinima(puntos) << endl;
      puntos.pop_back();
   }


   cout << endl;
   cout << "Segunda prueba: con puntos generados aleatoriamente" << endl;
   cout << "===================================================" << endl;
   
   default_random_engine default_random;
   uniform_real_distribution<float> generadorAleatorio(-1000.0, 1000.0);

   for (int talla = 2, tallaMax = 10; tallaMax <= 100000; tallaMax *= 10)
    
      for (; talla < tallaMax; talla += tallaMax / 10) {
      
	 while(puntos.size() < talla)
	    puntos.push_back(Punto(generadorAleatorio(default_random), generadorAleatorio(default_random)));
      
	 float distancia = distanciaMinima(puntos);
      
	 cout << "Cantidad de puntos: " << talla << " ---> Distancia minima: " << distancia << endl;
      }

}
