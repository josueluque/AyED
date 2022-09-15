#include <iostream>

using namespace std;

struct Alumno
{
    unsigned legajo;
    char nombre[21];
    unsigned nota;
};

int cargarVector(Alumno *v[], int cme);
int promedio(Alumno *v[], int t);

int main()
{
    Alumno *vecAlum[5];
    int cant = cargarVector(vecAlum, 5);
    cout << promedio(vecAlum, cant);

    return 0;
}

int cargarVector(Alumno *v[], int cme)
{
    Alumno *p;
    int leg, i = 0;
    cin >> leg;
    while (leg != 0 && i < cme)
    {
        /*
        p=new Alumno;
        p->legajo=leg;
        cin>>p->nombre;
        cin>>p->nota;
        v[i]=p;
        */

        v[i] = new Alumno;
        v[i]->legajo = leg;
        cin >> v[i]->nombre;
        cin >> v[i]->nota;

        i++;
        cin >> leg;
    }
    return i;
}

int promedio(Alumno *v[], int t)
{
    int s = 0;
    for (int i = 0; i < t; i++)
        s += v[i]->nota;
    return s / t;
}
