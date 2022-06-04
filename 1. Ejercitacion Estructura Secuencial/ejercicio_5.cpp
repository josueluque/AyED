#include <iostream>

using namespace std;
/*
    Obtener la edad de una persona en meses, si se ingresa su edad en años y meses.
    Ejemplo: Ingresado 3 años 4 meses debe mostrar 40 meses
*/

int main()
{
    int meses, años, edadEnMeses;
    cout << "Cuantos años tenes?: ";
    cin >> años;
    cout << "Cuantos meses pasaron desde tu último cumpleaños?: ";
    cin >> meses;

    edadEnMeses = años * 12 + meses;
    cout << "Tu edad en meses es: " << edadEnMeses << endl;
    return 0;
}