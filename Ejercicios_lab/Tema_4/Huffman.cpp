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
        Nodo * n = new Nodo(' ', 0);
        n->izquierdo = colaPrioridad.top();
        colaPrioridad.pop();
        n->derecho = colaPrioridad.top();
        colaPrioridad.pop();
        n->frecuencia = n->izquierdo->frecuencia + n->derecho->frecuencia;
        n->izquierdo->padre = n;
        n->derecho->padre = n;
        n->izquierdo->bit = '0';
        n->derecho->bit = '1';
        colaPrioridad.push(n);
    }

}

string Huffman::codificar(const string &mensaje) const
{
    string codigo = "";
    Nodo * referencia;

    for(char letra : mensaje)
    {
        try
        {
            Nodo * referencia = hojas.at(letra);
        }
        catch(out_of_range error) 
        {
            throw string("Intentando acceder a un caracter que no esta codificado: " + letra);
        }

        while(referencia != raiz)
        {
          codigo += referencia->bit;
          referencia = referencia->padre;  
        }
    }
        return codigo;
}

string Huffman::decodificar(const string & codificado) const
{
    string mensaje = "";
    Nodo * referencia = raiz;

    for(char numero : codificado)
    {
        if(numero == 0)
            referencia = referencia->izquierdo;
        else    
            referencia = referencia->derecho;

        if(referencia->derecho == nullptr)
        {
            mensaje += referencia->caracter;
            referencia = raiz;
        }
    }
    return mensaje;
}
