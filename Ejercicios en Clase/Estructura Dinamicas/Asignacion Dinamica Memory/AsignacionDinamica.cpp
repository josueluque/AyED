#include <iostream>

using namespace std;

int main()
{
    /*
    int a;
    a=5;
    int*p;
    p=&a;
    cout<<p<<endl;
    cout<<*p<<endl;
    *p=8;
    cout<<a<<endl;
    */
    int *p, *q;
    /*
    int*p;
    int*q;
    */
    p = new int;
    *p = 5;
    cout << p << endl;
    cout << *p << endl;
    /*
    delete p;
    p=NULL;
    cout<<p<<endl;
    */
    // q=p;
    q = new int;
    if (p == q)
        cout << "es el mismo espacio de memoria" << endl;
    else
        cout << "distinto espacio de memoria" << endl;
    *q = 5;
    if (*p == *q)
        cout << "igual" << endl;
    else
        cout << "distintos" << endl;

    return 0;
}
