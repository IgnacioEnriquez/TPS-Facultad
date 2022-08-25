#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



#endif // FUNCIONES_H_INCLUDED

/** \brief Muestra los resultados de las operaciones
 *
 * \param Resultado de la suma
 * \param Resultado de la resta
 * \param Resultado de la multiplicacion
 * \param Resultado del factorial 1
 * \param Resultado del factorial
 *
 */
void resultados(float a,float b,float c,float d,float e);

/** \brief Muestra en pantalla las opciones de la calculadora
 *
 * \param 1er operando elegido
 * \param 2do operando elegido

 * \return Opcion elegida por el usuario
 *
 */
int opcionesCalc(float a,float b);

/** \brief Pide un numero con el mensaje pedido
 *
 * \param Mensaje elegido para pedir el numero
 *
 * \return Numero ingresado
 *
 */
float ingresarNum(char a[30]);

/** \brief Muestra un mensaje para pedir una letra,valida 2 char y muestra un mensaje en caso de no ingresar letra elegida,returna 1 de las 2 opciones
 *
 * \param Mensaje elegido para pedir una letra
 * \param Mensaje en caso de no elegir la letra correcta
 * \param opcion 1 de letra correcta
 * \param opcion 2 de letra correcta
 *
 * \return
 *
 */

char validacion(char frase[50],char fraseError[50],char a,char b);
