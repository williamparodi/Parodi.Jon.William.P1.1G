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

int menu()
{
    int opcion;

    printf("-------------------------------\n");
    printf("  *** Nomina de Empleados ***\n\n");
    printf("-------------------------------\n");
    printf("1-Alta de Empleado\n");
    printf("2-Modificar Empleado\n");
    printf("3-Baja de Empleado\n");
    printf("4-Informes de Empleados\n");
    printf("5-Salir\n");
    printf("Ingrese Opcion: ");
    scanf("%d",&opcion);

    return opcion;
}
