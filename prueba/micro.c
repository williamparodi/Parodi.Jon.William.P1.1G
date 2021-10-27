#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "micro.h"
#include "biblioPropia.h"
#include "empresa.h"
#include "tipo.h"

int inicializarMicro(eMicro listaMicro[],int tamMicro)
{
    int todoOk = 0;

    if (listaMicro != NULL && tamMicro > 0)
    {
        todoOk = 1;

        for (int i = 0; i < tamMicro; i++)
        {
            listaMicro[i].isEmpty = 1;
        }
    }

    return todoOk;

}

int buscarLibre(eMicro listaMicro[], int tamMicro)
{
    int indice = -1;

    for (int i = 0; i < tamMicro; i++)
    {
        if (listaMicro[i].isEmpty)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarMicroPorId(eMicro listaMicro[], int tamMicro,int idMicro)
{
    int indice = -1;

    for (int i = 0; i < tamMicro; i++)
    {
        if(listaMicro[i].idMicro == idMicro && listaMicro[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int altaMicro(eMicro listaMicro[], int tamMicro,int* pIdMicro,eEmpresa listaEmpresa[], int tamEmpresa,eTipo listaTipo[], int tamTipo)
{
    int todoOk = 0;
    int indice;

    eMicro auxMicro;
    if (listaMicro != NULL && tamMicro > 0 && listaEmpresa != NULL && tamEmpresa > 0 && listaTipo != NULL && tamTipo >0)
    {
        system("cls");
        printf("  ***Alta Micro*** \n\n");

        indice = buscarLibre(listaMicro, tamMicro);

        if (indice == -1)
        {
            printf("No hay lugar\n");
        }
        else
        {
            auxMicro.idMicro = *pIdMicro;
            (*pIdMicro)++;

            mostrarEmpresas(listaEmpresa, tamEmpresa);

            auxMicro.idEmpresa = ingresarInt("Ingrese id de Empresa: ");


            while(!validarIdEmpresa(listaEmpresa,tamEmpresa,auxMicro.idEmpresa))
            {
                auxMicro.idEmpresa = ingresarInt("Error,Ingrese id de Empresa: ");
            }

            mostrarTipo(listaTipo,tamTipo);

            auxMicro.idTipo = ingresarInt("Ingrese el id del tipo de viaje: ");

            while(!validarIdTipo(listaTipo,tamTipo,auxMicro.idTipo))
            {
                auxMicro.idTipo = ingresarInt("Error,Ingrese el id del tipo de viaje : ");
            }

            auxMicro.capacidad = ingresarInt("Ingrese la capacidad del micro: ");

            while(!validarInt(auxMicro.capacidad,1,50))
            {
                auxMicro.capacidad = ingresarInt("Error,Ingrese la capacidad del micro: ");

            }


            auxMicro.isEmpty = 0;

            listaMicro[indice] = auxMicro;

            todoOk = 1;
        }
    }
    return todoOk;
}



int modificarMicro(eMicro listaMicro[], int tamMicro,eTipo listaTipo[],int tamTipo,eEmpresa listaEmpresa[],int tamEmpresa)
{
    int todoOk = 0;
    int indice;
    int id;
    int opcion;

    eMicro auxMicro;
    if ( listaMicro != NULL && tamMicro > 0  && listaTipo != NULL && tamTipo> 0)
    {
        system("cls");
        printf("   *** Modificar Micro *** \n\n");

        printf("-----------------------------------\n");

        mostrarMicros(listaMicro,tamMicro,listaTipo,tamTipo,listaEmpresa,tamEmpresa);

        id = ingresarInt("Ingresar Id de micro a Modificar : ");

        indice = buscarMicroPorId(listaMicro,tamMicro,id);

        if (indice == -1)
        {
            printf("No se encontro el id del micro\n %d", id);
        }
        else
        {
            opcion = ingresarInt("Ingrese el campo a modificar 1-Tipo o 2- Capacidad: ");

            while(!validarInt(opcion,1,2))
            {
                opcion = ingresarInt("Ingrese el campo a modificar 1-Tipo o 2- Capacidad: ");
            }

            if(opcion == 1)
            {


                mostrarTipo(listaTipo,tamTipo);

                auxMicro.idTipo = ingresarInt("Modifique el Tipo: ");

                while(!validarIdTipo(listaTipo,tamTipo,auxMicro.idTipo))
                {
                   auxMicro.idTipo = ingresarInt("Error,Modifique el Tipo: ");
                }

                listaMicro[indice].idTipo = auxMicro.idTipo;
            }
            else
            {

                auxMicro.capacidad = ingresarInt("Modifique la capacidad: ");

                while(!validarInt(auxMicro.capacidad,1,50))
                {
                    auxMicro.capacidad = ingresarInt("Error,Modifique la capacidad: ");
                }

                listaMicro[indice].capacidad = auxMicro.capacidad;
            }



            todoOk = 1;
        }
    }
    return todoOk;
}

void mostrarMicro(eMicro unMicro,eTipo listaTipos[],int tamTipo,eEmpresa listaEmpresa[],int tamEmpresa)
{
    char descripcionEmpresa[20];
    char descripcionTipo[20];

    if(cargarDescripcionEmpresa(listaEmpresa,tamEmpresa,unMicro.idEmpresa,descripcionEmpresa)== 1 && cargarDescripcionTipo(listaTipos,tamTipo,unMicro.idTipo,descripcionTipo))
    {
        printf(" %d   %5s      %5s      %d \n",
               unMicro.idMicro,
               descripcionEmpresa,
               descripcionTipo,
               unMicro.capacidad);
    }

}

int mostrarMicros(eMicro listaMicro[],int tamMicro , eTipo listaTipo[],int tamTipo, eEmpresa listaEmpresa[],int tamEmpresa)
{
    int todoOk = 0;
    int flag = 1;
    if (listaMicro != NULL && tamMicro > 0 && listaTipo != NULL && listaEmpresa != NULL && tamTipo > 0 && tamEmpresa > 0)
    {
        system("cls");
        printf("           ***Lista de Micros***                            \n");
        printf("------------------------------------------------------------\n");
        printf(" ID      Empresa     TIPO     Capacidad                     \n");
        printf("------------------------------------------------------------\n");
        for (int i = 0; i < tamMicro; i++)
        {
            if (!listaMicro[i].isEmpty)
            {
                mostrarMicro(listaMicro[i],listaTipo,tamTipo,listaEmpresa,tamEmpresa);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("No hay autos para mostrar.\n");

        }
        todoOk = 1;
    }
    return todoOk;
}

int bajaMicro(eMicro listaMicro[],int tamMicro,eTipo listaTipo[],int tamTipo,eEmpresa listaEmpresa[],int tamEmpresa)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if (listaMicro != NULL && listaMicro != NULL && listaEmpresa != NULL && tamMicro > 0 && tamEmpresa > 0 && tamTipo >0)
    {
        system("cls");
        printf("   *** Baja Micro *** \n\n");

        mostrarMicros(listaMicro,tamMicro,listaTipo,tamTipo,listaEmpresa,tamEmpresa);

        id = ingresarInt("Ingrese es id del micro que desea dar de baja: ");

        indice = buscarMicroPorId(listaMicro, tamMicro, id);

        if (indice == -1)
        {
            printf("El id del micro: %d no esta registrado en el sistema\n", id);
        }
        else
        {
            mostrarMicro(listaMicro[indice],listaTipo,tamTipo,listaEmpresa,tamEmpresa);
            printf("Confirma baja?: S/N");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if (confirma == 's')
            {
                listaMicro[indice].isEmpty = 1;
                todoOk = 1;
            }
            else
            {
                printf("Baja cancelada por el usuario.\n");
            }
        }
    }

    return todoOk;
}

int ordenarMicros(eMicro listaMicro[],int tamMicro,eEmpresa listaEmpresa[],int tamEmpresa)
{
    int todoOk = 0;
    eMicro auxMicro;
    char descripcionEmpresa1[20];
    char descripcionEmpresa2[20];

    int ordenEmpresa;
    int elegirOrden;

    if (listaMicro != NULL && listaEmpresa != NULL && tamMicro > 0 && tamEmpresa > 0)
    {
        todoOk = 1;

        elegirOrden = orden();


        for(int i = 0; i < tamMicro - 1;i++)
        {
            for(int j = i + 1;j < tamMicro;j++)
            {
                cargarDescripcionEmpresa(listaEmpresa,tamEmpresa,listaMicro[i].idEmpresa,descripcionEmpresa1);
                cargarDescripcionEmpresa(listaEmpresa,tamEmpresa,listaMicro[j].idEmpresa,descripcionEmpresa2);

                ordenEmpresa = strcmp(descripcionEmpresa1,descripcionEmpresa2);

                if(elegirOrden == 1)
                {
                    if((ordenEmpresa >0)|| (ordenEmpresa == 0 && listaMicro[i].capacidad > listaMicro[j].capacidad))
                    {
                        auxMicro = listaMicro[i];
                        listaMicro[i] = listaMicro[j];
                        listaMicro[j] = auxMicro;
                    }
                }
                else
                {
                    if((ordenEmpresa <0) || (ordenEmpresa == 0 && listaMicro[i].capacidad < listaMicro[j].capacidad))
                    {
                        auxMicro = listaMicro[i];
                        listaMicro[i] = listaMicro[j];
                        listaMicro[j] = auxMicro;
                    }
                }

            }
        }
    }

    return todoOk;

}

int validarIdMicro(eMicro listaMicro[], int tamMicro,int idMicro)
{
    int todoOk = 0;

    if (listaMicro != NULL && tamMicro > 0)
    {
        for (int i = 0; i < tamMicro; i++)
        {
            if (idMicro == listaMicro[i].idMicro)
            {
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}



