#ifndef FILA_H_
#define FILA_H_

#include <iostream>
using std::cout, std::endl;

template <class T> 
struct Nodo
{
    T dato;
    struct Nodo<T> *sig;
};

template <class T>
class IteradorFila;

template <class T>
class Fila
{
private:
    Nodo<T> *frente;
    Nodo<T> *final;
    int longitud;

public:
    Fila();
    Fila(const Fila<T> &copia);
    bool EsFilaVacia();
    T Frente();
    void Enfila(T dato);
    void Defila();
    int Longitud();
    bool Pertenece(T x);
    ~Fila();

    friend class IteradorFila<T>;
};

template <class T>
Fila<T>::Fila()
{
    this->frente = nullptr;
    this->final = nullptr;
    this->longitud = 0;
}

template <class T>
Fila<T>::Fila(const Fila<T> &copia) : frente(nullptr), final(nullptr), longitud(0)
{
    Nodo<T> *aux = copia.frente;
    while (aux != nullptr)
    {
        Enfila(aux->dato);
        aux = aux->sig;
    }
}

template <class T>
bool Fila<T>::EsFilaVacia()
{
    return this->frente == nullptr && this->final == nullptr;
}

template <class T>
T Fila<T>::Frente()
{
    if(this->EsFilaVacia())
        return *(new T);
    else
        return this->frente->dato;
}

template <class T>
void Fila<T>::Enfila(T dato)
{
    Nodo<T> *nuevo = new Nodo<T>;
    nuevo->dato = dato;
    nuevo->sig = nullptr;

    if (EsFilaVacia())
        this->frente = nuevo;
    else
        this->final->sig = nuevo;

    this->final = nuevo;
    this->longitud++;
}

template <class T>
void Fila<T>::Defila()
{
    if (!this->EsFilaVacia())
    {
        Nodo<T> *aux = this->frente;
        this->frente = this->frente->sig;
        if (this->longitud == 1)
            this->final = nullptr;
        delete aux;
        this->longitud--;
    }
}

template <class T>
int Fila<T>::Longitud()
{
    return this->longitud;
}

template <class T>
bool Fila<T>::Pertenece(T x)
{
    Nodo<T> *aux = this->frente;
    while (aux && aux->dato != x)
    {
        aux = aux->sig;
    }
    return aux != nullptr;
}

template <class T>
Fila<T>::~Fila()
{
    while (!this->EsFilaVacia())
    {
        this->Defila();
    }
}

#endif
