#include <iostream>
#include <stdio.h>
#define FIL 6 // CANTIDAD DE IDIOMAS
#define COL 8 // CANTIDAD DE NIVELES

using namespace std;

void ingresarCursos(Curso vc);

// Datos del curso
struct Curso
{
    int codigo;
    string idioma;
    unsigned nivel;
    int cupo; // Cantidad max de alumnos en el curso
    string nombreDocente;
    int dniDocente;
};

int main()
{
    Curso vCursos[];
    int matCursos[FIL][COL];

    ingresarCursos(vCursos);
    return 0;
}

void ingresarCursos(Curso vc)
{
    int i = 0;
    do
    {
        cout >> "ingrese código de curso: " << endl;
        cin << vc.codigo[i];
        cout >> "ingrese idioma del curso: " << endl;
        cin << vc.idioma[i];
        cout >> "ingrese nivel del curso: " << endl;
        cin << vc.nivel[i];
        cout >> "ingrese nombre del docente a cargo: " << endl;
        cin << vc.nombreDocente[i];
        cout >> "ingrese DNI del docete: " << endl;
        cin << vc.dniDocente[i];
        i++;
    } while (vc.codigo[i] > 0)
}

/*
void punto1()
{
    // Genero Archivos de los idiomas
    FILE *archCurso;
    char nombreCursoI[] = "Ingles.dat";     // 1
    char nombreCursoF[] = "Frances.dat";    // 2
    char nombreCursoP[] = "Portugues.dat";  // 3
    char nombreCursoIta[] = "Italiano.dat"; // 4
    char nombreCursoA[] = "Aleman.dat";     // 5
    char nombreCursoC[] = "Chino.dat";      // 6

    for (int i = 0; i < 6; i++)
    {
        if (idioma == arrayAux[i])
        {
            archCurso = fopen(arrayAux[i] + ".dat", "wb");

            cout << "Ingrese codigo (0 para finalizar) ";
            cin >> curso.codigo;
            fclose(archCurso);
        }
        else
        {
            cout << "ERROR" << endl;
        }
    }
}
*/