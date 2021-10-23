#ifndef BIBLIOPROPIA_H_INCLUDED
#define BIBLIOPROPIA_H_INCLUDED

/** \brief Despliega un menu
 *
 * \return chr Retorna un caracter con la opcion deseada
 *
 */
char menu();

/** \brief Permite escribir un mensaje y pedir un numero decimal
 *
 * \param mensaje[] char Mensaje a mostrar por pantalla
 * \return float Retorna el numero decimal ingresado.
 *
 */
float ingresarFloat(char mensaje[]);

/** \brief Permite escribir un mensaje y pedir un numero entero
 *
 * \param mensaje[] char Mensaje a mostrar por pantalla.
 * \return int Retona el numero entero ingresado.
 *
 */
int ingresarInt(char mensaje[]);

/** \brief Permite escribir un mensaje y pedir una cadena de carateres
 *
 * \param mensaje[] char Mensaje a mostrar por pantalla.
 * \param dato[] char La cadena de caracteres a recibir.
 * \return int Retrona 0 si hubo un error o 1 si se ejecuto con exito.
 *
 */
int ingresarString(char mensaje[], char info[]);

/** \brief pasa a mayuscula la primera letra de un string y detecta espacios
 *
 * \param string[] char el mensaje ingresado
 * \return int devuelve 0 en caso de error, 1 si se ejecuto con exito.
 *
 */
int pasarMayusculaPrimerCaracter(char string[]);

int validarInt(int numero,int min,int max);

float validarFloat(float numero,int min,int max);

#endif // BIBLIOPROPIA_H_INCLUDED
