#include <iostream>

using namespace std;
/*
    8) Dados tres valores que representan los lados de un triángulo, informar si el mismo es
    equilátero, isósceles o escaleno.
*/
int main()
{
    int a, b, c;
    cout << "Ingrese 3 valores de longitud de los lados de un triangulo" << endl;
    cin >> a >> b >> c;
    if (a == b && a == c) // Todos los lados iguales
    {
        cout << "Forma un triangulo equilatero" << endl;
    }
    else
    {
        if ((a == b && a != c) || (b == c && b != a) || (a == c && a != b)) // Dos lados iguales y uno diferente
        {
            cout << "Forma un triangulo isoceles" << endl;
        }
        else
        {
            cout << "Forma un triangulo escaleno" << endl; // Todos los lados diferentes
        }
    }
    return 0;
}