#include <iostream>

using namespace std;
/*
    9) Desarrollar una función tal que dada una fecha en formato número de 8 dígitos
    (AAAAMMDD), devuelva el día, el mes y el año correspondientes.
*/
void desformatear(int fecha, int &dia, int &mes, int &año) // Cuando colocamos un "&" delante del parametro, ese mismo devuelve un valor
{
    año = fecha / 10000;
    mes = (fecha % 10000) / 100;
    dia = fecha % 100;
}
int main()
{
    int fecha, dia, mes, año;
    cout << "Ingrese la fecha en formato(AAAAMMDD): ";
    cin >> fecha;
    desformatear(fecha, dia, mes, año);
    cout << "El dia es " << dia << ", del mes " << mes << " y del año " << año << endl;
    return 0;
}