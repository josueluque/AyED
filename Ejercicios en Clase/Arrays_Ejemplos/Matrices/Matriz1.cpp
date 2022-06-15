#include <iostream>

using namespace std;

void cargarPorColumna(int m[][6], int cf, int cc);
void mostrarPorFila(int m[][6], int cf, int cc);
void sumatoriaFilas(int m[][6], int cf, int cc, int v[]);
void sumatoriaColumnas(int m[][6], int cf, int cc, int v[]);
void mostrarVector(int v[], int t);
void inicializar(int v[], int t);

int main()
{
    int matriz[4][6], sumaFila[4], sumaCol[6];
    inicializar(sumaFila, 4);
    inicializar(sumaCol, 6);
    cargarPorColumna(matriz, 4, 6);
    mostrarPorFila(matriz, 4, 6);
    sumatoriaFilas(matriz, 4, 6, sumaFila);
    sumatoriaColumnas(matriz, 4, 6, sumaCol);
    cout << "sumatoria de las filas " << endl;
    mostrarVector(sumaFila, 4);
    cout << "sumatoria de las columnas " << endl;
    mostrarVector(sumaCol, 6);

    return 0;
}
void cargarPorColumna(int m[][6], int cf, int cc)
{
    for (int c = 0; c < cc; c++)
        for (int f = 0; f < cf; f++)
        {
            cout << "fila " << f << " columna " << c << endl;
            cin >> m[f][c];
        }
}

void sumatoriaFilas(int m[][6], int cf, int cc, int vf[])
{
    // int s;
    for (int i = 0; i < cf; i++)
    {
        // s=0;
        // vf[i]=0;
        for (int j = 0; j < cc; j++)
        {
            // s+=m[i][j];
            vf[i] += m[i][j];
        }
        // vf[i]=s;
    }
}
void sumatoriaColumnas(int m[][6], int cf, int cc, int vc[])
{

    for (int j = 0; j < cc; j++)
        for (int i = 0; i < cf; i++)
            vc[j] += m[i][j];

    for (int i = 0; i < cc; i++)
        for (int j = 0; j < cf; j++)
            vc[i] += m[j][i];

    /*
    for(int i=0;i<cf;i++)
        for(int j=0;j<cc;j++)
            vc[j]+=m[i][j];
    */
}

void mostrarPorFila(int m[][6], int cf, int cc)
{
    for (int i = 0; i < cf; i++)
    {
        for (int j = 0; j < cc; j++)
            cout << m[i][j] << "   ";
        cout << endl;
    }
}

void mostrarVector(int v[], int t)
{
    for (int i = 0; i < t; i++)
        cout << v[i] << endl;
}
void inicializar(int v[], int t)
{
    for (int i = 0; i < t; i++)
        v[i] = 0;
}
