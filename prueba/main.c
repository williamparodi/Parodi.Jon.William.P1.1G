#include <stdio.h>
#include <stdlib.h>
#include "biblioPropia.h"
#include "micro.h"
#include "empresa.h"
#include "tipo.h"
#include "destino.h"


#define TAM_MICRO 50
#define TAM_EMPRESA 4
#define TAM_TIPO 4
#define TAM_DESTINO 4


int main()
{
    char seguir = 's';
    int nextIdMicro = 2000;
    int nextIdViaje = 1000;
    int contadorMicro = 0;
    eMicro listaMicro[TAM_MICRO];


    if(!inicializarMicro(listaMicro,TAM_MICRO))
    {
        printf("Error\n");
    }

    eEmpresa listaEmpresa[TAM_EMPRESA] ={
    {1000,"Plusmar"},
    {1001,"Flecha Bus"},
    {1002,"Tas"},
    {1003,"El rapido"}};

    eTipo listaTipo[TAM_TIPO] = {
    {5000,"Comun"},
    {5001,"CocheCama"},
    {5002,"Doble"},
    {5003,"Vip"}};

    eDestino listaDestino[TAM_DESTINO] = {
    {20000,"Calafate",22250},
    {20001,"Bariloche",10300},
    {20003,"Iguazu",84400,},
    {20004,"Mendoza",95600}};

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
                if(!contadorMicro)
                {
                    printf("Debería dar de alta un micro pirmero\n");
                }
                else
                {
                    if(!modificarMicro(listaMicro,TAM_MICRO,listaTipo,TAM_TIPO,listaEmpresa,TAM_EMPRESA))
                    {
                        printf("Error, no se pudo modificar el micro\n");
                    }
                    else
                    {
                        printf("Modificacion exitosa\n");
                    }
                }
                break;
            case 'c':
                if(!contadorMicro)
                {
                    printf("Debería dar de alta un micro pirmero\n");
                }
                else
                {
                     if(!bajaMicro(listaMicro,TAM_MICRO,listaTipo,TAM_TIPO,listaEmpresa,TAM_EMPRESA))
                     {
                        printf("Error, baja sin efecto\n");
                     }
                     else
                     {
                        contadorMicro--;
                     }
                }
                break;
            case 'd':
                ordenarMicros(listaMicro,TAM_MICRO,listaEmpresa,TAM_EMPRESA);
                mostrarMicros(listaMicro,TAM_MICRO,listaTipo,TAM_TIPO,listaEmpresa,TAM_EMPRESA);
                break;
            case 'e':
                if(!mostrarEmpresas(listaEmpresa,TAM_EMPRESA))
                {
                    printf("Error,no se pudo mostar la lista\n");
                }
                break;
            case 'f':
                 if(!mostrarTipo(listaTipo,TAM_TIPO))
                 {
                    printf("Error,no se pudo mostar la lista\n");
                 }
                break;
            case 'g':
                if(!mostrarDestino(listaDestino,TAM_DESTINO))
                {
                    printf("Error,no se pudo mostar la lista \n");
                }
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
