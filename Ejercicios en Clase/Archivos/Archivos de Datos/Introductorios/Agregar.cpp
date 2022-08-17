#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Parcial
{
    int legajo;
    char nombre[36];
    int nota;
};

int main()
{
    char nombArch[21];
    cout << "Ingrese el nombre del archivo: ";
    cin >> nombArch;
    strcat(nombArch, ".dat");

    FILE *archParcial = fopen(nombArch, "ab");
    if (archParcial == NULL)
        cout << "ERROR" << endl;
    else
    {
        Parcial parcial;
        cout << "Legajo (cero fin) ";
        cin >> parcial.legajo;
        while (parcial.legajo != 0)
        {
            cout << "Nombre ";
            cin >> parcial.nombre;
            cout << "Nota ";
            cin >> parcial.nota;

            fwrite(&parcial, sizeof(Parcial), 1, archParcial);

            cout << "Legajo (cero fin) ";
            cin >> parcial.legajo;
        }
        fclose(archParcial);
    }
    return 0;
}
