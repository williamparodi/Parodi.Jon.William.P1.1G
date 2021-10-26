#ifndef VIAJES_H_INCLUDED
#define VIAJES_H_INCLUDED
#include "fecha.h"

typedef struct
{
    int idViaje;
    int idMicro;
    int idDestino;
    int fechaMes;
    int fechaDia;
    int fechaAnio;
    int isEmpty;

}eViaje;

int inicializarViaje(eViaje listaViaje[],int tamViaje);
int buscarLibreViaje(eViaje listaViaje[], int tamViaje);
int buscarViajePorId(eViaje listaViaje[], int tamViaje,int idViaje);
int altaViaje(eViaje listaViaje[], int tamViaje,int* pIdViaje,eMicro listaMicro[], int tamMicro,eDestino listaDestino[], int tamDestino,eTipo listaTipo[],int tamTipo,eEmpresa listaEmpresa[],int tamEmpresa,eFecha listaFecha[],int tamFecha);
void mostrarViaje(eViaje unViaje,eDestino listaDestino[],int tamDestino,eMicro unMicro,eEmpresa listaEmpresa[],int tamEmpresa,eTipo listaTipo[],int tamTipo,eFecha listaFecha[],int tamFecha);
int mostrarViajes(eViaje listaViaje[],int tamViaje , eMicro listaMicro[],int tamMicro,eDestino listaDestino[],int tamDestino,eEmpresa listaEmpresa[],int tamEmpresa,eTipo listaTipo[],int tamTipo,eFecha listaFecha[],int tamFecha);
#endif // VIAJES_H_INCLUDED
