#include <iostream>
#define TAM 4

using namespace std;
/*
    2) Hacer un algoritmo que lea 40 números y los muestre en orden inverso.
*/
// COMPLETAR

int ingresarNumero(int v[], int ce);
int invertirValores(int v[], int ce, int oi);

int main()
{
    int numeros[TAM], ordenInverso;
    ingresarNumero(numeros, TAM);
    ordenInverso = invertirValores(numeros, TAM, ordenInverso);

    cout << "Los valores ingresados ivertidamente: " << ordenInverso << endl;

    return 0;
}

int ingresarNumero(int v[], int ce)
{
    for (int i = 0; i < ce; i++)
    {
        cout << "Ingrese un número (vamos por el " << i + 1 << ") :" << endl;
        cin >> v[i];
        cout << "----------------" << endl;
    }
}

int invertirValores(int v[], int ce, int oi)
{
}
