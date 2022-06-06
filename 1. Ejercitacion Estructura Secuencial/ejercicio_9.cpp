#include <iostream>

using namespace std;
/*
    9. Determinar el porcentaje de alumnos aprobados, desaprobados y ausentes que hubo en un
    examen, conociendo las cantidades de cada uno.
*/
int main()
{
    int aprobados, desaprobados, ausentes, totalDeAlumnos, porcentajeAprobados, porcentajeDesaprobados, porcentajeAusentes;
    cout << "Cuantos alumnos aprobaron? ";
    cin >> aprobados;
    cout << "Cuantos alumnos desaprobaron?: ";
    cin >> desaprobados;
    cout << "Cuantos alumnos estuvieron ausentes?: ";
    cin >> ausentes;

    totalDeAlumnos = aprobados + desaprobados + ausentes;
    porcentajeAprobados = (aprobados * 100) / totalDeAlumnos;
    porcentajeDesaprobados = (desaprobados * 100) / totalDeAlumnos;
    porcentajeAusentes = (ausentes * 100) / totalDeAlumnos;

    cout << "El porcentaje de alumnos aprobados son el " << porcentajeAprobados << "%" << endl;
    cout << "El porcentaje de alumnos desaprobados son el " << porcentajeDesaprobados << "%" << endl;
    cout << "El porcentaje de alumnos ausentes son el " << porcentajeAusentes << "%" << endl;
    return 0;
}