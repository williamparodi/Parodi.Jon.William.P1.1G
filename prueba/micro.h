#ifndef MICRO_H_INCLUDED
#define MICRO_H_INCLUDED
#include "empresa.h"
#include "tipo.h"

typedef struct
{
    int idMicro;
    int idEmpresa;
    int idTipo;
    int capacidad;
    int isEmpty;

}eMicro;

int inicializarMicro(eMicro listaMicro[],int tamMicro);
int buscarLibre(eMicro listaMicro[], int tamMicro);
int altaMicro(eMicro listaMicro[], int tamMicro,int* pIdMicro,eEmpresa listaEmpresa[], int tamEmpresa,eTipo listaTipo[], int tamTipo);
int modificarMicro(eMicro listaMicro[], int tamMicro,eTipo listaTipo[],int tamTipo);
void mostrarMicro(eMicro unMicro,eTipo listaTipos[],int tamTipo,eEmpresa listaEmpresa[],int tamEmpresa);
int mostrarMicros(eMicro listaMicro[],int tamMicro , eTipo listaTipo[],int tamTipo, eEmpresa listaEmpresa[],int tamEmpresa);

#endif // MICRO_H_INCLUDED
