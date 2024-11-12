#include "Fila.h"

using std::cout, std::endl;

Fila::Fila()
{
    this->frente = nullptr;
    this->final = nullptr;
    this->longitud = 0;
}

Fila::Fila(const Fila &copia) : frente(nullptr), final(nullptr), longitud(0)
{
    Nodo *aux = copia.frente;
    while (aux != nullptr)
    {
        Enfila(aux->dato);
        aux = aux->sig;
    }
}

bool Fila::EsFilaVacia()
{
    return this->frente == nullptr && this->final == nullptr;
}

item Fila::Frente()
{
    return !this->EsFilaVacia() ? this->frente->dato : INDEFINIDO;
}

void Fila::Enfila(item dato)
{
    Nodo *nuevo = new Nodo;
    nuevo->dato = dato;
    nuevo->sig = nullptr;

    if (EsFilaVacia())
        this->frente = nuevo;
    else
        this->final->sig = nuevo;

    this->final = nuevo;
    this->longitud++;
}

void Fila::Defila()
{
    struct Nodo *aux;
    if (!this->EsFilaVacia())
    {
        aux = this->frente;
        this->frente = this->frente->sig;
        if (this->longitud == 1)
            this->final = nullptr;
        delete aux;
        this->longitud--;
    }
}

int Fila::Longitud()
{
    return this->longitud;
}

bool Fila::Pertenece(item x)
{
    struct Nodo *aux = this->frente;
    while (aux && aux->dato != x)
        aux = aux->sig;
    return aux != nullptr;
}

void Fila::Mostrar()
{
    struct Nodo *aux;
    aux = this->frente;
    cout << endl
         << "F - ";
    for (int i = 0; i < this->longitud; i++)
    {
        cout << aux->dato << " - ";
        aux = aux->sig;
    }
    cout << " NULL" << endl;
}

Fila::~Fila()
{
    while (!this->EsFilaVacia())
    {
        this->Defila();
    }
}