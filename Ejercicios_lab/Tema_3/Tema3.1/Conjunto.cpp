
#include <iostream>
using namespace std;

#include "Conjunto.h"

Conjunto::Nodo::Nodo(int elDato) : dato{elDato}, izquierdo{nullptr}, derecho{nullptr} {
}

Conjunto::Conjunto() : raiz{nullptr}, talla{0}, minimo{nullptr} {
}
  
void Conjunto::insertar(int unDato) {
   insertar(unDato, raiz);
}

void Conjunto::insertar(int unDato, Nodo * & n) {
   if (n == nullptr)
   {
      n = new Nodo(unDato);
      if(minimo == nullptr || unDato < minimo->dato)
         minimo = n;
      talla ++;
   }
   else if (unDato < n->dato)
      insertar(unDato, n->izquierdo);
   else if (unDato > n->dato)
      insertar(unDato, n->derecho);
   // No insertamos duplicados
}

// int Conjunto::minimoEnSubarbol(Nodo * n) const { // Sabiendo que n != nullptr
//    if (n->izquierdo == nullptr)
//       return n->dato;
//    return minimoEnSubarbol(n->izquierdo);
// }

void Conjunto::eliminar(int unDato) {
   eliminar(unDato, raiz);
}

void Conjunto::eliminar(int unDato, Nodo * & n) {
   if (n == nullptr)
      return;
   if (unDato < n->dato)
      eliminar(unDato, n->izquierdo);
   else if (unDato > n->dato)
      eliminar(unDato, n->derecho);
   else if (n->izquierdo != nullptr && n->derecho != nullptr) {
      n->dato = minimoEnSubarbol(n->derecho);
      eliminar(n->dato, n->derecho);
   } else {
      Nodo * basura = n;
      if (n->izquierdo != nullptr)
	 n = n->izquierdo;
      else
	 n = n->derecho;
      delete basura;
      talla --;
   }
}

bool Conjunto::buscar(int unDato) const {
   return buscar(raiz, unDato);
}

bool Conjunto::buscar(Nodo * n, int dato) const
{
   if(n == nullptr)
      return false;
   if(dato > n->dato)
      return buscar(n->derecho, dato);
   if(dato < n->dato)
      return buscar(n->izquierdo, dato);
   return true;
}


void Conjunto::MostrarTalla(){
    cout << talla;
}

void Conjunto::MostrarOrdenados() const
{
   cout << "{";
   MostrarOrdenados(raiz);
   cout << "}";
}

void Conjunto::MostrarOrdenados(Nodo * n) const
{
   if(n!=nullptr)
   {
      MostrarOrdenados(n->izquierdo);
      cout << " " << n->dato << " ";
      MostrarOrdenados(n->derecho);
   }
}

void Conjunto::vaciar()
{
   vaciar(raiz);
   talla = 0;
   raiz = nullptr;
}

void Conjunto::vaciar(Nodo * n)
{
   if(n != nullptr)
   {
      vaciar(n->derecho);
      vaciar(n->izquierdo);
      delete n;
   }
}

int Conjunto::consultarMinimo() const
{
   if(raiz == nullptr)
      throw string("Intenando acceder a un minimo de un arbol vacio");
   return minimoEnSubarbol(raiz);
}

int Conjunto::minimoEnSubarbol(Nodo * n) const
{
   if(raiz == nullptr)
      throw string("Intendando consultar el minimo de un arbol vacio");
   while(n->izquierdo != nullptr)
      n = n->izquierdo;
   return n->dato;
}



int main()
{
    Conjunto c;
    c.insertar(10);
    c.insertar(5);
    c.insertar(6);
    c.insertar(19);
    c.insertar(90);
    cout << c.consultarMinimo() << endl;
    cout << c.buscar(5) << endl;
}

