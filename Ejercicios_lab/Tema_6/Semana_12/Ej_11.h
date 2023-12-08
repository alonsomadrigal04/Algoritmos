
#include <vector>

using namespace std;

class ColaDePrioridad {

   vector<float> prioridad;

   int talla;

 public:

   ColaDePrioridad(int);
   
   void insertar(int, float);

   void cambiarPrioridad(int, float);

   int eliminarMinimo();

   bool estaVacia() const;

}; 
