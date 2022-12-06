#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

// DECLARACION DE STRUCTS
struct Curso
{
    int cod;
    int nivel;
    int cupo;
    char nombre[30];
    int dni;
};

struct Estudiante
{
    int dni;
    char nom[30];
};

struct NodoSub
{
    Estudiante info;
    NodoSub *sig;
};

struct CodCurso
{
    int cod;
    int cupoDisponible;
    int cupoOcupado;
    char pro[30];
    int dniPro;
    NodoSub *Est;
};

struct NodoC
{
    CodCurso info;
    NodoC *sig;
};

struct Cola
{
    Estudiante info;
    int cod;
    Cola *sig;
};

struct InfoAr
{
    char nom[30];
    int dni;
    int cantA;
};
struct nodoAr
{
    InfoAr info;
    nodoAr *izq;
    nodoAr *der;
};

// PROTOTIPOS
NodoC *buscarInsertar(NodoC *&lista, int cod);
bool buscarArch(int codigo, CodCurso &dato);
void asignar(Curso cur, CodCurso &dato);
int busqueda(FILE *arch, int codigo, Curso &cur);
void insertarSub(NodoSub *&lista, Estudiante dato);
void ColaDeEspera(Cola *&cola, Estudiante est, int codigo);

NodoC *buscarCurso(NodoC *lista, int cod);
NodoSub *buscarDNI(NodoSub *lista, int dni, NodoSub *&ant);
void eliminarAlumno(NodoC *&curso, NodoSub *&p, NodoSub *&ant, Cola *&cola, int cod);
Cola *buscarCola(Cola *cola, int cod);

void mostrarCola(Cola *cola);
void buscarInsertarA(NodoC *&lista, nodoAr *&raiz);
void generarArchivos(NodoC *lista);
void ListarIn(nodoAr *raiz);

int main()
{
    // MENU
    int opcion;
    Cola *cola = NULL;
    nodoAr *ArbolProf = NULL;
    NodoC *lista = NULL;

    cout << "1-Inscripcion de estudiantes" << endl
         << "2-Baja de estudiantes" << endl
         << "3-Mostrar lista de estudiantes" << endl
         << "4-Salir" << endl;
    cin >> opcion;
    while (opcion != 4)
    {
        switch (opcion)
        {
        // INSCRIPCION
        case 1:
        {
            Estudiante est;
            int codigo;
            Curso cur;
            NodoC *p;

            cout << "Ingrese el nombre del estudiante" << endl;
            cin >> est.nom;
            cout << "Ingrese el dni" << endl;
            cin >> est.dni;

            cout << "Ingrese el codigo del curso en el que desea inscribirse" << endl;
            cin >> codigo;

            p = buscarInsertar(lista, codigo);
            if (p != NULL)
            {
                if (p->info.cupoDisponible > 0)
                {
                    p->info.cupoDisponible -= 1;
                    p->info.cupoOcupado += 1;
                    insertarSub(p->info.Est, est);
                }
                else
                {
                    ColaDeEspera(cola, est, codigo);
                    cout << "El curso no tiene cupos disponibles, ha sido agregado a la cola de espera" << endl;
                }
            }
            else
                cout << "El curso ingresado no existe" << endl;
            break;
        }

        // DAR DE BAJA
        case 2:
        {
            int dniBuscar, codBuscar;
            NodoSub *dniEnc, *anterior;
            NodoC *codEnc;

            cout << "Ingrese el dni del estudiante" << endl;
            cin >> dniBuscar;
            cout << "Ingrese el codigo" << endl;
            cin >> codBuscar;

            codEnc = buscarCurso(lista, codBuscar);

            if (codEnc != NULL)
            {
                dniEnc = buscarDNI(codEnc->info.Est, dniBuscar, anterior);
                if (dniEnc != NULL)
                {
                    eliminarAlumno(codEnc, dniEnc, anterior, cola, codBuscar);
                }
                else
                    cout << "El dni ingresado no existe" << endl;
            }
            else
                cout << "El curso ingresado no existe";
            break;
        }

        // MOSTRAR
        case 3:
        {
            NodoC *p = lista;
            NodoSub *v;
            while (p != NULL)
            {
                cout << "Curso: " << p->info.cod << endl;
                cout << "Cantidad Vacantes Ocupadas: " << p->info.cupoOcupado << endl;
                cout << "Cantidad de Vacante Disponibles: " << p->info.cupoDisponible << endl;
                v = p->info.Est;
                while (v != NULL)
                {
                    cout << v->info.dni << "   " << v->info.nom << endl;
                    v = v->sig;
                }
                p = p->sig;
            }
            break;
        }
        default:
            cout << "La opcion ingresada no es valida, intentelo nuevamente" << endl;
        }
        cout << "-------------------------------------------------------------------------" << endl;
        cout << "1-Inscripcion de estudiantes" << endl
             << "2-Baja de estudiantes" << endl
             << "3-Mostrar lista de estudiantes" << endl
             << "4-Salir" << endl;
        cin >> opcion;
    }
    // SALIR
    mostrarCola(cola);
    buscarInsertarA(lista, ArbolProf);
    ListarIn(ArbolProf);
    generarArchivos(lista);

    return 0;
}

// FUNCIONES

NodoC *buscarInsertar(NodoC *&lista, int cod)
{
    NodoC *p, *ant;
    p = lista;
    while (p != NULL && p->info.cod < cod)
    {
        ant = p;
        p = p->sig;
    }
    if (p == NULL || p->info.cod != cod)
    {
        NodoC *n = new NodoC;
        CodCurso dato;
        bool b;
        b = buscarArch(cod, dato);
        if (b == true)
        {
            n->sig = p;
            n->info = dato;
            if (p != lista)
                ant->sig = n;
            else
                lista = n;
            return n;
        }
        else
            return NULL;
    }
    else
        return p;
}

bool buscarArch(int codigo, CodCurso &dato)
{
    string nom[6] = {"Ingles.dat", "Frances.dat", "Portugues.dat", "Italiano.dat", "Aleman.dat", "Chino.dat"};
    FILE *archCursos;
    int k = 0;
    int pos = -1;
    Curso cur;
    bool encontrado;

    while (k < 6 && pos == -1)
    {
        char nomArch[30];
        strcpy(nomArch, nom[k].c_str());
        archCursos = fopen(nomArch, "rb");
        if (archCursos != NULL)
        {
            pos = busqueda(archCursos, codigo, cur);
        }
        k++;
    }
    if (pos == -1)
        encontrado = false;
    else
    {
        encontrado = true;
        asignar(cur, dato);
    }
    return encontrado;
}

void asignar(Curso cur, CodCurso &dato)
{
    dato.cod = cur.cod;
    dato.cupoDisponible = cur.cupo;
    dato.cupoOcupado = 0;
    strcpy(dato.pro, cur.nombre);
    dato.dniPro = cur.dni;
    dato.Est = NULL;
}

int busqueda(FILE *arch, int codigo, Curso &cur)
{
    int i = 0;
    fread(&cur, sizeof(Curso), 1, arch);
    while (!feof(arch) && cur.cod != codigo)
    {
        i++;
        fread(&cur, sizeof(Curso), 1, arch);
    }

    if (feof(arch))
        return (-1);
    else
        return i;
}

void insertarSub(NodoSub *&lista, Estudiante dato)
{
    NodoSub *n, *p, *ant;
    n = new NodoSub;
    n->info = dato;
    p = lista;
    while (p != NULL && p->info.dni > dato.dni)
    {
        ant = p;
        p = p->sig;
    }
    n->sig = p;
    if (p != lista)
        ant->sig = n;
    else
        lista = n;
}

void ColaDeEspera(Cola *&cola, Estudiante est, int codigo)
{
    Cola *n = new Cola;
    n->info = est;
    n->cod = codigo;
    n->sig = NULL;
    Cola *p = cola;

    if (p == NULL)
        cola = n;
    else
    {
        while (p->sig != NULL)
            p = p->sig;
        p->sig = n;
    }
}

NodoC *buscarCurso(NodoC *lista, int cod)
{
    NodoC *p;
    p = lista;
    while (p != NULL && p->info.cod < cod)
        p = p->sig;
    if (p == NULL || p->info.cod != cod)
        return NULL;
    else
        return p;
}

NodoSub *buscarDNI(NodoSub *lista, int dni, NodoSub *&ant)
{
    NodoSub *p;
    p = lista;
    ant = NULL;
    while (p != NULL && p->info.dni < dni)
    {
        ant = p;
        p = p->sig;
    }
    if (p == NULL || p->info.dni != dni)
        return NULL;
    else
        return p;
}

void eliminarAlumno(NodoC *&curso, NodoSub *&p, NodoSub *&ant, Cola *&cola, int cod)
{
    Cola *n;
    n = buscarCola(cola, cod);
    if (n != NULL)
    {
        ant->sig = p->sig;
        delete p;
        insertarSub(curso->info.Est, n->info);
    }
    else
    {
        curso->info.cupoDisponible += 1;
        curso->info.cupoOcupado -= 1;
        ant->sig = p->sig;
        delete p;
    }
}

Cola *buscarCola(Cola *cola, int cod)
{
    Cola *p = cola;
    while (p != NULL && p->cod != cod)
        p = p->sig;
    if (p->cod == cod)
        return p;
    else
        return NULL;
}

void mostrarCola(Cola *cola)
{
    cout << "Estudiantes sin vacante:" << endl;
    Cola *r = cola;
    while (r != NULL)
    {
        cout << r->info.dni << "   " << r->info.nom << endl;
        r = r->sig;
    }
    if (r == cola)
        cout << "No hay estudiantes sin vacante" << endl;
}

void buscarInsertarA(NodoC *&lista, nodoAr *&raiz)
{
    NodoC *p = lista;
    while (p != NULL)
    {
        nodoAr *r = raiz, *ant;

        while (r != NULL && r->info.dni != p->info.dniPro)
        {
            ant = r;
            if (p->info.dniPro < r->info.dni)
                r = r->izq;
            else
                r = r->der;
        }
        if (r->info.dni == p->info.dniPro)
            r->info.cantA += p->info.cupoOcupado;
        else
        {
            r = new nodoAr;
            r->info.dni = p->info.dniPro;
            r->info.cantA = p->info.cupoOcupado;
            strcpy(r->info.nom, p->info.pro);
            r->der = r->izq = NULL;

            if (raiz == NULL)
                raiz = r;
            else
            {
                if (p->info.dniPro < ant->info.dni)
                    ant->izq = r;
                else
                    ant->der = r;
            }
        }
        p = p->sig;
    }
}

void generarArchivos(NodoC *lista)
{
    NodoC *cur = lista;
    while (cur != NULL)
    {
        string nom = to_string(cur->info.cod);
        nom = nom + ".dat";

        char nomArch[30];
        strcpy(nomArch, nom.c_str());

        FILE *arch = fopen(nomArch, "wb");
        NodoSub *rc = cur->info.Est;
        while (rc != NULL)
        {
            Estudiante v;
            v.dni = rc->info.dni;
            strcpy(v.nom, rc->info.nom);
            fwrite(&v, sizeof(Estudiante), 1, arch);
            // fwrite(&rc.info,sizeof(Estudiante),1,arch);
            rc = rc->sig;
        }
        fclose(arch);
        cur = cur->sig;
    }
}

void ListarIn(nodoAr *raiz)
{
    if (raiz != NULL)
    {
        ListarIn(raiz->izq);
        cout << raiz->info.nom << "   " << raiz->info.dni << "    " << raiz->info.cantA << endl;
        ListarIn(raiz->der);
    }
}
