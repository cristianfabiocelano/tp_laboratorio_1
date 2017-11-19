#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
/** \brief permite el ingreso de un numero por pantalla
 *
 * \param variable en la cual se va a guardar el numero
 * \return un numero flotante
 *
 */
float ingreso(float);

/** \brief muestra un numero flotante por pantalla
 *
 * \param variable flotante que se quiere mostrar
 * \return -
 *
 */
void mostrarInt(long long int);

/** \brief muestra un numero entero por pantalla
 *
 * \param variable entero que se quiere mostrar
 * \return -
 *
 */
void mostrarFloat(float);

/** \brief suma dos variables flotantes
 *
 * \param primer numero flotante que se quiere sumar
 * \param segundo numero flotante que se quiere sumar
 * \return resultado de la suma
 *
 */
float sumar(float, float);

/** \brief resta dos numeros flotantes
 *
 * \param primer numero flotante es el minuendo
 * \param segundo numero flotante es el sustraendo
 * \return resultado de la resta
 *
 */
float restar (float, float);

/** \brief multiplica dos numeros flotantes
 *
 * \param primer numero flotante a multiplicar
 * \param segundo numero flotante a multiplicar
 * \return resultado de la multiplicacion
 *
 */
float multiplicar (float, float);

/** \brief divide dos numeros flotantes
 *
 * \param primer numero flotante tomado como dividendo
 * \param segundo numero flotante tomado como divisor
 * \return resultado de la division
 *
 */
float dividir (float, float);

/** \brief factorea un numero entero
 *
 * \param numero entero a factorear
 * \return resultado del factoreo
 *
 */
long long int factorial (long long int);

/** \brief valida una divicion impidiendo que el divisor ingresados sea 0
 *
 * \param numero flotante a validar
 * \return -1 si el numero es 0
 * \return 0 si el numero es 0
 *
 */
float validarDivicion(float);

/** \brief calida que el numero a factorear no sea negativo
 *
 * \param numero entero a validar
 * \return -1 si el numero es menor que 0
 * \return 0 si el numero es mayor o igual a 0
 *
 */
int validarFactorial (float);

/** \brief Valida un entero pasado como cadena.
 *
 * \param Entero a validar como cadena.
 * \return Numero entero validado.
 *
 */
int validarEntero(char[]);
#endif // FUNCIONES_H_INCLUDED
