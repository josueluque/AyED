#include <iostream>
#define TAM 5 // Aca Designamos la cantidad de notas que se van a ingresar

using namespace std;
/*
    4) Desarrollar un programa que permita:
        - Cargar un vector de 50 valores enteros
        - Mostrar por pantalla el contenido del vector
        - Obtener el mayor valor entero contenido en el vector y su posición en el mismo
        - Obtener el menor valor entero contenido en el vector y su posición en el mismo.
    Analizar y describir los cambios necesarios para resolver el mismo problema considerando a lo
    sumo 50 valores enteros.
*/
int ingresarNumeros(int v[], int ce);
void mostrarValores(int v[], int ce);
void calcularMayor(int v[], int ce);
void calcularMenor(int v[], int ce);

int main()
{
    int valoresEnt[TAM];
    ingresarNumeros(valoresEnt, TAM);
    mostrarValores(valoresEnt, TAM);
    calcularMayor(valoresEnt, TAM);
    calcularMenor(valoresEnt, TAM);

    return 0;
}

int ingresarNumeros(int v[], int ce)
{
    for (int i = 0; i < ce; i++)
    {
        cout << "Ingrese un número (vamos por el (" << i + 1 << ")) :";
        cin >> v[i];
    }
    cout << " " << endl;
}

void mostrarValores(int v[], int ce)
{
    cout << "Valores ingresados" << endl;
    for (int j = 0; j < ce; j++)
    {
        cout << v[j] << " ";
    }
}

void calcularMayor(int v[], int ce)
{
    int nmayor;
    int nMayorPos;
    for (int j = 0; j < ce; j++)
    {
        if (j == 0)
        {
            nmayor = v[j];
            nMayorPos = j + 1;
        }
        if (v[j] > nmayor)
        {
            nmayor = v[j];
            nMayorPos = j + 1;
        }
    }
    cout << "Mayor valor: " << nmayor << "    se encuentra en la posicón: " << nMayorPos << endl;
}

void calcularMenor(int v[], int ce)
{
    int nmenor;
    int nMenorsPos;
    for (int j = 0; j < ce; j++)
    {
        if (j == 0)
        {
            nmenor = v[j];
            nMenorsPos = j + 1;
        }
        if (v[j] < nmenor)
        {
            nmenor = v[j];
            nMenorsPos = j + 1;
        }
    }
    cout << "Menor valor: " << nmenor << "    se encuetra en la posición: " << nMenorsPos << endl;
}
