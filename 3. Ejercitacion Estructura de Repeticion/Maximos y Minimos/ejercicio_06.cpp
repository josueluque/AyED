#include <iostream>

using namespace std;
/*
    6) Dado un conjunto de Nombres y Fechas de nacimientos (AAAAMMDD), que finaliza con un
    Nombre = ‘FIN’, informar el nombre de la persona con mayor edad y el de la más joven.
*/
// Juan 20000310
// Ana  19991220
// Luis 20000110
// FIN

int main()
{
    unsigned fechaNac, menor, mayor;
    bool pri = true;
    string nombre, viejo, joven;
    cout << "Nombre, FIN para finalizar" << endl;
    cin >> nombre;
    while (nombre != "FIN")
    {
        cout << "Fecha nacimiento (AAAAMMDD)" << endl;
        cin >> fechaNac;

        if (pri)
        {
            menor = fechaNac;
            mayor = fechaNac;
            viejo = nombre;
            joven = nombre;
            pri = false;
        }
        else
        {
            if (fechaNac > mayor)
            {
                mayor = fechaNac;
                joven = nombre;
            }
            else
            {
                if (fechaNac < menor)
                {
                    menor = fechaNac;
                    viejo = nombre;
                }
            }
        }

        cout << "Nombre, FIN para finalizar" << endl;
        cin >> nombre;
    }
    if (pri)
        cout << "no hubo ingreso" << endl;
    else
    {
        cout << "La persona mas vieja es " << viejo << endl;
        cout << "La persona mas joven es " << joven << endl;
    }
}