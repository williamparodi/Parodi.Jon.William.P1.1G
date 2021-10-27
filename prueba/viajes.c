#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "micro.h"
#include "biblioPropia.h"
#include "empresa.h"
#include "tipo.h"
#include "destino.h"
#include "viajes.h"
#include "fecha.h"

int inicializarViaje(eViaje listaViaje[],int tamViaje)
{
    int todoOk = 0;

    if (listaViaje != NULL && tamViaje > 0)
    {
        todoOk = 1;

        for (int i = 0; i < tamViaje; i++)
        {
            listaViaje[i].isEmpty = 1;
        }
    }

    return todoOk;

}

int buscarLibreViaje(eViaje listaViaje[], int tamViaje)
{
    int indice = -1;

    for (int i = 0; i < tamViaje; i++)
    {
        if (listaViaje[i].isEmpty)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarViajePorId(eViaje listaViaje[], int tamViaje,int idViaje)
{
    int indice = -1;

    for (int i = 0; i < tamViaje; i++)
    {
        if(listaViaje[i].idViaje == idViaje && listaViaje[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int altaViaje(eViaje listaViaje[], int tamViaje,int* pIdViaje,eMicro listaMicro[], int tamMicro,eDestino listaDestino[], int tamDestino,eTipo listaTipo[],int tamTipo,eEmpresa listaEmpresa[],int tamEmpresa,eFecha listaFecha[],int tamFecha)
{
    int todoOk = 0;
    int indice;

    eViaje auxViaje;

    if(listaViaje != NULL && tamViaje && listaMicro != NULL && tamMicro > 0 && listaDestino != NULL && tamDestino > 0 && pIdViaje != NULL &&
            listaEmpresa != NULL && listaTipo != NULL && tamEmpresa >0 && tamTipo > 0)
    {
        system("cls");
        printf("  ***Alta Viaje*** \n\n");

        indice = buscarLibreViaje(listaViaje, tamViaje);

        if(indice == -1)
        {
            printf("No hay lugar\n");
        }
        else
        {
            auxViaje.idViaje = *pIdViaje;
            (*pIdViaje)++;

            mostrarMicros(listaMicro,tamMicro,listaTipo,tamTipo,listaEmpresa,tamEmpresa);

            auxViaje.idMicro = ingresarInt("Ingrese id del micro: ");


            while(!validarIdMicro(listaMicro,tamMicro,auxViaje.idMicro))
            {
                auxViaje.idMicro = ingresarInt("Error,Ingrese id del micro: ");
            }

            mostrarDestino(listaDestino,tamDestino);

            auxViaje.idDestino = ingresarInt("Ingrese el id del Destino: ");

            while(!validarIdDestino(listaDestino,tamDestino,auxViaje.idDestino))
            {
                auxViaje.idDestino = ingresarInt("Error,Ingrese el id del Destino: ");

            }

            printf("Ingrese la fecha de viaje (D/M/AAAA)\n");

            auxViaje.fechaDia = ingresarInt("Ingrese un dia: ");
            auxViaje.fechaMes = ingresarInt("Ingrese un mes: ");
            auxViaje.fechaAnio = ingresarInt("Ingrese anio: ");


            while(!validarFecha(auxViaje.fechaMes,auxViaje.fechaAnio,auxViaje.fechaDia))
            {
                printf("Vuelva a ingresar la fecha de viaje (D/M/AAAA)\n");
                auxViaje.fechaDia = ingresarInt("Ingrese un dia: ");
                auxViaje.fechaMes = ingresarInt("Ingrese un mes: ");
                auxViaje.fechaAnio = ingresarInt("Ingrese anio: ");

            }



            auxViaje.isEmpty = 0;

            listaViaje[indice] = auxViaje;

            todoOk = 1;
        }
    }
    return todoOk;
}





void mostrarViaje(eViaje unViaje,eDestino listaDestino[],int tamDestino,eMicro unMicro,eEmpresa listaEmpresa[],int tamEmpresa,eTipo listaTipo[],int tamTipo,eFecha listaFecha[],int tamFecha)
{
    char descripcionDestino[25];
    char descripcionEmpresa[25];
    char descripcionTipo[25];
    float precio;

    if(cargarDescripcionDestino(listaDestino,tamDestino,unViaje.idDestino,descripcionDestino,&precio) && cargarDescripcionEmpresa(listaEmpresa,tamEmpresa,unMicro.idEmpresa,descripcionEmpresa) && cargarDescripcionTipo(listaTipo,tamTipo,unMicro.idTipo,descripcionTipo))
    {
        printf(" %d    %d      %5s    %s     %d      %s       $%.2f       %d/%d/%d    \n",
               unViaje.idViaje,
               unViaje.idMicro,
               descripcionEmpresa,
               descripcionTipo,
               unMicro.capacidad,
               descripcionDestino,
               precio,
               unViaje.fechaDia,
               unViaje.fechaMes,
               unViaje.fechaAnio);
    }

}

int mostrarViajes(eViaje listaViaje[],int tamViaje, eMicro listaMicro[],int tamMicro,eDestino listaDestino[],int tamDestino,eEmpresa listaEmpresa[],int tamEmpresa,eTipo listaTipo[],int tamTipo,eFecha listaFecha[],int tamFecha)
{
    int todoOk = 0;
    int flag = 1;

    if (listaViaje != NULL && tamViaje > 0 && listaMicro != NULL && tamMicro >0)
    {
        system("cls");
        printf("                                    ***Lista de viajes***                                               \n");
        printf("--------------------------------------------------------------------------------------------------------\n");
        printf(" IdViaje    IdMicro     Empresa     TIPO     Capacidad    Destino    Precio         Fecha               \n");
        printf("--------------------------------------------------------------------------------------------------------\n");

        for (int i = 0; i < tamMicro; i++)
        {
            if (!listaViaje[i].isEmpty)
            {
                mostrarViaje(listaViaje[i],listaDestino,tamDestino,listaMicro[i],listaEmpresa,tamEmpresa,listaTipo,tamTipo,listaFecha,tamFecha);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("No hay viajes  para mostrar.\n");

        }
        todoOk = 1;
    }
    return todoOk;
}




