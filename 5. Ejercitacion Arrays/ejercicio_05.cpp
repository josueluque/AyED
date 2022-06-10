#include <iostream>

using namespace std;

/*
    5) Dado un conjunto desordenado de valores enteros comprendidos entre 1 y 500, sin repetición, que
    finaliza con cero, desarrollar un algoritmo que:
    . Imprima un listado ordenado de aquellos valores enteros que se encuentran en el conjunto
    . Imprima un listado ordenado de aquellos valores enteros que no se encuentran en el conjunto.
*/

void cargar(bool v[]);
void inic(bool v[]);
void mostrar(bool v[], bool valor);

int maxValor;

int main()
{

    cout << "Ingrese el rango de números (Ejemplo: ingreso '10' entonces el rango es de 1 a 10): " << endl;
    cin >> maxValor;
    bool vec[maxValor];
    inic(vec);
    cargar(vec);
    cout << "       Lista Ordenada\n";
    cout << "-----------------------------" << endl;
    cout << "Números ingresados: " << endl;
    mostrar(vec, true);
    cout << "\n"
         << endl;
    cout << "Números no ingresados: " << endl;
    mostrar(vec, false);
    return 0;
}
void cargar(bool v[])
{
    int nro;
    cout << "Ingrese un número entre 1 y " << maxValor << "(0 para finalizar): " << endl;
    cin >> nro;
    if (nro > maxValor)
    {
        cout << "NUMEROS COMPRENDIDOS ENTRE 1 y " << maxValor << endl;
    }
    while (nro != 0)
    {
        v[nro - 1] = true;
        cout << "Ingrese un número entre 1 y " << maxValor << "(0 para finalizar): " << endl;
        cin >> nro;
        if (nro > maxValor)
        {
            cout << "NUMEROS COMPRENDIDOS ENTRE 1 y " << maxValor << endl;
        }
    }
}

void inic(bool v[])
{
    for (int i = 0; i < maxValor; i++)
        v[i] = false;
}
void mostrar(bool v[], bool valor)
{
    for (int i = 0; i < maxValor; i++)
        if (v[i] == valor)
            cout << i + 1 << " ";
}