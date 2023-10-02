
class Cola {

   struct Nodo {
      int dato;
      Nodo * siguiente;
      Nodo(int);
   };

   Nodo * primero;
   Nodo * ultimo;

   void mostrar(Nodo *) const;

public:

   Cola();
  
   void encolar(int);

   void desencolar();

   int consultarPrimero() const;

   void mostrar() const;

   bool estaVacia() const;

};
