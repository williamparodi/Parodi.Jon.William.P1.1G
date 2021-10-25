#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED

typedef struct
{
    int idDestino;
    char descripcion[25];
    float precio;

}eDestino;

int cargarDescripcionDestino(eDestino listaDestino[],int tamDestino,int idDestino, char descripcionDestino[],float* precio);
int validarIdDestino(eDestino listaDestino[], int tamDestino,int idDestino);
int mostrarDestino(eDestino listaDestino[],int tamDestino);

#endif // DESTINO_H_INCLUDED
