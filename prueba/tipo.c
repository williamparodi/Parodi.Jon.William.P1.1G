#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"

int cargarDescripcionTipo(eTipo listaTipo[],int tamTipo,int idTipo, char descripcionTipo[])
{
    int todoOk = 0;

    if(listaTipo != NULL && tamTipo >0)
    {
        todoOk = 1;

        for(int i = 0;i<tamTipo;i++)
        {
            if(listaTipo[i].idTipo == idTipo)
            {
                strcpy(descripcionTipo,listaTipo[i].descripcionTipo);
                break;
            }
        }
    }

    return todoOk;
}

int validarIdTipo(eTipo listaTipo[], int tamTipo,int idTipo)
{
    int todoOk = 0;

    if (listaTipo != NULL && tamTipo > 0)
    {
        for (int i = 0; i < tamTipo; i++)
        {
            if (idTipo == listaTipo[i].idTipo)
            {
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int mostrarTipo(eTipo listaTipo[],int tamTipo)
{
    int todoOk = 0;

    if(listaTipo != NULL && tamTipo >0)
    {
        todoOk = 1;

        printf("-------------------------------\n");
        printf("      ***Tipos de viajes***    \n");
        printf("   ID              Tipo        \n");
        printf("-------------------------------\n");

        for(int i = 0; i < tamTipo;i++)
        {
            printf(" %d         %s       \n",listaTipo[i].idTipo,listaTipo[i].descripcionTipo);
        }


    }

    return todoOk;
}


