#include <iostream>
#include <stdio.h>

using namespace std;

struct Parcial
{
    int legajo;
    char nombre[36];
    int nota;
};

int main()
{
    FILE *archParcial;
    Parcial par;
    char nomArch[20];
    cout << "Nombre del archivo (con .dat)";
    cin >> nomArch;

    // archParcial=fopen("Parcial1.dat","wb");
    archParcial = fopen(nomArch, "wb");

    if (archParcial == NULL)
        cout << "ERROR" << endl;
    else
    {
        cout << "Ingrese legajo (0 para finalizar) ";
        cin >> par.legajo;
        while (par.legajo != 0)
        {
            cout << "Nombre: ";
            cin >> par.nombre;
            cout << "Nota: ";
            cin >> par.nota;
            fwrite(&par, sizeof(Parcial), 1, archParcial);
            cout << "Ingrese legajo (0 para finalizar) ";
            cin >> par.legajo;
        }
        fclose(archParcial);
    }

    return 0;
}
