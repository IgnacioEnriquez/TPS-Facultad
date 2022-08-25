#ifndef MOTOS_H_INCLUDED
#define MOTOS_H_INCLUDED


typedef struct
{
    int id;
    char marca[128];
    float precio;
    int anio;
}eMoto;

/** brief Guarda una nueva moto en la memoria dinamica con espacios vacios
 *
 *
 *
 * return moto guardado en memoria dinamica
 */
eMoto* moto_new();
/** brief Se le asignan los parametros tipo string
 *
 *	param id tipo string
 *	param marca
 *	param anio tipo string
 *	param precio tipo string
 *
 *  return
 */
eMoto* moto_newParametros(char* idStr,char* marcaStr,char* anio,char* precio);
/** \brief Menu de opciones del main
 *
 *
 */
int menu();
/** brief setea el precio a un moto
 *
 * param moto
 * param precio a setear
 *
 * return si todo esta ok 0, si no 1
 *
 */
int moto_setPrecio(eMoto* moto,float precio);
/** brief setea las el anio de  una moto
 *
 * param moto
 * param anio
 *
 * return si todo esta ok 0, si no 1
 *
 */
int moto_setAnio(eMoto* moto,int anio);
/** brief setea la marca a una moto
 *
 * param moto
 * param marca a setear
 *
 * return si todo esta ok 0, si no 1
 *
 */
int moto_setMarca(eMoto* moto,char* marca);
/** brief setea el id a una moto
 *
 * param moto
 * param id a setear
 *
 * return si todo esta ok 0, si no 1
 *
 */
int moto_setId(eMoto* moto,int id);
/** brief obtener el id de un moto
 *
 * param moto
 * param id en el que se va a guardar el id obtenido
 *
 * return si todo esta ok 0, si no 1
 *
 */
int moto_getId(eMoto* moto,int* id);
/** brief obtener la marca de una moto
 *
 * param moto
 * param marca en el que se va a guardar la marca obtenida
 *
 * return si todo esta ok 0, si no 1
 *
 */

int moto_getMarca(eMoto* moto,char* marca);
/** brief obtener el anio de un moto
 *
 * param moto
 * param parametro en el que se va a guardar el marca obtenido
 *
 * return si todo esta ok 0, si no 1
 *
 */
int moto_getAnio(eMoto* moto,int* anio);
/** brief obtener el precio de un moto
 *
 * param moto
 * param parametro en el que se va a guardar el precio
 *
 * return si todo esta ok 0, si no 1
 *
 */
int moto_getPrecio(eMoto* moto,float* precio);
/** brief compara IDs para usar en el alta, baja y modificar
 *
 * param lista Linkedlist*
 * param id a comparar dentro de la funcion con un auxiliar
 *
 * return indice del motos
 *
 */
int compararIdMotos(LinkedList* pArrayListMotos,int id);
/** \brief Muestra los motos
 *
 * \param  LinkedList* lista
 * \return int
 *
 */
int mostrarMotos(LinkedList* pArrayListMotos);
/** \brief Muestra una solo moto
 *
 * \param  LinkedList* lista
 * \return int
 *
 */
int mostrarMoto( eMoto* moto);
/** \brief Menu de opciones de modificaciones
 *
 *
 */
int menuModificacion();
/** \brief Permite elegir las modificaciones
 *
 *
 * \param
 */
void elegirModificacion(eMoto* aux);
/** brief ordenar dos motos por Marca
 *
 * param moto x
 * param moto y
 *
 * return si todo esta ok 0, si no 1
 *
 */
int sortMotoMarca(void* x, void* y);
#endif // MOTOS_H_INCLUDED
