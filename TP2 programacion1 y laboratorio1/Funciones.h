#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    unsigned int dni;

}EPersona;

/**\brief Obtiene el primer indice libre del array.
 *
 * @param lista el array se pasa como parametro.
 * @param tamaño del array.
 * @return el primer indice disponible.
 *
 */
int obtenerEspacioLibre(EPersona[], int);

/**\brief Obtiene el indice que coincide con el DNI pasado por parametro.
 *
 * @param Lista el array se pasa como parametro.
 * @param DNI a ser buscado en el array.
 * @param Tamaño del array.
 * @return El indice en donde se encuentra el elemento que coincide con el parametro DNI.
 *
 */
int buscarPorDni(EPersona[], int, int);

/** \brief Ordena y muestra los perfiles en estado 1 de manera acendente.
 *
 * \param Lista el array se pasa como parametro.
 * \param Tamaño del array.
 * \return -
 *
 */
void ordenarPorNombre(EPersona[], int);

/** \brief Permite el ingreso de un perfil.
 *
 * \param Lista el array se pasa como parametro.
 * \param Tamaño del array.
 * \return -
 *
 */
void altaPersona(EPersona[], int);

/** \brief Da de baja al perfil asociado con el documento ingresado.
 *
 * \param Lista el array se pasa como parametro.
 * \param Tamaño del array.
 * \return -
 *
 */
void bajaPersona(EPersona[], int);

/** \brief Inicializa todos los estados de los perfiles en 0.
 *
 * \param Lista el array se pasa como parametro.
 * \param Tamaño del array.
 * \return -
 *
 */
void inicioEstado(EPersona[], int);

/** \brief Valida una cadena de char.
 *
 * \param Cadena a validar.
 * \return 1 si la cadena es valida o 0 si la cadena es invalida.
 *
 */
int validarCadena(char[]);

/** \brief Valida un entero.
 *
 * \param Entero a validar tomado como cadena de char.
 * \return 1 si el numero entero es valida o 0 si el numero es invalida.
 *
 */
int validarEntero(char[]);

/** \brief Permite el reingreso de una cadena de char en el caso de que la devolucion de la validacion sea 0.
 *
 * \param Cadena de char a validar.
 * \param Valor que devuelve la anterior validacion.
 * \return -
 *
 */
void reingresoStr(char[], int);

/** \brief Permite el reingreso de una numero entero en el caso de que la devolucion de la validacion sea 0.
 *
 * \param Entero a validar tomado como cadena de char.
 * \param Valor que devuelve la anterior validacion.
 * \return Numero entero validado.
 *
 */
int reingresoInt(char[], int);

/** \brief Divide las edades de los perfiles con estado en 1 en 3 categorias.
 *
 * \param Lista el array se pasa como parametro.
 * \param Tamaño del array.
 * \param Array donde se va aguardar las 3 categorias.
 * \return -
 *
 */
void dividirEdades(EPersona[], int, int[]);

/** \brief Compara los numeros de un array y selecciona el mayor.
 *
 * \param Array que contiene los numeros a comparar.
 * \param Tamaño del array.
 * \return Mayor numero encontrado.
 *
 */
int buscarMax(int[], int);

/** \brief Muestra un array con 3 categorias de edades en un grafico vertical.
 *
 * \param Lista el array se pasa como parametro.
 * \param Tamaño del array.
 * \return -
 *
 */
void graficoVertical(EPersona[], int);
#endif // FUNCIONES_H_INCLUDED
