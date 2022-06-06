#include <iostream>

using namespace std;
/*
    5) Desarrollar una función que dados n y m devuelva el combinatorio de m tomados de a n.
    Usar función punto 2
    Combinación: m!/n!(m-n)!
*/
int combinatorio(int m, int n);
int factorial(int n);

int combinatorio(int m, int n)
{
    return factorial(m) / factorial(n) * factorial(m - n);
}

int factorial(int n)
{
    int f = 1;
    for (int i = 1; i <= n; i++)
        f *= i;
    return f;
}

int main()
{
    int m, n;
    cout << "ingrese un número" << endl;
    cin >> m;
    cout << "ingrese otro número" << endl;
    cin >> n;
    cout << "El combinatorio de " << m << " tomados de a " << n << " es: " << combinatorio(m, n) << endl;
    return 0;
}
