#include <iostream>
#include <stdio.h>
/*
    Generar una lista de alumnos con sublista de examenes rendidos por alumno en un mes de examen.
    Se ingresa examen por examen, sin orden.
    Por cada examen se ingresa dni y nombre del alumno, fecha, c�digo de materia y nota del examen
*/

using namespace std;

struct Examen
{
    int dia;
    int codMat;
    int nota;
};
struct NodoSub
{
    Examen info;
    NodoSub *sig;
};
struct Alumno
{
    int dni;
    string nom;
    NodoSub *listaExa;
};
struct Nodo
{
    Alumno info;
    Nodo *sig;
};

void insertar(NodoSub *&, Examen);
Nodo *buscarInsertar(Nodo *&, Alumno);
void generar(Nodo *&lista);

int main()
{
    Nodo *listaAlumnos = NULL;
    generar(listaAlumnos);
    // ej10(listaAlumnos);
    return 0;
}

void generar(Nodo *&lista)
{
    Alumno al;
    Examen ex;
    Nodo *p;
    cout << "DNI alumno: ";
    cin >> dniAl;
    while (dniAl != 0) // ingresa datos del examen
    {
        cout << "Nombre alumno: ";
        cin >> nomAl;
        cout << "Fecha examen: ";
        cin >> fechaEx;
        cout << "Materia rendida: ";
        cin >> codMateria;
        cout << "Nota: ";
        cin >> notaOb;

        al.dni = dniAl;
        al.nom = nomAl;
        al.listaExa = NULL;
        p = buscarInsertar(lista, al);
        ex.dia = fechaEx;
        ex.codMat = codMateria;
        ex.nota = notaOb;
        insertar(p->info.listaExa, ex);

        cout << "DNI alumno: ";
        cin >> dniAl;
    }
}

void insertar(NodoSub *&lista, Examen ex) // ordenado por fecha
{
    NodoSub *n, *p, *ant;
    n = new NodoSub;
    n->info = ex;
    p = lista;
    while (p != NULL && p->info.dia < ex.dia)
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
    Nodo *ant, *p = lista;
    while (p != NULL && p->info.dni < al.dni)
    {
        ant = p;
        p = p->sig;
    }
    if (p != NULL && al.dni == p->info.dni)
        return p;
    else
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
}
