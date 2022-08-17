#include <iostream>
#include <stdio.h>

// Dado un archivo de productos actualizar el stock de uno de ellos, si existe o agregarlo si no existe

using namespace std;

struct Producto
{
    unsigned codigo;
    unsigned stock;
};

int main()
{
    FILE *arch;
    arch = fopen("Productos.dat", "r+b");
    if (arch == NULL)
        cout << "ERROR";
    else
    {
        unsigned unCod;
        Producto prod;
        cout << "Codigo de producto a buscar ";
        cin >> unCod;
        int stockSumar;
        cout << "ingrese el stock a sumar ";
        cin >> stockSumar;

        fread(&prod, sizeof(Producto), 1, arch);
        while (!feof(arch) && prod.codigo != unCod)
            fread(&prod, sizeof(Producto), 1, arch);

        if (feof(arch))
        {
            cout << unCod << " no existe" << endl;
            prod.codigo = unCod;
            prod.stock = stockSumar;
            // fwrite(&prod,sizeof(Producto),1,arch);
        }

        else
        {
            cout << "El stock es " << prod.stock << endl;
            prod.stock += stockSumar;
            fseek(arch, -sizeof(Producto), SEEK_CUR);
            // fwrite(&prod,sizeof(Producto),1,arch);
        }
        fwrite(&prod, sizeof(Producto), 1, arch);
    }
    return 0;
}
