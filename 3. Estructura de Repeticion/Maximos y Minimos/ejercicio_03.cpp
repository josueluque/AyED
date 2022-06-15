#include <iostream>
#define TAM 10 // Aca modificamos el maximo de valores

using namespace std;
/*
3) Dados 50 valores que se ingresan por teclado, mostrar el mayor y la cantidad de veces que fue
ingresado
*/
int main()
{
    int mayor = 0;
    int cantidad = 0;
    for (int i = 1; i <= TAM; i++)
    {
        int input;
        cout << "Ingrese un numero (vamos por el " << i << "): " << endl;
        cin >> input;
        if (i == 1)
        {
            mayor = input;
        }
        else
        {
            if (input > mayor)
            {
                mayor = input;
                cantidad = 0;
            }
        }
        if (mayor == input)
        {
            cantidad++;
        }
    }
    cout << "El mayor es: " << mayor << " y se ingreso " << cantidad << " veces" << endl;
    return 0;
}