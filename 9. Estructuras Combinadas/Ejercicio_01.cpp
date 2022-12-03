#include <iostream>

using namespace std;
/*
    En una empresa de construcción se quiere almacenar en un archivo los importes y
    fechas de los materiales comprados para cada una de las obras que está
    construcción. Para ello se ingresa por teclado, por cada compra de materiales
    realizada: el código de la obra, la fecha y el importe de la compra. Los datos son
    ingresados sin orden. Para cada obra se puede haber comprado materiales varias
    veces. Se pide generar un archivo secuencial con código de obra, fecha e importe,
    ordenado por código de obra y por fecha, con los datos ingresados por teclado.
*/

struct mComprados
{
    int codigoObra;
    int fecha;
    int importe;
};

struct Nodo
{
    mComprados info;
    Nodo *sig;
};

int main()
{
    FILE *archCompras;
    Nodo *listaCompras;

    archCompras = fopen("Compras.dat", "wb");
    if (archCompras != NULL)
    {
        cargarArch(listaCompras, archCompras);
        fclose(archCompras);
    }
    return 0;
}

void cargarVector(Nodo *v[], FILE *avtas)
{
    
}

void cargarArch(Nodo *listaCom, FILE *archC)
{
    mComprados matComp;

    cout << "ingrese codigo de obra" << endl;
    cin >> matComp.codigoObra;
    while (matComp.codigoObra != 0)
    {
        cout << "ingrese fecha" << endl;
        cin >> matComp.fecha;
        cout << "ingrese importe" << endl;
        cin >> matComp.importe;
        fwrite(&matComp, sizeof(mComprados), 1, archC);
        cout << "ingrese codigo de obra" << endl;
        cin >> matComp.codigoObra;
    }
}
