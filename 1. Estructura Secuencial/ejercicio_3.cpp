#include <iostream>

using namespace std;

/*
    Determinar la suma de las cifras de un número entero positivo de 4 cifras. Ejemplo: Dado
    8125, la suma es 16.
 */
int main()
{
    int num, digito1, digito2, digito3, digito4, suma;
    cout << "Ingrese un numero de 4 cifras" << endl; // Supongamos que el usuario es bueno y no ingresa ningun otro caracter
    cin >> num;

    digito1 = num / 1000;
    digito2 = (num - (digito1 * 1000)) / 100;
    digito3 = (num - (digito1 * 1000 + digito2 * 100)) / 10;
    digito4 = num - (digito1 * 1000 + digito2 * 100 + digito3 * 10);

    suma = digito1 + digito2 + digito3 + digito4;
    cout << "La suma de las cifras del numero es: " << suma << endl;

    return 0;
}