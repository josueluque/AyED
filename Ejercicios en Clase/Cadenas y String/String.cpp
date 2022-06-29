#include <iostream>

using namespace std;

int main()
{
    string nombre, palabra;
    // cin >> nombre;
    getline(cin, nombre); // puede ingresar con espacios
    cout << nombre << endl;

    palabra = "casa";
    // palabra = nombre;
    if (palabra == "casa")
        cout << "si";
    if (palabra < nombre)
        cout << "si";

    else
        cout << "no";
    return 0;
}
