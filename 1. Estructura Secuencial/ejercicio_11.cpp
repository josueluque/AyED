#include <iostream>

using namespace std;
/*
    11.En una empresa vendedora de alambres se quiere calcular el precio de un pedido. Para ello
    se ingresa los metros pedidos. El precio del alambre es de 10,50 Pesos por metro.
*/
int main()
{
    int metros, precio;
    float precioPorMetro = 10.50;
    cout << "Ingrese los metros de alambre pedidos: ";
    cin >> metros;

    precio = metros * precioPorMetro;
    cout << "El precio del pedido es de $" << precio << " pesos." << endl;
    return 0;
}