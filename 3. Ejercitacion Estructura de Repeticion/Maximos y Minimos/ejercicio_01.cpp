#include <iostream>
#define TAM 10 // Aca modificamos el maximo de valores
using namespace std;
/*
    1) Dados 50 valores distintos que se ingresan por teclado, mostrar el menor.
*/
int main()
{
    int menorNumero = 0;
    for (int i = 0; i < TAM; i++)
    {
        int numIngresado;
        cout << "Ingrese un numero (vamos por el " << i << "): " << endl;
        cin >> numIngresado;

        if (i == 0)
        {
            menorNumero = numIngresado; // En la primera iteracion, el menor número sea el primer número ingresado
        }
        else
        {
            if (numIngresado < menorNumero)
            {
                menorNumero = numIngresado;
            }
        }
    }
    cout << "El menor es: " << menorNumero << endl;

    return 0;
}