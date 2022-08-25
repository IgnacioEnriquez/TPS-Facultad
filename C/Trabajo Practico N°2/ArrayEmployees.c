#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include "ArrayEmployees.h"
#include "ABM.h"

#include "Menus.h"
int initEmployees(Employee* list, int len)
{
    int retorno = -1;



    if(list != NULL )
    {

        for(int i = 0; i < len ; i++)
        {

            list[i].isEmpty = 1;
            retorno = 0;

        }

        retorno = 0;

    }

    return retorno;
}

int findEmpty(Employee* list,int len)
{
    int retorno = -1;

    for(int i = 0; i<len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int retorno;
    retorno = findEmpty(list,len);

    if (list != NULL && retorno != -1)
    {

        list[retorno].id = id;
        list[retorno].salary = salary;
        list[retorno].sector = sector;
        strcpy(list[retorno].name,name);
        strcpy(list[retorno].lastName,lastName);
        list[retorno].isEmpty = 0;

        retorno = 0;
    }



    return retorno;
}



int findEmployeeById(Employee* list, int len,int id)
{
    int retorno = -1;

    if(list != NULL)
    {

    for(int i = 0 ; i<len;  i++)
    {
        if(list[i].id == id && list[i].isEmpty == 0)
        {
            retorno = i;
            break;
        }


    }

    }
    return retorno;
}

int removeEmployee(Employee* list, int len, int id)
{
    int retorno;

    retorno = findEmployeeById(list,len,id);

    if (retorno != -1 && list != NULL)
    {
        list[retorno].isEmpty = 1;
        retorno = 0;
    }

    return retorno;
}

int sortEmployees(Employee* list, int length, int order)
{
    Employee aux;
    int retorno = -1;

    if(list != NULL)
    {

        for(int i = 0; i<length -1; i++)
        {
            for(int j = i+1; j<length ; j++)
            {
                if(order == 0 && list[i].isEmpty == 0 && list[j].isEmpty == 0)
                {

                    if(list[i].sector > list[j].sector)
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;

                    }
                    if(list[i].sector == list[j].sector && strcmp(list[i].lastName,list[j].lastName) == 1)
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                }
                else if(order == 1 && list[i].isEmpty == 0 && list[j].isEmpty == 0)
                {
                    if(list[j].sector > list[i].sector)
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;

                    }
                    if(list[i].sector == list[j].sector && strcmp(list[i].lastName,list[j].lastName) == -1 && list[i].isEmpty == 0 && list[j].isEmpty == 0 )
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }

                }

            }
        }

        retorno = 0;
    }

    return retorno;

}
int printEmployees(Employee* list, int length)
{
    int retorno = 0;
    system("cls");

    printf("-------------------- Lista de Empleados ---------------------\n");
    printf("ID         NOMBRE       APELLIDO         SUELDO        SECTOR\n");
    for(int i = 0; i<length; i++)
    {
        if(list[i].isEmpty == 0)
        {
            mostrarEmpleado(list[i]);
        }

    }



    return retorno;
}

