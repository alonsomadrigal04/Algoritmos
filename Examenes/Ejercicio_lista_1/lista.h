class Conjunto
{
    struct Nodo
    {
        int dato;
        Nodo * siguiente;
        Nodo(int);
    };

    Nodo * primero;
    int talla;
    void insertar(float, int, Nodo *);
    void mostrar(Nodo * );

    public:
        Conjunto();
        void insertar(float, int);
        void mostrar();

};