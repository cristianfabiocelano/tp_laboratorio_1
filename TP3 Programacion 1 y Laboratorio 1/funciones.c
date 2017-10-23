#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"
void agregarPelicula(EMovie movie[],int TAM,FILE*arch)
{
    int indice;
    char strAux[50];
    char titulo[50];
    int esta;


    indice=obtenerEspacioLibre(movie,TAM);
    if(indice!=-1)
    {
        system("cls");
        printf("\nIngrese el Titulo de la pelicula: ");
        fflush(stdin);
        gets(titulo);

        esta= buscarPorNombre(movie,TAM,titulo);
        if(esta!=-1)
        {
            system("cls");
            printf("esta pelicula ya fue registrada\n");
            system("pause");
        }
        else
        {
            strcpy(movie[indice].titulo,titulo);

            system("cls");
            printf("\nIngrese el genero de la pelicula: ");
            fflush(stdin);
            gets(movie[indice].genero);
            validarCadena(movie[indice].genero);

            system("cls");
            printf("\nIngrese duracion de la pelicula: ");
            fflush(stdin);
            gets(strAux);
            movie[indice].duracion=validarEntero(strAux);

            system("cls");
            printf("\nIngrese la descripcion de la pelicula: ");
            fflush(stdin);
            gets(movie[indice].descripcion);

            system("cls");
            printf("\nIngrese el puntaje de la pelicula: ");
            fflush(stdin);
            gets(strAux);
            movie[indice].puntaje=validarEntero(strAux);
            system("cls");

            printf("\nIngrese el link de la imagen la pelicula: ");
            fflush(stdin);
            gets(movie[indice].linkImagen);

            movie[indice].estado=1;

            fseek(arch,(long)sizeof(movie),SEEK_END);
            fwrite(&movie[indice], sizeof(movie[indice]), 1, arch);
        }
    }
    else
    {
        system("cls");
        printf("no hay mas espacio\n");
        system("pause");

    }

}

void borrarPelicula(EMovie movie[],int TAM,FILE*arch)
{

    char titulo[20];
    int indice;
    int flagBorrar=1;
    char confirmar;
    system("cls");
    printf("\nIngrese el titulo que desea borrar: \n");
    fflush(stdin);
    gets(titulo);

    indice=buscarPorNombre(movie,TAM,titulo);

    if(indice!=-1)
    {
        while(flagBorrar)
        {
            system("cls");
            printf("\n-------------------\n");
            printf("\n%s\n\n\t%s\nDuracion:\n\t%d\n\t%s\n\tPts del filme:%d\n\t%s\n", movie[indice].titulo, movie[indice].genero, movie[indice].duracion, movie[indice].descripcion, movie[indice].puntaje, movie[indice].linkImagen);
            printf("-------------------\n");
            printf("\nEsta seguro? \n");
            printf("(s/n)\n");
            fflush(stdin);
            confirmar=getche();

            switch(confirmar)
            {
            case 's':
                movie[indice].estado=0;


                    if((arch=fopen("movies", "wb")) == NULL)
                    {
                        printf("Error al querer borrar.");
                    }
                    else
                    {
                            if(movie[indice].estado==1)
                            {
                            fseek(arch,(long)(-1)*sizeof(movie),SEEK_CUR);
                            fwrite(&movie[indice], sizeof(movie[indice]), 1, arch);
                            }
                            system("cls");
                            printf("\nPerfil borrado con exito!!\n");

                    }

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
            printf("\nEsta pelicula no esta registrada\n");
            system("pause");
        }
    }

void modificarPelicula(EMovie movie [],int TAM,FILE*arch)
{
    char titulo[50];
    char strAux[50];
    int indice;
    int flagBorrar=1;
    int confirmar;
    system("cls");
    printf("\nIngrese el titulo que desea modificar: \n");
    fflush(stdin);
    gets(titulo);

    indice=buscarPorNombre(movie,TAM,titulo);

    if(indice!=-1)
    {
        while(flagBorrar)
        {
            system("cls");
            printf("\n-------------------\n");
            printf("\n%s\n\n\t%s\nDuracion:\n\t%d\n\t%s\n\tPts del filme:%d\n\t%s\n", movie[indice].titulo, movie[indice].genero, movie[indice].duracion, movie[indice].descripcion, movie[indice].puntaje, movie[indice].linkImagen);
            printf("-------------------\n");
            printf("\nSeleccione la modificacion que desea realizar:\n");
            printf("1-Titulo.\n2-Genero.\n3-Duracion.\n4-Descripcion.\n5-Puntaje.\n6-Link.\n0-Cancelar modificacion.");
            scanf("%d",&confirmar);

            switch(confirmar)
            {
                case 1:
                            if(movie[indice].estado==1)
                            {
                            system("cls");
                            printf("Ingrese el nuevo titulo: ");
                            fflush(stdin);
                            gets(strAux);

                            strcpy(movie[indice].titulo, strAux);

                            fseek(arch,(long)(-1)*sizeof(movie),SEEK_CUR);
                            fwrite(&movie[indice], sizeof(movie[indice]), 1, arch);

                            system("cls");
                            printf("\nPerfil modificado con exito!!\n");
                            }
                            else
                            {
                                printf("el perfil ah sido dado de baja anteriormente");
                            }


                    flagBorrar=0;
                    system("pause");
                    break;

               case 2:
                            if(movie[indice].estado==1)
                            {
                            system("cls");
                            printf("Ingrese el nuevo genero: ");
                            fflush(stdin);
                            gets(strAux);

                            strcpy(movie[indice].genero, strAux);

                            fseek(arch,(long)(-1)*sizeof(movie),SEEK_CUR);
                            fwrite(&movie[indice], sizeof(movie[indice]), 1, arch);

                            system("cls");
                            printf("\nPerfil modificado con exito!!\n");
                            }
                            else
                            {
                                printf("el perfil ah sido dado de baja anteriormente");
                            }


                    flagBorrar=0;
                    system("pause");
                    break;

            case 3:
                            if(movie[indice].estado==1)
                            {
                            system("cls");
                            printf("Ingrese la nueva duracion: ");
                            fflush(stdin);
                            scanf("%d",&movie[indice].duracion);

                            fseek(arch,(long)(-1)*sizeof(movie),SEEK_CUR);
                            fwrite(&movie[indice], sizeof(movie[indice]), 1, arch);

                            system("cls");
                            printf("\nPerfil modificado con exito!!\n");
                            }
                            else
                            {
                                printf("el perfil ah sido dado de baja anteriormente");
                            }

                    flagBorrar=0;
                    system("pause");
                    break;

                case 4:
                            if(movie[indice].estado==1)
                            {
                            system("cls");
                            printf("Ingrese la nueva descripcion: ");
                            fflush(stdin);
                            gets(strAux);

                            strcpy(movie[indice].descripcion, strAux);

                            fseek(arch,(long)(-1)*sizeof(movie),SEEK_CUR);
                            fwrite(&movie[indice], sizeof(movie[indice]), 1, arch);

                            system("cls");
                            printf("\nPerfil modificado con exito!!\n");
                            }
                            else
                            {
                                printf("el perfil ah sido dado de baja anteriormente");
                            }

                    flagBorrar=0;
                    system("pause");
                    break;

                case 5:
                            if(movie[indice].estado==1)
                            {
                            system("cls");
                            printf("Ingrese el nuevo puntaje: ");
                            fflush(stdin);
                            scanf("%d",&movie[indice].puntaje);

                            fseek(arch,(long)(-1)*sizeof(movie),SEEK_CUR);
                            fwrite(&movie[indice], sizeof(movie[indice]), 1, arch);

                            system("cls");
                            printf("\nPerfil modificado con exito!!\n");
                            }
                            else
                            {
                                printf("el perfil ah sido dado de baja anteriormente");
                            }

                    flagBorrar=0;
                    system("pause");
                    break;

            case 6:
                            if(movie[indice].estado==1)
                            {
                            system("cls");
                            printf("Ingrese el nuevo link: ");
                            fflush(stdin);
                            gets(strAux);

                            strcpy(movie[indice].linkImagen, strAux);

                            fseek(arch,(long)(-1)*sizeof(movie),SEEK_CUR);
                            fwrite(&movie[indice], sizeof(movie[indice]), 1, arch);

                            system("cls");
                            printf("\nPerfil modificado con exito!!\n");
                            }
                            else
                            {
                                printf("el perfil ah sido dado de baja anteriormente");
                            }

                    flagBorrar=0;
                    system("pause");
                    break;

                case 0:
                    system("cls");
                    printf("\nDecidio no modificar este perfil\n");
                    flagBorrar=0;
                    system("pause");
                    break;
                }
            }
        }
        else
        {
            system("cls");
            printf("\nEsta pelicula no esta registrada\n");
            system("pause");
        }
    }

    int obtenerEspacioLibre(EMovie lista[],int TAM)
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

    int buscarPorNombre(EMovie lista[], int TAM, char Nombre[])
    {
        int i;
        int indice=-1;
        for(i=0; i<TAM; i++)
        {
            if((strcmp(lista[i].titulo,Nombre)==0)&& lista[i].estado==1)
            {
                indice=i;
                break;
            }
        }
        return indice;
    }

    int validarEntero(char numerostr[50])
    {
        int cant;
        int i=0;
        int flag=0;

        do
        {
            if(flag==-1)
            {
                printf("ERROR!!\nNumero invalido!!\n\nReingrese: ");
                fflush(stdin);
                gets(numerostr);
            }

            cant=strlen(numerostr);
            flag=0;
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
        }
        while(flag==-1);

        return flag;
    }

    void validarCadena(char palabra[50])
    {
        int cant;
        int i=0;
        int flag=0;

        do
        {
            if(flag==1)
            {
                printf("ERROR!!!\nReingrese: ");
                fflush(stdin);
                gets(palabra);
            }

            cant=strlen(palabra);
            flag=0;
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
        }
        while(flag==1);
    }

    void inicioEstado(EMovie lista[],int TAM)
    {
        int i;
        for(i=0; i<TAM; i++)
        {
            lista[i].estado=0;
        }
        return;
    }

