#include <iostream>
#include "IteradorFila.h"
#include "Fila.h"

int ContarX(const Fila &fila, item x);

using std::cout, std::endl;

int main()
{
    Fila fila;

    // Agregar elementos a la fila
    cout << "Agregando elementos a la fila: 10, 20, 30, 40, 50" << endl;
    fila.Enfila(10);
    fila.Enfila(20);
    fila.Enfila(30);
    fila.Enfila(40);
    fila.Enfila(50);

    // Mostrar los elementos de la fila
    cout << "Elementos en la fila:" << endl;
    fila.Mostrar();

    // Usar el iterador para recorrer la fila
    cout << "\nIterando sobre la fila usando IteradorFila:" << endl;
    IteradorFila iterador(fila);
    while (iterador.HayMasElementos())
    {
        cout << iterador.ElementoActual() << " ";
        iterador.Avanzar();
    }
    cout << endl;

    // Probar el método Pertenece
    int elemento = 30;
    cout << "\n¿El elemento " << elemento << " pertenece a la fila? ";
    cout << (fila.Pertenece(elemento) ? "Sí" : "No") << endl;

    // Obtener y mostrar el frente de la fila
    cout << "El elemento al frente de la fila es: " << fila.Frente() << endl;

    // Desencolar un elemento y mostrar el contenido de la fila
    cout << "\nDesencolando un elemento..." << endl;
    fila.Defila();
    cout << "Elementos en la fila después de desencolar:" << endl;
    fila.Mostrar();

    int cantidad = ContarX(fila, 40);

    cout << "Cantidad: " << cantidad << endl;
    return 0;
}

int ContarX(const Fila &fila, item x)
{
    IteradorFila iterador(fila);
    int contador = 0;

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
