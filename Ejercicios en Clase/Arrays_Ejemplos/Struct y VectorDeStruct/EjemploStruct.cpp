#include <iostream>

using namespace std;

struct Fecha
{
    unsigned dia, mes, anio;
    /*
    unsigned dia;
    unsigned mes;
    unsigned anio;
    */
};
struct Empleado
{
    int legajo;
    string nombre;
    int sueldo;
    Fecha fechaIng;
};

void mostrar(Empleado e);
Empleado ingresarEmple();
void ingresarEmple(Empleado &emple);
float sueldoNeto(int sueldoBasico);
int antiguedad(Fecha fecha);

int main()
{
    Empleado empleado;
    // empleado=ingresarEmple();
    ingresarEmple(empleado);
    mostrar(empleado);
    cout << "Antiguedad " << antiguedad(empleado.fechaIng) << endl;

    return 0;
}

void mostrar(Empleado e)
{
    cout << e.legajo << e.nombre << sueldoNeto(e.sueldo) << endl;
}

Empleado ingresarEmple()
{
    Empleado emple;
    cin >> emple.legajo;
    cin >> emple.nombre;
    cin >> emple.sueldo;
    return emple;
}

void ingresarEmple(Empleado &emple)
{
    cin >> emple.legajo;
    cin >> emple.nombre;
    cin >> emple.sueldo;
}

float sueldoNeto(int sueldoBasico)
{
    return sueldoBasico * 0.85;
}

int antiguedad(Fecha fecha)
{
    Fecha hoy;
    //...
    int a = hoy.anio - fecha.anio;
    if (hoy.mes < fecha.mes)
        a--;
    else if (hoy.mes == fecha.mes && hoy.dia < fecha.dia)
        a--;
    return a;
}
