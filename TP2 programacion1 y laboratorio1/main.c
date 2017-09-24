#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"
#define TAM 20

int main()
{
    EPersona persona[TAM];
    char seguir='s';
    int opcion=0;

    inicioEstado(persona,TAM);

    while(seguir=='s')
    {
        system("cls");
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            altaPersona(persona,TAM);
            break;

        case 2:
            bajaPersona(persona,TAM);
            break;

        case 3:
            ordenarPorNombre(persona,TAM);
            break;

        case 4:
            graficoVertical(persona,TAM);
            break;

        case 5:
            seguir = 'n';
            break;
        }
    }
    return 0;
}
