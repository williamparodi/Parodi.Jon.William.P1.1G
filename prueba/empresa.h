#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED

 typedef struct
 {
     int idEmpresa;
     char descripcion[20];

 }eEmpresa;

 /** \brief muestra las empresas junto con su nombre y id
  *
  * \param listaEmpresa[] eEmpresa la estrutura empresa
  * \param tamEmpresa int El tamaño del array
  * \return int retorna 0 si hay error o 1 si esta ok
  *
  */
 int mostrarEmpresas(eEmpresa listaEmpresa[],int tamEmpresa);

 /** \brief valida que exista id de la empresa
  *
  * \param listaEmpresa[] eEmpresa la estrutura empresa
  * \param tamEmpresa int  El tamaño del array
  * \param idEmpresa int el id correspondiente a las empresas
  * \return int retorna 0 si hay error o 1 si esta ok
  *
  */
 int validarIdEmpresa(eEmpresa listaEmpresa[], int tamEmpresa,int idEmpresa);


 /** \brief carga la decripcion de la empresa segun el id correspondiente
  *
  * \param listaEmpresa[] eEmpresa la estrutura empresa
  * \param tamEmpresa int El tamaño del array
  * \param idEmpresa int el id correspondiente a las empresas
  * \param descripcion[] char nombre de la empresa
  * \return int int retorna 0 si hay error o 1 si esta ok
  *
  */
 int cargarDescripcionEmpresa(eEmpresa listaEmpresa[],int tamEmpresa,int idEmpresa, char descripcion[]);


#endif // EMPRESA_H_INCLUDED
