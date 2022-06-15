#include <iostream>

using namespace std;
/*
    6) Desarrollar la función porcentaje que dados los parámetros a y b devuelva el porcentaje que
    representa a sobre b.
*/

int porcentaje(float a, float b)
{
    return (a / b) * 100;
}

int main()
{
    float a, b, p;
    cout << "Ingrese el valor de a: ";
    cin >> a;
    cout << "Ingrese el valor de b: ";
    cin >> b;

    cout << "El porcentaje de a sobre b es: " << porcentaje(a, b) << "%" << endl;
    return 0;
}