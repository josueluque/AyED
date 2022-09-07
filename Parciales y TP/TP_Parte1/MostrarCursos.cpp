#include <iostream>
#include <stdio.h>

using namespace std;

struct ArchCurso
{
    int codigo;
    int nivel;
    int cupo;
    char nombreDocente[30];
    int dniDocente;
};

int main()
{
    ArchCurso sc;
    char nomArch[30];
    cout << "Nombre del archivo (con .dat)";
    cin >> nomArch;

    FILE *archivo = fopen(nomArch, "rb");
    if (archivo == NULL)
        cout << "ERROR" << endl;
    else
    {

        fread(&sc, sizeof(ArchCurso), 1, archivo);
        while (!feof(archivo))
        {
            cout << "Código del curso: " << sc.codigo << endl;
            cout << "Nivel: " << sc.nivel << endl;
            cout << "Cupos:" << sc.cupo << endl;
            cout << "Nombre del docente: " << sc.nombreDocente << endl;
            cout << "Dni del docente: " << sc.dniDocente << endl;
            fread(&sc, sizeof(ArchCurso), 1, archivo);
        }
        fclose(archivo);
    }

    return 0;
}
