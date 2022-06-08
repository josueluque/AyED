#include <iostream>

using namespace std;
/*
    Ingrese la cantidad de números a ingresar y a continuación ingresar esa cantidad de números e
    informar cuántos de ellos son mayores a su promedio
*/
int main()
{
    int i, suma = 0, prom, cont = 0, cantNros;
    cout << "Ingrese la cantidad de numeros a ingresar" << endl;
    cin >> cantNros;
    int nros[cantNros];
    for (i = 0; i < cantNros; i++)
    {
        cout << "Ingrese el numero de orden " << i + 1 << endl;
        cin >> nros[i];
    }
    for (i = 0; i < cantNros; i++)
        suma += nros[i];

    prom = suma / cantNros;

    for (i = 0; i < cantNros; i++)
    {
        if (nros[i] > prom)
            cont++;
    }
    cout << "Hay " << cont << " numeros mayores al promedio " << prom << endl;

    return 0;
}