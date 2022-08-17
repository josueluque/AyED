#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Examen
{
    int leg;
    char nom[36];
    int nota;
};

int main()
{
    Examen exa;
    char nomArch[20];
    cout << "Nombre del archivo (con .dat)";
    cin >> nomArch;
    // FILE *arch=fopen("Parcial1.dat","rb");
    FILE *arch = fopen(nomArch, "rb");
    if (arch == NULL)
        cout << "ERROR" << endl;
    else
    {
        fread(&exa, sizeof(Examen), 1, arch);
        while (!feof(arch))
        {
            cout << exa.leg << exa.nom << exa.nota << endl;
            fread(&exa, sizeof(Examen), 1, arch);
        }
        fclose(arch);
    }

    return 0;
}
