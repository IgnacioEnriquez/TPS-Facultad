#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



#endif // FUNCIONES_H_INCLUDED

#include "ArrayEmployees.h"
#include "ABM.h"
#include "Menus.h"


/**
 *@brief Permite elegir un sector validado,y devuelve
 * dicho sector elegido
 *
 *@return El sector elegido
 */
int elegirSector();

/**
 *@brief Permite elegir si se desea ordenar
 * de forma ascendente o descendente los empleados
 * y el sector
 *
 *@param Array de empleados
 *@param Tamaño del Array
 *
 */
void elegirOrdenamiento(Employee* list,int length);

/**
 * @brief Valida que lo ingresado sea un numero flotante. Cuenta los puntos (que sea solo uno)
 * y valida todas las posiciones de la cadena.
 *
 * @param Cadena donde se guardara el numero flotante validado
 *
 * @return Retorna 0 si la cadena es de numeros y un solo punto (o sin punto), -1 si no.
 */
int isFloat(char* pAux);

/**
 * @brief Valida que el numero ingresado sea un numero flotante
 *
 * @param Puntero a la variable float donde se cargaria el numero validado.
 * @param Numero de reintentos
 * @param Mensaje
 * @param Mensaje de error
 * @param Minimo numero a ingresar
 * @param Maximo numero a ingresar
 *
 * @return 0 si tuvo exito, y -1 si no.
 */
int utn_getFlotante(float* pFloat,int retry, char* msg, char*msgError, float min, float max);

/**
 * @brief Se encarga de pasar la cadena validada a flotante.
 *
 * @param Puntero donde escribir el resultado de la validacion.
 *
 * @return Retorna 0 si tuvo exito, -1 si no.
 */
int getFloat(float*pAux);

/**
 * @brief Recorre la cadena validando que cada posicion sea un numero (0 - 9)
 *
 * @param Cadena a cargar el numero validado
 *
 * @return Retorna 0 si logra validar, o -1 si no.
 */
int isInt(char *pAux);

/**
 * @brief Llama a getInt y a isCadena para validar que lo ingresado es un numero entero y pasa la cadena a integer.
 *
 * @param Puntero a variable a cargar el numero validado.
 *
 * @return Retorna 0 si logra validar, o -1 si no.
 */
int getInt(int* pAux);

/**
 * @brief Envia un mensaje y valida que lo ingresado sea un numero entero.
 *
 * @param Puntero a donde se cargara lo validado.
 * @param Numero de reintentos
 * @param Mensaje
 * @param Mensaje de error
 * @param Minimo numero a ingresar
 * @param Maximo numero a ingresar
 *
 * @return 0 si tuvo exito, y -1 si no
 */
int utn_getEntero(int* pEntero, int retry, char* msg, char*msgError, int min, int max);

/**
 * @brief Toma la cadena ingresada y le quita el '\n' al fgets.
 *
 * @param Puntero a  char en la que se va a cargar la cadena validada.
 *
 * @return 0 si tuvo exito, y -1 si no.
 */
int getCadena(char* pAux, int limit);

/**
 * @brief Valida que se ingrese un array de caracteres
 *
 * @param Puntero a variable char en la que se cargara la cadena validada.
 * @param Limite de caracteres que se pueden ingresar
 * @param Numero de reintentos
 * @param Mensaje a mostrar
 * @param Mensaje en caso de error
 * @return 0 si tuvo exito, y -1 si no.
 */
int utn_getCadena(char *pAux, int limit, int retry, char* msg, char* msgError);

/**
 * @brief Permite elegir el ordenamiento que se desea mostrar(Sueldo o Ascendente/Descendente)
 *
 * @param Array de empleados que ordenar
 * @param Tamaño del Array
 *
 */
void informes(Employee* list,int length);

/**
 * @brief Muestra el total de sueldos,el promedio de sueldos y los empleados
 * que superaron ese promedio.
 *
 * @param Array de empleados a analizar
 * @param Tamaño del Array
 *
 */
void ordenamientoSalario(Employee* list,int length);

/**
 * @brief Muestra el empleado guardado en la estructura Employee
 *
 * @param Empleado que se desea mostrar
 *
 */
void mostrarEmpleado(Employee list);

