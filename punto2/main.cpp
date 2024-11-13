#include <iostream>
#include "Fila.h"
#include "IteradorFila.h"

using namespace std;

template <class T>
int ContarX(const Fila<T> &fila, T x)
{
    int contador = 0;
    IteradorFila<T> iterador(fila);

    while (iterador.HayMasElementos())
    {
        if (iterador.ElementoActual() == x)
        {
            contador++;
        }
        iterador.Avanzar();
    }

    return contador;
}

int main()
{
    // Probar con enteros
    Fila<int> filaInt;
    filaInt.Enfila(1);
    filaInt.Enfila(2);
    filaInt.Enfila(3);
    filaInt.Enfila(2);
    filaInt.Enfila(4);
    filaInt.Enfila(2);
    cout << "Fila de enteros: ";
    cout << "El número 2 aparece " << ContarX(filaInt, 2) << " veces en la fila de enteros." << endl;

    // Probar con doubles
    Fila<double> filaDouble;
    filaDouble.Enfila(1.1);
    filaDouble.Enfila(2.2);
    filaDouble.Enfila(3.3);
    filaDouble.Enfila(2.2);
    filaDouble.Enfila(4.4);
    filaDouble.Enfila(2.2);
    cout << "Fila de doubles: ";
    cout << "El número 2.2 aparece " << ContarX(filaDouble, 2.2) << " veces en la fila de doubles." << endl;

    // Probar con strings
         Fila<string> filaString;
        filaString.Enfila("apple");
        filaString.Enfila("banana");
        filaString.Enfila("apple");
        filaString.Enfila("cherry");
        filaString.Enfila("apple");
        cout << "Fila de strings: ";
        string dato= "apple";
        cout << "La palabra 'apple' aparece " << ContarX(filaString, dato) << " veces en la fila de strings." << endl; 

    return 0;
}