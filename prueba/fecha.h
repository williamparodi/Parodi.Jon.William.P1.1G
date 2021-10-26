#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

/** \brief valida la fecha correcta, recibe tres valores y pone como maximo el año 2050
 *
 * \param mes int
 * \param anio int
 * \param dia int
 * \return int Retorna 1 si esta Ok o 0 si hay hay error
 *
 */
int validarFecha(int mes,int anio,int dia);
#endif // FECHA_H_INCLUDED
