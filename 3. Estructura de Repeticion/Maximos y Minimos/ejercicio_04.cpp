#include <iostream>
#define TAM 10 // Aca modificamos el maximo de valores

using namespace std;
/*
    4) Dados 50 valores distintos que se ingresan por teclado, mostrar los dos mayores.
*/
int main()
{
    int mayor1, mayor2;
    for (int i = 1; i <= TAM; i++)
    {
        int input;
        cout << "Ingrese un numero (vamos por el " << i << "): " << endl;
        cin >> input;
        if (i == 1)
        {
            mayor1 = input;
            mayor2 = input;
        }
        else
        {
            if (input > mayor1)
            {
                mayor2 = mayor1;
                mayor1 = input;
            }
            else if (input > mayor2)
            {
                mayor2 = input;
            }
        }
    }
    cout << "El mayor es: " << mayor1 << " y el segundo mayor es: " << mayor2 << endl;
    return 0;
}