#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int idTipo;
    char descripcionTipo[20];

}eTipo;

/** \brief carga la descripcion del tipo de viaje considerando el numero de id correspondiente
 *
 * \param listaTipo[] eTipo la lista tipo
 * \param tamTipo int tamaño del array
 * \param idTipo int id del tipo de viaje
 * \param descripcionTipo[] char nombre del tipo de viaje
 * \return int retorna 0 si hay erro o 1 si esta ok
 *
 */
int cargarDescripcionTipo(eTipo listaTipo[],int tamTipo,int idTipo, char descripcionTipo[]);

/** \brief valida que exista el id cargado en la estructura Tipo
 *
 * \param listaTipo[] eTipo lista tipo
 * \param tamTipo int tamaño del array
 * \param idTipo int el id a validar
 * \return int retorna 1 si esta ok o 0 si hay error
 *
 */
int validarIdTipo(eTipo listaTipo[], int tamTipo,int idTipo);


/** \brief muestra la lista de tipos de viaje que hay junto con el id correspondiente
 *
 * \param listaTipo[] eTipo lista de tipo
 * \param tamTipo int tamaño del array
 * \return int retorna 0 si hay error o 1 si esta ok
 *
 */
int mostrarTipo(eTipo listaTipo[],int tamTipo);


#endif // TIPO_H_INCLUDED
