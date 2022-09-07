#include <iostream>
#include <stdio.h>

#define FIL 8 // CANTIDAD DE NIVELES
#define COL 6 // CANTIDAD DE IDIOMAS

using namespace std;

// Datos del curso
struct Curso
{
    int codigo;
    int idioma; // idioma por opciones
    int nivel;
    int cupo;
    char nombreDocente[30];
    int dniDocente;
};

void punto1(Curso vc, FILE *a);

int main()
{
    FILE *archParcial;
    Curso vc;

    punto1(vc, archParcial);
    return 0;
}

void punto1(Curso vc, FILE *a)
{
    char nomArch[20];
    cout << "Nombre del archivo (con .dat)";
    cin >> nomArch;

    // archParcial=fopen("Parcial1.dat","wb");
    a = fopen(nomArch, "wb");
    if (a == NULL)
        cout << "ERROR" << endl;
    else
    {
        cout << "Ingrese codigo (0 para finalizar) ";
        cin >> vc.codigo;
        while (vc.codigo != 0)
        {
            cout << "Nivel: ";
            cin >> vc.nivel;
            cout << "Cupo: ";
            cin >> vc.cupo;
            cout << "Nombre: ";
            cin >> vc.nombreDocente;
            cout << "Dni del Docente: ";
            cin >> vc.dniDocente;

            fwrite(&vc, sizeof(Curso), 1, a);
            cout << "Ingrese legajo (0 para finalizar) ";
            cin >> vc.codigo;
        }
        fclose(a);
    }
}