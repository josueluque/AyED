#include <iostream>
#include <stdio.h>
#define FIL 8 // CANTIDAD DE NIVELES
#define COL 6 // CANTIDAD DE IDIOMAS

using namespace std;

/*
    APERTURA DE CURSOS PARA EL CICLO LECTIVO DE UN INSTITUTO DE IDIOMAS

    Definición de los cursos que se dictarán en el ciclo lectivo.
    En el instituto se dictan cursos de inglés, francés, portugués, italiano, alemán y chino mandarín.
    Estos cursos pueden ser en 8 niveles de enseñanza diferentes, numerados del 1 al 8 según su
    complejidad.
    Por cada curso que se dictará este cuatrimestre, se ingresa por teclado:
        Código del curso
        Idioma
        Nivel
        Cupo (cantidad máxima de alumnos del curso)
        Nombre y número de documento del docente a cargo
    Puede haber un solo curso por idioma y por nivel. Rechazar el curso si ya existe un curso para ese
    idioma para ese nivel.
    Puede ser que para algún idioma no haya curso en algunos niveles.
    Un mismo docente puede dictar varios cursos.
    La finalización del ingreso de datos de cursos por teclado queda a criterio del grupo.
*/

// Datos del curso
struct Curso
{
    int codigo;
    int idioma; // idioma por opciones
    int nivel;
    int cupo; // Cantidad max de alumnos en el curso
    string nombreDocente;
    int dniDocente;
};

// Prototipo de funciones
void cargarVectorCurso(Curso vc[], int t, bool matCursos[][COL], int cf, int cc);
void inicializar(bool matCurso[][COL], int cf, int cc);
void mostrarPorFila(bool matCursos[][COL], int cf, int cc);
void punto2(bool matCursos[][COL], int cf, int cc);

int main()
{
    Curso vc[48];
    bool matCursos[FIL][COL];

    inicializar(matCursos, FIL, COL);
    cargarVectorCurso(vc, 48, matCursos, FIL, COL);
    mostrarPorFila(matCursos, FIL, COL);
    punto2(matCursos, FIL, COL);

    return 0;
}

void cargarVectorCurso(Curso vc[], int t, bool matCursos[][COL], int cf, int cc)
{
    for (int i = 0; i < cc; i++)
    {
        cout << "ingrese código de curso, cero para finalizar: " << endl;
        cin >> vc[i].codigo;
        if (vc[i].codigo != 0)
        {
            cout << "ingrese el número correspondiente al idioma del curso: " << endl;
            cout << "1) Inglés - 2)Fraces - 3)Portugues - 4)Italiano - 5)Aleman - 6)Chino Mandarin " << endl;
            cin >> vc[i].idioma;
            cout << "ingrese nivel del curso: " << endl;
            cin >> vc[i].nivel;

            if (matCursos[vc[i].nivel - 1][vc[i].idioma - 1] != 1)
            {
                matCursos[vc[i].nivel - 1][vc[i].idioma - 1] = 1;
                cout << "ingrese cupo maximo del curso: " << endl;
                cin >> vc[i].cupo;
                cout << "ingrese nombre del docente a cargo: " << endl;
                cin >> vc[i].nombreDocente;
                cout << "ingrese DNI del docete: " << endl;
                cin >> vc[i].dniDocente;
            }
            else
            {
                cout << "¡CURSO YA EXISTENTE!" << endl;
            }
        }
        else
        {
            i = cc;
        }
    }
}

void mostrarPorFila(bool matCursos[][COL], int cf, int cc)
{
    cout << "Ingles - Frances - Portu - Italiano - Aleman - Chino Mandarin" << endl;
    for (int i = 0; i < cf; i++)
    {
        for (int j = 0; j < cc; j++)
        {
            cout << "   " << matCursos[i][j] << "     ";
        }
        cout << endl;
    }
}

void inicializar(bool matCurso[][COL], int cf, int cc)
{
    for (int i = 0; i < cc; i++)
        for (int j = 0; j < cf; j++)
            matCurso[i][j] = 0;
}

/*
    1) Generar los archivos “Ingles.dat”, “Frances.dat”, “Protugues.dat”, “Italiano.dat”,
    “Aleman.dat” y “Chino.dat” con los datos de los cursos que se dictarán de cada uno de los
    idiomas.
    Cada registro debe tener el siguiente diseño:
        Código del curso
        Nivel
        Cupo
        Nombre y número de documento del docente a cargo
    Estos archivos deben estar ordenados por código de curso.
*/

/*
void punto1()
{
    // Genero Archivos de los idiomas
    char nombreCursoI[20] = "Ingles.dat";     // 1
    char nombreCursoF[20] = "Frances.dat";    // 2
    char nombreCursoP[20] = "Portugues.dat";  // 3
    char nombreCursoIta[20] = "Italiano.dat"; // 4
    char nombreCursoA[20] = "Aleman.dat";     // 5
    char nombreCursoC[20] = "Chino.dat";      // 6
}
*/

/*
    2) Informar por cada idioma la cantidad de cursos que se dictarán.
*/

void punto2(bool matCursos[][COL], int cf, int cc)
{
    string vAux[6] = {"Inglés", "Frances", "Portugues", "Italiano", "Aleman", "Chino Mandarin"};
    for (int i = 0; i < cc; i++)
    {
        int cont = 0;
        for (int j = 0; j < cf; j++)
        {
            if (matCursos[j][i] == 1)
            {
                cont += 1;
            }
        }
        cout << "Se van a dictar ";
        cout << cont;
        cout << " cursos de " + vAux[i] << endl;
    }
}