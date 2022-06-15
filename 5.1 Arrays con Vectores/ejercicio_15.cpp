#include <iostream>

using namespace std;

/*
    15)Se tiene un vector con las notas de los exámenes rendidos por los alumnos
    (nombre y nota) ordenado por nombre con un elemento por cada examen rendido
    (un alumno puede haber rendido 1, 2, ó más exámenes).
    Se pide generar un vector con un elemento por alumno
    con el promedio de las notas de sus exámenes, ordenado por nombre.
*/

struct Parcial
{
    string nombre;
    unsigned nota;
};

void cargarVector(Parcial v[], int ce);
void mostrarVec(Parcial v[], int ce);
void corteControlEj15(Parcial vr[], int tvr, Parcial vu[], int &tvu);

int main()
{
    Parcial vMuchos[8], vUno[8];
    int tamVUno;
    cargarVector(vMuchos, 8);
    corteControlEj15(vMuchos, 8, vUno, tamVUno);
    mostrarVec(vUno, tamVUno);
    return 0;
}

void corteControlEj15(Parcial vr[], int tvr, Parcial vu[], int &j)
{
    int i = 0, suma, cont;
    // string nom;
    j = 0;
    while (i < tvr)
    {
        // nom=vr[i].nombre;
        vu[j].nombre = vr[i].nombre;
        suma = 0;
        cont = 0;
        do
        {
            suma += vr[i].nota;
            cont++;
            i++;
            //}while(i<tvr && vr[i].nombre==nom);
        } while (i < tvr && vr[i].nombre == vu[j].nombre);
        // vu[j].nombre=nom;
        vu[j].nota = suma / cont;
        j++;
    }
}

void cargarVector(Parcial v[], int ce)
{
    for (int i = 0; i < ce; i++)
    {
        cout << "nombre de posicion " << i << endl;
        cin >> v[i].nombre;
        cout << "nota de posicion " << i << endl;
        cin >> v[i].nota;
    }
}

void mostrarVec(Parcial v[], int ce)
{
    for (int i = 0; i < ce; i++)
        cout << v[i].nombre << v[i].nota << endl;
}
