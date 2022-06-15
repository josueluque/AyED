#include <iostream>

using namespace std;
// Desarrollar una función tal que dado un número entero positivo calcule y retorne su factorial
int functionFactorial(int numero)
{
    int factorial = 1;
    for (int i = 1; i <= numero; i++)
    {
        factorial *= i;
    }
    return factorial; // Retorna el factorial del número
}

int main()
{
    int n;
    int factorialDeNumero;
    cout << "Ingrese un numero entero positivo: " << endl;
    cin >> n;

    factorialDeNumero = functionFactorial(n);
    cout << "El factorial de " << n << " es: " << factorialDeNumero << endl;

    return 0;
}
