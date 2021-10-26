#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"
#include "biblioPropia.h"

int validarFecha(int mes,int anio,int dia)
{
    int todoOk = 0;
    int validarDia;
    int validarAnio;

    if(dia < 1 || dia >31)
    {
        printf("Error, dia erroneo\n ");
        validarDia = 0;
    }

    switch(mes)
    {
        case 4:
        case 6:
        case 9:
        case 11:
            if(dia > 30)
            {
                printf("Error,este mes solo tiene 30 dias\n");
                validarDia = 0;
            }
            else
            {
                validarDia = 1;
            }
            break;
        case 2:
            if(dia >28)
            {
                printf("Error, este mes solo tiene 28 dias\n");
                validarDia = 0;
            }
            else
            {
                validarDia = 1;
            }
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(dia >31)
            {
                printf("Error, este mes solo tiene 31 dias\n");
                validarDia = 0;
            }
            else
            {
                validarDia = 1;
            }
            break;
        default:
            printf("No existe el mes\n");
            validarDia = 0;
            break;
    }


    if((anio <=2021 && mes <11) || anio > 2050)
    {
        printf("Error,viajes programados hasta el 2050 y desde el 01/11/2021: ");
        validarAnio = 0;
    }
    else
    {
        validarAnio = 1;
    }

    if(validarDia == 1 && validarAnio == 1)
    {
        todoOk = 1;
    }

    return todoOk;

}




