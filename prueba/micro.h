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

/** \brief pone todos los campos en 1 para indicar q estan vaciosen la estructura micro
 *
 * \param listaMicro[] eMicro la estructura micro
 * \param tamMicro int tamaño del array
 * \return int retorna 0 en caso de error o 1 si esta ok
 *
 */
int inicializarMicro(eMicro listaMicro[],int tamMicro);

/** \brief busca un espacio libre en los campos isEmpty
 *
 * \param listaMicro[] eMicro la estructura micro
 * \param tamMicro int tamaño del array
 * \return int retorna el indice en -1 en caso de error o el indice en el caso de que no este cargado
 *
 */
int buscarLibre(eMicro listaMicro[], int tamMicro);


/** \brief se le piden al usuario datos y se agregaan a la lista de micros en la primera posicion libre
 *
 * \param listaMicro[] eMicro  la estructura micro
 * \param tamMicro int tamaño del array
 * \param pIdMicro int* la direccion de memoria del id de micro para ir incrementandola
 * \param listaEmpresa[] eEmpresa la estructura empresa
 * \param tamEmpresa int tamalo del array
 * \param listaTipo[] eTipo lista de tipo de viaje
 * \param tamTipo int tamaño del array
 * \return int retorna 0 en caso de error o 1 si esta ok
 *
 */
int altaMicro(eMicro listaMicro[], int tamMicro,int* pIdMicro,eEmpresa listaEmpresa[], int tamEmpresa,eTipo listaTipo[], int tamTipo);


/** \brief muestra los micros con todos los datos cargados
 *
 * \param listaMicro[] eMicro la estructura micro
 * \param tamMicro int tamaño del array
 * \param listaTipo[] eTipo lista de tipo de viaje
 * \param tamTipo int tamaño del array
 * \param listaEmpresa[] eEmpresa la estructura empresa
 * \param tamEmpresa int tamaño del array
 * \return int retorna 0 en caso de error o 1 si esta ok
 *
 */
int mostrarMicros(eMicro listaMicro[],int tamMicro , eTipo listaTipo[],int tamTipo, eEmpresa listaEmpresa[],int tamEmpresa);

/** \brief muestra un micro con sus paramaetros y descripciones
 *
 * \param unMicro eMicro un micro
 * \param listaTipos[] eTipo lista de tipo de viaje
 * \param tamTipo int tamaño del array
 * \param listaEmpresa[] eEmpresa la estructura empresa
 * \param tamEmpresa int tamaño del array
 * \return void
 *
 */
void mostrarMicro(eMicro unMicro,eTipo listaTipos[],int tamTipo,eEmpresa listaEmpresa[],int tamEmpresa);

/** \brief modifica dos campos de la lista micro, tipo o empresa
 *
 * \param listaMicro[] eMicro la estructura micro
 * \param tamMicro int tamaño del array
 * \param listaTipo[] eTipo lista de tipo de viaje
 * \param tamTipo int  tamaño del array
 * \param listaEmpresa[] eEmpresa la estructura empresa
 * \param tamEmpresa int  tamaño del array
 * \return int retorna 0 en caso de error o 1 si esta ok
 *
 */
int modificarMicro(eMicro listaMicro[], int tamMicro,eTipo listaTipo[],int tamTipo,eEmpresa listaEmpresa[],int tamEmpresa);

/** \brief da de baja un micro pidiendo el id de este y deja el campo isEmpty en vacio
 *
 * \param listaMicro[] eMicro la estructura micro
 * \param tamMicro int tamaño del array
 * \param listaTipo[] eTipo lista de tipo de viaje
 * \param tamTipo int tamaño del array
 * \param listaEmpresa[] eEmpresa la estructura empresa
 * \param tamEmpresa int
 * \return int retorna 0 en caso de error o 1 si esta ok
 *
 */
int bajaMicro(eMicro listaMicro[],int tamMicro,eTipo listaTipo[],int tamTipo,eEmpresa listaEmpresa[],int tamEmpresa);

/** \brief valida que el id cargado en la lsita micro exista
 *
 * \param listaMicro[] eMicro la estructura micro
 * \param tamMicro int tamaño del array
 * \param idMicro int el id a validar
 * \return int retorna le indice si esta ok o -1 si no lo encuentra o hay error
 *
 */
int validarIdMicro(eMicro listaMicro[], int tamMicro,int idMicro);


/** \brief Ordena los parametros cargados en la lista micros y los muestra en el orden deseado ascendente o descendente
    los ordena segun la descripcion de la empresa y si son la misma considera la capacidad
 *
 * \param listaMicro[] eMicro la estructura micro
 * \param tamMicro int tamaño del array
 * \param listaEmpresa[] eEmpresa la estructura empresa
 * \param tamEmpresa int tamaño del array
 * \return int retorna 0 en caso de error o 1 si esta ok
 *
 */
int ordenarMicros(eMicro listaMicro[],int tamMicro,eEmpresa listaEmpresa[],int tamEmpresa);

#endif // MICRO_H_INCLUDED
