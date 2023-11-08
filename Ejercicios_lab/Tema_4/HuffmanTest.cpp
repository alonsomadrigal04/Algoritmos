
#include <iostream>
#include <string>
#include <vector>
#include <utility> // pair
#include <cstdlib> // rand

using namespace std;

#include "Huffman.h"

int main() {
  
   vector<string> pruebas =  {"AEIOU", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "ZU", "A", ""};

   for (const string & alfabeto : pruebas) {

      cout << endl << "Probando con alfabeto [" << alfabeto << "]" << endl;
      
      vector< pair<char, float> > datos;
      
      cout << "Generando frecuencias aleatorias como datos de prueba:" << endl;
      for (char caracter : alfabeto) {
	 int frecuencia = rand() % 100;
	 cout << " [" << caracter << ":" << frecuencia << "]" << endl;
	 datos.push_back( make_pair(caracter, frecuencia) );
      }
      
      try {
	 Huffman miCodificador(datos);
	 
	 vector<string> mensajes = {"A", "E", "I", "O", "U", "EI", "UU", "UZU", "OUIA"};
	 
	 for (string mensaje : mensajes) {
	    try {
	       string mensajeCodificado   = miCodificador.codificar(mensaje);
	       string mensajeDecodificado = miCodificador.decodificar(mensajeCodificado);
	       if (mensajeDecodificado != mensaje)
		  cout << "MAL: ";
	       else
		  cout << "BIEN: ";
	       cout << mensaje << "--->" << mensajeCodificado << "--->" << mensajeDecodificado << endl;
	    } catch(string error) {
	       cout << "ERROR con [" << mensaje << "]: " << error << endl;
	    }
	 }
      } catch (string error) {
	 cout << "ERROR: " << error << endl;
      }
   }

}