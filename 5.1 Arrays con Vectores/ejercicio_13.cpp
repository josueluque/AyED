#include <iostream>

using namespace std;
/*
    13)Se tiene un vector de notas (cada elemento tiene nombre del alumno y nota obtenida)
    correspondientes al primer parcial y otro vector del mismo tipo del anterior
    con las notas correspondientes al segundo parcial,
    ambos vectores están ordenados alfabéticamente por nombre.
    Se pide hacer un listado ordenado por nombre con la condición obtenida por el alumno
    en la materia, según lo siguiente:
    - Primer y segundo parcial con nota mayor o igual a 8: PROMOCIÓN
    - Primer y segundo parcial con nota mayor o igual a 6: RINDE FINAL
    - Primer o segundo parcial con nota menor a 6: RECURSA
*/
struct Parcial
{
    string nombre;
    unsigned nota;
};

void cargarVector(Parcial v[], int ce);
void listado(Parcial vp1[], int t1, Parcial vp2[], int t2);

int main()
{
    Parcial v1[5], v2[6];
    cargarVector(v1, 5);
    cargarVector(v2, 6);
    listado(v1, 5, v2, 6);
    return 0;
}

void listado(Parcial vp1[], int t1, Parcial vp2[], int t2)
{
    int i = 0, j = 0;
    while (i < t1 && j < t2)
    {
        if (vp1[i].nombre == vp2[j].nombre)
        {
            if (vp1[i].nota >= 8 && vp2[j].nota >= 8)
                cout << vp1[i].nombre << " promocion" << endl;
            else
            {
                if (vp1[i].nota >= 6 && vp2[j].nota >= 6)
                    cout << vp1[i].nombre << " final" << endl;
                else
                    cout << vp1[i].nombre << " recursa" << endl;
            }
            i++;
            j++;
        }
        else
        {
            if (vp1[i].nombre < vp2[j].nombre)
            {
                cout << vp1[i].nombre << " recursa" << endl;
                i++;
            }
            else
            {
                cout << vp2[j].nombre << " recursa" << endl;
                j++;
            }
        }
    }
    for (int k = i; k < t1; k++)
        cout << vp1[k].nombre << " recursa" << endl;
    for (int k = j; k < t2; k++)
        cout << vp2[k].nombre << " recursa" << endl;
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
