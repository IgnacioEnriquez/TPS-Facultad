#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}Employee;

#include "ABM.h"
#include "Funciones.h"
#include "Menus.h"
#endif // ARRAYEMPLOYEES_H_INCLUDED


/**
 *@brief Funciona para indicar que todas las posiciones del Array estan vacias,
 * esta funcion pone la bandera (IsEmpty) en 1(Verdadero)en todas
 * las posiciones del Array
 *
 *@param list Employee* Puntero a un Array de empleados
 *@param len Tamaño del Array
 *
 *@return int Devuelve (-1) Si ocurre un error [Tamaño invalido o puntero en NULL] - (0) Si esta todo correcto
 *
 */
int initEmployees(Employee* list, int len);

/**
 * @brief Agrega en la lista de empleados ya existente,los valores recibidos en los parametros,
 * en la primera posicion vacia
 *
 *@param list employee* Array de empleados
 *@param len int Tamaño del Array
 *@param id int ID a Agregar
 *@param name[] char Nombre a Agregar
 *@param lastName[] char Apellido a Agregar
 *@param salary float Salario a Agregar
 *@param sector int Sector a Agregar
 *
 *@return int Retorna (-1) Si ocurre un error [Tamaño invalido o Puntero NULL o No hay espacio
 * libre] - (0) Si esta todo correcto
 *
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/**
*@brief Busca un espacio vacio en una lista de empleados y retorna el lugar,si esta
* vacio retorna -1
*
*@param Lista de empleados
*@param Tamaño de la lista
*
*@return retorna -1 si no encuentra lugar,sino retorna el lugar encontrado
*
*/
int findEmpty(Employee* list,int len);

/**
 *@brief Busca un empleado por su ID y retorna el indice de posicion en el Array.
 *
 *@param list Employee* Array de empleados
 *@param len int Tamaño del Array
 *@param id int Id a busar
 *
 *@return Retorna el indice de la posicion del empleado o (-1) si [Tamaño invalido o Puntero
 *NULL recibido o el empleado no es encontrado]
 *
 */
int findEmployeeById(Employee* list, int len,int id);

/**
 *@brief Elimina un empleado por su ID (Pone la bandera isEmpty Flag en 1)
 *
 *@param list Employee* Array de Empleados
 *@param len int Tamaño del Array
 *@param id int Id a Eliminar
 *
 *@return int Retorna (-1) Si ocurre un error [Tamaño invalido o Puntero NULL o No se puede encontrar
 el empleado] - (0) Si todo esta correcto
 *
 */
int removeEmployee(Employee* list, int len, int id);

/**
 *@brief Ordena los elementos del Array de empleados, el argumento "order"
 * indica si el orden es ascendente o descendente.
 *
 *@param list Employee* Array de empleados
 *@param len int Tamaño del Array
 *@param order int [1] indica Ascendente - [0] indica Descendente
 *
 *@return int Retorna (-1) Si ocurre un Error [Tamaño invalido o Puntero NULL] - (0) Si todo esta correcto
 *
 */
int sortEmployees(Employee* list, int len, int order);

/**
 *@brief Muestra el contenido de un array de empleados
 *
 *@param list Employee* Array de empleados
 *@param length int Tamaño del Array
 *
 *@return int un entero
 *
 */
int printEmployees(Employee* list, int length);
