
#include <vector>

using namespace std;

class GrafoNoDirigido {

   struct Arco {
      int vecino;
      float peso;
      Arco * siguiente;
      Arco(int, float, Arco *);
   };

   struct Vertice {
      Arco * primerArco;
      int grado;
      Vertice();
   };

   vector<Vertice> vertices;
   
 public:

   GrafoNoDirigido(const char *);

   void mostrar() const;

   int cantidadDeVertices() const;

};