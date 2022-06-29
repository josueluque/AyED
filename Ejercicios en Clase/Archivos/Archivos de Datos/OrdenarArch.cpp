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

void ordenar(Parcial v[], unsigned t);
void grabarArch(char n[], Parcial v[], int c);
int cargarVector(Parcial v[], FILE *a, int cme);

int main()
{
    char nomArch[21];
    cout << "Ingrese el nombre del archivo: ";
    cin >> nomArch;
    strcat(nomArch, ".dat");
    FILE *a = fopen(nomArch, "rb");
    if (a != NULL)
    {
        Parcial v[40];
        int cant = cargarVector(v, a, 40);
        fclose(a);
        ordenar(v, cant);
        grabarArch(nomArch, v, cant);
    }

    return 0;
}

int cargarVector(Parcial v[], FILE *a, int cme)
{

    Parcial ex;
    int i = 0;
    fread(&ex, sizeof(Parcial), 1, a);
    while (!feof(a) && i < cme)
    {
        v[i] = ex;
        i++;
        fread(&ex, sizeof(Parcial), 1, a);
    }
    return i;
}

void ordenar(Parcial v[], unsigned t)
{
    unsigned i = 1, j;
    Parcial aux;
    bool cambio;
    do
    {
        cambio = false;
        for (j = 0; j < t - i; j++)
        {
            if (v[j].legajo > v[j + 1].legajo)
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                cambio = true;
            }
        }
        i++;
    } while (i < t && cambio);
}

void grabarArch(char n[], Parcial v[], int c)
{
    FILE *a = fopen(n, "wb");
    for (int i = 0; i < c; i++)
        fwrite(&v[i], sizeof(Parcial), 1, a);
    fclose(a);
}
/*
void grabarArch(char n[],Parcial v[],int c)
{
    FILE *a=fopen(n,"wb");
    fwrite(v,sizeof(Parcial),c,a);
    fclose(a);
}
*/
