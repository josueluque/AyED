#include <iostream>

using namespace std;

struct Alumno
{
    unsigned legajo;
    char nombre[21];
    unsigned nota;
};

int main()
{
    /*
    Alumno alu,al;
    cin>>alu.legajo;
    cin>>alu.nombre;
    cin>>alu.nota;
    al=alu;
    */
    Alumno *pa, *pb;
    pa = new Alumno;
    /*
    cin>>(*pa).legajo;
    cin>>(*pa).nombre;
    cin>>(*pa).nota;
    */
    cin >> pa->legajo;
    cin >> pa->nombre;
    cin >> pa->nota;

    pb = new Alumno;

    return 0;
}
