#include <iostream>

using namespace std;
/*
    5) Calcular e informar la sumatoria de 10 números ingresados por teclado.
*/
int main()
{
    int sumatoria = 0;
    for (int i = 1; i <= 10; i++)
    {
        int numero;
        cout << "Ingrese un número, vamos por el (" << i << "): ";
        cin >> numero;
        sumatoria += numero;
    }
    cout << "La suma de los 10 números es: " << sumatoria << endl;
    return 0;
}