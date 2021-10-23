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

float validarFloat(float numero,int min,int max)
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

    printf("--------------------------------------\n");
    printf("  *** Menu de Servicio de Viajes ***\n\n");
    printf("--------------------------------------\n");
    printf("A-Alta Micro\n");
    printf("B-Modificar Micro \n");
    printf("C-Baja Micro\n");
    printf("D-Listar Micros\n");
    printf("E-Litar Empresas\n");
    printf("F-Listar Tipos \n");
    printf("G-Listar Destinos");
    printf("H-Alta Viaje\n");
    printf("I-Listar viajes\n");
    printf("J-Salir");
    fflush(stdin);
    scanf("%c",&opcion);


    return opcion;
}
