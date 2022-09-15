#include <iostream>
#include <stdio.h>

using namespace std;

struct NodoCola
{
    int info;
    NodoCola *sig;
};

void encolar(NodoCola *&pri, NodoCola *&ult, int dato);
int desencolar(NodoCola *&pri, NodoCola *&ult);

void encolar(NodoCola *&pri, NodoCola *&ult, int dato)
{
    NodoCola *p;
    p = new NodoCola;
    p->info = dato;
    p->sig = NULL;
    if (ult != NULL)
    {
        ult->sig = p;
    }
    else
    {
        pri = p;
    }
    ult = p;
}

int desencolar(NodoCola *&pri, NodoCola *&ult)
{
    NodoCola *p;
    p = pri;
    int dato = p->info;
    pri = p->sig;
    delete p;
    if (pri == NULL)
        ult = NULL;
    return dato;
}
