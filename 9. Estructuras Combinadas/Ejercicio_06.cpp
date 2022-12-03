#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct RegArchInfraccion
{
    char patente[7];
    int fecha;
    int codIfraccion;
};

struct DatoLista
{
    int codIfraccion;
    char patente[7];
};

struct Nodo
{
    DatoLista info;
    Nodo *sig;
};

void cargarDatos(Nodo *listaInf, FILE *aInf);
Nodo *buscarPatente(Nodo *lista, Nodo *bus);
void insertar(Nodo *&lista, DatoLista dato);
void listar(Nodo *lista);

int main()
{
    FILE *archInf;
    Nodo *listaInf;
    archInf = fopen("Infracciones.dat", "rb");
    if (archInf != NULL)
    {
        cargarDatos(listaInf, archInf);
        listar(listaInf);
    }
    return 0;
}

void cargarDatos(Nodo *listaInf, FILE *aInf)
{
    RegArchInfraccion inf;
    DatoLista d;
    string str;
    fread(&inf, sizeof(RegArchInfraccion), 1, aInf);
    while (!feof(aInf))
    {
        str = string(inf.patente);
        strcpy(d.patente, str.c_str());
        // d.patente = str;
        d.codIfraccion = inf.codIfraccion;
        // n = buscarPatente(listaInf, d);
        // if (n > 1)
        //{
        insertar(listaInf, d);
        //}
        fread(&inf, sizeof(RegArchInfraccion), 1, aInf);
    }
}

void listar(Nodo *lista)
{
    Nodo *p;
    p = lista;
    while (p != NULL)
    {
        Nodo *pa = buscarPatente(lista, p);
        if (pa != NULL)
        {
            cout << pa->info.patente << endl;
            cout << pa->info.codIfraccion << endl;
        }
        p = p->sig;
    }
}

Nodo *buscarPatente(Nodo *lista, Nodo *bus)
{
    Nodo *p = lista;
    int cont = 0;
    while (p != NULL)
    {
        if (p->info.patente == bus->info.patente && p->info.codIfraccion == bus->info.codIfraccion)
            cont += 1;
        p = p->sig;
    }
    if (p != NULL && cont > 1)
        return p;
    else
        return NULL;
}

void insertar(Nodo *&lista, DatoLista dato)
{
    Nodo *n, *p, *ant;
    n = new Nodo;
    n->info = dato;
    p = lista;
    while (p != NULL && p->info.codIfraccion > dato.codIfraccion)
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
