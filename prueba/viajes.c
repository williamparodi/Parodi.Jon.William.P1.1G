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
#include "chofer.h"

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


int altaViaje(eViaje listaViaje[], int tamViaje,int* pIdViaje,eMicro listaMicro[], int tamMicro,eDestino listaDestino[], int tamDestino,eTipo listaTipo[],int tamTipo,eEmpresa listaEmpresa[],int tamEmpresa,eFecha listaFecha[],int tamFecha,eChofer lista[],int tamChofer)
{
    int todoOk = 0;
    int indice;

    eViaje auxViaje;

    if(listaViaje != NULL && tamViaje && listaMicro != NULL && tamMicro > 0 && listaDestino != NULL && tamDestino > 0 && pIdViaje != NULL &&
            listaEmpresa != NULL && listaTipo != NULL && lista != NULL && tamEmpresa >0 && tamTipo > 0 && tamChofer > 0)
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

            mostrarMicros(listaMicro,tamMicro,listaTipo,tamTipo,listaEmpresa,tamEmpresa,lista,tamChofer);

            auxViaje.idMicro = ingresarInt("\nIngrese id del micro: ");


            while(!validarIdMicro(listaMicro,tamMicro,auxViaje.idMicro))
            {
                auxViaje.idMicro = ingresarInt("Error,Ingrese id del micro: ");
            }

            mostrarDestino(listaDestino,tamDestino);

            auxViaje.idDestino = ingresarInt("\nIngrese el id del Destino: ");

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





void mostrarViaje(eViaje unViaje,eDestino listaDestino[],int tamDestino,eMicro listaMicro[],int tamMicro,eEmpresa listaEmpresa[],int tamEmpresa,eTipo listaTipo[],int tamTipo,eFecha listaFecha[],int tamFecha)
{
    char descripcionDestino[25];
    char descripcionEmpresa[25];
    char descripcionTipo[25];
    float precio;
    int indice;

    indice = buscarMicroPorId(listaMicro,tamMicro,unViaje.idMicro);

    if(cargarDescripcionDestino(listaDestino,tamDestino,unViaje.idDestino,descripcionDestino,&precio)== 1 && cargarDescripcionEmpresa(listaEmpresa,tamEmpresa,listaMicro[indice].idEmpresa,descripcionEmpresa)==1 && cargarDescripcionTipo(listaTipo,tamTipo,listaMicro[indice].idTipo,descripcionTipo)== 1)
    {
        printf(" %d       %d        %-10s    %-10s     %-10d      %-10s       $%.2f       %d/%d/%d    \n",
               unViaje.idViaje,
               unViaje.idMicro,
               descripcionEmpresa,
               descripcionTipo,
               listaMicro[indice].capacidad,
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

    if (listaViaje != NULL &&  listaMicro != NULL && listaDestino != NULL && listaEmpresa != NULL && listaTipo != NULL && listaFecha != NULL &&
        tamMicro >0 && tamViaje > 0 && tamFecha >0 && tamTipo && tamDestino > 0 &&tamEmpresa > 0)
    {
        system("cls");
        printf("                                    ***Lista de viajes***                                               \n");
        printf("--------------------------------------------------------------------------------------------------------------\n");
        printf(" IdViaje    IdMicro     Empresa       TIPO           Capacidad       Destino          Precio          Fecha   \n");
        printf("--------------------------------------------------------------------------------------------------------------\n");

        for (int i = 0; i < tamMicro; i++)
        {
            if (!listaViaje[i].isEmpty)
            {
                mostrarViaje(listaViaje[i],listaDestino,tamDestino,listaMicro,tamMicro,listaEmpresa,tamEmpresa,listaTipo,tamTipo,listaFecha,tamFecha);
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

int mostrarViajesConFecha(eViaje listaViaje[],int tamViaje, eMicro listaMicro[],int tamMicro,eDestino listaDestino[],int tamDestino,
                  eEmpresa listaEmpresa[],int tamEmpresa,eTipo listaTipo[],int tamTipo,eFecha listaFecha[],int tamFecha,eChofer lista[],int tamChofer)
{

    int todoOk = 0;
    int flag = 1;
    float precio;
    char descDestino[20];
    eViaje auxViaje;

    if (listaViaje != NULL &&  listaMicro != NULL && listaDestino != NULL && listaEmpresa != NULL && listaTipo != NULL && listaFecha != NULL && lista != NULL && tamChofer > 0 &&
        tamMicro  >0 && tamViaje > 0 && tamFecha >0 && tamTipo  > 0 && tamDestino > 0 &&tamEmpresa > 0)
    {


        printf(" ******  Viajes por Fecha: ********* \n");
        printf("-------------------------------------\n");

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


        for(int i = 0; i < tamViaje;i++)
        {
            if(!listaViaje[i].isEmpty && listaViaje[i].fechaDia == auxViaje.fechaDia && listaViaje[i].fechaMes == auxViaje.fechaMes && listaViaje[i].fechaAnio == auxViaje.fechaAnio)
            {
                cargarDescripcionDestino(listaDestino,tamDestino,listaViaje[i].idDestino,descDestino,&precio);
                printf("En el %d/%d/%d los viajes son a : %s",auxViaje.fechaDia,auxViaje.fechaMes,auxViaje.fechaAnio,descDestino);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("No hay viajes para mostrar en la fecha.\n");
        }

        todoOk =1;

    }

    return todoOk;


}
/*
int mostrarViajesconUnMicro(eViaje listaViaje[],int tamViaje, eMicro listaMicro[],int tamMicro,eDestino listaDestino[],int tamDestino,
                  eEmpresa listaEmpresa[],int tamEmpresa,eTipo listaTipo[],int tamTipo,eFecha listaFecha[],int tamFecha,eChofer lista[],int tamChofer)
{
    int todoOk = 0;
    int flag = 1;
    int idMicro;

    if (listaViaje != NULL &&  listaMicro != NULL && listaDestino != NULL && listaEmpresa != NULL && listaTipo != NULL && listaFecha != NULL && lista != NULL && tamChofer > 0
        tamMicro >0 && tamViaje > 0 && tamFecha >0 && tamTipo && tamDestino > 0 &&tamEmpresa > 0)
    {
        mostrarMicros(listaMicro,tamMicro,listaTipo,tamTipo,listaEmpresa,tamEmpresa,lista,tamChofer);

        idMicro = ingresarInt("Ingrese el Id del Micro \n");

        while(!validarIdMicro(listaMicro,tamMicro,idMicro))
        {
            idMicro = ingresarInt("Error,Ingrese el Id del micro \n");
        }
        system("cls");
        printf("                                    ***Listado de viajes con un Micro***                                               \n");
        printf("--------------------------------------------------------------------------------------------------------------\n");
        printf(" IdViaje    IdMicro     Empresa       TIPO           Capacidad       Destino          Precio          Fecha   \n");
        printf("--------------------------------------------------------------------------------------------------------------\n");

        for (int i = 0; i < tamMicro; i++)
        {
            if (!listaViaje[i].isEmpty && listaViaje[i].idMicro == idMicro)
            {
                mostrarViaje(listaViaje[i],listaDestino,tamDestino,listaMicro,tamMicro,listaEmpresa,tamEmpresa,listaTipo,tamTipo,listaFecha,tamFecha);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("No hay viajes con ese Micro .\n");

        }
        todoOk = 1;
    }
    return todoOk;
}*/




