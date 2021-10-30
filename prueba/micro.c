#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "micro.h"
#include "biblioPropia.h"
#include "empresa.h"
#include "tipo.h"
#include "chofer.h"

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


int altaMicro(eMicro listaMicro[], int tamMicro,int* pIdMicro,eEmpresa listaEmpresa[], int tamEmpresa,eTipo listaTipo[], int tamTipo,eChofer lista[],int tamChofer,int* pIdChofer)
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

            lista[indice].idChofer = *pIdChofer;
            auxMicro.idChofer = *pIdChofer;
            (*pIdChofer)++;

            ingresarString("Ingrese nombre de cliente: ",lista[indice].nombre);
            pasarMayusculaPrimerCaracter(lista[indice].nombre);

            printf("Ingrese sexo : f o m\n");
            fflush(stdin);
            scanf("%c",&lista[indice].sexo);

            while(lista[indice].sexo != 'f' && lista[indice].sexo != 'm')
            {
                printf("Error, Ingrese sexo : f o m\n");
                fflush(stdin);
                scanf("%c",&lista[indice].sexo);
            }

            mostrarEmpresas(listaEmpresa, tamEmpresa);

            auxMicro.idEmpresa = ingresarInt("\nIngrese id de Empresa: ");


            while(!validarIdEmpresa(listaEmpresa,tamEmpresa,auxMicro.idEmpresa))
            {
                auxMicro.idEmpresa = ingresarInt("Error,Ingrese id de Empresa: ");
            }

            mostrarTipo(listaTipo,tamTipo);

            auxMicro.idTipo = ingresarInt("\nIngrese el id del tipo de viaje: ");

            while(!validarIdTipo(listaTipo,tamTipo,auxMicro.idTipo))
            {
                auxMicro.idTipo = ingresarInt("Error,Ingrese el id del tipo de viaje : ");
            }

            auxMicro.capacidad = ingresarInt("\nIngrese la capacidad del micro: ");

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

int modificarMicro(eMicro listaMicro[], int tamMicro,eTipo listaTipo[],int tamTipo,eEmpresa listaEmpresa[],int tamEmpresa,eChofer lista[],int tamChofer)
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

        mostrarMicros(listaMicro,tamMicro,listaTipo,tamTipo,listaEmpresa,tamEmpresa,lista,tamChofer);

        id = ingresarInt("\nIngresar Id de micro a Modificar : ");

        indice = buscarMicroPorId(listaMicro,tamMicro,id);

        if (indice == -1)
        {
            printf("No se encontro el id del micro\n %d", id);
        }
        else
        {
            opcion = ingresarInt("\nIngrese el campo a modificar 1-Tipo o 2- Capacidad: ");

            while(!validarInt(opcion,1,2))
            {
                opcion = ingresarInt("\nIngrese el campo a modificar 1-Tipo o 2- Capacidad: ");
            }

            if(opcion == 1)
            {


                mostrarTipo(listaTipo,tamTipo);

                auxMicro.idTipo = ingresarInt("\nModifique el Tipo: ");

                while(!validarIdTipo(listaTipo,tamTipo,auxMicro.idTipo))
                {
                   auxMicro.idTipo = ingresarInt("Error,Modifique el Tipo: ");
                }

                listaMicro[indice].idTipo = auxMicro.idTipo;
            }
            else
            {

                auxMicro.capacidad = ingresarInt("\nModifique la capacidad: ");

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


void mostrarMicro(eMicro unMicro,eTipo listaTipos[],int tamTipo,eEmpresa listaEmpresa[],int tamEmpresa,eChofer lista[],int tamChofer)
{
    char descripcionEmpresa[20];
    char descripcionTipo[20];
    char descripcionNombre[25];

    if(cargarNombreChofer(lista,tamChofer,unMicro.idChofer,descripcionNombre)== 1 && cargarDescripcionEmpresa(listaEmpresa,tamEmpresa,unMicro.idEmpresa,descripcionEmpresa)== 1 && cargarDescripcionTipo(listaTipos,tamTipo,unMicro.idTipo,descripcionTipo))
    {
        printf(" %d   %-13s         %-13s %-13d   %d       %s  \n",
               unMicro.idMicro,
               descripcionEmpresa,
               descripcionTipo,
               unMicro.capacidad,
               unMicro.idChofer,
               descripcionNombre);
    }

}

int mostrarMicros(eMicro listaMicro[],int tamMicro , eTipo listaTipo[],int tamTipo, eEmpresa listaEmpresa[],int tamEmpresa,eChofer lista[],int tamChofer)
{
    int todoOk = 0;
    int flag = 1;
    if (listaMicro != NULL && tamMicro > 0 && listaTipo != NULL && listaEmpresa != NULL && tamTipo > 0 && tamEmpresa > 0 && lista != NULL && tamChofer > 0)
    {
        system("cls");
        printf("                       ***Lista de Micros***          \n");
        printf("-------------------------------------------------------------------------------------\n");
        printf(" ID     Empresa               Tipo          Capacidad     IdChofer    Nombre        \n");
        printf("-------------------------------------------------------------------------------------\n");
        for (int i = 0; i < tamMicro; i++)
        {
            if (!listaMicro[i].isEmpty)
            {
                mostrarMicro(listaMicro[i],listaTipo,tamTipo,listaEmpresa,tamEmpresa,lista,tamChofer);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("No hay autos para mostrar\n");

        }
        todoOk = 1;
    }
    return todoOk;
}

int bajaMicro(eMicro listaMicro[],int tamMicro,eTipo listaTipo[],int tamTipo,eEmpresa listaEmpresa[],int tamEmpresa,eChofer lista[],int tamChofer)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if (listaMicro != NULL && listaMicro != NULL && listaEmpresa != NULL && tamMicro > 0 && tamEmpresa > 0 && tamTipo >0 && lista != NULL && tamChofer > 0)
    {
        system("cls");
        printf("   *** Baja Micro *** \n\n");

        mostrarMicros(listaMicro,tamMicro,listaTipo,tamTipo,listaEmpresa,tamEmpresa,lista,tamChofer);

        id = ingresarInt("\nIngrese es id del micro que desea dar de baja: ");

        indice = buscarMicroPorId(listaMicro, tamMicro, id);

        if (indice == -1)
        {
            printf("El id del micro: %d no esta registrado en el sistema\n", id);
        }
        else
        {
            mostrarMicro(listaMicro[indice],listaTipo,tamTipo,listaEmpresa,tamEmpresa,lista,tamChofer);
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

int mostrarMicrosPorEmpresa(eMicro listaMicro[],int tamMicro,eTipo listaTipo[],int tamTipo,eEmpresa listaEmpresa[],int tamEmpresa,eChofer lista[],int tamChofer)
{
    int todoOk = 0;
    int idEmpresa;

    if(listaEmpresa != NULL && listaMicro != NULL && listaTipo != NULL && lista != NULL && tamMicro > 0 && tamTipo > 0 && tamEmpresa >0 && tamChofer > 0)
    {
        todoOk = 1;
        system("cls");
        printf("        ***Micros de una Empresa ***\n");
        printf("----------------------------------------------\n");
        mostrarEmpresas(listaEmpresa,tamEmpresa);

        idEmpresa = ingresarInt("Ingrese un id de empresa : ");

        while(!validarIdEmpresa(listaEmpresa,tamEmpresa,idEmpresa))
        {
            idEmpresa = ingresarInt("Error,Ingrese el id de empresa: ");
        }

        mostrarMicrosPorIdEmpresa(listaMicro,tamMicro,listaTipo,tamTipo,listaEmpresa,tamEmpresa,idEmpresa,lista,tamChofer);


    }

    return todoOk;

}

int mostrarMicrosPorIdEmpresa(eMicro listaMicro[],int tamMicro,eTipo listaTipo[],int tamTipo,eEmpresa listaEmpresa[],int tamEmpresa,int idEmpresa,eChofer lista[],int tamChofer)
{
    int todoOk = 0;
    char descripcion[20];
    int flag = 1;

    if(listaEmpresa != NULL && listaMicro != NULL && listaTipo !=NULL && listaEmpresa != NULL && lista != NULL && tamMicro > 0 && tamTipo > 0 && tamEmpresa >0 && tamChofer >0)
    {
        system("cls");
        printf("                       ***Lista de Empresas***          \n");
        printf("-------------------------------------------------------------------------------------------\n");
        printf(" ID      Empresa               Tipo          Capacidad      IdChofer    Nombre             \n");
        printf("-------------------------------------------------------------------------------------------\n");

        for(int i = 0;i < tamMicro;i++)
        {
            if(!listaMicro[i].isEmpty && idEmpresa == listaMicro[i].idEmpresa)
            {
                mostrarMicro(listaMicro[i],listaTipo,tamTipo,listaEmpresa,tamEmpresa,lista,tamChofer);
                flag = 0;
            }
        }
        if(flag)
        {
            cargarDescripcionEmpresa(listaEmpresa,tamEmpresa,idEmpresa,descripcion);
            printf("No hay ningun micro de esa empresa : %s\n",descripcion);
        }
        todoOk = 1;
    }


    return todoOk;

}

int mostrarMicrosPorTipo(eMicro listaMicro[],int tamMicro,eTipo listaTipo[],int tamTipo,eEmpresa listaEmpresa[],int tamEmpresa,eChofer lista[],int tamChofer)
{
    int todoOk = 0;
    int idTipo;

    if(listaEmpresa != NULL && listaMicro != NULL && listaTipo !=NULL && lista != NULL && tamChofer >0 && tamMicro > 0 && tamTipo > 0 && tamEmpresa >0)
    {

        printf("        ***Micros de un Tipo ***\n");
        printf("----------------------------------------------\n");
        mostrarTipo(listaTipo,tamTipo);

        idTipo = ingresarInt("Ingrese el id tipo: ");

        while(!validarIdTipo(listaTipo,tamTipo,idTipo))
        {
            idTipo = ingresarInt("Error,Ingrese el id del tipo de viaje : ");
        }

        mostrarMicrosIdTipo(listaMicro,tamMicro,listaTipo,tamTipo,listaEmpresa,tamEmpresa,idTipo,lista,tamChofer);

        todoOk = 1;
    }

    return todoOk;

}

int mostrarMicrosIdTipo(eMicro listaMicro[],int tamMicro,eTipo listaTipo[],int tamTipo,eEmpresa listaEmpresa[],int tamEmpresa,int idTipo,eChofer lista[],int tamChofer)
{
    int todoOk = 0;
    char descripcion[20];
    int flag = 1;

    if(listaEmpresa != NULL && listaMicro != NULL && listaTipo !=NULL && lista != NULL && tamMicro > 0 && tamTipo > 0 && tamEmpresa >0 && tamChofer > 0)
    {
        system("cls");
        printf("                       ***Lista de Micros***          \n");
        printf("-------------------------------------------------------------------------------------------\n");
        printf(" ID     Empresa               Tipo          Capacidad      IdChofer    Nombre             \n");
        printf("-------------------------------------------------------------------------------------------\n");

        for(int i = 0;i < tamMicro;i++)
        {
            if(!listaMicro[i].isEmpty && idTipo == listaMicro[i].idTipo)
            {
                mostrarMicro(listaMicro[i],listaTipo,tamTipo,listaEmpresa,tamEmpresa,lista,tamChofer);
                flag = 0;
            }
        }
        if(flag)
        {
            cargarDescripcionTipo(listaTipo,tamTipo,idTipo,descripcion);
            printf("No hay ningun micro de este tipo : %s\n",descripcion);
        }
        todoOk = 1;
    }


    return todoOk;

}

int mostrarEmpresaMayorCapacidad(eMicro listaMicro[],int tamMicro,eEmpresa listaEmpresa[],int tamEmpresa,eTipo listaTipo[],int tamTipo,eChofer lista[],int tamChofer)
{
    int todoOk = 0;
    int mayorCapacidad;
    int flag = 1;

    if(listaMicro != NULL && listaEmpresa != NULL && listaTipo != NULL && lista != NULL && tamEmpresa > 0 && tamMicro >0 && tamTipo >0 && tamChofer > 0)
    {
        for(int i = 0;i < tamMicro;i++)
        {
            if(!listaMicro[i].isEmpty)
            {
                if(flag|| listaMicro[i].capacidad > mayorCapacidad)
                {
                    mayorCapacidad = listaMicro[i].capacidad;
                    flag = 0;
                }
            }
        }
        system("cls");
        printf("                       ***Lista de Micros***          \n");
        printf("-------------------------------------------------------------------------------------\n");
        printf(" ID     Empresa               Tipo          Capacidad     IdChofer    Nombre         \n");
        printf("-------------------------------------------------------------------------------------\n");
        printf("                        *** Micro menor capacidad *** \n");

        for (int i = 0; i < tamMicro; i++)
        {
            if(!listaMicro[i].isEmpty && listaMicro[i].capacidad == mayorCapacidad)
            {

                mostrarMicro(listaMicro[i],listaTipo,tamTipo,listaEmpresa,tamEmpresa,lista,tamChofer);
            }
        }
        todoOk = 1;
    }
    return todoOk;


}

int mostrarMicrosOrdenado(eMicro listaMicro[],int tamMicro, eEmpresa listaEmpresa[], int tamEmpresa,eTipo listaTipo[], int tamTipo,eChofer lista[],int tamChofer)
{
    int todoOk = 0;

    if(listaMicro != NULL && tamMicro > 0 && listaEmpresa != NULL && tamEmpresa > 0 && listaTipo != NULL && tamTipo > 0)
    {

        printf("              **Micros de cada Empresa **\n");

        for (int i = 0; i < tamEmpresa; i++)
        {

            printf("Empresa: %s\n", listaEmpresa[i].descripcion);
            mostrarMicrosPorIdEmpresa(listaMicro,tamMicro,listaTipo,tamTipo,listaEmpresa,tamEmpresa,listaEmpresa[i].idEmpresa,lista,tamChofer);
            printf("\n------------------------------------------------------------\n");
        }
        todoOk = 1;
    }
    return todoOk;
}







