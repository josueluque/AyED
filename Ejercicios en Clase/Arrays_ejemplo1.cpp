#include <iostream>

#define TAM 5

using namespace std;

// Ingresar 5 números  enteros e
// informar cuántos de ellos son mayores a su promedio

int main()
{
    int i, suma = 0, prom, cont = 0, nros[TAM];
    for (i = 0; i < TAM; i++)
    {
        cout << "Ingrese el numero de orden " << i + 1 << endl;
        cin >> nros[i];
    }

    for (i = 0; i < TAM; i++)
    {
        suma += nros[i];
    }
    prom = suma / TAM;

    for (i = 0; i < TAM; i++)
    {
        if (nros[i] > prom)
            cont++;
    }

    cout << "Hay " << cont << " numeros mayores al promedio " << prom << endl;
    return 0;
}
