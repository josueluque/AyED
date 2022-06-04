#include <iostream>
#define TAM 5

using namespace std;
/*
    3) Hacer un algoritmo que lea 40 edades de alumnos y muestre por pantalla las edades que superen a
    la edad promedio.
*/
int ingresarEdad(int v[], int ce);
int calcularPromedio(int v[], int t);
int sumatoria(int v[], int c);
int mayoresAlPromedio(int v[], int ce, int p);

int main()
{
    int edad[TAM], prom, cantM;
    ingresarEdad(edad, TAM);
    prom = calcularPromedio(edad, TAM);
    cantM = mayoresAlPromedio(edad, TAM, prom);

    cout << "Hay " << cantM << " alumnos que superan la edad promedio que es " << prom << endl;
    return 0;
}

int ingresarEdad(int v[], int ce)
{
    for (int i = 0; i < ce; i++)
    {
        cout << "Ingrese la edad del alumno (" << i + 1 << ") :";
        cin >> v[i];
        cout << "-----" << endl;
    }
}

int calcularPromedio(int v[], int t)
{
    return sumatoria(v, t) / t;
}

int sumatoria(int v[], int c)
{
    int s = 0;
    for (int j = 0; j < c; j++)
        s += v[j];
    return s;
}

int mayoresAlPromedio(int v[], int ce, int p)
{
    int c = 0;
    for (int k = 0; k < ce; k++)
    {
        if (v[k] > p) // si la edad del alumno "v[k]" supera el promedio "p" incrementa "c" (cantidad)
            c++;
    }
    return c;
}