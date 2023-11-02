#include <iostream>
#include <vector>
#include <utility> // pair
#include <queue>
using namespace std;

#include "Huffman.h"

Huffman::Nodo::Nodo(char car, float frec) : caracter{car}, frecuencia{frec}, padre{nullptr}, izquierdo{nullptr}, derecho{nullptr}, bit{' '} {

}

Huffman::Huffman(const vector<pair<char, float>> & frec) : raiz{nullptr}
{

    class CompararNodos
    {
        public:
            bool Operador(Nodo * n1, Nodo * n2)
            {
                return n1->frecuencia > n2->frecuencia;
            }
    };

    priority_queue<Nodo *, vector<Nodo *>, CompararNodos> colaPrioridad;

    for(auto & par : frec)
    {
        Nodo * nuevo = new Nodo(par.first, par.second);
        colaPrioridad.push(nuevo);
        hojas.emplace(par.first, par.second);
    }

    while(!colaPrioridad.empty())
    {
        
    }

}