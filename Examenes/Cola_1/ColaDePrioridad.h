
class ColaDePrioridad {

   struct Nodo {
      int prioridad;
      Nodo * siguiente;
      Nodo(int, Nodo *);
   };

   Nodo * primero, * minimo;

 public:

   ColaDePrioridad();
  
   void insertar(int);

   int consultarMinimo() const;

   void eliminarMinimo();

   bool estaVacia() const; // Esto no se pedia en el ejercicio

   void mostrar() const; // Esto tampoco se pedia, se ha hecho para probar los demas

};
