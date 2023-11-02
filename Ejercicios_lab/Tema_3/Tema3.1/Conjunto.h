class Conjunto {

    struct Nodo {
        int dato;
        Nodo * izquierdo;
        Nodo * derecho;
        Nodo(int);
    };

    Nodo * raiz;
    int talla;

    void insertar(int, Nodo * &);
    void eliminar(int, Nodo * &);
    int  minimoEnSubarbol(Nodo *) const;
    bool buscar(Nodo *, int) const;
    void MostrarOrdenados(Nodo *) const;
    void vaciar(Nodo *);

    public:

        Conjunto();
        void insertar(int);
        void eliminar(int);
        bool buscar(int) const;
        void MostrarTalla();
        void MostrarOrdenados() const;
        void vaciar();

};