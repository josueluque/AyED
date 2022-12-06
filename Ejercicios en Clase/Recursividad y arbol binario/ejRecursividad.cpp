#include <iostream>

using namespace std;

unsigned factorial(unsigned n);

int main()
{
    int nro;
    cin >> nro;
    cout << factorial(nro) << endl;
    return 0;
}

unsigned factorial(unsigned n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}