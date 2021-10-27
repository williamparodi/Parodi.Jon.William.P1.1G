#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empresa.h"

int cargarDescripcionEmpresa(eEmpresa listaEmpresa[],int tamEmpresa,int idEmpresa, char descripcion[])
{
    int todoOk = 0;
    int flag = 1;
    if(listaEmpresa != NULL && tamEmpresa >0)
    {
        todoOk = 1;

        for(int i = 0;i<tamEmpresa;i++)
        {
            if(listaEmpresa[i].idEmpresa == idEmpresa)
            {
                strcpy(descripcion,listaEmpresa[i].descripcion);
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            todoOk = -1;
        }
    }

    return todoOk;
}

int validarIdEmpresa(eEmpresa listaEmpresa[], int tamEmpresa,int idEmpresa)
{
    int todoOk = 0;

    if (listaEmpresa != NULL && tamEmpresa > 0)
    {
        for (int i = 0; i < tamEmpresa; i++)
        {
            if (idEmpresa == listaEmpresa[i].idEmpresa)
            {
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int mostrarEmpresas(eEmpresa listaEmpresa[],int tamEmpresa)
{
    int todoOk = 0;

    if(listaEmpresa != NULL && tamEmpresa >0)
    {
        todoOk = 1;

        printf("-------------------------------\n");
        printf(" ***Lista de empresas***       \n");
        printf(" ID        Nombre              \n");
        printf("-------------------------------\n");

        for(int i = 0; i < tamEmpresa;i++)
        {
            printf(" %d      %s       \n",listaEmpresa[i].idEmpresa,listaEmpresa[i].descripcion);
        }


    }

    return todoOk;
}

