#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destino.h"

int cargarDescripcionDestino(eDestino listaDestino[],int tamDestino,int idDestino, char descripcionDestino[],float* precioDestino)
{
    int todoOk = 0;

    if(listaDestino != NULL && tamDestino >0)
    {
        todoOk = 1;

        for(int i = 0;i<tamDestino;i++)
        {
            if(listaDestino[i].idDestino == idDestino)
            {
                strcpy(descripcionDestino,listaDestino[i].descripcion);
                *precioDestino = listaDestino[i].precio;
                 break;
            }
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
        printf("   ID         Destinos     Precios     \n");
        printf("---------------------------------------\n");

        for(int i = 0; i < tamDestino;i++)
        {
            printf(" %d          %s           %5.2f  \n",listaDestino[i].idDestino,listaDestino[i].descripcion,listaDestino[i].precio);
        }


    }

    return todoOk;
}

