#include <iostream>

using namespace std;

struct Libro
{
    string titulo;
    string materia;
};

struct NodoPila
{
    Libro info;
    NodoPila *sig;
};

void apilar(NodoPila *&pila, Libro dato);
Libro desapilar(NodoPila *&pila);
void mostrar(NodoPila *&pila);

int main()
{
    NodoPila *pilaLibros = NULL;
    Libro libro;
    char r;
    do
    {
        cin >> libro.titulo;
        cin >> libro.materia;
        apilar(pilaLibros, libro);
        cout << "quiere apilar otro libro? (s/n) ";
        cin >> r;
    } while (r == 's');
    int i = 0;
    while (i < 2)
    {
        libro = desapilar(pilaLibros);
        cout << libro.titulo << "-" << libro.materia << endl;
        i++;
    }
    cout << "Ingrese el nuevo libro: " << endl;
    cin >> libro.titulo;
    cin >> libro.materia;
    apilar(pilaLibros, libro);

    cout << "Pila actual: ";
    mostrar(pilaLibros);

    return 0;
}

void apilar(NodoPila *&pila, Libro dato)
{
    NodoPila *p;
    p = new NodoPila;
    // NodoPila*p=new NodoPila;
    p->info = dato;
    p->sig = pila;
    pila = p;
}

Libro desapilar(NodoPila *&pila)
{
    NodoPila *p = pila;
    Libro dato = p->info;
    pila = p->sig;
    delete p;
    return dato;
}

void mostrar(NodoPila *&pila)
{
    while (pila != NULL)
    {
        Libro dato = pila->info;
        cout << dato.titulo << " - " << dato.materia << endl;
        pila = pila->sig;
    }
}
