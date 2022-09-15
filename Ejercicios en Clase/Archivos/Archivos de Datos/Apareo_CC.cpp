#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

struct Parcial
{
    unsigned dni;
    char nom[21];
    unsigned nota;
};

string condicion(unsigned n1,unsigned n2);
void apareo(FILE*ap1,FILE*ap2);
void corteControl(FILE*a);
void ccArchivo(FILE*a,FILE*ap);

int main()
{

    FILE *p1=fopen("Parcial1.dat","rb");
    FILE *p2=fopen("Parcial2.dat","rb");
    cout<<endl<<"Apareo"<<endl;
    apareo(p1,p2);
    fclose(p1);
    fclose(p2);


    FILE *ex=fopen("Examenes.dat","rb");
    cout<<endl<<"Corte de control"<<endl;
    corteControl(ex);
    fclose(ex);

    ex=fopen("Examenes.dat","rb");
    FILE *exProm=fopen("ExPromedio.dat","wb");
    ccArchivo(ex,exProm);
    fclose(ex);
    fclose(exProm);

    return 0;
}

string condicion(unsigned n1,unsigned n2)
{
    if(n1>7&&n2>7)
        return " Prom";
    else
    {
        if(n1>5&&n2>5)
            return " Final";
        else
            return " Recursa";
    }
}

void apareo(FILE*a1,FILE*a2)
{
    Parcial p1,p2;
    fread(&p1,sizeof(Parcial),1,a1);
    fread(&p2,sizeof(Parcial),1,a2);
    while(!feof(a1)&&!feof(a2))
    {
        if(p1.dni<p2.dni)
        {
            cout<<p1.dni<<" "<<p1.nom<<condicion(p1.nota,0)<<endl;
            fread(&p1,sizeof(Parcial),1,a1);
        }
        else
        {
            if(p1.dni==p2.dni)
            {
                cout<<p1.dni<<" "<<p1.nom<<condicion(p1.nota,p2.nota)<<endl;
                fread(&p1,sizeof(Parcial),1,a1);
                fread(&p2,sizeof(Parcial),1,a2);
            }
            else
            {
                cout<<p2.dni<<" "<<p2.nom<<condicion(0,p2.nota)<<endl;
                fread(&p2,sizeof(Parcial),1,a2);
            }
        }
    }
    while(!feof(a1))
    {
        cout<<p1.dni<<" "<<p1.nom<<condicion(p1.nota,0)<<endl;
        fread(&p1,sizeof(Parcial),1,a1);
    }
    while(!feof(a2))
    {
        cout<<p2.dni<<" "<<p2.nom<<condicion(0,p2.nota)<<endl;
        fread(&p2,sizeof(Parcial),1,a2);
    }
}

void corteControl(FILE*a)
{
    Parcial ex;
    int dniA,s,c;
    fread(&ex,sizeof(Parcial),1,a);
    while(!feof(a))
    {
        dniA=ex.dni;
        s=c=0;
        do
        {
            s+=ex.nota;
            c++;
            fread(&ex,sizeof(Parcial),1,a);
        }while(!feof(a)&&ex.dni==dniA);
        cout<<dniA<<" "<<s/c<<endl;
    }
}
void ccArchivo(FILE*a,FILE*ap)
{
    Parcial ex,exp;
    int s,c;
    fread(&ex,sizeof(Parcial),1,a);
    while(!feof(a))
    {
        exp.dni=ex.dni;
        strcpy(exp.nom,ex.nom);
        s=c=0;
        do
        {
            s+=ex.nota;
            c++;
            fread(&ex,sizeof(Parcial),1,a);
        }while(!feof(a)&&ex.dni==exp.dni);

        exp.nota=s/c;
        fwrite(&exp,sizeof(Parcial),1,ap);
    }

}






