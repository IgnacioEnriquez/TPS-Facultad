#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED


#include "Funciones.h"
#include "ArrayEmployees.h"
#include "ABM.h"
#endif // MENUS_H_INCLUDED

/**
 * @brief Muestra las opciones del menu de modificaciones y pide
 * que se ingrese una opcion
 *
 * @return Retorna la opcion elegida
 */
int menuModificacion();

/**
 * @brief Muestra las opciones del menu de ordenamientos(informes) y pide
 * que se ingrese una opcion
 *
 * @return Retorna la opcion elegida
 */
int menuInformes();

/**
 * @brief Muestra las opciones de ordenamiento alfabetico y pide
 * que se ingrese una opcion
 *
 * @return Retorna la opcion elegida
 */
int menuAscODesc();

/**
 * @brief Muestra las opciones del menu principal y pide que
 * se ingrese una opcion
 *
 * @return Retorna la opcion elegida
 */
int menu();

/**
 * @brief Muestra las opciones del menu de sectores y pide que
 * se ingrese una opcion
 *
 * @return Retorna la opcion elegida
 */
int menuSector();
