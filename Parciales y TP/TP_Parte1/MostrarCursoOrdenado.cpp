#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct ArchCurso
{
    int codigo;
    int nivel;
    int cupo;
    char nombreDocente[30];
    int dniDocente;
};

void ordenar(ArchCurso vc[], unsigned t);
void mostrar(ArchCurso vc[], int t);
int cargarVector(ArchCurso vc[], FILE *a, int cme);

int main()
{
    char nomArch[30];
    cout << "Nombre del archivo (con .dat)";
    cin >> nomArch;

    FILE *arch = fopen(nomArch, "rb");
    if (arch != NULL)
    {
        ArchCurso vc[48]; // hay 40 insriptos
        int cant = cargarVector(vc, arch, 48);
        fclose(arch);
        ordenar(vc, cant);
        mostrar(vc, cant);
    }

    return 0;
}

int cargarVector(ArchCurso vc[], FILE *a, int cme)
{
    ArchCurso p;
    int i = 0;
    fread(&p, sizeof(ArchCurso), 1, a);
    while (!feof(a) && i < cme)
    {
        vc[i] = p;
        i++;
        fread(&p, sizeof(ArchCurso), 1, a);
    }
    return i;
}

void ordenar(ArchCurso vc[], unsigned t)
{
    unsigned i = 1, j;
    ArchCurso aux;
    bool cambio;
    do
    {
        cambio = false;
        for (j = 0; j < t - i; j++)
        {
            if (vc[j].codigo > vc[j + 1].codigo)
            {
                aux = vc[j];
                vc[j] = vc[j + 1];
                vc[j + 1] = aux;
                cambio = true;
            }
        }
        i++;
    } while (i < t && cambio);
}

void mostrar(ArchCurso vc[], int t)
{
    cout << "--- POR CÓDIGO DE CURSO --- " << endl;
    for (int i = 0; i < t; i++)
    {
        cout << endl
             << "Código del curso: " << vc[i].codigo << endl;
        cout << "Nivel: " << vc[i].nivel << endl;
        cout << "Cupos:" << vc[i].cupo << endl;
        cout << "Nombre del docente: " << vc[i].nombreDocente << endl;
        cout << "Dni del docente: " << vc[i].dniDocente << endl;
    }
}
