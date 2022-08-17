#include <iostream>
#include <stdio.h>

// Dado un código mostrar stock

using namespace std;

struct Producto
{
    unsigned codigo;
    unsigned stock;
};

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
        fread(&prod, sizeof(Producto), 1, arch);
        while (!feof(arch) && prod.codigo != unCod)
            fread(&prod, sizeof(Producto), 1, arch);
        if (feof(arch))
            cout << unCod << " no existe" << endl;
        else
            cout << "El stock es " << prod.stock << endl;
    }
    return 0;
}
