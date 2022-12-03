#include <iostream>
#include <stdio.h>

#define m 3 // Filas
#define n 3 // Columnas

using namespace std;

// Prototipo de funciones
void ingresarPorFila(int mat[][n], int fil, int col);
void inicializar(int mat[][n], int fil, int col);
void mostrarPorColum(int mat[][n], int fil, int col);
int ingDatoLimitado(int desde, int hasta);

int main()
{
    int mat[m][n];
    inicializar(mat, m, n);
    ingresarPorFila(mat, m, n);
    mostrarPorColum(mat, m, n);

    return 0;
}

void ingresarPorFila(int mat[][n], int fil, int col)
{
    for (int i = 0; i < fil; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int valor;
            cout << "Ingresar valor " << endl;
            valor = ingDatoLimitado(0, 9);
            if (valor != 0)
            {

                mat[i][j] = valor;
            }
            else
            {
                j++;
            }
        }
    }
}

int sumatoria(int mat[][n], int fil, int col)
{
    int s = 0;
    for (int i = 0; i < fil; i++)
    {
        for (int j = 0; j < col; j++)
        {
            s += mat[i][j];
        }
    }
    return s;
}

int ingDatoLimitado(int desde, int hasta)
{
    int dato;
    do
    {
        cin >> dato;
    } while (dato < desde || dato > hasta);
    return dato;
}

void mostrarPorColum(int mat[][n], int fil, int col)
{
    for (int i = 0; i < fil; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j)
            {
                cout << "   " << mat[i][j] << "   ";
            }
            else
            {
                cout << "   "
                     << "0"
                     << "   ";
            }
        }
        cout << endl;
    }
}

void inicializar(int mat[][n], int fil, int col)
{
    for (int i = 0; i < fil; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mat[i][j] = 0;
        }
    }
}
