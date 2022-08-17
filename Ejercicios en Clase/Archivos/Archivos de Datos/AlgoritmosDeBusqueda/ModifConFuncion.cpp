#include <iostream>
#include <stdio.h>

// Dado un archivo de productos actualizar el stock de uno de ellos, si existe o agregarlo si no existe

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

        int pos = busquedaSecuencial(arch, unCod, prod);

        if (pos == -1)
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
            fseek(arch, pos * sizeof(Producto), SEEK_SET);
            // fwrite(&prod,sizeof(Producto),1,arch);
        }
        fwrite(&prod, sizeof(Producto), 1, arch);
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
