#include <iostream>

using namespace std;

int sumar(int, int);
void sumar(int, int, int &);

int main()
{
    int num1, num2, suma;
    cout << "nro1 ";
    cin >> num1;
    cout << "nro2 ";
    cin >> num2;
    // suma=sumar(nro1,nro2);
    sumar(num1, num2, suma);
    cout << "Suma " << suma;
    // cout<<"Suma "<<sumar(num1,num2);
    return 0;
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
void sumar(int a, int b, int &s)
{
    s = a + b;
}
