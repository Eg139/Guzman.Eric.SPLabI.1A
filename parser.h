/** \brief Parsea los datos de las bicicletas desde el archivo bicicletas.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListBicis LinkedList*
 * \return int
 *
 */
int parser_BicisFromText(FILE* pFile , LinkedList* pArrayListBicis);

/** \brief funcion encargada de escribir el contenido de la linked list dentro de un archivo de texto
 *
 * \param pFile FILE*
 * \param pArrayListBicis LinkedList*
 * \return int
 *
 */
int parser_BicisToText(FILE* pFile , LinkedList* pArrayListBicis);
