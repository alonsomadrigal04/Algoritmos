
class Conjunto {

    struct Nodo {
        int dato;
        Nodo * izquierdo;
        Nodo * derecho;
        Nodo(int);
    };

    Nodo * raiz;

    void insertar(int, Nodo * &);

    void mostrar(Nodo *) const;

    void eliminar(int, Nodo * &);

    int  minimoEnSubarbol(Nodo *) const;

    int sumarRecursivo(Nodo *) const;

    void incrementarTodos(Nodo *);

    int altura(Nodo *) const;

    bool noHayHijosSinHermanos(Nodo *) const;

    bool arbolesIguales(Nodo *, Nodo *) const;

    bool verificarProfundidad(Nodo *, int) const;

    public:

        Conjunto();

        void insertar(int);

        void mostrar() const;

        void eliminar(int);

        bool buscar(int) const;

        int sumarRecursivo() const;

        void incrementarTodos();

        int altura() const;

        bool noHayHijosSinHermanos() const;

        bool arbolesIguales(const Conjunto &) const;
        
        void mostrarPorNiveles() const;

        bool verificarProfundidad(int) const;
        



};