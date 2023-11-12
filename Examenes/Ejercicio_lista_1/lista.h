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
    void insertar(float dato, int i, Nodo * n);

    public:
        Conjunto();
        void insertar(float dato, int i);

};