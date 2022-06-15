#include <iostream>
#define TAM 10
using namespace std;
/*
    9) Dados 50 números enteros, informar el promedio de los mayores que 100 y la suma de los
    menores que –10.
*/
int main()
{
    int numerosMayores, cantidadMenores, sumaDeMenores, PromedioNumerosMayores;
    for (int i = 1; i <= TAM; ++i)
    {
        int numero;
        cout << "Ingrese " << TAM << " números enteros "
             << "vamos por el (" << i << "): " << endl;
        cin >> numero;
        if (numero > 100)
        {
            numerosMayores += numero;
            cantidadMenores++;
        }
        if (numero < -10)
        {
            sumaDeMenores += numero; // Esto causa un problema con el tema de los bits de la variable, es como que hace un overflow para abajo y se reinicia
        }
    }
    PromedioNumerosMayores = numerosMayores / cantidadMenores;
    cout << "El promedio de los números mayores a 100 es: " << PromedioNumerosMayores << endl;
    cout << "La suma de los números menores a -10 es: " << sumaDeMenores << endl;
    return 0;
}