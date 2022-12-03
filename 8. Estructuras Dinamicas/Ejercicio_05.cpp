#include <iostream>
#include <stdio.h>

using namespace std;

struct NodoCola
{
    int info;
    NodoCola *sig;
};

int desencolar(NodoCola *&pri, NodoCola *&ult)
{
    int dato;
    NodoCola *p = pri;
    pri = p->sig;
    dato = p->info;
    delete p;
    if (pri == NULL)
        ult = NULL;
    return dato;
}

bool ejercicio5(NodoCola *pri, NodoCola *ult)
{
    int i = 0;
    while (pri != NULL && i < 4)
    {
        desencolar(pri, ult);
        i++;
    }
    /*
    if(i==4)
        return true;
    else
        return false;
    */
    return i == 4;
}
