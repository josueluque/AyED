#include <iostream>

using namespace std;

// Ingresar 5 números  enteros e
// informar cuántos de ellos son mayores a su promedio
void ingresarNumeros(int[], int);
int calcularPromedio(int vec[], int t);
int sumatoria(int vn[], int c);
int cantMayorANro(int v[], int cElem, int x);

int main()
{
    int nros[5], prom, cantM;
    ingresarNumeros(nros, 5);
    prom = calcularPromedio(nros, 5);
    cantM = cantMayorANro(nros, 5, prom);

    cout << "Hay " << cantM << " numeros mayores al promedio " << prom << endl;

    return 0;
}

void ingresarNumeros(int v[], int ce)
{
    for (int i = 0; i < ce; i++)
    {
        cout << "Ingrese el numero de orden " << i + 1 << endl;
        cin >> v[i];
    }
}

int calcularPromedio(int vec[], int t)
{
    return sumatoria(vec, t) / t;
}

int sumatoria(int vn[], int c)
{
    int s = 0;
    for (int j = 0; j < c; j++)
        s += vn[j];
    return s;
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