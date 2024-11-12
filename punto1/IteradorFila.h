#ifndef ITERADORFILA_H_
#define ITERADORFILA_H_

#include <iostream>
#include "Fila.h"

class IteradorFila
{
private:
    const Fila &fila;
    struct Nodo *actual;

public:
    IteradorFila(const Fila &fila) : fila(fila), actual(fila.frente) {};
    bool HayMasElementos()
    {
        return this->actual != nullptr;
    };

    item ElementoActual()
    {
        if (HayMasElementos())
            return this->actual->dato;
        return INDEFINIDO;
    };
    void Avanzar()
    {
        if (HayMasElementos())
            actual = actual->sig;
    }
};

#endif