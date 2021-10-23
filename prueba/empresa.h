#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED

 typedef struct
 {
     int idEmpresa;
     char descripcion[20];

 }eEmpresa;

 int mostrarEmpresas(eEmpresa listaEmpresa[],int tamEmpresa);
 int validarIdEmpresa(eEmpresa listaEmpresa[], int tamEmpresa,int idEmpresa);
 int cargarDescripcionEmpresa(eEmpresa listaEmpresa[],int tamEmpresa,int idEmpresa, char descripcion[]);


#endif // EMPRESA_H_INCLUDED
