#include <stdio.h>
#include <stdlib.h>
#include "biblioPropia.h"
#include "micro.h"
#include "empresa.h"
#include "tipo.h"


#define TAM_MICRO 50
#define TAM_EMPRESA 4
#define TAM_TIPO 4

int main()
{
    char seguir = 's';
    int nextIdMicro = 2000;
    eMicro listaMicro[TAM_MICRO];
    int contadorMicro;

    if(!inicializarMicro(listaMicro,TAM_MICRO))
    {
        printf("Error\n");
    }

    eEmpresa listaEmpresa[TAM_EMPRESA] ={
    {1000,"Plusmar"},
    {1001,"Flecha Bus"},
    {1002,"Tas"},
    {1003,"El rapido"}};

    eTipo listaTipo[TAM_MICRO] = {
    {5000,"Comun"},
    {5001,"CocheCama"},
    {5002,"Doble"},
    {5003,"Vip"}};

    do
    {
        switch(menu())
        {
            case 'a':
                if(!altaMicro(listaMicro,TAM_MICRO,&nextIdMicro,listaEmpresa,TAM_EMPRESA,listaTipo,TAM_TIPO))
                {
                    printf("Error, no se pudo dar el alta\n");
                }
                else
                {
                    contadorMicro++;
                    printf("Alta Exitosa\n");
                }
                break;
            case 'b':
                if(!modificarMicro(listaMicro,TAM_MICRO,listaTipo,TAM_TIPO,listaEmpresa,TAM_EMPRESA))
                {
                    printf("Error, no se pudo modificar el micro\n");
                }
                else
                {
                    printf("MOdificacion exitosa");
                }
                break;
            case 'c':
                break;
            case 'd':
                break;
            case 'e':
                break;
            case 'f':
                break;
            case 'g':
                break;
            case 'h':
                break;
            case 'i':
                break;
            default:
                printf("opcion invalida\n");
                break;
        }






    }while(seguir == 's');


    return 0;
}
