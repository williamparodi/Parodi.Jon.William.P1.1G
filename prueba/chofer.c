#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "chofer.h"

int cargarNombreChofer(eChofer lista[], int tamChofer, int idChofer, char nombre[])
{
    int todoOk = 0;
    int flag = 1;
    if (lista != NULL && tamChofer > 0 && nombre != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tamChofer; i++)
        {
            if (lista[i].idChofer == idChofer)
            {
                strcpy(nombre, lista[i].nombre);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}

