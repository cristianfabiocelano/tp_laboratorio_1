#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"

int main()
{
    int flagA=0;
    int flagB=0;
    float valiDiv;
    int valiFactorial;
    float A;
    float B;
    float resultadoSuma;
    float resultadoMultiplicacion;
    float resultadoResta;
    float resultadoDivicion;
    long long int resultadoFactorial;
    char seguir='s';
    int opcion=0;
    char opcionChar[30];


    while(seguir=='s')
    {
        if(flagA==1)
        {
        printf("\n1- Ingresar 1er operando (A=%.2f)\n",A);
        }
        else
        {
        printf("\n1- Ingresar 1er operando (A=x)\n");
        }
        if(flagB==1)
        {
        printf("2- Ingresar 2do operando (B=%.2f)\n",B);
        }
        else
        {
        printf("2- Ingresar 2do operando (B=y)\n");
        }
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        gets(opcionChar);
        opcion=validarEntero(opcionChar);

        switch(opcion)
        {
            case 1:
                A=ingreso(A);
                system("cls");
                flagA=1;
                break;
            case 2:
                B=ingreso(B);
                system("cls");
                flagB=1;
                break;
            case 3:
                system("cls");
                printf("\n--------------------\n\n");
                resultadoSuma=sumar(A,B);
                printf("3-");
                mostrarFloat(resultadoSuma);
                printf("--------------------");
                break;
            case 4:
                system("cls");
                printf("\n--------------------\n\n");
                resultadoResta=restar(A,B);
                printf("4-");
                mostrarFloat(resultadoResta);
                printf("--------------------");
                break;
            case 5:
                system("cls");
                valiDiv=validarDivicion(B);
                if(valiDiv==-1)
                {
                printf("\n--------------------\n\n");
                resultadoDivicion=dividir(A,B);
                printf("5-");
                mostrarFloat(resultadoDivicion);
                printf("--------------------");
                break;
                }
                else
                {
                break;
                }
            case 6:
                system("cls");
                printf("\n--------------------\n\n");
                resultadoMultiplicacion=multiplicar(A,B);
                printf("6-");
                mostrarFloat(resultadoMultiplicacion);
                printf("--------------------");
                break;
            case 7:
                system("cls");
                valiFactorial=validarFactorial(A);
                if(valiFactorial==-1)
                {
                printf("\n--------------------\n\n");
                resultadoFactorial=factorial(A);
                printf("7-");
                mostrarInt(resultadoFactorial);
                printf("--------------------");
                break;
                }
                else
                {
                break;
                }
            case 8:
                system("cls");
                resultadoSuma=sumar(A,B);
                resultadoResta=restar(A,B);
                resultadoDivicion=dividir(A,B);
                resultadoMultiplicacion=multiplicar(A,B);
                resultadoFactorial=factorial(A);
                printf("\n--------------------\n");
                printf("\n3-");
                mostrarFloat(resultadoSuma);
                printf("4-");
                mostrarFloat(resultadoResta);
                valiDiv=validarDivicion(B);
                if(valiDiv==-1)
                {
                printf("5-");
                mostrarFloat(resultadoDivicion);
                }
                printf("6-");
                mostrarFloat(resultadoMultiplicacion);
                valiFactorial=validarFactorial(A);
                if(valiFactorial==-1)
                {
                printf("7-");
                mostrarInt(resultadoFactorial);
                }
                printf("--------------------");
                break;
            case 9:
                seguir = 'n';
                break;
        }

    }

    return 0;
}
