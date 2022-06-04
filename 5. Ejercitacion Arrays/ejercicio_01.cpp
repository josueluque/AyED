#include <iostream>
#define TAM 5 // Aca Designamos la cantidad de notas que se van a ingresar

using namespace std;
/*
    1) Hacer un algoritmo que lea 30 notas las cargue un vector y luego muestre la nota máxima.
*/
int ingresarNota(int v[], int ce);
int calcularNotaMayor(int v[], int ce, int nm);

int main()
{
    int nota[TAM], notaMaxima = 0;
    ingresarNota(nota, TAM);
    notaMaxima = calcularNotaMayor(nota, TAM, notaMaxima);

    cout << "La nota maxima es : " << notaMaxima << endl;

    return 0;
}

int ingresarNota(int v[], int ce)
{
    for (int i = 0; i < ce; i++)
    {
        cout << "Ingrese la nota " << i + 1 << " :";
        cin >> v[i];
        cout << "----------------" << endl;
    }
}

int calcularNotaMayor(int v[], int ce, int nm)
{
    for (int j = 0; j < ce; j++)
    {
        if (v[j] > nm)
        {
            nm = v[j];
        }
    }
    return nm;
}