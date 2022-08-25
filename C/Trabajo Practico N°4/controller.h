#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



/**brief Carga los datos de los motos desde el archivo
 *
 * \param file char*
 * \param pArrayListMotos LinkedList*
 * \return int
 **/
int controller_loadFromText(char* file, LinkedList* pArrayListMotos);
/** \brief Listar motos
 *
 * \param pArrayListMotos LinkedList*
 * \return int
 */

int controller_ListMotos(LinkedList* pArrayListMotos);

/** \brief Alta de motos
 *
 * \param pArrayListMotos LinkedList*
 * \return int
 *
 */
int controller_addMoto(LinkedList* pArrayListMotos);
/** \brief Modificar datos de las motos
 *
 * \param pArrayListMotos LinkedList*
 * \return int
 *
 */
int controller_editMotos(LinkedList* pArrayListMotos);
/** \brief Baja de motos
 *
 * \param pArrayListMotos LinkedList*
 * \return int
 *
 */
int controller_removeMoto(LinkedList* pArrayListMotos);
/** \brief Guarda los datos de las motos en el archivo saveMotos.csv
 *
 * \param file char*
 * \param pArrayListMotos LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* file, LinkedList* pArrayListMotos);
/** \brief Ordenar motos
 *
 * \param pArrayListMotos LinkedList*
 * \return int
 *
 */
int controller_sortMoto(LinkedList* pArrayListMotos);
/** \brief Eliminar todos las motos de la lista
 * \param pArrayListMotos LinkedList*
 * \return int
 *
 */
int controller_deleteAll(LinkedList* pArrayListMotos);
#endif // CONTROLLER_H_INCLUDED
