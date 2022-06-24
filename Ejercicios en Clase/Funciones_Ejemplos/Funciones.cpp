#include <iostream>

using namespace std;

// Escribir un programa que ingrese el nombre y dos notas de un estudiante
//  y calcule y muestre su nombre y su promedio

void mostrarMensaje(string, int);
void mostrarMensaje(string);
void mostrarMensaje(string, float);
int sumar(int, int);
float promedio(int, int);
int ingresarEnteroEntre(int desde, int hasta);

int main()
{
    string nombre;
    int nota1, nota2;
    float prom;
    mostrarMensaje("Ingrese nombre");
    cin >> nombre;
    mostrarMensaje("Ingrese nota ", 1);
    nota1 = ingresarEnteroEntre(1, 10);
    mostrarMensaje("Ingrese nota ", 2);
    nota2 = ingresarEnteroEntre(1, 10);

    prom = promedio(nota1, nota2);
    mostrarMensaje("Promedio :", prom);

    return 0;
}

void mostrarMensaje(string msj)
{
    cout << msj << endl;
}
void mostrarMensaje(string msj, int x)
{
    cout << msj << x << endl;
}
void mostrarMensaje(string msj, float result)
{
    cout << msj << result << endl;
}

float promedio(int n1, int n2)
{
    /*
    //int sum=sumar(n1,n2);
    //float p=(float)sum/2;
    float p=(float)sumar(n1,n2)/2;
    return p;
    */
    return (float)sumar(n1, n2) / 2;
}

int sumar(int a, int b)
{
    /*
    int s;
    s=a+b;
    return s;
    */
    return a + b;
}
int ingresarEnteroEntre(int desde, int hasta)
{
    int n;
    do
        cin >> n;
    while (n < desde || n > hasta);
    return n;
}
