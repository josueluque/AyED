#include <iostream>

using namespace std;
/*
    Dados los legajos y sueldos de los empleados de una empresa que, como máximo tiene 100  empleados,
    se pide mostrar los legajos de los empleados que tienen el mayor sueldo.
    - El ingreso de datos finaliza con legajo cero.
    - Los legajos son números entre 1 y 100
*/

void cargarDatos(int v[]);
int ingresarVal(int d, int h);
void inicializar(int v[], int n);
int mayor(int vs[], int ce);
void mostrar(int v[], int c, int x);
int mayor(int v[], int t, int pos[], int &j);
void mostrar(int vp[], int cvp);

int main()
{
    int sueldos[100], mayorSueldo;
    inicializar(sueldos, 100);
    cargarDatos(sueldos);
    /*
    mayorSueldo=mayor(sueldos,100);

    if(mayorSueldo>0)
    {
        cout<<"Legajos con sueldo mayor "<<mayorSueldo<<endl;
        mostrar(sueldos,100,mayorSueldo);
    }
    else
        cout<<"No se ingresaron empleados"<<endl;
    */
    int vecPos[100], cantPos = 0; // para mayor con vector de posiciones
    mayorSueldo = mayor(sueldos, 100, vecPos, cantPos);
    if (cantPos > 0)
    {
        cout << "Legajos con sueldo mayor " << mayorSueldo << endl;
        mostrar(vecPos, cantPos);
    }
    else
        cout << "No se ingresaron empleados" << endl;
    return 0;
}

void cargarDatos(int v[])
{
    int leg, suel;
    cout << "Legajo (cero para terminar) ";
    leg = ingresarVal(0, 100);
    while (leg != 0)
    {
        cout << "Sueldo ";
        // cin>>suel;
        // v[leg-1]=suel;
        cin >> v[leg - 1];
        cout << "Legajo (cero para terminar) ";
        leg = ingresarVal(0, 100);
    }
}

int ingresarVal(int d, int h)
{
    int dato;
    do
        cin >> dato;
    while (dato < d || dato > h);
    return dato;
}

void inicializar(int v[], int n)
{
    for (int i = 0; i < n; i++)
        v[i] = 0;
}
/*
int mayor(int vs[],int ce)
{
    int m=vs[0];
    for(int i=1;i<ce;i++)
    {
        if(vs[i]>m)
            m=vs[i];
    }
    return m;
}
*/

int mayor(int vs[], int ce)
{
    bool pri = true;
    int m;
    for (int i = 0; i < ce; i++)
    {
        if (vs[i] != 0)
        {
            if (pri)
            {
                m = vs[i];
                pri = false;
            }
            else
            {
                if (vs[i] > m)
                    m = vs[i];
            }
        }
    }
    if (pri)
        return 0;
    else
        return m;
}

void mostrar(int v[], int c, int x)
{
    for (int i = 0; i < c; i++)
    {
        if (v[i] == x)
            cout << i + 1 << endl;
    }
}
int mayor(int v[], int t, int pos[], int &j)
{
    int may;
    bool pri = true;
    for (int i = 0; i < t; i++)
    {
        if (v[i] != 0)
        {
            if (pri || v[i] > may)
            {
                may = v[i];
                j = 0;
                pos[j] = i;
                j++;
                pri = false;
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
    }
    return may;
}
void mostrar(int vp[], int cvp)
{
    int pos;
    for (int i = 0; i < cvp; i++)
    {
        cout << vp[i] + 1 << endl;
    }
}