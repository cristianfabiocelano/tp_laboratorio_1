#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "funcion.h"
float ingreso(float num)
{
    printf("\ningrese el valor: ");
    fflush(stdin);
    scanf("%f",&num);

    return num;
}
void mostrarInt(long long int X)
{
    printf("el resultado es: %lli\n\n",X);
}
void mostrarFloat(float Y)
{
    printf("el resultado es: %.3f \n\n",Y);
}
float sumar(float X, float Y)
{
    float rta;
    rta= X+Y;

    return rta;
}
float restar(float X, float Y)
{
    float rta;
    rta=(float)X-Y;

    return rta;
}
float multiplicar(float X, float Y)
{
    float rta;
    rta=X*Y;

    return rta;
}
float dividir(float X, float Y)
{
    float rta;
    rta=(float)X/Y;

    return rta;
}
long long int factorial(long long int X)
{
    long long int acum=1;
    long long int i;

    for(i=X;i>0;i--)
    {
        acum=acum*i;
    }
    return acum;
}
float validarDivicion(float Y)
{
    int num1 =0;
     while(Y==num1)
    {
        printf("5-no se puede dividir por %d\n\n",num1);

        return num1;
    }
    return -1;
}
int validarFactorial (float X)
{
    int copia=X;
    int num1=0;
    float resultado;

    resultado=X-copia;
    while(X<num1||resultado!=0)
    {
        printf("7-no se puede calcular el factorial");
        if(X<num1)
        {
            printf(" porque el numero es menor a 0\n\n");
        }
        if (resultado!=0)
        {
            printf(" porque el numero no es un numero entero\n\n");
        }
        return 0;
    }

    return -1;
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

