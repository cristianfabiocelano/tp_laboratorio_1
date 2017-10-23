#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 50


int main()
{
    EMovie movie[TAM];
    char seguir='s';
    int opcion=0;
    int cant;
    int i;
    FILE* arch;
    inicioEstado(movie,TAM);

    while(seguir=='s')
    {

        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula.\n");
        printf("4- Generar pagina web\n");
        printf("\n0- SALIR.\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
    case 1:

            if ((arch=fopen("movies", "ab")) == NULL)
            {
                 if((arch=fopen("movies", "wb")) == NULL)
                {
                    printf("El archivo no puede ser abierto");
                    exit(1);
                }
                else
                {
                    agregarPelicula(movie,TAM,arch);
                }
            }
            else
            {
                agregarPelicula(movie,TAM,arch);
            }

            break;

    case 2:
            if ((arch=fopen("movies","wb+"))==NULL)
                 if ((arch=fopen("movies","rb+"))==NULL)
            {
                printf("No se encontro el archivo");
                exit(1);
            }
                while(!feof(arch))
                {

                     cant = fread(&movie, sizeof(movie), 1, arch);

                    if(cant != 1)
                    {
                        if(feof(arch))
                            break;
                        else
                        {
                            printf("No leyo el ultimo registro\n");
                            break;
                        }
                    }

                }
            borrarPelicula(movie,TAM,arch);
            break;

    case 3:
            if ((arch=fopen("movies","wb+"))==NULL)
                if ((arch=fopen("movies","rb+"))==NULL)
            {
                printf("No se encontro el archivo");
                exit(1);
            }

                while(!feof(arch))
                {

                     cant = fread(&movie, sizeof(movie), 1, arch);

                    if(cant != 1)
                    {
                        if(feof(arch))
                            break;
                        else
                        {
                            printf("No leyo el ultimo registro\n");
                            break;
                        }
                    }

                }
            modificarPelicula(movie,TAM,arch);
            fclose(arch);
            break;

    case 4:
            if ((arch=fopen("index.html","w+"))==NULL)
                if ((arch=fopen("index.html","r+"))==NULL)
            {
                printf("No se encontro el archivo");
                exit(1);
            }

                while(!feof(arch))
                {
                    for(i=0;i<TAM;i++)
                    {
                    cant = fread(&movie[i], sizeof(movie[i]), 1, arch);

                    if(cant != 1)
                    {
                        if(feof(arch))
                            break;
                        else
                        {
                            printf("No leyo el ultimo registro\n");
                            break;
                        }
                    }
                    }
                }
            for(i=0;i<TAM;i++)
            {
                if(movie[i].estado==1)
                fprintf(arch,"<article class='col-md-4 article-intro'> <a href='#'> <img class='img-responsive img-rounded' src='%s'alt=''>                </a>                <h3>                    <a href='#'>%s</a>                </h3> <ul> <li>Género:%s</li> <li>Puntaje:%d</li> <li>Duración:%d</li> </ul>                <p>%s</p> </article>",movie[i].linkImagen, movie[i].titulo, movie[i].genero, movie[i].puntaje, movie[i].duracion,movie[i].descripcion );
            }
            break;
    case 0:
            seguir = 'n';
            fclose(arch);
            break;
        }
    }


    return 0;
}
