#include <stdio.h>
#include <stdlib.h>
#include "dataWareHouse.h"
#include "micro.h"
#include "empresa.h"
#include "tipo.h"

int idEmpresa[10] = {1000,1002,1001,1000,1003,1002,1000,1003,1001,1002};

int idTipo[10] = {5001,5000,5002,5003,5000,5002,5003,5001,5002,5000};

int capacidad[10]= {10,20,30,45,6,50,45,6,38,49};

int hardcodearMicro(eMicro lista[], int tam, int cant, int* pId)
{
    int contador = -1;

    if (lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
    {
        contador = 0;
        for(int i = 0; i < cant;  i++)
        {
            lista[i].idMicro = *pId;
            (*pId)++;
            lista[i].idEmpresa = idEmpresa[i];
            lista[i].idTipo = idTipo[i];
            lista[i].capacidad = capacidad[i];
            lista[i].isEmpty = 0;
            contador++;
        }
    }
    return contador;
}
