#include <iostream>
#include <stdio.h>

using namespace std;

struct Alumno
{
    int leg;
    string nom;
    int nota;
};

struct NodoPila
{
    int info;
    NodoPila *sig;
};

void apilar(NodoPila *&pila, int dato);
void desapilar(NodoPila *&pila, int &dato);

int main()
{
    NodoPila *listaAlumnos = NULL;
    Alumno alumno;
    cin >> alumno.leg;
    while (alumno.leg != 0)
    {
        cin >> alumno.nom;
        cin >> alumno.nota;
        apilar(listaAlumnos, alumno);
        cin >> alumno.leg;
    }
    listar(listaAlumnos);
    return 0;
}

void apilar(NodoPila *&pila, int dato)
{
    NodoPila *p;
    p = new NodoPila;
    p->info = dato;
    p->sig = pila;
    pila = p;
}

void desapilar(NodoPila *&pila, int &dato)
{
    NodoPila *p;
    p = pila;
    dato = p->info;
    pila = p->sig;
    delete p;
}

void ejercicio4(NodoPila *&pila, int x, int y)
{
    int nro;
    NodoPila *paux = NULL;
    while (pila != NULL)
    {
        desapilar(pila, nro);
        if (nro == y)
            apilar(paux, x);
        else
            apilar(paux, nro);
    }
    while (paux != NULL)
    {
        desapilar(paux, nro);
        apilar(pila, nro);
    }
}
