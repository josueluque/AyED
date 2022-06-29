#include <iostream>
#define FIL 3
#define COL 6

/*
    En la facultad se dictarán 15 cursos extraprogramáticos en el segundo semestre. Todos los cursos duran
    un mes y se dictará una edición por mes, esto quiere decir que se repite todos los meses.
    Primero se ingresarán los cursos, por cada curso se sabe:
        código de curso
        nombre del curso
        cupo para cada edición.
    A continuación se ingresan las inscripciones. Por cada inscripción se ingresa:
        código de curso
        mes en el que quiere realizar el curso (7 a 12)
    El ingreso de datos finaliza con código de curso cero.
    Si no hay cupo para ese curso en ese mes emitir el mensaje "inscripción rechazada por falta de cupo".
    Una vez finalizada la inscripción, el programa debe:
        1. Informar la cantidad de inscriptos por cada curso y por cada mes.
        2. Informar código de curso y cantidad total de inscriptos, ordenado de mayor a menor por
        cantidad total de inscriptos por curso (sin tener en cuenta los meses)
*/

using namespace std;

struct Curso
{
    int codigo;
    string nombre;
    int cupo;
};

struct CursoM
{
    int codigo;
    int cantIns;
};

// Prototipo de funciones
void ingresarCursos(Curso vc[], int cant);
void ingresarInscripciones(Curso vc[], int cant, int m[][COL]);
int buscar(Curso vc[], int c, int x);
// void sumatoriaFila(int m[][COL], int cf, int cc, int vs[]);
void punto1(int m[][COL], int cf, int cc, Curso v[]);
void punto2(Curso vc[], int vi[], int c);

//  No estan esta funciones pero se las llama
// void inicializar(int m[][6], int cf, int cc);
// void ordenar(CursoM v[], int c); // ordena v de temaño c de > a < por cantIns
// void ordenar(int vi[], Curso vc[], int c); // ordena vi de > a < arrastrando vc
//

int main()
{
    Curso vcursos[FIL];
    int matInsc[FIL][COL], inscCurso[FIL];

    ingresarCursos(vcursos, FIL);
    ingresarInscripciones(vcursos, FIL, matInsc);
    // inicializar(matInsc, 15, 6);
    punto1(matInsc, FIL, COL, vcursos);
    // sumatoriaFila(matInsc, FIL, COL, inscCurso);
    punto2(vcursos, inscCurso, FIL);

    return 0;
}

// Funciones

void ingresarCursos(Curso vc[], int cant)
{
    for (int i = 0; i < cant; i++)
    {
        cout << "Ingrese código del curso (" << i << "): " << endl;
        cin >> vc[i].codigo;
        cout << "Nombre del curso (" << i << "): " << endl;
        cin >> vc[i].nombre;
        cout << "Cupos del curso (" << i << "): " << endl;
        cin >> vc[i].cupo;
    }
}

void ingresarInscripciones(Curso vc[], int cant, int m[][COL])
{
    int codCurso, mes, p;
    cout << "-------------" << endl;
    cout << "Inscripciones" << endl;
    cout << "------------- " << endl;
    cout << "Codigo del curso: " << endl;
    cin >> codCurso;

    while (codCurso != 0)
    {
        p = buscar(vc, cant, codCurso);
        if (p != -1)
        {
            cout << "Mes: " << endl;
            do
                cin >> mes;
            while (mes <= 7 || mes >= 12);
            if (m[p][mes - 7] < vc[p].cupo)
            {
                m[p][mes - 7]++;
            }
            else
            {
                cout << "inscripción rechazada por falta de cupo" << endl;
                cout << "Mes: " << endl;
            }
        }

        cout << "Código del curso: " << endl;
        cin >> codCurso;
    }
}
int buscar(Curso vc[], int c, int x)
{
    int i = 0;
    while (i < c && vc[i].codigo != x)
        i++;
    if (i == c)
        return -1;
    else
        return i;
}
/*
void sumatoriaFila(int m[][COL], int cf, int cc, int vs[])
{
    for (int i = 0; i < cf; i++)
    {
        vs[i] = 0;
        for (int j = 0; j < cc; j++)
            vs[i] += m[i][j];
    }
}
*/
void punto1(int m[][COL], int cf, int cc, Curso v[])
{
    for (int i = 0; i < cf; i++)
    {
        cout << v[i].codigo << v[i].nombre << endl;
        for (int j = 0; j < cc; j++)
        {
            cout << "Mes: " << j + 7 << "   Inscriptos " << m[i][j] << endl;
        }
    }
}

void punto2(Curso vc[], int vi[], int c)
{
    CursoM v[c];
    for (int i = 0; i < c; i++)
    {
        v[i].codigo = vc[i].codigo;
        v[i].cantIns = vi[i];
    }
    // ordenar(v, c);
    for (int i = 0; i < c; i++)
    {
        cout << "Código: " << v[i].codigo << "   Cantidad de inscriptos: " << v[i].cantIns << endl;
    }
}

/*
void punto2(Curso vc[], int vi[], int c)
{ // sin CursoM
    ordenar(vi, vc, c);
    for (int i = 0; i < c; i++)
        cout << vc[i].codigo << vi[i] << endl;
}
*/