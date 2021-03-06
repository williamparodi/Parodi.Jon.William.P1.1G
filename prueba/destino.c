#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destino.h"

int cargarDescripcionDestino(eDestino listaDestino[],int tamDestino,int idDestino, char descripcionDestino[],float* precioDestino)
{
    int todoOk = 0;
    int flag = 1;
    if(listaDestino != NULL && tamDestino >0 && descripcionDestino != NULL && precioDestino != NULL)
    {
        todoOk = 1;

        for(int i = 0;i<tamDestino;i++)
        {
            if(listaDestino[i].idDestino == idDestino)
            {
                strcpy(descripcionDestino,listaDestino[i].descripcion);
                *precioDestino = listaDestino[i].precio;
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

int validarIdDestino(eDestino listaDestino[], int tamDestino,int idDestino)
{
    int todoOk = 0;

    if (listaDestino != NULL && tamDestino > 0)
    {
        for (int i = 0; i < tamDestino; i++)
        {
            if (idDestino == listaDestino[i].idDestino)
            {
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int mostrarDestino(eDestino listaDestino[],int tamDestino)
{
    int todoOk = 0;

    if(listaDestino != NULL && tamDestino >0)
    {
        todoOk = 1;

        printf("---------------------------------------\n");
        printf("       *** Lista de Destinos ***       \n");
        printf(" ID       Destinos      Precios         \n");
        printf("---------------------------------------\n");

        for(int i = 0; i < tamDestino;i++)
        {
            printf(" %d    %-10s    %-10.2f  \n",listaDestino[i].idDestino,listaDestino[i].descripcion,listaDestino[i].precio);
        }


    }

    return todoOk;
}

