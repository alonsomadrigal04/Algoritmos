#include <iostream>
#include <string>
using namespace std;


class Conjunto
{
    struct Nodo
    {
        float dato;
        Nodo * derecha;
        Nodo * izquierda;
        Nodo(float);
    };
    
    Nodo * raiz;
    int consultarProfundidad(float, Nodo *, int) const;
    void mostrar(Nodo *) const;
    void insertar(int, Nodo * &);
    void eliminarMaximo(Nodo * &);


    public:
    Conjunto();
        int consultarProfundidad(float) const;
        void mostrar() const;
        void insertar(int);
        void eliminarMaximo();


};
