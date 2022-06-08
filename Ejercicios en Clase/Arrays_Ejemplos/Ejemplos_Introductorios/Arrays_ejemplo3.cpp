#include <iostream>

using namespace std;

// Ingresar como máximo 100 números enteros,
// el ingreso de datos finaliza con un cero que no se procesa.
// Informar cuántos de ellos son mayores al primer número ingresado
// y cuántos mayores al último (no el cero)

void ingresarNros(int v[], int tam, int &i);
int ingresarNros(int v[], int tam);
int cantMayorANro(int v[], int cElem, int x);

int main()
{
    int vNros[100], cn;
    // cn=ingresarNros(vNros,100);
    ingresarNros(vNros, 100, cn);
    int cmp = cantMayorANro(vNros, cn, vNros[0]);
    int cmu = cantMayorANro(vNros, cn, vNros[cn - 1]);

    cout << "Hay " << cmp << " mayores al primero" << endl;
    cout << "Hay " << cmu << " mayores al ultimo" << endl;

    return 0;
}

void ingresarNros(int v[], int tam, int &i)
{
    int num;
    i = 0;
    cout << "Ingrese un numero ";
    cin >> num;
    while (num != 0 && i < tam)
    {
        v[i] = num;
        i++;
        cout << "Ingrese un numero ";
        cin >> num;
    }
}
int ingresarNros(int v[], int tam)
{
    int num;
    int i = 0;
    cout << "Ingrese un numero ";
    cin >> num;
    while (num != 0 && i < tam)
    {
        v[i] = num;
        i++;
        cout << "Ingrese un numero ";
        cin >> num;
    }
    return i;
}
int cantMayorANro(int v[], int cElem, int x)
{
    // devuelve la cantidad de numeros del vector v de tamañan cElem
    // mayores a un número recibido por parámetro (x)
    int c = 0;
    for (int k = 0; k < cElem; k++)
    {
        if (v[k] > x)
            c++;
    }
    return c;
}