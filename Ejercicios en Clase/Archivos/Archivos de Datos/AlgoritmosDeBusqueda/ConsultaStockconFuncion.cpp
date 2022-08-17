#include <iostream>
#include <stdio.h>

// Dado un código mostrar stock

using namespace std;

struct Producto
{
    unsigned codigo;
    unsigned stock;
};

int busquedaSecuencial(FILE *archivo, int bus, Producto &prod);

int main()
{
    FILE *arch;
    arch = fopen("Productos.dat", "rb");
    if (arch == NULL)
        cout << "ERROR";
    else
    {
        unsigned unCod;
        Producto prod;
        cout << "Codigo de producto a buscar ";
        cin >> unCod;
        int pos = busquedaSecuencial(arch, unCod, prod);
        if (pos == -1)
            cout << unCod << " no existe" << endl;
        else
            cout << "El stock es " << prod.stock << endl;
    }
    return 0;
}

int busquedaSecuencial(FILE *archivo, int bus, Producto &prod)
{
    int i = 0;
    fread(&prod, sizeof(Producto), 1, archivo);
    while (!feof(archivo) && prod.codigo != bus)
    {
        i++;
        fread(&prod, sizeof(Producto), 1, archivo);
    }

    if (feof(archivo))
        return -1;
    else
        return i;
}
