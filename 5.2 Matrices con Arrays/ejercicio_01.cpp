#include <iostream>
#include <stdio.h>

#define m 3 // Filas
#define n 5 // Columnas

using namespace std;

// Prototipo de funciones
void ingresarPorFila(int mat[][n], int fil, int col);
void inicializar(int mat[][n], int fil, int col);
void mostrarPorColum(int mat[][n], int fil, int col);
int ingDatoLimitado(int desde, int hasta);
int sumatoria(int mat[][n], int fil, int col);
void valorPromedio(int mat[][n], int fil, int col);
void maximoValor(int mat[][n], int fil, int col);

int main()
{
    int mat[m][n];
    inicializar(mat, m, n);
    ingresarPorFila(mat, m, n);
    mostrarPorColum(mat, m, n);
    valorPromedio(mat, m, n);
    maximoValor(mat, m, n);

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

void maximoValor(int mat[][n], int fil, int col)
{
    for (int i = 0; i < fil; i++)
    {
        int s = 0;
        int vMayor = mat[i][0];
        for (int j = 1; j < col; j++)
        {
            if (mat[i][j] > vMayor)
            {
                vMayor = mat[i][j];
            }
        }
        cout << "El mayor de la fila " << i + 1 << " es: " << vMayor << endl;
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

void valorPromedio(int mat[][n], int fil, int col)
{
    cout << "Valor promedio:" << endl;
    cout << sumatoria(mat, fil, col) / (fil * col);
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
            cout << "   " << mat[i][j] << "   ";
        }
        cout << endl;
    }
}

void inicializar(int mat[][n], int fil, int col)
{
    for (int j = 0; j < col; j++)
    {
        for (int i = 0; i < fil; i++)
        {
            mat[i][j] = 0;
        }
    }
}
