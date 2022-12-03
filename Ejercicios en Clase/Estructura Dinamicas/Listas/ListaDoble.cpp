#include <iostream>
#include <stdio.h>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *sig;
    Nodo *ant;
};

void insertar(Nodo *&lis1, Nodo *&lis2, int nro);
void mostrarAsc(Nodo *l);
void mostrarDesc(Nodo *l);

int main()
{
    Nodo *listaD1 = NULL, *listaD2 = NULL;
    int nro;
    cin >> nro;
    while (nro != 0)
    {
        insertar(listaD1, listaD2, nro);
        cin >> nro;
    }
    cout << "ascendente" << endl;
    mostrarAsc(listaD1);
    cout << "descendente" << endl;
    mostrarDesc(listaD2);

    return 0;
}

void insertar(Nodo *&lis1, Nodo *&lis2, int nro)
{
    Nodo *n = new Nodo;
    n->dato = nro;
    if (lis1 == NULL && lis2 == NULL)
    {
        n->ant = NULL;
        n->sig = NULL;
        lis1 = lis2 = n;
    }
    else
    {
        Nodo *p = lis1;
        while (p != NULL && p->dato < nro)
            p = p->sig;
        if (p == lis1)
        {
            n->sig = p;
            n->ant = NULL;
            p->ant = n; // lis1->ant=n;
            lis1 = n;
        }
        else
        {
            if (p == NULL)
            {
                n->sig = NULL; // n->sig=p;
                n->ant = lis2;
                lis2->sig = n;
                lis2 = n;
            }
            else
            {
                /*
                Nodo*ante=p->ant;
                n->sig=p;
                n->ant=ante;
                ante->sig=n;
                p->ant=n;
                */
                n->sig = p;
                n->ant = p->ant;
                p->ant->sig = n;
                p->ant = n;
            }
        }
    }
}

void mostrarAsc(Nodo *l)
{
    Nodo *p = l;
    while (p != NULL)
    {
        cout << p->dato << endl;
        p = p->sig;
    }
}

void mostrarDesc(Nodo *l)
{
    Nodo *p = l;
    while (p != NULL)
    {
        cout << p->dato << endl;
        p = p->ant;
    }
}
