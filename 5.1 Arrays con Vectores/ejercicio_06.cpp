#include <iostream>
#include <cstdlib>

using namespace std;

/*
    6) Escriba un programa que permita ingresar la tirada de un par de dados 50 veces y muestre una lista
    donde se vea cuántas veces se dio cada uno de los resultados posibles. Por cada tirada se deberán
    ingresar 2 valores, cada uno representa el valor de un dado. El formato de la salida debe ser el
    siguiente:
    2 salió ... veces
    3 salió ... veces
    .
    .
    12 salió ... veces
*/

// Completar

void numAleatorio();

int main()
{
    int CantDeTiros;
    int DadoTirado[CantDeTiros];
    cout << "Ingrese cuántas veces quiere tirar el dado: ";
    cin >> CantDeTiros;

    for (int i = 0; i < CantDeTiros; i++)
    {
        DadoTirado[i] = 1 + rand() % 6; // Genera un valor entre 1 y 6
    }
    for (int j = 0; j < CantDeTiros; j++)
    {
        cout << "- " << DadoTirado[j] << endl;
    }

    return 0;
}

void numAleatorio()
{
}