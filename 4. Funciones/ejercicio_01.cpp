#include <iostream>

using namespace std;
/*
    1) Desarrollar una función que calcule el máximo común divisor de dos números eteros A, B
    con el siguiente algoritmo:
        1. Dividir A por B y calcular el resto (0 < R < B).
        2. Si R = 0, el MCD es B, si no seguir en 3.
        3. Reemplazar A por B, B por R, y volver al paso 1.
*/
int CalcularMCD(int a, int b)
{
    int resto = a % b;
    if (resto == 0)
    {
        return b;
    }
    else
    {
        return CalcularMCD(b, resto);
    }
}

int main()
{
    int num1 = 0;
    int num2 = 0;
    int mcd = 0;
    cout << "ingrese el primer número" << endl;
    cin >> num1;
    cout << "ingrese el segundo número" << endl;
    cin >> num2;

    mcd = CalcularMCD(num1, num2); // Llama a la función y le envia como parametro los números ingresados
    cout << "El máximo común divisor de " << num1 << " y " << num2 << " es: " << mcd << endl;

    return 0;
}
