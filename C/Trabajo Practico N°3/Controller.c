#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f = fopen(path,"r");
    int retorno;


    retorno = parser_EmployeeFromText(f,pArrayListEmployee);


    fclose(f);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    system("cls");


    FILE* pf = fopen(path, "rb");

    if(pf != NULL)
    {
        parser_EmployeeFromBinary(pf, pArrayListEmployee);

        printf("Archivo encontrado.\n");
        retorno = 0;

    }
    else
    {
        printf("Error. No se encontro el archivo.\n");
        system("pause");
    }
    fclose(pf);

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    char resp;
    int retorno = -1;
    Employee* pAux = employee_new();

    printf("Desea aniadir un empleado a la lista? S/N : ");
    fflush(stdin);
    scanf("%c",&resp);

    if( resp == 'S' || resp == 's' )
    {
        if((utn_getCadena(pAux->nombre,20,0,"Ingrese el nombre del empleado: ","Error : Ingrese un nombre validado\n") == 0))
        {
            if(employee_setNombre(pAux,pAux->nombre) == 0)
            {
                if((utn_getEntero(&pAux->horasTrabajadas,0,"Ingrese las horas trabajadas del empleado: ","Error: Saldo incorrecto,reingrese datos",0,1000000) == 0))
                {
                    if(employee_setHorasTrabajadas(pAux,pAux->horasTrabajadas) == 0)
                    {

                        if((utn_getEntero(&pAux-> sueldo,0,"Ingrese el sueldo del empleado: ","Error: Saldo incorrecto,reingrese datos",0,1000000) == 0))
                        {
                            if(employee_setSueldo(pAux,pAux->sueldo) == 0)
                            {
                                if((utn_getEntero(&pAux->id,0,"Ingrese el ID del empleado: ","Error: ID incorrecto,reingrese datos",0,1000000) == 0))
                                {

                                    if(employee_setId(pAux,pAux-> id) == 0)
                                    {
                                        if((compararIdEmpleado(pArrayListEmployee, pAux->id)) == 0)
                                        {

                                            system("cls");
                                            ll_add(pArrayListEmployee,pAux);
                                            printf("Empleado agregado con exito");


                                        }
                                        else
                                        {
                                            printf("El Empleado con este ID ya existe,reingrese datos");
                                            system("pause");
                                        }


                                    }

                                }

                            }

                        }

                    }

                }
            }
        }

    }
    else if(resp == 'N' || resp == 'n')
    {

        retorno = 1;

    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int cant;
    int validacion;
    int auxId;
    char resp;
    Employee* aux;

    cant = ll_len(pArrayListEmployee);

    if(cant > 0 && pArrayListEmployee != NULL)
    {

        if((utn_getEntero(&auxId,0,"Ingrese el ID del empleado :  ","Error: ID incorrecto,reingrese datos",0,1000000)) == 0)
        {

            validacion = compararIdEmpleado(pArrayListEmployee,auxId);

            if(validacion == -1)
            {

                for(int i = 0; i < cant; i++)
                {
                    aux = (Employee*)ll_get(pArrayListEmployee,i);

                    if(aux->id == auxId)
                    {
                        mostrarEmpleado(aux);
                        printf("Desea modificar este empleado? S/N : ");
                        fflush(stdin);
                        scanf("%c", &resp);

                        if(resp == 'S' || resp == 's')
                        {

                            elegirModificacion(aux);
                            system("pause");
                            retorno = 0;

                        }
                        break;
                    }

                }

            }


        }

    }
    else
    {
        system("cls");
        printf("---------------------------------------\n");
        printf("No hay empleados para mostrar\n");
        printf("---------------------------------------\n");
        system("pause");


    }

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int cant;
    Employee* aux;
    int auxId;
    char resp;

    cant = ll_len(pArrayListEmployee);

    if(cant > 0 && pArrayListEmployee != NULL)
    {
        if((utn_getEntero(&auxId,0,"Ingrese el ID del empleado que desea eliminar : ","Error : Reingrese Datos",0,1000000000)) == 0)
        {
            if(compararIdEmpleado(pArrayListEmployee,auxId) == -1)
            {

                for(int i = 0; i < cant; i++)
                {
                    aux = (Employee*)ll_get(pArrayListEmployee,i);

                    if(aux->id == auxId)
                    {
                        mostrarEmpleado(aux);
                        printf("Desea eliminar este empleado? S/N : ");
                        fflush(stdin);
                        scanf("%c", &resp);

                        if(resp == 'S' || resp == 's')
                        {

                            ll_remove(pArrayListEmployee,i);
                            retorno = 0;
                        }
                        break;
                    }

                }

            }
        }
    }
    else
    {
        system("cls");
        printf("No hay empleados para mostrar\n");
        system("pause");


    }




    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

    mostrarEmpleados(pArrayListEmployee);

    return 0;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int orden;
    int opcion;

    system("cls");
    utn_getEntero(&opcion, 2, "Ingrese si quiere ordenar por nombre(1), o por id (2):   ", "Error. Ingrese un numero valido.\n", 1, 2); //eleccion
    switch(opcion)
    {
    case 1:
        system("cls");
        utn_getEntero(&orden, 2, "Ingrese el orden en el que quiere que se \nacomoden los nombres.Recuerde que este proceso\ntarda unos segundos. (1 ascendente o 0 descendente): ", "Error. Ingrese un numero valido\n", 0, 1);

        ll_sort(pArrayListEmployee, sortEmployeeNombre, orden);

        //se ordenan por nombre
        break;
    case 2:
        system("cls");
        utn_getEntero(&orden, 2, "Ingrese el orden en el que quiere que se \nacomoden los Id.Recuerde que este proceso\ntarda unos segundos. (1 ascendente o 0 descendente): ", "Error. Ingrese un numero valido\n", 0, 1);

        ll_sort(pArrayListEmployee, sortEmployeeId,orden);

        //se ordenan por id
        break;

    }



    controller_ListEmployee(pArrayListEmployee);
    system("pause");




    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 1;

    FILE* pf;
    char auxNombre[20];
    int auxId;
    int auxHoras;
    int auxSueldo;
    int tam = ll_len(pArrayListEmployee);
    Employee* pEmpleado;


    pf = fopen(path, "w");


    if(pf != NULL)
    {

        for(int i = 0; i < tam; i++)
        {
            pEmpleado = ll_get(pArrayListEmployee, i);

            if((employee_getId(pEmpleado, &auxId)==0) &&
                    (employee_getNombre(pEmpleado, auxNombre)==0) &&
                    (employee_getHorasTrabajadas(pEmpleado, &auxHoras)==0) &&
                    (employee_getSueldo(pEmpleado, &auxSueldo)==0))
            {
                fprintf(pf, "%d,%s,%d,%d\n", auxId, auxNombre, auxHoras, auxSueldo);
                todoOk = 0;
            }
        }
        fclose(pf);
        printf("Archivo guardado con exito\n");
        system("pause");
    }


    return todoOk;
}
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    FILE* pf;
    Employee* pEmpleado;
    int tam = ll_len(pArrayListEmployee);


    pf = fopen(path, "wb");

    if(pf != NULL)
    {

        for(int i = 0; i < tam; i++)
        {

            pEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
            fwrite(pEmpleado, sizeof(Employee), 1, pf);


        }

        printf("Archivo binario guardado.\n");
        system("pause");

    }

    fclose(pf);


    retorno = 0;


    return retorno;


    return 1;
}

