class Conjunto {
private:
    struct Nodo {
        float dato;
        Nodo* siguiente;
        
        Nodo(float d);
    };
    
    Nodo* primero;

    void mostrar(Nodo *) const;

public:
    Conjunto();

    void Insertar(float);

    void Eliminar(float);

    bool buscar(float) const;

    void eliminarComunes(const Conjunto &);

    void mostrar() const;

};