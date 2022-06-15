#include <iostream>
#define TAM 10 // Aca modificamos el maximo de valores

using namespace std;
/*
2) Dados 50 valores distintos que se ingresan por teclado, mostrar en qué posición se ingresó el mayor
*/
int main()
{
    int mayorNumero, posicion;
    for (int i = 0; i < TAM; i++)
    {
        int numIngresado;
        cout << "Ingrese un numero (vamos por el " << i << "): " << endl;
        cin >> numIngresado;

        if (i == 0)
        {
            mayorNumero = numIngresado;
            posicion = i;
        }
        else
        {
            if (numIngresado > mayorNumero)
            {
                mayorNumero = numIngresado;
                posicion = i;
            }
        }
    }
    cout << "El mayor es: " << mayorNumero << " y se ingreso en la posicion: " << posicion << endl;
    return 0;
}