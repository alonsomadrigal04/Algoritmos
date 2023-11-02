
#include <iostream>
#include <utility> // pair

using namespace std;

int main() {

   // Podemos inicializar un pair al declararlo
   pair<string, int> p = {"Bilbao", 99};

   // Podemos acceder directamente (sin metodos) a las componentes del pair
   cout << p.first << ": " << p.second << endl;

   // Podemos modificar las componentes del pair
   p.first = "Oviedo";
   p.second++;
   cout << p.first << ": " << p.second << endl;

   // Podemos crear un nuevo pair con make_pair
   p = make_pair("Pamplona", 33);
   cout << p.first << ": " << p.second << endl;

}