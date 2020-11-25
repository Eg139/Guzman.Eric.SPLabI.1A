/** \brief Carga los datos de las bicicletas desde el archivo bicicletas.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListBicis LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListBicis);

/** \brief Listar bicis
 *
 * \param path char*
 * \param pArrayListBicis LinkedList*
 * \return int
 *
 */
int controller_ListBicis(LinkedList* pArrayListBicis);

/** \brief Ordenar las bicis
 *
 * \param path char*
 * \param pArrayListBicis LinkedList*
 * \return int
 *
 */
int controller_sortBicis(LinkedList* pArrayListBicis);

/** \brief Guarda los datos de las bicis en el archivo listaFiltrada.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListBicis LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListBicis);

/** \brief Menu para elegir como filtrar el archivo
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_MenuFilter(LinkedList* pArrayListEmployee);
