#include <iostream>

using namespace std;
/*
    7) Desarrollar la función unsigned edadAGrupoEtario (unsigned edad) que retorne un valor de
    1 a 8, de acuerdo al siguiente cuadro:
    Edad Valor
    Hasta 14 años 1
    De 15 a 21 2
    De 22 a 28 3
    De 29 a 35 4
    De 36 a 42 5
    De 43 a 49 6
    De 50 a 63 7
    Mayores de 64 8
*/

unsigned edadAGrupoEtario(unsigned edad)
{
    int mayor = 14;
    int menor = 0;
    int grupo = 1;
    for (int i = 0; i <= 8; i++)
    {
        if (edad >= menor && edad <= mayor)
        {
            return grupo;
        }
        else
        {

            if (edad >= 50 && edad <= 63)
            {
                return 7;
            }
            else if (edad >= 64)
            {
                return 8;
            }
            else
            {
                menor = mayor + 1;
                mayor = menor + 6;
                grupo += 1;
            }
        }
    }
}

int main()
{
    unsigned edad;
    cout << "Ingrese la edad: ";
    cin >> edad;
    while (edad != 0)
    {
        cout << "La edad ingresada pertenece al grupo etario: " << edadAGrupoEtario(edad) << endl;
        cout << "Ingrese la edad (ingrese 0 para terminar): ";
        cin >> edad;
    }
    return 0;
}