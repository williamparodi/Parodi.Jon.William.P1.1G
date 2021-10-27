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


/** \brief Pone todos los campos en 1 para indicar q estan vacios en la lista isEmpty viaje
 *
 * \param listaViaje[] eViaje lista viaje
 * \param tamViaje int tamaño del array
 * \return int retorna 0 en caso de error o 1 si esta ok
 *
 */
int inicializarViaje(eViaje listaViaje[],int tamViaje);


/** \brief busca el primer espacio vacio en la lista viaje
 *
 * \param listaViaje[] eViaje lista viaje
 * \param tamViaje int tamaño del array
 * \return int devuelve el inidice en caso de encontrar lugar o -1 en caso de error o no encontrar lugar
 *
 */
int buscarLibreViaje(eViaje listaViaje[], int tamViaje);

/** \brief busca que por id que exista cargado en la lista viaje
 *
 * \param listaViaje[] eViaje lista viaje
 * \param tamViaje int tamaño del array
 * \param idViaje int id el cual se busca q exista
 * \return int retorna el indice cargado en de encontarlo  o -1 si no hay nada.
 *
 */
int buscarViajePorId(eViaje listaViaje[], int tamViaje,int idViaje);

/** \brief Se piden el id de micro al usuario y datos para dar de alta en la lista de viajes y se pone el campo de isEmpty en 0 indicando que se cargo.
 *
 * \param listaViaje[] eViaje lista viaje
 * \param tamViaje int tamaño del array
 * \param pIdViaje int* puntero de id de viaje a incrementar
 * \param listaMicro[] eMicro
 * \param tamMicro int tamaño del array
 * \param listaDestino[] eDestino
 * \param tamDestino int tamaño del array
 * \param listaTipo[] eTipo
 * \param tamTipo int tamaño del array
 * \param listaEmpresa[] eEmpresa
 * \param tamEmpresa int tamaño del array
 * \param listaFecha[] eFecha
 * \param tamFecha int tamaño del array
 * \return int retorna 0 en caso de error o 1 si esta ok
 *
 */
int altaViaje(eViaje listaViaje[], int tamViaje,int* pIdViaje,eMicro listaMicro[], int tamMicro,eDestino listaDestino[], int tamDestino,eTipo listaTipo[],int tamTipo,eEmpresa listaEmpresa[],int tamEmpresa,eFecha listaFecha[],int tamFecha);

/** \brief se muestran los datos de un viaje con todos sus campos y se cargan las descripciones
 *
 * \param unViaje eViaje lista viaje
 * \param listaDestino[] eDestino lsita destino
 * \param tamDestino int tamaño del array
 * \param unMicro eMicro datos de un micro
 * \param listaEmpresa[] eEmpresa lista empresa
 * \param tamEmpresa int tamaño del array
 * \param listaTipo[] eTipo lista tipo
 * \param tamTipo int tamaño del array
 * \param listaFecha[] eFecha lista fecha
 * \param tamFecha int tamaño del array
 * \return void
 *
 */
void mostrarViaje(eViaje unViaje,eDestino listaDestino[],int tamDestino,eMicro listaMicro[],int tamMicro,eEmpresa listaEmpresa[],int tamEmpresa,eTipo listaTipo[],int tamTipo,eFecha listaFecha[],int tamFecha);


/** \brief se muetra una lista entera con todos los datos cargado por el usuario
 *
 * \param listaViaje[] eViaje lista viaje
 * \param tamViaje int tamaño del array
 * \param listaMicro[] eMicro lista micro
 * \param tamMicro int tamaño del array
 * \param listaDestino[] eDestino lista destino
 * \param tamDestino int tamaño del array
 * \param listaEmpresa[] eEmpresa lista empresa
 * \param tamEmpresa int tamaño del array
 * \param listaTipo[] eTipo lista tipo
 * \param tamTipo int tamaño del array
 * \param listaFecha[] eFecha lista fecha
 * \param tamFecha int tamaño del array
 * \return int  retona 0 en caso de error o 1 si esta ok
 *
 */
int mostrarViajes(eViaje listaViaje[],int tamViaje , eMicro listaMicro[],int tamMicro,eDestino listaDestino[],int tamDestino,eEmpresa listaEmpresa[],int tamEmpresa,eTipo listaTipo[],int tamTipo,eFecha listaFecha[],int tamFecha);
#endif // VIAJES_H_INCLUDED
