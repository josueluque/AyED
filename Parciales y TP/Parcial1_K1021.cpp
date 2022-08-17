#include <iostream>

using namespace std;

// Declaración de struct
struct Repartidor
{
    int dni;
    string nombre;
    int zona;
    int cantEntregas;
};

// Prototipo de funciones
void sumatoriaFilas(int m[][5], int cf, int cc, int v[]);
void ingresarRepartidores(Repartidor v[], int t);
void ingresarPedidos(int m[][5], Repartidor v[], int t);
void punto1(int m[][5], int cf, int cc);
void punto2(int v[], int t);
void punto3(Repartidor vr[], int t);
int ControlDatoIngresado(int desde, int hasta);
int buscar(Repartidor vr[], int t, int bus);
void inicializar(int m[][5], int cf, int cc);

int main()
{
    // Declarar variables
    Repartidor rep[6];
    int cantDiaZona[7][5], totDia[7];
    inicializar(cantDiaZona, 7, 5);
    ingresarRepartidores(rep, 6);         // agregar argumentos
    ingresarPedidos(cantDiaZona, rep, 6); // agregar argumentos
    punto1(cantDiaZona, 7, 5);            // agregar argumentos
    sumatoriaFilas(cantDiaZona, 7, 5, totDia);
    punto2(totDia, 7);
    punto3(rep, 6); // agregar argumentos
    return 0;
}

// Funciones

void ingresarRepartidores(Repartidor v[], int t)
{
    for (int i = 0; i < t; i++)
    {
        cout << "ingrese dni" << endl;
        cin >> v[i].dni;
        cout << "ingrese nombre" << endl;
        cin >> v[i].nombre;
        cout << "ingrese Zona" << endl;
        v[i].zona = ControlDatoIngresado(1, 5);
        v[i].cantEntregas = 0;
    }
}
void ingresarPedidos(int m[][5], Repartidor v[], int t)
{
    int dia, dni, pos;
    cout << "ingrese Dia (1-7)" << endl;
    dia = ControlDatoIngresado(0, 7);
    while (dia != 0)
    {
        cout << "ingrese dni" << endl;
        cin >> dni;
        pos = buscar(v, t, dni);
        if (pos != -1)
        {
            v[pos].cantEntregas++;
            m[dia - 1][v[pos].zona - 1]++;
        }
        cout << "ingrese Dia (1-7)" << endl;
        dia = ControlDatoIngresado(0, 7);
    }
}

void punto1(int m[][5], int cf, int cc)
{
    for (int j = 0; j < cc; j++)
    {
        cout << "Zona " << j + 1 << endl;
        for (int i = 0; i < cf; i++)
            cout << "Dia " << i + 1 << " entregas " << m[i][j] << endl;
    }
}
void punto2(int v[], int t)
{
    int men = v[0], pos = 0;
    for (int i = 1; i < t; i++)
    {
        if (v[i] < men)
        {
            men = v[i];
            pos = i;
        }
    }
    cout << pos + 1;
}
void punto3(Repartidor vr[], int t)
{
    for (int i = 0; i < t; i++)
        cout << vr[i].dni << vr[i].nombre << vr[i].cantEntregas << endl;
}
void sumatoriaFilas(int m[][5], int cf, int cc, int v[])
{
    // int s;
    for (int i = 0; i < cf; i++)
    {
        // s=0;
        v[i] = 0;
        for (int j = 0; j < cc; j++)
            v[i] += m[i][j];
        // v[i]=s;
    }
}
int ControlDatoIngresado(int desde, int hasta)
{
    int dato;
    do
    {
        cin >> dato;
    } while (dato < desde || dato > hasta);
    return dato;
}
int buscar(Repartidor vr[], int t, int bus)
{
    int i = 0;
    while (i < t && vr[i].dni != bus)
        i++;
    if (i == t)
        return -1;
    else
        return i;
}
void inicializar(int m[][5], int cf, int cc)
{
    for (int i = 0; i < cf; i++)
        for (int j = 0; j < cc; j++)
            m[i][j] = 0;
}
