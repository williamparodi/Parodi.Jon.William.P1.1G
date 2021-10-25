#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"
#include "biblioPropia.h"

int pedirFecha(eFecha listaFecha[],int tamFecha)
{
    int todoOk = 0;
    int indice;

    eFecha auxFecha;

    if(listaFecha != NULL && tamFecha > 0)
    {
        todoOk = 1;

        auxFecha.mes = ingresarInt("Ingrese un mes: ");

        while(!validarInt(auxFecha.mes,1,12))
        {
            auxFecha.mes = ingresarInt("Error, Ingrese un mes: ");
        }


        auxFecha.dia = ingresarInt("Ingrese un día del mes : ");

        while(!validarInt(auxFecha.dia,1,31))
        {
            auxFecha.dia = ingresarInt("Error,Ingrese un día del mes : ");
        }

        switch(auxFecha.mes)
        {
            case 4:
            case 6:
            case 9:
            case 11:
                if(auxFecha.dia > 30)
                {
                    printf("Error,este mes solo tiene 30 dias\n");
                }
                else
                {
                    indice = auxFecha.dia;
                }
                break;
            case 2:
                if(auxFecha.dia >28)
                {
                    printf("Error, este mes solo tiene 28 días\n");
                }
                else
                {
                    indice = auxFecha.dia;
                }
                break;
            default:
                indice = auxFecha.dia;
                break;
        }

        auxFecha.anio = ingresarInt("Ingrese el anio: ");

        while(!validarInt(auxFecha.anio,2021,3000) && auxFecha.mes <11)
        {
            auxFecha.anio = ingresarInt("Error, ingrese un anio valido: ");
        }

        listaFecha[indice] = auxFecha;


    }

    return todoOk;
}


