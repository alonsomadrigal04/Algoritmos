
#include <iostream>

#include <utility> // pair
#include <map>

using namespace std;

int main() {
   map<string, int> puntuacion = {{"Bilbao", 99}, {"Oviedo", 88}};

   // INSERTAR (version 1)
   puntuacion.insert(make_pair("Barcelona", 22)); // Cada elemento del diccionario es de tipo pair

   // INSERTAR (version 2)
   puntuacion.emplace("Sevilla", 33); // Asi el pair se crea internamente

   // INSERTAR (version 3)
   puntuacion["Valencia"] = 11; // Esto es equivalente a lo anterior y permite trabajar con diccionarios
                                // "como si" fuesen vectores indexados por la clave.

   // RECORRER
   cout << endl << "Tras las inserciones:" << endl;
   for (const auto & elemento : puntuacion)
      cout << elemento.first << ": " << elemento.second << endl; // Recuerda que los elementos son de tipo pair

   // BUSCAR (version 1): con el metodo at, si no hay ningun elemento con esa clave, obtenemos una excepcion
   cout << endl << "Primeras busquedas:" << endl;
   try {
      cout << "Barcelona: " << puntuacion.at("Barcelona") << endl;
      cout << "Sevilla: "   << puntuacion.at("Sevilla") << endl;
      cout << "Zaragoza: "  << puntuacion.at("Zaragoza") << endl; // Aqui se interrumpe el bloque try
      cout << "Valencia: "  << puntuacion.at("Valencia") << endl;
   } catch(out_of_range error) {
      cout << "No tenemos la puntuacion de alguien (" << error.what() << ")" << endl;
   }

   // BUSCAR (version 2): con los corchetes, si no hay ningun elemento con esa clave, se crea uno nuevo
   cout << endl << "Segundas busquedas:" << endl;
   cout << "Barcelona: " << puntuacion["Barcelona"] << endl;
   cout << "Sevilla: "   << puntuacion["Sevilla"] << endl;
   cout << "Zaragoza: "  << puntuacion["Zaragoza"] << endl; // Aqui se crea un elemento nuevo
   cout << "Valencia: "  << puntuacion["Valencia"] << endl;

   cout << endl << "Tras las busquedas:" << endl;
   for (const auto & elemento : puntuacion)
      cout << elemento.first << ": " << elemento.second << endl;
   cout << "Ahora tenemos seis elementos !!! Parece magia pero es consecuencia del comportamiento de los corchetes." << endl;

   // MODIFICAR: la diferencia entre at y corchetes es la misma de antes
   cout << endl << "Modificaciones:" << endl;
   try {
      puntuacion["Valencia"] = 44;
      puntuacion.at("Sevilla") = 55;
      puntuacion["Tenerife"] = 66; // Aqui se crea un elemento nuevo
      puntuacion.at("Paris") = 77; // Aqui se interrumpe el bloque try
      puntuacion["Londres"] = 333;
      puntuacion["Bilbao"] = 111;
   } catch(out_of_range error) {
      cout << "No podemos modificar la puntuacion de alguien (" << error.what() << ")" << endl;
   }

   cout << endl << "Tras las modificaciones:" << endl;
   for (const auto & elemento : puntuacion)
      cout << elemento.first << ": " << elemento.second << endl;

   // ELIMINAR
   puntuacion.erase("Valencia");

   cout << endl << "Tras eliminar Valencia:" << endl;
   for (const auto & elemento : puntuacion)
      cout << elemento.first << ": " << elemento.second << endl;

   // VACIAR
   puntuacion.clear();

   cout << endl << "Tras vaciar:" << endl;
   for (const auto & elemento : puntuacion)
      cout << elemento.first << ": " << elemento.second << endl;

}