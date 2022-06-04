#include <iostream>

using namespace std;

// Dados los legajos y sueldos de los empleados de una empresa que,
// como máximo tiene 100  empleados,
// se pide mostrar los legajos de los empleados que tienen el mayor sueldo.
// El ingreso de datos finaliza con legajo cero.
// 2)Los legajos son números no correlativos de 4 dígitos (entre 1000 y 9999)
// Además mostrar legajo y sueldo de cada empleado

int cargarDatos(int vs[], int vl[], int cme);
int mayor(int vs[], int ce);
void mostrar(int vs[], int vl[], int t, int x);
int mayor(int v[], int t, int pos[], int &j);
void mostrar(int vp[], int cvp, int vl[]);

int main()
{
    int sueldos[100], legajos[100], mayorSueldo;
    int cant = cargarDatos(sueldos, legajos, 100);
    if (cant > 0)
    {
        /*
        mayorSueldo=mayor(sueldos,cant);
        cout<<"Legajos con sueldo mayor "<<mayorSueldo<<endl;
        mostrar(sueldos,legajos,cant,mayorSueldo);
        */
        int vecPos[cant], cantPos;
        mayorSueldo = mayor(sueldos, cant, vecPos, cantPos);
        cout << "Legajos con sueldo mayor " << mayorSueldo << endl;
        mostrar(vecPos, cantPos, legajos);
    }
    else
        cout << "No se ingresaron empleados" << endl;
    return 0;
}

int cargarDatos(int vs[], int vl[], int cme)
{
    int leg, i = 0;
    cout << "Legajo (cero fin) ";
    cin >> leg;
    while (leg != 0 && i < cme)
    {
        vl[i] = leg;
        cout << "Sueldo ";
        cin >> vs[i];
        i++;
        cout << "Legajo (cero fin) ";
        cin >> leg;
    }
    return i;
}

int mayor(int vs[], int ce)
{
    int m = vs[0];
    for (int i = 1; i < ce; i++)
    {
        if (vs[i] > m)
            m = vs[i];
    }
    return m;
}
void mostrar(int vs[], int vl[], int t, int x)
{
    for (int i = 0; i < t; i++)
    {
        if (vs[i] == x)
            cout << vl[i] << endl;
    }
}

int mayor(int v[], int t, int pos[], int &j)
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

void mostrar(int vp[], int cvp, int vl[])
{
    int pos;
    for (int i = 0; i < cvp; i++)
    {
        /*
        pos=vp[i];
        cout<<vl[pos]<<endl;
        */
        cout << vl[vp[i]] << endl;
    }
}