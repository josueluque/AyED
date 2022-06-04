#include <iostream>

using namespace std;
/*
    7) Dado tres valores que representan las longitudes de segmentos determinar e imprimir una
    leyenda según sea: “Forman triangulo” o “No forman triangulo”.
*/
int main()
{
    int a, b, c;
    cout << "Ingresar 3 valores de logitud de segmentos de un triangulo" << endl;
    cin >> a >> b >> c;

    if ((a + b > c) && (a + c > b) && (b + c > a))
    {
        cout << "Forman un triangulo" << endl;
    }
    else
    {
        cout << "No forman un triangulo" << endl;
    }

    return 0;
}