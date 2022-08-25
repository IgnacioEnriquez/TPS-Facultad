#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** brief Guarda un nuevo empleado en la memoria dinamica con espacios vacios
 *
 *
 *
 * return Empleado guardado en memoria dinamica
 */
Employee* employee_new();

/** brief Se le asignan los parametros tipo string
 *
 *	param id tipo string
 *	param nombre
 *	param horas tipo string
 *	param sueldo tipo string
 *
 *  return
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);

/** brief elimina un empleado de la memoria dinamica
 *
 * param empleado a eliminar
 *
 * return
 */
void employee_delete(Employee* emp);

/** brief setea el id a un empleado
 *
 * param empleado
 * param id a setear
 *
 * return si todo esta ok 0, si no 1
 *
 */

int employee_setId(Employee* emp,int id);

/** brief obtener el id de un empleado
 *
 * param empleado
 * param id en el que se va a guardar el id obtenido
 *
 * return si todo esta ok 0, si no 1
 *
 */
int employee_getId(Employee* emp,int* id);

/** brief setea el nombre a un empleado
 *
 * param empleado
 * param nombre a setear
 *
 * return si todo esta ok 0, si no 1
 *
 */
int employee_setNombre(Employee* emp,char* nombre);

/** brief obtener el nombre de un empleado
 *
 * param empleado
 * param nombre en el que se va a guardar el nombre obtenido
 *
 * return si todo esta ok 0, si no 1
 *
 */
int employee_getNombre(Employee* emp,char* nombre);

/** brief setea las horas trabajadas a un empleado
 *
 * param empleado
 * param horas trabajadas a setear
 *
 * return si todo esta ok 0, si no 1
 *
 */
int employee_setHorasTrabajadas(Employee* emp,int horasTrabajadas);

/** brief obtener las horas trabajadas de un empleado
 *
 * param empleado
 * param parametro en el que se va a guardar el nombre obtenido
 *
 * return si todo esta ok 0, si no 1
 *
 */
int employee_getHorasTrabajadas(Employee* emp,int* horasTrabajadas);

/** brief setear el sueldo a un empleado
 *
 * param empleado
 * param sueldo a setear
 *
 * return si todo esta ok 0, si no 1
 *
 */
int employee_setSueldo(Employee* emp,int sueldo);

/** brief obtener el sueldo de un empleado
 *
 * param empleado
 * param parametro en el que se va a guardar el sueldo
 *
 * return si todo esta ok 0, si no 1
 *
 */
int employee_getSueldo(Employee* emp,int* sueldo);

/** brief ordenar dos empleados por id
 *
 * param empleado x
 * param empleado y
 *
 * return si todo esta ok 0, si no 1
 *
 */
int sortEmployeeId(void* x, void* y);
/** brief ordenar dos empleados por nombre
 *
 * param empleado x
 * param empleado y
 *
 * return si todo esta ok 0, si no 1
 *
 */
int sortEmployeeNombre(void* x, void* y);


/** \brief Menu de opciones del main
 *
 *
 */
int menu();

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
void elegirModificacion(Employee* aux);

/** \brief Muestra un solo empleado
 *
 * \param  LinkedList* lista
 * \return int
 *
 */
int mostrarEmpleado( Employee* emp);


/** \brief Muestra los empleados
 *
 * \param  LinkedList* lista
 * \return int
 *
 */
int mostrarEmpleados(LinkedList* lista);

/** brief comparar IDs para usar en el alta, baja y modificar
 *
 * param lista
 * param id a comparar dentro de la funcion con un auxiliar
 *
 * return indice del empleado
 *
 */
int compararIdEmpleado(LinkedList* pArrayListEmployee,int id );

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos);

int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo,char maximo, int reintentos);

int utn_getCadena(char *pAux, int limit, int retry, char* msg, char* msgError);

int utn_getFlotante(float* pFloat, int retry, char* msg, char*msgError, float min, float max);

int utn_getEntero(int* pEntero, int retry, char* msg, char*msgError, int min, int max);

int isChar(char str[]);

int getCadena(char* pAux, int limit);

int isFloat(char* pAux);

int getFloat(float* pAux);

int isInt(char *pAux);

int getInt(int* pAux);

#endif // employee_H_INCLUDED
