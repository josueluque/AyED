#include <iostream>
#include <string.h>

using namespace std;

struct RegArchBecas
{
    int codBeca;
    string descrip;
    int maxVacantes;
};

struct RegArchSol
{
    int dni;
    char nomCom[30];
    int codBeca;
    int ingresoF;
};

struct Solicitantes
{
    int dni;
    char nomCompleto[30];
    int codBeca;
    int ingresoF;
};

struct NodoSub
{
    Solicitantes info;
    NodoSub *sig;
};

struct Becas
{
    int codBeca;
    int maxVacantes;
    NodoSub *listaSol;
};

struct Nodo
{
    Becas info;
    Nodo *sig;
};

// Prototipos
void generar(Nodo *lista, FILE *aBecas, FILE *aSol);
Nodo *buscarInsertar(Nodo *&lista, Becas b);
void insertar(NodoSub *&lista, Solicitantes s);
void listar(Nodo *lista);

int main()
{
    FILE *archBecas, *archSolicitantes;
    Nodo *listaBecas = NULL;
    archBecas = fopen("Becas.dat", "rb");
    archSolicitantes = fopen("Solicitantes.dat", "rb");

    generar(listaBecas, archBecas, archSolicitantes);
    listar(listaBecas);
    return 0;
}

void listar(Nodo *lista)
{
    Nodo *p = lista;
    while (p != NULL)
    {
        cout << p->info.listaSol->info.codBeca << endl;
        int maxV = p->info.maxVacantes;
        while (maxV != 0)
        {
            cout << p->info.listaSol->info.dni << endl
                 << p->info.listaSol->info.nomCompleto << endl;
            maxV--;
        }
        p = p->sig;
    }
}

void generar(Nodo *lista, FILE *aBecas, FILE *aSol)
{
    RegArchBecas ab;
    Becas b;
    RegArchSol as;
    Solicitantes s;
    Nodo *p;

    fread(&ab, sizeof(RegArchBecas), 1, aBecas);
    while (!feof(aBecas))
    {
        b.codBeca = ab.codBeca;
        b.maxVacantes = ab.maxVacantes;
        b.listaSol = NULL;
        p = buscarInsertar(lista, b);
        fread(&as, sizeof(RegArchSol), 1, aSol);
        while (!feof(aSol))
        {
            s.codBeca = as.codBeca;
            if (p->info.codBeca == s.codBeca)
            {
                s.dni = as.dni;
                strcpy(s.nomCompleto, as.nomCom);
                // s.nomCompleto = as.nomCom;
                s.ingresoF = as.ingresoF;
                insertar(p->info.listaSol, s);
            }
            fread(&as, sizeof(RegArchSol), 1, aSol);
        }
        fread(&ab, sizeof(RegArchBecas), 1, aBecas);
    }
}

void insertar(NodoSub *&lista, Solicitantes s)
{
    NodoSub *n, *p, *ant;
    n = new NodoSub;
    n->info = s;
    p = lista;
    while (p != NULL && p->info.ingresoF < s.ingresoF)
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

Nodo *buscarInsertar(Nodo *&lista, Becas b)
{
    Nodo *ant, *p = lista;
    while (p != NULL && p->info.codBeca < b.codBeca)
    {
        ant = p;
        p = p->sig;
    }
    if (p != NULL && b.codBeca == p->info.codBeca)
        return p;
    else
    {
        Nodo *n = new Nodo;
        n->info = b;
        n->sig = p;
        if (p != lista)
            ant->sig = n;
        else
            lista = n;
        return n;
    }
}