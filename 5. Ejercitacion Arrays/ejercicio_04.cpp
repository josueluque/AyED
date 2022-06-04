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
