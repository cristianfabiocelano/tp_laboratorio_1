#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

int obtenerEspacioLibre(EPersona lista[], int TAM)
{
    int indice=-1;
    int i;
    for(i=0; i<TAM; i++)
    {
        if(lista[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

void inicioEstado(EPersona persona[], int TAM)
{
    int i;
    for(i=0; i<TAM; i++)
    {
        persona[i].estado=0;
    }
    return;
}

int buscarPorDni(EPersona persona[], int TAM, int dni)
{
    int i;
    int indice=-1;
    for(i=0; i<TAM; i++)
    {
        if(persona[i].dni==dni && persona[i].estado==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

void altaPersona(EPersona persona[], int TAM)
{
    int indice;
    char dniStr[20];
    int nombreInt;
    char edadStr[20];
    int DNI;
    int esta;


    indice=obtenerEspacioLibre(persona,TAM);
    if(indice!=-1)
    {
        system("cls");
        printf("\nIngrese DNI: ");
        fflush(stdin);
        gets(dniStr);
        DNI=validarEntero(dniStr);
        DNI=reingresoInt(dniStr,DNI);

        esta= buscarPorDni(persona,TAM,DNI);
        if(esta!=-1)
        {
            system("cls");
            printf("esta persona ya esta registrada\n");
            system("pause");
        }
        else
        {
            persona[indice].dni=DNI;

            system("cls");
            printf("\nIngrese nombre: ");
            fflush(stdin);
            gets(persona[indice].nombre);
            nombreInt=validarCadena(persona[indice].nombre);
            reingresoStr(persona[indice].nombre,nombreInt);

            system("cls");
            printf("\nIngrese edad: ");
            fflush(stdin);
            gets(edadStr);
            persona[indice].edad=validarEntero(edadStr);
            persona[indice].edad=reingresoInt(edadStr,persona[indice].edad);


            persona[indice].estado=1;
        }
    }
    else
    {
        system("cls");
        printf("no hay mas espacio\n");
        system("pause");

    }

}

void bajaPersona(EPersona persona[], int TAM)
{
    int DNI;
    char dniStr[20];
    int indice;
    int flagBorrar=1;
    int confirmar;

    system("cls");
    printf("\nIngrese el DNI que desea borrar: \n");
    fflush(stdin);
    gets(dniStr);

    DNI=validarEntero(dniStr);
    DNI=reingresoInt(dniStr,DNI);

    indice=buscarPorDni(persona,TAM,DNI);

    if(indice!=-1)
    {
        while(flagBorrar)
        {
            system("cls");
            printf("\n-------------------\n");
            printf("DNI: %u\nNombre: %s\nEdad: %d\n",persona[indice].dni,persona[indice].nombre,persona[indice].edad);
            printf("-------------------\n");
            printf("\nEsta seguro? \n");
            printf("(s/n)\n");
            fflush(stdin);
            confirmar=getche();

            switch(confirmar)
            {
            case 's':
                persona[indice].estado=0;
                system("cls");
                printf("\nPerfil borrado con exito!!\n");
                flagBorrar=0;
                system("pause");
                break;
            case'n':
                system("cls");
                printf("\nDecidio no eliminar este perfil\n");
                flagBorrar=0;
                system("pause");
                break;
            }
        }
    }
    else
    {
        system("cls");
        printf("\nEsta persona no esta registrada\n");
        system("pause");
    }
}

void ordenarPorNombre(EPersona persona[], int TAM)
{
    int i;
    int j;
    int auxInt;
    char aux[50];

    for(i=0; i<TAM-1; i++)
    {
        for(j=i+1; j<TAM; j++)
        {
            if (persona[i].estado==1&&persona[j].estado==1)
            {
                if(strcmp(persona[i].nombre,persona[j].nombre)>0)
                {
                    strcpy(aux,persona[i].nombre);
                    strcpy(persona[i].nombre,persona[j].nombre);
                    strcpy(persona[j].nombre,aux);

                    auxInt=persona[i].edad;
                    persona[i].edad=persona[j].edad;
                    persona[j].edad=auxInt;

                    auxInt=persona[i].dni;
                    persona[i].dni=persona[j].dni;
                    persona[j].dni=auxInt;
                }
            }
        }
    }
    system("cls");
    for(i=0; i<TAM; i++)
    {
        if(persona[i].estado==1)
        {

            printf("\n----------\n");
            printf("DNI: %u\nNombre: %s\nEdad: %d\n",persona[i].dni,persona[i].nombre,persona[i].edad);
            printf("\n----------\n");

        }
    }
    system("pause");
}

int validarCadena(char palabra[50])
{
    int cant;
    int i=0;
    int flag=0;
    cant=strlen(palabra);
    while(i<cant&&flag==0)
    {
        if(isalpha(palabra[i])!=0)
        {
            i++;
        }
        else
        {
            flag=1;
        }
    }
    return flag;

}

int validarEntero(char numerostr[50])
{
    int cant;
    int i=0;
    int flag=0;

    cant=strlen(numerostr);
    while(i<cant&&flag==0)
    {
        if(isdigit(numerostr[i])!=0)
        {
            i++;
        }
        else
        {
            flag=-1;
        }

    }
    if(flag==0)
    {
        flag=atoi(numerostr);
    }
    return flag;
}

void reingresoStr(char nombre[50], int valor)
{
    while(valor==1)
    {
        system("cls");
        printf("ERROR!!\nPalabra invalida!!\n\nReingrese: ");
        fflush(stdin);
        gets(nombre);
        valor=validarCadena(nombre);
    }
}

int reingresoInt(char numerostr[50], int numeroInt)
{
    while(numeroInt==-1)
    {
        system("cls");
        printf("ERROR!!\nNumero invalido!!\n\nReingrese: ");
        fflush(stdin);
        gets(numerostr);
        numeroInt=validarEntero(numerostr);
    }
    return numeroInt;
}

void dividirEdades(EPersona persona[], int TAM, int contEdad[3])
{
    int i;

    for(i=0; i<3; i++)
    {
        contEdad[i]=0;
    }
    for(i=0; i<TAM; i++)
    {
        if(persona[i].estado==1)
        {

            if(persona[i].edad<18)
            {
                contEdad[0]=contEdad[0]+1;
            }
            else if(persona[i].edad>35)
            {
                contEdad[2]=contEdad[2]+1;
            }
            else
            {
                contEdad[1]=contEdad[1]+1;
            }
        }
    }
}

int buscarMax(int contador[], int tam)
{
    int i=0;
    int max;
    int flag=0;
    for(i=0; i<tam; i++)
    {
        if(flag==0||contador[i]>max)
        {
            max=contador[i];
            flag=1;
        }
    }
    return max;
}

void graficoVertical(EPersona persona[], int TAM)
{
    int j;
    int edades[3];
    int i;
    int max;

    dividirEdades(persona,TAM,edades);
    max=buscarMax(edades,3);

    system("cls");

    printf("\n\n\n\n\n");
    printf("---------------------------------------\n\n");
    for(i=max; i>0; i--)
    {
        for(j=0; j<3; j++)
        {
            if(edades[j]>=i)
            {
                printf("\t *");
            }
            else
            {
                printf("\t  ");
            }
        }
        putchar('\n');
    }

    printf("\t<18    18-35\t>35");
    printf("\n\n---------------------------------------\n\n");

    system("pause");
}
