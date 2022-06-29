#include <iostream>
#define TAM 3 // Definimos cantidad de empleados (Tambien se podria desarrollar una función que pregunte la cantidad que se quiere ingresar)

using namespace std;

struct Empleado
{
    unsigned nroLeg;
    string nombre;
    float sueldo;
};

void cargarVector(Empleado v[], int t);
void ingresarEmple(Empleado &emp);
Empleado ingresarEmple();
void mostrarTodos(Empleado v[], int t);
void mostrar(Empleado e);
float promSueldo(Empleado v[], int t);
void ordenar(Empleado v[], unsigned t);

int main()
{
    Empleado vecEmples[TAM];
    cargarVector(vecEmples, TAM);
    cout << endl
         << "lista de empleados" << endl;
    mostrarTodos(vecEmples, TAM);
    cout << endl
         << "Sueldo promedio " << promSueldo(vecEmples, TAM) << endl;
    ordenar(vecEmples, TAM);
    cout << endl
         << "lista de empleados ordenados por legajo" << endl;
    mostrarTodos(vecEmples, TAM);

    return 0;
}

void mostrar(Empleado e)
{
    cout << "Legajo: " << e.nroLeg << " -   Nombre: " << e.nombre << " -    Sueldo: " << e.sueldo << endl;
}

// También se podrian utilizar para el ingreso de datos de empleados
/*
Empleado ingresarEmple()
{
    Empleado emp;
    cout << "Nro Legajo ";
    cin >> emp.nroLeg;
    cout << "Nombre ";
    cin >> emp.nombre;
    cout << "Sueldo ";
    cin >> emp.sueldo;

    return emp;
}
*/
void ingresarEmple(Empleado &emp)
{
    cout << "Nro Legajo ";
    cin >> emp.nroLeg;
    cout << "Nombre ";
    cin >> emp.nombre;
    cout << "Sueldo ";
    cin >> emp.sueldo;
}

void cargarVector(Empleado v[], int t)
{
    for (int i = 0; i < t; i++)
    {
        // v[i]=ingresarEmple();
        ingresarEmple(v[i]);
    }
}
void mostrarTodos(Empleado v[], int t)
{
    for (int i = 0; i < t; i++)
    {
        mostrar(v[i]);
    }
}
float promSueldo(Empleado v[], int t)
{
    float suma = 0;
    for (int i = 0; i < t; i++)
        suma += v[i].sueldo;
    return suma / t;
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
