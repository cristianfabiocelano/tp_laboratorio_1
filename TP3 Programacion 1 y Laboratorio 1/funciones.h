#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[500];
    int puntaje;
    char linkImagen[500];
    int estado;
}EMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param estructura a ser agregada al archivo
 *  @param Tamaño del array de peliculas.
 *  @param Puntero del archivo.
 *  @return -
 */
void agregarPelicula(EMovie[],int,FILE*);

/**
 *  Borra una pelicula del archivo binario.
 *  @param Estructura de donde se tomara la pelicula que va a ser eliminada al archivo.
 *  @param Tamaño del array de peliculas.
 *  @param Puntero del archivo.
 *  @return -
 */
void borrarPelicula(EMovie [],int,FILE*);

/**
 *  Borra una pelicula del archivo binario
 *  @param Estructura de donde se tomara la pelicula que va a ser modificada.
 *  @param Tamaño del array de peliculas.
 *  @param Puntero del archivo.
 *  @return -
 */
void modificarPelicula(EMovie [],int,FILE*);

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

/**\brief Obtiene el indice que coincide con el Valor pasado por parametro.
 *
 * @param Lista el array se pasa como parametro.
 * @param Nombre a ser buscado en el array.
 * @param Tamaño del array.
 * @return El indice en donde se encuentra el elemento que coincide con el parametro Nombre.
 *
 */
int buscarPorNombre(EMovie[], int, char[]);

/** \brief Inicializa todos los estados de los perfiles en 0.
 *
 * \param Lista el array se pasa como parametro.
 * \param Tamaño del array.
 * \return -
 *
 */
void inicioEstado(EMovie[],int);

/**\brief Obtiene el primer indice libre del array.
 *
 * @param lista el array se pasa como parametro.
 * @param tamaño del array.
 * @return el primer indice disponible.
 *
 */
int obtenerEspacioLibre(EMovie[],int);
#endif // FUNCIONES_H_INCLUDED

