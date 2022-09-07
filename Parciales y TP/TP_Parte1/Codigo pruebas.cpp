#include <iostream>
#include <stdio.h>
#include <string.h>
#define FIL 8 // CANTIDAD DE NIVELES
#define COL 6 // CANTIDAD DE IDIOMAS

using namespace std;

// Datos del curso
struct Curso
{
    int codigo;
    int idioma; // idioma por opciones
    int nivel;
};

struct ArchCurso
{
    int codigo;
    int nivel;
    int cupo;
    char nombreDocente[30];
    int dniDocente;
};

// Prototipo de funciones
int ingDatoLimitado(int desde, int hasta);
void ingresarCursos(FILE *a, ArchCurso curso, Curso vc[], int t, bool matCursos[][COL], int cc);
void inicializar(bool matCurso[][COL], int cf, int cc);
void mostrarPorFila(bool matCursos[][COL], int cf, int cc);

int main()
{
    FILE *archCursos;
    ArchCurso curso;
    Curso vc[48];
    bool matCursos[FIL][COL];

    inicializar(matCursos, FIL, COL);
    ingresarCursos(archCursos, curso, vc, 48, matCursos, COL);
    mostrarPorFila(matCursos, FIL, COL);
    return 0;
}

void ingresarCursos(FILE *a, ArchCurso curso, Curso vc[], int t, bool matCursos[][COL], int cc)
{
    string nom[6] = {"Ingles.dat", "Frances.dat", "Portugues.dat", "Italiano.dat", "Aleman.dat", "ChinoMandarin.dat"};
    for (int j = 0; j < cc; j++)
    {
        char nomA[20];
        strcpy(nomA, nom[j].c_str());
        a = fopen(nomA, "wb");
    }

    int i = 0;
    cout << "Ingrese código de curso, cero para finalizar: " << endl;
    cin >> vc[i].codigo;

    while (vc[i].codigo != 0 && i < t)
    {
        cout << "Ingrese idioma del curso: " << endl;
        cout << "1) Inglés - 2)Frances - 3)Portugues - 4)Italiano - 5)Aleman - 6)Chino Mandarin " << endl;
        vc[i].idioma = ingDatoLimitado(1, 6);

        char nomArch[20];
        strcpy(nomArch, nom[vc[i].idioma - 1].c_str());

        a = fopen(nomArch, "ab");

        if (a == NULL)
            cout << "ERROR" << endl;
        else
        {
            cout << "Ingrese nivel del curso: " << endl;
            vc[i].nivel = ingDatoLimitado(1, 8);
            if (matCursos[vc[i].nivel - 1][vc[i].idioma - 1] != 1) // Para que no se repitan mismos cursos de mismo nivel
            {
                matCursos[vc[i].nivel - 1][vc[i].idioma - 1] = 1;
                curso.codigo = vc[i].codigo;
                curso.nivel = vc[i].nivel;
                cout << "Ingrese cupo maximo del curso: " << endl;
                cin >> curso.cupo;
                cout << "Ingrese nombre del docente a cargo: " << endl;
                cin >> curso.nombreDocente;
                cout << "Ingrese dni del docente a cargo: " << endl;
                cin >> curso.dniDocente;
                fwrite(&curso, sizeof(ArchCurso), 1, a);
            }
            else
            {
                cout << "¡CURSO YA EXISTENTE!" << endl;
            }

            fclose(a);

            i++;
            cout << "Ingrese código de curso, cero para finalizar: " << endl;
            cin >> vc[i].codigo;
        }
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
            matCurso[j][i] = 0;
}
