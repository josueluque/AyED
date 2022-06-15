#include <iostream>

using namespace std;
/*
    2) Hacer un algoritmo que lea 40 números y los muestre en orden inverso.
*/

void ingresarNumero(int v[], int ce);
void invertirValores(int v[], int ce, int vi[]);

int main()
{
    int TAM;
    cout << "Ingrese cuántos números va a ingresar: ";
    cin >> TAM;

    int numeros[TAM], ordenInverso[TAM];
    ingresarNumero(numeros, TAM);
    invertirValores(numeros, TAM, ordenInverso);
    return 0;
}

void ingresarNumero(int v[], int ce)
{
    for (int i = 0; i < ce; i++)
    {
        cout << "Ingrese un número (vamos por el " << i + 1 << ") :" << endl;
        cin >> v[i];
        cout << " " << endl;
    }
}

void invertirValores(int v[], int ce, int vi[])
{
    for (int i = 0; i < ce; i++)
    {
        vi[i] = v[ce - (i + 1)];
    }

    cout << "El orden inverso de los número ingresados es: " << endl;
    for (int j = 0; j < ce; j++)
    {
        cout << "> " << vi[j] << endl;
    }
}
