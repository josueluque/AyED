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
void ingresarCursos(Curso vc[], int t, bool matCursos[][COL]);
void inicializar(bool matCurso[][COL], int cf, int cc);
void mostrarPorFila(bool matCursos[][COL], int cf, int cc);
int ingDatoLimitado(int desde, int hasta);
void sumatoriaColum(bool matCursos[][COL], int cf, int cc, int vc[]);
void punto2(int vc[], int t);
void punto3(int vc[], int t);

void sumatoriaFilas(bool matCursos[][COL], int cf, int cc, int vf[]);
void punto4(int vf[], int t);

int main()
{
    Curso vc[48];
    bool matCursos[FIL][COL];
    int totalCursoIdioma[COL], totalCursoNivel[FIL];
    inicializar(matCursos, FIL, COL);
    ingresarCursos(vc, 48, matCursos);
    mostrarPorFila(matCursos, FIL, COL);
    sumatoriaColum(matCursos, FIL, COL, totalCursoIdioma);
    cout << "2) Lista de cursos que se dictarán por idioma: " << endl;
    punto2(totalCursoIdioma, COL);

    cout << "3) Cursos en los que se imparten los 8 niveles: " << endl;
    punto3(totalCursoIdioma, COL);

    sumatoriaFilas(matCursos, FIL, COL, totalCursoNivel);
    cout << "4) Niveles en los que no se dictan clases en los 6 idiomas: " << endl;
    punto4(totalCursoNivel, FIL);

    return 0;
}

void ingresarCursos(Curso vc[], int t, bool matCursos[][COL])
{
    int i = 0;
    cout << "Ingrese código de curso, cero para finalizar: " << endl;
    cin >> vc[i].codigo;
    while (vc[i].codigo != 0 && i < t)
    {
        cout << "Ingrese idioma del curso: " << endl;
        cout << "1) Inglés - 2)Fraces - 3)Portugues - 4)Italiano - 5)Aleman - 6)Chino Mandarin " << endl;
        vc[i].idioma = ingDatoLimitado(1, 6);
        cout << "Ingrese nivel del curso: " << endl;
        vc[i].nivel = ingDatoLimitado(1, 8);
        if (matCursos[vc[i].nivel - 1][vc[i].idioma - 1] != 1) // Para que no se repitan mismos cursos de mismo nivel
        {
            matCursos[vc[i].nivel - 1][vc[i].idioma - 1] = 1;
            cout << "Ingrese cupo maximo del curso: " << endl;
            cin >> vc[i].cupo;
            cout << "Ingrese nombre del docente a cargo: " << endl;
            cin >> vc[i].nombreDocente;
            cout << "Ingrese dni del docente a cargo: " << endl;
            cin >> vc[i].dniDocente;
        }
        else
        {
            cout << "¡CURSO YA EXISTENTE!" << endl;
        }
        i++;
        cout << "Ingrese código de curso, cero para finalizar: " << endl;
        cin >> vc[i].codigo;
    }
}

//  2) Informar por cada idioma la cantidad de cursos que se dictarán.

void punto2(int vc[], int t)
{
    string vAux[6] = {"Inglés", "Frances", "Portugues", "Italiano", "Aleman", "Chino Mandarin"};
    for (int i = 0; i < t; i++)
    {
        cout << "   " << vAux[i] << ": " << vc[i] << endl;
    }
}

//  3) Informar, si hay, los idiomas que tienen cursos en los ocho niveles.

void punto3(int vc[], int t)
{
    string vAux[6] = {"Inglés", "Frances", "Portugues", "Italiano", "Aleman", "Chino Mandarin"};
    int cont = 0;
    for (int i = 0; i < t; i++)
    {
        if (vc[i] == 8)
        {
            cout << "   - " + vAux[i] << endl;
        }
        else
            cont++;
    }
    if (cont == t)
    {
        cout << "   - En ninguno de los idiomas se imparten los ocho niveles" << endl;
    }
}

//  4) Informar, si hay, los niveles en los que no se dictará ningún idioma.
void punto4(int vf[], int t)
{
    int cont = 0;
    for (int i = 0; i < t; i++)
    {
        if (vf[i] == 0)
        {
            cout << "   Nivel " << i + 1 << endl;
        }
        else
            cont++;
    }
    if (cont == t)
    {
        cout << "   - No existen los niveles en donde no se dicte ningún idioma" << endl;
    }
}

void sumatoriaFilas(bool matCursos[][COL], int cf, int cc, int vf[])
{
    for (int i = 0; i < cf; i++)
    {
        vf[i] = 0;
        for (int j = 0; j < cc; j++)
            vf[i] += matCursos[i][j];
    }
}

void sumatoriaColum(bool matCursos[][COL], int cf, int cc, int vc[])
{
    for (int j = 0; j < cc; j++)
    {
        vc[j] = 0;
        for (int i = 0; i < cf; i++)
            vc[j] += matCursos[i][j];
    }
}

int ingDatoLimitado(int desde, int hasta)
{
    int dato;
    do
    {
        cin >> dato;
    } while (dato < desde || dato > hasta);
    return dato;
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
