#ifndef CHOFER_H_INCLUDED
#define CHOFER_H_INCLUDED

typedef struct
{
    int idChofer;
    char nombre[51];
    char sexo;

}eChofer;

int cargarNombreChofer(eChofer lista[], int tamChofer, int idChofer, char nombre[]);


#endif // CHOFER_H_INCLUDED
