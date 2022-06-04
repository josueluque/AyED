#include <iostream>

using namespace std;
/*
    3) Desarrollar una función que dados dos números, retorne verdadero si el primero es múltiplo del segundo,
    y falso en caso contrario
*/
int functionMultiplo(int n1, int n2)
{
    if (n2 % n1 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n1, n2;
    bool factorialDeNumero;
    cout << "Ingrese un número" << endl;
    cin >> n1;
    cout << "Ingrese otro número" << endl;
    cin >> n2;
    factorialDeNumero = functionMultiplo(n1, n2);

    if (factorialDeNumero)
    {
        cout << "el número " << n2 << " es multiplo de " << n1 << endl;
    }
    else
    {
        cout << "el número " << n2 << " no es multiplo de " << n1 << endl;
    }
    return 0;
}