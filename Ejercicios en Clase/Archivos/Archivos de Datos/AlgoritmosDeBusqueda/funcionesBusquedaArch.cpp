
// FUNCIONES DE BUSQUEDA ARCHIVOS

/*
int busquedaSecuencial(FILE *archivo,int bus,Producto &prod)
{
    int i=0;
    fread(&prod,sizeof(Producto),1,archivo);
    while(!feof(archivo)&&prod.codigo!=bus)
    {
        i++;
        fread(&prod,sizeof(Producto),1,archivo);
    }

    if(feof(archivo))
        return -1;
    else
        return i;
}
*/

/*
int cantRegistros(FILE *archivo)
{
    fseek(archivo,0,SEEK_END);
    return ftell(archivo)/sizeof(Producto);
}
*/

/*
int busquedaBinaria(FILE *archivo,int bus,Producto &prod)
{
    int desde,hasta,medio,pos=-1;
    desde=0;
    hasta=cantRegistros(archivo)-1;
    while(desde<=hasta && pos==-1)
    {
        medio=(desde+hasta)/2;
        fseek(archivo,medio*sizeof(Producto),SEEK_SET);
        fread(&prod,sizeof(Producto),1,archivo);
        if(prod.codigo==bus)
            pos=medio;
        else
        {
            if(bus<prod.codigo)
                hasta=medio-1;
            else
                desde=medio+1;
        }
    }
    return pos;
}
*/