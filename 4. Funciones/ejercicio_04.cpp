#include <iostream>

using namespace std;
/*
    4) Dada una serie de números enteros positivos que finalizan con cero, informar:
        a) su factorial
        b) cuantos múltiplos de 3
        c) cuantos múltiplos de 5
        d) cuantos múltiplos de 3 y de 5
    Utilice las funciones de ejercicios anteriores.
*/

// Incompleto

int functionFactorial(int numero)
{
    int factorial = 1;
    for (int i = 1; i <= numero; i++)
    {
        factorial *= i;
    }
    return factorial;
}

int main()
{
    int cantidadDeNumeros;
    cout << "Cuántos números desea ingresar?: ";
    cin >> cantidadDeNumeros;

    int num;
    int factorialDeNumero;
    int cantidadMultiplosDeTres = 0;
    int cantidadDeMultiplosDeCinco = 0;
    int cantidadDeMultiplosDeTresyCinco = 0;

    factorialDeNumero = functionFactorial(num);
    cout << "El factorial de " << num << " es: " << factorialDeNumero << endl;
    cout << "Hay " << cantidadMultiplosDeTres << " multiplos de 3" << endl;
    cout << "Hay " << cantidadDeMultiplosDeCinco << " multiplos de 5" << endl;
    cout << "Hay " << cantidadDeMultiplosDeTresyCinco << " multiplos de 3 y 5" << endl;

    return 0;
}