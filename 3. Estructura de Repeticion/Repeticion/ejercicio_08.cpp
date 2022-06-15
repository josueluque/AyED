#include <iostream>

using namespace std;
/*
    8) Dado un número entero positivo entre 1 y 3999 informar su correspondiente número Romano.
*/
int main()
{
    int n;
    cout << "Ingrese un número entero positivo entre 1 y 3999: ";
    cin >> n;

    const string letrasRomanas[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}; // Valores en string de los numeros romanos
    const int valoresRomanos[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};                    // Valores numericos de los numeros romanos (siguiendo el orden de arriba)

    string resultado = "";

    for (int i = 0; i < 13; ++i)
    {
        while (n - valoresRomanos[i] >= 0) // Si el numero ingresado menos el valor romano de la posición "i" es menor a 0
        {
            resultado += letrasRomanas[i]; // Agrego la letra romana al resultado a enviar
            n -= valoresRomanos[i];        // Se reduce la cantidad de numeros a comparar
        }
    }
    cout << "El número " << n << " en romanos es:" << resultado << endl;

    return 0;
}