#ifndef ABM_H_INCLUDED
#define ABM_H_INCLUDED


#include "ArrayEmployees.h"
#include "Funciones.h"
#include "Menus.h"
#endif // ABM_H_INCLUDED

/** \brief Da de alta un empleado pidiendo Nombre,Apellido,Salario
 * y sector,les asigna un ID automatico
 *
 * \param list Array de empleados
 * \param flag Bandera para validar otras opciones
 * \param length Tamaño del Array
 * \param id ID autoasignable
 */
void altaEmpleado(Employee* list,int* flag,int length,int id);

/** \brief Da de baja[IsEmpty = 1] un empleado pidiendo su ID
 *
 * \param list Array de empleados
 * \param length Tamaño del Array
 */
void bajaEmpleado(Employee* list,int length);

/** \brief Pide el ID de un empleado y da opciones de
 * modificar su Nombre,Apellido,Sector y Salario
 *
 * \param list Array de empleados
 * \param length Tamaño del Array
 */
void modificarEmpleado(Employee* list,int length);
