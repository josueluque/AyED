#include <iostream>

using namespace std;
/*
    OBTENCION DEL MAXIMO
*/
int mayor1(int v[], int t, int &pos);
int mayor2(int v[], int t, int pos[], int &j);
void mostrar(int v[], int t);

int main()
{
    int v[] = {20, 40, 10, 90, 100, 60, 70, 30, 50, 80};
    int vr[] = {30, 40, 30, 40, 40, 50, 40, 20, 50, 20};
    int posicion, m = mayor1(v, 10, posicion);
    cout << "mayor: " << m << " en la posicion " << posicion << endl;

    int vecPos[10], tamVecPos;
    m = mayor2(vr, 10, vecPos, tamVecPos);
    cout << "mayor: " << m << " en las posiciones ";
    mostrar(vecPos, tamVecPos);
    cout << endl;

    return 0;
}
int mayor1(int v[], int t, int &pos)
{
    int may = v[0];
    pos = 0;
    for (int i = 1; i < t; i++)
    {
        if (v[i] > may)
        {
            may = v[i];
            pos = i;
        }
    }
    return may;
}

int mayor2(int v[], int t, int pos[], int &j)
{
    int may;
    for (int i = 0; i < t; i++)
    {
        if (i == 0 || v[i] > may)
        {
            may = v[i];
            j = 0;
            pos[j] = i;
            j++;
        }
        else
        {
            if (v[i] == may)
            {
                pos[j] = i;
                j++;
            }
        }
    }
    return may;
}

void mostrar(int v[], int t)
{
    for (int i = 0; i < t; i++)
        cout << v[i] << "  ";
}