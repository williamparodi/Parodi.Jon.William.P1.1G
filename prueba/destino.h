#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED

typedef struct
{
    int idDestino;
    char descripcion[25];
    float precio;

}eDestino;

/** \brief carga la descripcion del destino comarandola con el id correspondiente y el precio
 *
 * \param listaDestino[] eDestino la estrutura destino
 * \param tamDestino int El tamaño del array.
 * \param idDestino int el id del destino
 * \param descripcionDestino[] char el nombre del destino
 * \param precio float* la direccion de memoria del precio
 * \return int retorna 0 si hay error o  1 si esta ok
 *
 */
int cargarDescripcionDestino(eDestino listaDestino[],int tamDestino,int idDestino, char descripcionDestino[],float* precio);

/** \brief valida que exista el id de destino cargado
 *
 * \param listaDestino[] eDestino la estructura destino
 * \param tamDestino el tamaño del array
 * \return retorna 0 en caso de error o 1 si esta ok
 *
 */
int validarIdDestino(eDestino listaDestino[], int tamDestino,int idDestino);


/** \brief muestra la lista de destinos con su id correspondiente, descripcion y precio
 *
 * \param listaDestino[] eDestino
 * \param tamDestino int el tamaño del array
 * \return int retorna 0 en caso de error o 1 si esta ok
 *
 */
int mostrarDestino(eDestino listaDestino[],int tamDestino);

#endif // DESTINO_H_INCLUDED
