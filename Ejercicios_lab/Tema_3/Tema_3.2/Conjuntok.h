
class Conjunto {

    struct Nodo {
        int dato;
        Nodo * izquierdo;
        Nodo * derecho;
        int indice;

        Nodo(int);
    };

    Nodo * raiz;


    void insertar(int, Nodo * &);
    void eliminar(int, Nodo * &);
    int  minimoEnSubarbol(Nodo *) const;
    


    public:

        Conjunto();
        void insertar(int);

        void eliminar(int);

        bool buscar(int) const;

        int buscarKesimo(int) const;



};
