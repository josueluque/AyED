#include <iostream>
#include <stdio.h>

using namespace std;

struct RegArchCobranza
{
    int codCliente;
    int numCuota;
};

struct DatoLista
{
    int codCliente;
    int cuotasAd;
};

struct Nodo
{
    DatoLista info;
    Nodo *sig;
};

void cargarDatos(Nodo *lisCliente, FILE *aCobr);
void insertar(Nodo *&lista, DatoLista dato);
void listar(Nodo *lista);

int main()
{
    FILE *archCobr;
    Nodo *listaCliente;
    archCobr = fopen("Cobranzas.dat", "rb"); // Asumo que el nombre del archivo es Cobranzas.dat
    if (archCobr != NULL)
    {
        cargarDatos(listaCliente, archCobr);
        listar(listaCliente);
    }
    return 0;
}

void listar(Nodo *lista)
{
    Nodo *p;
    p = lista;
    while (p != NULL)
    {
        cout << "El cliente: " << p->info.codCliente << "     Adeuda:" << p->info.cuotasAd << " cuotas" << endl;
        p = p->sig;
    }
}

void cargarDatos(Nodo *lisCliente, FILE *aCobr)
{
    RegArchCobranza cobr;
    DatoLista d;
    fread(&cobr, sizeof(RegArchCobranza), 1, aCobr);
    while (!feof(aCobr))
    {
        if (cobr.numCuota != 0) // Asumo que si un cliente no adeuoda ni una cuota tiene numCuota = 0
        {
            d.codCliente = cobr.codCliente;
            d.cuotasAd = cobr.numCuota;
            insertar(lisCliente, d);
        }
        fread(&cobr, sizeof(RegArchCobranza), 1, aCobr);
    }
}

void insertar(Nodo *&lista, DatoLista dato)
{
    Nodo *n, *p, *ant;
    n = new Nodo;
    n->info = dato;
    p = lista;
    while (p != NULL && p->info.codCliente < dato.codCliente)
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