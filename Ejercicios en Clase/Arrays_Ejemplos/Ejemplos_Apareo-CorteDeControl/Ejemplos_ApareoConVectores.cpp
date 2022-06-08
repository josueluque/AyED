#include <iostream>

using namespace std;

/*
    Ingresa los empleados que trabajaron en la sucursal 1 (como max 10)
    y los que trabajaron en la 2 (como max 10) en el día de ayer
    Mostrar todos los empleados que trabajaron ayer ordenados
*/

struct Empleado
{
    unsigned nroLeg;
    string nombre;
};

Empleado ingresarEmple();
void ingresarEmpleados(Empleado v[], int ce);
void mostrar(Empleado v[], int t);
void ordenar(Empleado v[], unsigned t);
void apareo(Empleado vs1[], unsigned t1, Empleado vs2[], unsigned t2);

int main()
{
    int c1, c2;
    cout << "Cantidad empleados suc 1 ";
    cin >> c1;
    cout << "Cantidad empleados suc 2 ";
    cin >> c2;
    Empleado vecEmpleS1[c1], vecEmpleS2[c2];
    ingresarEmpleados(vecEmpleS1, c1);
    // ordenar(vecEmpleS1,c1);
    cout << "Empleados Suc1" << endl;
    mostrar(vecEmpleS1, c1);
    ingresarEmpleados(vecEmpleS2, c2);
    // ordenar(vecEmpleS2,c2);
    cout << "Empleados Suc2" << endl;
    mostrar(vecEmpleS2, c2);
    cout << "Empleados" << endl;
    apareo(vecEmpleS1, c1, vecEmpleS2, c2);
    return 0;
}

Empleado ingresarEmple()
{
    Empleado emple;
    cout << "Ingresar nro de Legajo ";
    cin >> emple.nroLeg;
    cout << "Ingresar nombre ";
    cin >> emple.nombre;

    return emple;
}

void ingresarEmpleados(Empleado v[], int ce)
{
    for (int i = 0; i < ce; i++)
        v[i] = ingresarEmple();
}

void ordenar(Empleado v[], unsigned t)
{
    unsigned i = 1, j;
    Empleado aux;
    bool cambio;
    do
    {
        cambio = false;
        for (j = 0; j < t - i; j++)
        {
            if (v[j].nroLeg > v[j + 1].nroLeg)
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                cambio = true;
            }
        }
        i++;
    } while (i < t && cambio);
}
void mostrar(Empleado v[], int t)
{
    for (int i = 0; i < t; i++)
        cout << v[i].nroLeg << "-" << v[i].nombre << endl;
}

void apareo(Empleado vs1[], unsigned t1, Empleado vs2[], unsigned t2)
{
    // ambos vectores tienen que estar ordenados
    unsigned i = 0, j = 0;
    while (i < t1 && j < t2)
    {
        if (vs1[i].nroLeg < vs2[j].nroLeg)
        {
            cout << vs1[i].nroLeg << "-" << vs1[i].nombre << endl;
            i++;
        }
        else
        {
            if (vs1[i].nroLeg == vs2[j].nroLeg)
            {
                cout << vs1[i].nroLeg << "-" << vs1[i].nombre << endl;
                // cout<<vs2[j].nroLeg<<"-"<<vs2[j].nomApe<<endl;
                i++;
                j++;
            }
            else
            {
                cout << vs2[j].nroLeg << "-" << vs2[j].nombre << endl;
                j++;
            }
        }
    }
    for (int k = i; k < t1; k++)
        cout << vs1[k].nroLeg << "-" << vs1[k].nombre << endl;
    for (int k = j; k < t2; k++)
        cout << vs2[k].nroLeg << "-" << vs2[k].nombre << endl;
}