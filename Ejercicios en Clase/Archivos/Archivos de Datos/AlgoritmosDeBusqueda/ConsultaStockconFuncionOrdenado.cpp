#include <iostream>
#include <stdio.h>

// Dado un código mostrar stock

using namespace std;

struct Producto
{
    unsigned codigo;
    unsigned stock;
};

int busquedaBinaria(FILE *archivo, int bus, Producto &prod);
int cantRegistros(FILE *archivo);

int main()
{
    FILE *arch;
    arch = fopen("ProductosOrd.dat", "rb");
    if (arch == NULL)
        cout << "ERROR";
    else
    {
        unsigned unCod;
        Producto prod;
        cout << "Codigo de producto a buscar ";
        cin >> unCod;
        int pos = busquedaBinaria(arch, unCod, prod);
        if (pos == -1)
            cout << unCod << " no existe" << endl;
        else
            cout << "El stock es " << prod.stock << endl;
    }
    return 0;
}

int cantRegistros(FILE *archivo)
{
    fseek(archivo, 0, SEEK_END);
    return ftell(archivo) / sizeof(Producto);
}

int busquedaBinaria(FILE *archivo, int bus, Producto &prod)
{
    int desde, hasta, medio, pos = -1;
    desde = 0;
    hasta = cantRegistros(archivo) - 1;
    while (desde <= hasta && pos == -1)
    {
        medio = (desde + hasta) / 2;
        fseek(archivo, medio * sizeof(Producto), SEEK_SET);
        fread(&prod, sizeof(Producto), 1, archivo);
        if (prod.codigo == bus)
            pos = medio;
        else
        {
            if (bus < prod.codigo)
                hasta = medio - 1;
            else
                desde = medio + 1;
        }
    }
    return pos;
}
