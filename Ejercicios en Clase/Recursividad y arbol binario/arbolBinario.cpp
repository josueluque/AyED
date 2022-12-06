#include <iostream>

using namespace std;

struct Nodo
{
    int info;
    Nodo *izq;
    Nodo *der;
};

Nodo *buscar(Nodo *raiz, int nro);
void insertar(Nodo *&raiz, int nro);
void listarIn(Nodo *raiz);
void listarPre(Nodo *raiz);
void listarPost(Nodo *raiz);

int main()
{
    Nodo *raizArbol = NULL;
    int num;
    cin >> num;
    while (num != 0)
    {
        insertar(raizArbol, num);
        cin >> num;
    }
    cout << endl
         << "inorden" << endl;
    listarIn(raizArbol);
    cout << endl
         << "preorden" << endl;
    listarPre(raizArbol);
    cout << endl
         << "postorden" << endl;
    listarPost(raizArbol);
    return 0;
}

// funciones abb

Nodo *buscar(Nodo *raiz, int nro)
{
    Nodo *r;
    r = raiz;
    while (r != NULL && r->info != nro)
    {
        if (nro < r->info)
            r = r->izq;
        else
            r = r->der;
    }
    return r;
}

void insertar(Nodo *&raiz, int nro)
{
    Nodo *n;
    n = new Nodo;
    n->info = nro;
    n->der = n->izq = NULL;
    if (raiz == NULL)
        raiz = n;
    else
    {
        Nodo *r = raiz, *ant;
        while (r != NULL)
        {
            ant = r;
            if (nro < r->info)
                r = r->izq;
            else
                r = r->der;
        }
        if (nro < ant->info)
            ant->izq = n;
        else
            ant->der = n;
    }
}

void listarIn(Nodo *raiz)
{
    if (raiz != NULL)
    {
        listarIn(raiz->izq);
        cout << raiz->info << "  ";
        listarIn(raiz->der);
    }
}
//

void listarPre(Nodo *raiz)
{
    if (raiz != NULL)
    {
        cout << raiz->info << "  ";
        listarPre(raiz->izq);
        listarPre(raiz->der);
    }
}

void listarPost(Nodo *raiz)
{
    if (raiz != NULL)
    {
        listarPost(raiz->izq);
        listarPost(raiz->der);
        cout << raiz->info << "  ";
    }
}