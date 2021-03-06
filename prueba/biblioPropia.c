#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int ingresarInt(char mensaje[])
{
    int numeroInt;

    printf("%s",mensaje);
    scanf("%d",&numeroInt);

    return numeroInt;
}

int ingresarString(char mensaje[], char info[])
{
    int todoOk = 0;

    if(mensaje != NULL && info !=NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        gets(info);

        todoOk = 1;
    }

    return todoOk;
}

int pasarMayusculaPrimerCaracter(char string[])
{
    int todoOk = 0;
    int i = 0;

    if(string != NULL)
    {
        strlwr(string);
        string[0] = toupper(string[0]);
        while(string[i] != '\0')
        {
            if(string[i] == ' ')
            {
                string[i+1] = toupper(string[i+1]);
            }

            i++;
        }
        todoOk = 1;
    }

    return todoOk;
}

int validarInt(int numero,int min,int max)
{
    int todoOk = 0;

    if(numero >= min && numero <= max)
    {
        todoOk = 1;
    }

    return todoOk;
}

int validarFloat(float numero,int min,int max)
{
    int todoOk = 0;

    if(numero >= min && numero <= max)
    {
        todoOk = 1;
    }

    return todoOk;

}

char menu()
{
    char opcion;

    printf("\n-------------------------------------\n");
    printf("  *** Menu de Servicio de Viajes ***  \n\n");
    printf("-------------------------------------\n");
    printf("\nA-Alta Micro\n");
    printf("B-Modificar Micro \n");
    printf("C-Baja Micro\n");
    printf("D-Listar Micros\n");
    printf("E-Litar Empresas\n");
    printf("F-Listar Tipos \n");
    printf("G-Listar Destinos\n");
    printf("H-Alta Viaje\n");
    printf("I-Listar viajes\n");
    printf("J-Informes\n");
    printf("K-Salir\n");
    printf("\nIngrese una opcion: ");
    fflush(stdin);
    scanf("%c",&opcion);
    opcion = tolower(opcion);

    return opcion;
}

int orden()
{
    int todoOk = 0;
    int elegir;

    elegir = ingresarInt("Ingrese un orden: 1- Para mostrar en orden ascendente o 2- Para descendente: ");

    while(!validarInt(elegir,1,2))
    {
        elegir = ingresarInt("Error, Ingrese un orden: 1- Para mostrar en orden ascendente o 2- Para descendente: ");
    }

    if(elegir == 1)
    {
        todoOk = 1;
    }
    else
    {
        todoOk = -1;
    }

    return todoOk;
}

int informes()
{
    int opcion;

    printf("\n--------------------------------\n");
    printf("*** Informes ***  \n\n");
    printf("----------------------------------\n");
    printf("1-Micros por empresa\n");
    printf("2-Micros por tipo  \n");
    printf("3-Promedio de Micros de tipo VIP\n");
    printf("4-\n");
    printf("5-\n");
    printf("6-Listar Tipos \n");
    printf("7-Listar Destinos\n");
    printf("8-Alta Viaje\n");
    printf("9-");
    printf("10-");
    opcion = ingresarInt("Elija una opcion: ");

    return opcion;

}


