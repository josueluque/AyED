#include <iostream>

using namespace std;
/*
    13) Hacer un algoritmo que calcule el promedio de números enteros positivos ingresados por teclado
    hasta que se ingrese un cero. Este cero sólo indica el fin de ingreso de datos, no se incluirá en el
    promedio.
*/
int main()
{
    unsigned nro, sum = 0, cont = 0;
    cout << "Ingrese numero positivo(cero para finalizar) ";
    cin >> nro;
    while (nro != 0)
    {
        sum += nro;
        cont++;
        cout << "Ingrese numero positivo(cero para finalizar) ";
        cin >> nro;
    }
    if (cont != 0)
    {
        float prom = (float)sum / cont;
        cout << "El promedio de todos los número ingresados: " << prom;
    }
    else
        cout << "no hubo numeros, cero fue el primero" << endl;
}