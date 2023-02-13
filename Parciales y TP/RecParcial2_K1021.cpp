#include <iostream>

using namespace std;

struct RegArchVentas
{
    int numProvincia;
    int dia;
    int numMes;
    int impVenta;
};

struct RegArchVentasProv
{
    int nroProvicia;
    int impTotal;
};

struct DatoLista
{
    int dia;
    int numMes;
    int impVenta;
};

struct Nodo
{
    DatoLista info;
    Nodo *sig;
};

void generarArchivo(Nodo *v[], int t, FILE *aVtaP);
int impTotal(Nodo *lista);
void listar(Nodo *lista);
void listado(Nodo *v[], int t);
void cargarDatos(Nodo *v[], FILE *aVta);
void insertar(Nodo *&lista, DatoLista dato);
void inicializar(Nodo *v[], int t);

int main()
{
    FILE *archVtas, *archVtaP;
    Nodo *listaProvincia[24];

    archVtas = fopen("Ventas.dat", "rb");
    if (archVtas != NULL)
    {
        inicializar(listaProvincia, 24);
        cargarDatos(listaProvincia, archVtas);
        listado(listaProvincia, 24);
        fclose(archVtas);
        archVtaP = fopen("VentaProvincia.dat", "wb");
        if (archVtaP != NULL)
        {
            generarArchivo(listaProvincia, 24, archVtaP);
            fclose(archVtaP);
        }
    }
    return 0;
}

void generarArchivo(Nodo *v[], int t, FILE *aVtaP)
{
    RegArchVentasProv vtaP;

    for (int i = 0; i < t; i++)
    {
        vtaP.nroProvicia = i + 1;
        vtaP.impTotal = impTotal(v[i]);
        fwrite(&vtaP, sizeof(RegArchVentasProv), 1, aVtaP);
    }
}

int impTotal(Nodo *lista)
{
    Nodo *p;
    int t;
    p = lista;
    while (p != NULL)
    {
        t += p->info.impVenta;
        p = p->sig;
    }
    return t;
}

void listado(Nodo *v[], int t)
{
    for (int i = 0; i < t; i++)
    {
        if (v[i] != NULL)
        {
            cout << "Provincia " << i + 1 << endl;
            listar(v[i]);
        }
    }
}

void listar(Nodo *lista)
{
    Nodo *p;
    p = lista;
    while (p != NULL)
    {
        cout << p->info.numMes
             << p->info.dia
             << p->info.impVenta
             << endl;

        p = p->sig;
    }
}

void cargarDatos(Nodo *v[], FILE *aVta)
{
    RegArchVentas vta;
    DatoLista d;

    fread(&vta, sizeof(RegArchVentas), 1, aVta);
    while (!feof(aVta))
    {
        d.dia = vta.dia;
        d.numMes = vta.numMes;
        d.impVenta = vta.impVenta;
        insertar(v[vta.numProvincia - 1], d);
        fread(&vta, sizeof(RegArchVentas), 1, aVta);
    }
}

void insertar(Nodo *&lista, DatoLista dato)
{
    Nodo *p, *n, *ant;
    n = new Nodo;
    n->info = dato;
    p = lista;
    while (p != NULL && p->info.numMes < dato.numMes)
    {
        ant = p;
        p = p->sig;
    }
    n->sig = p;
    if (p != lista)
        ant->sig = n;
    else
        lista = n;
}

void inicializar(Nodo *v[], int t)
{
    for (int i = 0; i < t; i++)
        v[i] == NULL;
}
