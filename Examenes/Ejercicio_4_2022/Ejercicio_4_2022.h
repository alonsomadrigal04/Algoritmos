class Conjunto {

    struct Nodo {
        int dato;
        Nodo * izquierdo;
        Nodo * derecho;
        int tallaIzquierdo;
        int tallaDerecho;
        Nodo(int);
        };

    Nodo * raiz;
    Nodo * maximo;


    void mostrar(Nodo *) const;

    
    
    public:
        Conjunto();

        void insertar(int);

        void mostrar() const;

        void eliminarMaximo();

        void encontrarMaximo();
};
