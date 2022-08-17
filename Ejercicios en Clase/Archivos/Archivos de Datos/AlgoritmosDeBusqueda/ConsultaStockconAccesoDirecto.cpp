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
    arch = fopen("ProductosAccDir.dat", "rb");
    if (arch == NULL)
        cout << "ERROR";
    else
    {
        unsigned unCod;
        Producto prod;
        cout << "Codigo de producto a buscar ";
        cin >> unCod;

        fseek(arch, (unCod - 1) * sizeof(Producto), SEEK_SET);
        fread(&prod, sizeof(Producto), 1, arch);

        cout << "El stock es " << prod.stock << endl;
    }
    return 0;
}
