#include <iostream>

using namespace std;

/*
    Dados los legajos y sueldos de los empleados de una empresa que,
    como maximo tiene 100  empleados,
    se pide mostrar los legajos de los empleados que tienen el mayor sueldo.
    El ingreso de datos finaliza con legajo cero.
    2)Los legajos son números no correlativos de 4 digitos (entre 1000 y 9999)
    AGREGADO 1: Mostrar legajo y sueldo de cada empleado ORDENADO POR LEGAJO
    AGREGADO 2: Ingresar un legajo, informar su sueldo
    AGREGADO 3: verificar en la carga que el legajo no haya sido previamente ingresado
*/

int cargarDatos(int vs[], int vl[], int cme);
int mayor(int vs[], int ce);
void mostrar(int vs[], int vl[], int t, int x);
int mayor(int v[], int t, int pos[], int &j);
void mostrar(int vp[], int cvp, int vl[]);
void mostrarTodos(int l[], int s[], int t);
void ordenar(int v[], int s[], int t);
int binaria(int v[], unsigned t, int bus);
int secuencial(int v[], unsigned t, int bus);

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

        // AG1
        ordenar(legajos, sueldos, cant);
        mostrarTodos(legajos, sueldos, cant);

        // AG2
        int legBus;
        cout << "ingrese legajo a buscar ";
        cin >> legBus;
        int pos = binaria(legajos, cant, legBus);
        if (pos == -1)
            cout << "Legajo inexistente" << endl;
        else
            cout << sueldos[pos] << endl;
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
        // AG3
        int p = secuencial(vl, i, leg);
        if (p == -1)
        {
            vl[i] = leg;
            cout << "Sueldo ";
            cin >> vs[i];
            i++;
        }
        else
            cout << "Ese legajo ya fue cargado" << endl;
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

void mostrarTodos(int l[], int s[], int t)
{
    for (int i = 0; i < t; i++)
    {
        cout << "Legajo: " << l[i] << " Sueldo: " << s[i] << endl;
    }
}

void ordenar(int v[], int s[], int t)
{
    unsigned i = 1, j;
    int aux;
    bool cambio;
    do
    {
        cambio = false;
        for (j = 0; j < t - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;

                aux = s[j];
                s[j] = s[j + 1];
                s[j + 1] = aux;

                cambio = true;
            }
        }
        i++;
    } while (i < t && cambio);
}

int binaria(int v[], unsigned t, int bus)
{
    int desde = 0, hasta = t - 1, medio;
    do
    {
        medio = (desde + hasta) / 2;

        if (bus < v[medio])
            hasta = medio - 1;
        else
            desde = medio + 1;

    } while (desde <= hasta && v[medio] != bus);
    if (v[medio] == bus)
        return medio;
    else
        return -1;
}
int secuencial(int v[], unsigned t, int bus)
{
    unsigned i = 0;
    while (i < t && v[i] != bus)
        i++;
    if (i == t)
        return -1;
    else
        return i;
}
