template <class T>
class IteradorFila
{
private:
    const Fila<T> &fila;
    Nodo<T> *actual;

public:
    IteradorFila(const Fila<T> &fila) : fila(fila), actual(fila.frente) {}
    bool HayMasElementos() { return this->actual != nullptr; }
    T ElementoActual() { return this->actual->dato; }
    void Avanzar()
    {
        if (actual)
            actual = actual->sig;
    }
};
