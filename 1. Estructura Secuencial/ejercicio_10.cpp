#include <iostream>
#include <math.h> //Biblioteca que permite operar con operaciones matemáticas basicas.

using namespace std;
/*
    10.Dado la longitud de los dos catetos de un triángulo rectángulo y mostrar la longitud de la
    hipotenusa.
*/
int main()
{
    int cateto1, cateto2;
    double hipotenusa; // double permite obtener un resultado exacto y preciso (doble precisión mas que el tipo float)
    // Aplicando el teorema de pitagoras
    cout << "Cuánto mide el cateto 1?: ";
    cin >> cateto1;
    cout << "Cuánto mide el cateto 2?: ";
    cin >> cateto2;

    hipotenusa = sqrt(cateto1 * cateto1 + cateto2 * cateto2); // sqrt (raiz cuadrada)
    cout << "El valor de la hipotenusa del triangulo es: " << hipotenusa << endl;
    return 0;
}