#include <iostream>

using namespace std;
/*
    10) Una compañía aérea desea emitir un listado con los movimientos mensuales de sus M vuelos al
    exterior.
    Para ello cuenta con la siguiente información:
    De cada vuelo realizado el número de vuelo, destino, y cantidad de asientos.
    De cada pasajero el número de pasaporte y el importe que abonó por el pasaje en dólares.
    La información de los pasajeros de cada vuelo finaliza con un número de pasaporte igual a cero.
    Se pide emitir el siguiente listado:
    Nro. de Vuelo ………. Destino: ………..
    Nro. de Pasaporte Importe en u$s
    …………. ………….
    …………. ………….
    Total recaudado del vuelo: ………
    Cantidad de asientos libres: ………
    Número de vuelo que más recaudó: ……..
*/

int main()
{
    int cantVuelos, nroVuelo, cantAsi, nroPasap, cantPasaj, nroVMayorRec;
    float importe, totalRec, mayorRec;
    string destino;
    cout << "Ingresar la cantidad de vuelos ";
    cin >> cantVuelos;
    for (int i = 1; i <= cantVuelos; i++)
    {
        totalRec = 0;
        cantPasaj = 0;
        cout << "Ingrese el numero de vuelo " << i << endl;
        cin >> nroVuelo;
        cout << "Ingrese el destino del vuelo ";
        cin >> destino;
        cout << "Ingrese la cantidad de asientos del vuelo ";
        cin >> cantAsi;

        cout << "--------------" << endl;
        cout << "Numero de vuelo: " << nroVuelo << "    Destino: " << destino << endl;
        cout << "--------------" << endl;

        cout << "Ingrese el numero de pasaporte (0 para finalizar) ";
        cin >> nroPasap;
        while (nroPasap != 0 && cantPasaj < cantAsi)
        {
            cout << "Ingrese el importe abonado ";
            cin >> importe;

            cantPasaj++;
            totalRec += importe;

            cout << endl
                 << "--------------" << endl;
            cout << "Numero de Pasaporte: " << nroPasap << "    Importe: " << importe << endl;
            cout << "--------------" << endl;

            cout << "Ingrese el numero de pasaporte (0 para finalizar) ";
            cin >> nroPasap;
        }

        if (i == 1 || totalRec > mayorRec)
        {
            mayorRec = totalRec;
            nroVMayorRec = nroVuelo;
        }

        cout << "--------------" << endl;
        cout << "Total recaudado del vuelo: " << totalRec << endl;
        cout << "Cantidad de asientos libres: " << cantAsi - cantPasaj << endl;
        cout << "--------------" << endl;
    }
    cout << "--------------" << endl;
    cout << "Numero de vuelo que mas recaudo: " << nroVMayorRec << endl;
    cout << "--------------" << endl;

    return 0;
}