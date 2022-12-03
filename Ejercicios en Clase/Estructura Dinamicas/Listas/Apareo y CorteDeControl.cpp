#include <iostream>
#include <stdio.h>

// Apareo: Dadas dos listas (ordenadas por legajo) con alumnos que rindieron en dos fechas,
// informar el resultado de todos en un listado ordenado por legajo
// si se repiten informar con la mayor nota
// CC: Dada una lista con alumnos repetidos mostrar alumno y promedio

using namespace std;

struct Alumno
{
    unsigned leg;
    string nom;
    unsigned nota;
};

struct Nodo
{
    Alumno info;
    Nodo *sig;
};

void apareo(Nodo *lista1, Nodo *lista2);
void generar(Nodo *&lis);
void insertar(Nodo *&lista, Alumno alu);
void listar(Nodo *lista);
void cc1(Nodo *lista);
void cc2(Nodo *lista);

int main()
{
    /*
    //APAREO
    Nodo*l1,*l2;
    generar(l1);
    cout<<"lista 1"<<endl;
    listar(l1);
    generar(l2);
    cout<<"lista 2"<<endl;
    listar(l2);
    cout<<"listas juntas"<<endl;
    apareo(l1,l2);
    */
    // CC
    Nodo *lis;
    generar(lis);
    listar(lis);
    cout << "Alumnos con promedio" << endl;
    cc2(lis);

    return 0;
}

void apareo(Nodo *lista1, Nodo *lista2)
{
    Nodo *p1, *p2;
    p1 = lista1;
    p2 = lista2;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->info.leg < p2->info.leg)
        {
            cout << p1->info.leg << p1->info.nom << p1->info.nota << endl;
            p1 = p1->sig;
        }
        else
        {
            if (p1->info.leg == p2->info.leg)
            {
                cout << p1->info.leg << p1->info.nom;
                if (p1->info.nota > p2->info.nota)
                    cout << p1->info.nota << endl;
                else
                    cout << p2->info.nota << endl;
                p1 = p1->sig;
                p2 = p2->sig;
            }
            else
            {
                cout << p2->info.leg << p2->info.nom << p2->info.nota << endl;
                p2 = p2->sig;
            }
        }
    }
    while (p1 != NULL)
    {
        cout << p1->info.leg << p1->info.nom << p1->info.nota << endl;
        p1 = p1->sig;
    }
    while (p2 != NULL)
    {
        cout << p2->info.leg << p2->info.nom << p2->info.nota << endl;
        p2 = p2->sig;
    }
}

void cc1(Nodo *lista)
{
    int legA, suma, cont;
    string nomA;
    Nodo *p;
    p = lista;
    while (p != NULL)
    {
        legA = p->info.leg;
        nomA = p->info.nom;
        suma = cont = 0;
        do
        {
            suma += p->info.nota;
            cont++;
            p = p->sig;
        } while (p != NULL && p->info.leg == legA);
        cout << legA << nomA << suma / cont << endl;
    }
}

void cc2(Nodo *lista) // versión con 2 punteros
{
    int suma, cont;
    Nodo *p, *q;
    p = q = lista;
    while (p != NULL)
    {
        // q=p;
        suma = cont = 0;
        do
        {
            suma += q->info.nota;
            cont++;
            q = q->sig;
        } while (q != NULL && q->info.leg == p->info.leg);
        cout << p->info.leg << p->info.nom << suma / cont << endl;
        p = q;
    }
}

void generar(Nodo *&lis)
{
    lis = NULL;
    Alumno al;
    cin >> al.leg;
    while (al.leg != 0)
    {
        cin >> al.nom;
        cin >> al.nota;
        insertar(lis, al);
        cin >> al.leg;
    }
}

void insertar(Nodo *&lista, Alumno alu)
{
    Nodo *n, *r, *ant;
    n = new Nodo;
    n->info = alu;
    r = lista;
    while (r != NULL && r->info.leg < alu.leg)
    {
        ant = r;
        r = r->sig;
    }
    n->sig = r;
    if (r != lista)
        ant->sig = n;
    else
        lista = n;
}

void listar(Nodo *lista)
{
    Nodo *r;
    r = lista;
    while (r != NULL)
    {
        cout << r->info.leg << r->info.nom << r->info.nota << endl;
        r = r->sig;
    }
}
