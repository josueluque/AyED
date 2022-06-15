#include <iostream>

using namespace std;
/*
    6) Escribir un algoritmo que lea dos fechas (día, mes y año) e informe cual es la más reciente.
*/

int main()
{
    int fecha1, fecha2;
    cout << "Ingresa una fecha en formato AAAAMMDD, AÑO MES DIA, 20220617 sería 17 de Junio de 2022: ";
    cin >> fecha1;
    cout << "-----" << endl;
    cout << "Ingresa otra fecha con el mismo formato de arriba: ";
    cin >> fecha2;

    if (fecha1 > fecha2)
    {
        cout << "La fecha1 (" << fecha1 << ") es la mas reciente" << endl;
    }
    else
    {
        cout << "La fecha2 (" << fecha2 << ") es la mas reciente" << endl;
    }

    return 0;
}