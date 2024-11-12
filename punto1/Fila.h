#ifndef FILA_H_
#define FILA_H_

#include <iostream>

typedef int item;

const item INDEFINIDO = -9999;

struct Nodo
{
    item dato;
    struct Nodo *sig;
};

class Fila
{
    struct Nodo *frente;
    struct Nodo *final;
    int longitud;

public:
    Fila();
    Fila(const Fila &copia);
    bool EsFilaVacia();
    item Frente();
    void Enfila(item dato);
    void Defila();
    int Longitud();
    bool Pertenece(item x);
    void Mostrar();
    ~Fila();
    friend class IteradorFila;
};

#endif