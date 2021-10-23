#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int idTipo;
    char descripcionTipo[20];

}eTipo;

int cargarDescripcionTipo(eTipo listaTipo[],int tamTipo,int idTipo, char descripcionTipo[]);
int validarIdTipo(eTipo listaTipo[], int tamTipo,int idTipo);
int mostrarTipo(eTipo listaTipo[],int tamTipo);


#endif // TIPO_H_INCLUDED
