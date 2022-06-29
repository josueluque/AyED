#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char nombre[15], palabra[15];
    char nom[5] = "pepe";
    // cin >> nombre;
    cin.getline(nombre, 15); // Permite ingresar ingresar vector de char con espacios

    cout << nombre << endl;

    // palabra=nom; // MAL
    strcpy(palabra, nom);
    cout << palabra << endl;
    // palabra = "casa"; // MAL
    // strcpy(palabra,"casa");
    // cout << palabra<<endl;
    /*
        if(palabra == nom)  // NO COMPARA LAS CADENAS
            cout << "=" << endl;
         else
            cout << "No =" << endl;
    */

    if (strcmp(palabra, nom) == 0)
        cout << "=" << endl; // iGUALES
    else
        cout << "No =" << endl; // NO IGUALES

    cout << strcmpi("Ala", "ala") << endl;

    cout << strlen(nom) << endl;
    strcat(nombre, " Perez");
    cout << nombre << endl;
    cout << strlen(nombre) << endl;

    return 0;
}
