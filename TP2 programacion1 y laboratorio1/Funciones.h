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

/** \brief Valida un entero pasado como cadena.
 *
 * \param Entero a validar como cadena.
 * \return Numero entero validado.
 *
 */
int validarEntero(char[]);

/** \brief Valida una cadena de char.
 *
 * \param Cadena a validar.
 * \return -
 *
 */
void validarCadena(char[]);
#endif // FUNCIONES_H_INCLUDED
