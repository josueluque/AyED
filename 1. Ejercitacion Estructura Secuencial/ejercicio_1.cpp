#include <iostream>

using namespace std;
// 1. Dados 3 números enteros positivos, muestre la suma, la resta y la multiplicación de todos.

int main()
{
    int num1, num2, num3, suma, resta, multiplicacion; // Variables de tipo entero
    cout << "Ingrese un número" << endl;
    cin >> num1;
    cout << "Ingrese otro número" << endl;
    cin >> num2;
    cout << "Ingrese otro número" << endl;
    cin >> num3;

    suma = num1 + num2 + num3;
    resta = num1 - num2 - num3;
    multiplicacion = num1 * num2 * num3;

    cout << "La suma es: " << suma << endl;
    cout << "La resta es: " << resta << endl;
    cout << "La multiplicacion es: " << multiplicacion << endl;

    return 0; // Se usa para que no rompa
}