#include <iostream>
#include <stdio.h>

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

void insertar(Nodo *&lista, Alumno al);
void listar(Nodo *lista);
void insertarPorNota(Nodo *&lista, Alumno al);
void insertarPorNotaLog(Nodo *&lista, Nodo *n);

int main()
{
    Nodo *listaAlumnos = NULL;
    Alumno alumno;
    cin >> alumno.leg;
    while (alumno.leg != 0)
    {
        cin >> alumno.nom;
        cin >> alumno.nota;
        insertar(listaAlumnos, alumno);
        cin >> alumno.leg;
    }
    listar(listaAlumnos);
    return 0;
}

void listar(Nodo *lista)
{
    Nodo *p;
    p = lista;
    while (p != NULL)
    {
        cout << p->info.leg << p->info.nom << p->info.nota << endl;
        p = p->sig;
    }
}

Nodo *buscar(Nodo *lista, int legBus)
{
    Nodo *p = lista;
    while (p != NULL && p->info.leg != legBus)
        p = p->sig;
    return p;
}

int buscarPatente(Nodo *lista, int bus)
{
    Nodo *p = lista;
    int cont = 0;
    while (p != NULL)
    {
        if (p->info.leg == bus)
            cont += 1;
        p = p->sig;
    }
    return cont;
}

// Para esta Función si o si la lista debee estar ordenada
Nodo *buscarMejor(Nodo *lista, int legBus)
{
    Nodo *p = lista;
    while (p != NULL && p->info.leg < legBus)
        p = p->sig;
    if (p == NULL || p->info.leg != legBus)
        return NULL;
    else
        return p;
}

void insertar(Nodo *&lista, Alumno al)
{
    Nodo *n, *p, *ant;
    n = new Nodo;
    n->info = al;
    p = lista;
    while (p != NULL && p->info.leg < al.leg)
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

Nodo *buscarInsertar(Nodo *&lista, Alumno al)
{
    Nodo *p, *ant;
    p = lista;
    while (p != NULL && p->info.leg < al.leg)
    {
        ant = p;
        p = p->sig;
    }
    if (p == NULL || p->info.leg != al.leg)
    {
        Nodo *n = new Nodo;
        n->info = al;
        n->sig = p;
        if (p != lista)
            ant->sig = n;
        else
            lista = n;
        return n;
    }
    else
        return p;
}

void eliminar(Nodo *&lista, int legBus)
{
    Nodo *ant, *p = lista;
    while (p != NULL && p->info.leg < legBus)
    {
        ant = p;
        p = p->sig;
    }

    if (p == NULL || p->info.leg != legBus)
        cout << "no esta" << endl;
    else
    {
        if (p != lista)
            ant->sig = p->sig;
        else
            lista = p->sig;
        delete p;
    }
}

void listaOrdenada(Nodo *lista, Nodo *&listaOrd)
{
    // de > a < por nota
    listaOrd = NULL;
    Nodo *r = lista;
    while (r != NULL)
    {
        insertarPorNota(listaOrd, r->info);
        r = r->sig;
    }
}

void reordenar(Nodo *&lista)
{
    // de > a < por nota
    Nodo *listaOrd = NULL;
    Nodo *r;
    while (lista != NULL)
    {
        r = lista;
        lista = lista->sig;
        insertarPorNotaLog(listaOrd, r);
    }
    lista = listaOrd;
}

void consultarNota(Nodo *lista, int unLeg)
{
    // muestra la nota de un alumno dada su legajo
    // Nodo*pa=buscar(lista,unLeg);
    Nodo *pa = buscarMejor(lista, unLeg);
    if (pa == NULL)
        cout << "no existe un alumno con ese legjo" << endl;
    else
        cout << pa->info.nota << endl;
}

void cambiarNota(Nodo *lista, int unLeg, int nuevaNota)
{
    // cambia la nota de un alumno dada su legajo
    // Nodo*pa=buscar(lista,unLeg);
    Nodo *pa = buscarMejor(lista, unLeg);
    if (pa == NULL)
        cout << "no existe un alumno con ese legjo" << endl;
    else
        pa->info.nota = nuevaNota;
}

void cargarUnRecu(Nodo *&lista, Alumno alu)
{
    Nodo *p = buscarInsertar(lista, alu);
    p->info.nota = alu.nota;
}

void listaAprobados(Nodo *lista)
{
}
float promedio(Nodo *lista)
{
}

void insertarPorNota(Nodo *&lista, Alumno al)
{
    Nodo *n, *p, *ant;
    n = new Nodo;
    n->info = al;
    p = lista;
    while (p != NULL && p->info.nota > al.nota)
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
void insertarPorNotaLog(Nodo *&lista, Nodo *n)
{
    Nodo *p, *ant;

    p = lista;
    while (p != NULL && p->info.nota > n->info.nota)
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