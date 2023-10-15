class CDPDF
{
    struct Nodo
    {
        int prioridad;
        Nodo * siguiente;
        Nodo * anterior;


        Nodo(int);
    };


    Nodo * primero;
    Nodo * ultimo;
    // int talla;

    void mostrar(Nodo *) const;

    public:
        CDPDF();

        void insertar(int);          // O(n)

        void insertarRecursivo(int);

        void insertarRecursivo(int, Nodo*);

        void eliminar(int);          // O(n)

        void eliminarMinimo();       // O(1)

        int consultarMinimo() const; // O(1)

        void eliminarMaximo();       // O(1)

        int consultarMaximo() const; // O(1)

        int talla() const;           // O(1)

        void mostrar() const;        // O(n)

    
};