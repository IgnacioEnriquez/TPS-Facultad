#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include "ArrayEmployees.h"
#include "ABM.h"
#include "Menus.h"


void altaEmpleado(Employee* list,int* flag,int length,int id)
{
    int lugar;
    int validacion;
    Employee aux;
    lugar = findEmpty(list,length);
    system("cls");

    if(lugar == -1)
    {
        printf("|---------------------------|\n\n");
        printf("| El sistema esta completo  |\n\n");
        printf("|---------------------------| \n\n");
        system("pause");

    }
    else
    {
        printf("-----------------------------\n");
        validacion = utn_getCadena(aux.name,20,0,"Ingrese un nombre  : ","Error : El nombre ingresado es incorrecto,reingrese datos\n");


        if(validacion != -1)
        {
            printf("-----------------------------\n");
            validacion = utn_getCadena(aux.lastName,20,0,"Ingrese un apellido  : ","Error : El apellido ingresado es incorrecto,reingrese datos\n");

            if(validacion != -1)
            {
                printf("-----------------------------\n");
                validacion = utn_getFlotante(&aux.salary,0,"Ingrese un sueldo : ","Error : El sueldo ingresado es incorrecto,reingrese datos\n",0,1000000);

                if(validacion != -1)
                {

                    aux.sector = elegirSector();

                    if(aux.sector != -1)
                    {


                        *flag = 1;
                        aux.isEmpty = 0;
                        addEmployee(list,length,id,aux.name,aux.lastName,aux.salary,aux.sector);

                        system("cls");
                        printf("----------------------------------------------------------\n");
                        printf("El Empleado fue agregado con exito\n");
                        printf("----------------------------------------------------------\n");
                        system("pause");
                    }
                }



            }


        }

    }

}

void bajaEmpleado(Employee* list,int length)
{
    int id;
    int indice;
    int validacion;
    char respuesta;

    system("cls");

    printf("---------------------------------------------------------------\n");
    validacion = utn_getEntero(&id,0,"Ingrese el ID que desea eliminar : ","Error : Dato incorrecto,reingrese datos\n",0,999);

    if(validacion != -1)
    {
        indice = findEmployeeById(list,length,id);

        if(indice == -1)
        {
            system("cls");
            printf("---------------------------------------------------------------\n");
            printf("No existe un empleado con ese ID\n\n");
            printf("---------------------------------------------------------------\n");
            system("pause");
        }
        else
        {
            mostrarEmpleado(list[indice]);
            printf("\nDesea eliminar este empleado? n/s : ");
            fflush(stdin);
            scanf("%c",&respuesta);

            if(respuesta == 's' || respuesta == 'S')
            {
                removeEmployee(list,length,id);
                system("cls");
                printf("---------------------------------------------------------------\n");
                printf("El Empleado fue eliminado con exito\n");
                printf("---------------------------------------------------------------\n");
                system("pause");

            }
            else if (respuesta == 'n'||respuesta == 'N')
            {
                system("cls");
                printf("---------------------------------------------------------------\n");
                printf("El Empleado no fue eliminado\n");
                printf("---------------------------------------------------------------\n");
                system("pause");

            }
            else
            {
                system("cls");
                printf("---------------------------------------------------------------\n");
                printf("La opcion elegida no es correcta,reingrese datos\n");
                printf("---------------------------------------------------------------\n");
                system("pause");
            }
        }
    }




}
void modificarEmpleado(Employee* list,int length)
{
    int id;
    int indice;
    int validacion;
    Employee aux;
    char respuesta;
    char seguir = 's';

    system("cls");

    printf("-----------------------------\n");
    validacion = utn_getEntero(&id,0,"Ingrese el ID que desea modificar : ","Error : Dato incorrecto,reingrese datos\n",0,999);

    if(validacion != -1)
    {
        indice = findEmployeeById(list,length,id);

        if(indice == -1)
        {
            printf("-----------------------------\n");
            printf("No existe un empleado con ese ID\n");
            printf("-----------------------------\n");
            system("pause");
        }
        else
        {
            mostrarEmpleado(list[indice]);
            printf("\nDesea modificar este empleado? n/s : ");
            fflush(stdin);
            scanf("%c",&respuesta);

            if(respuesta == 's'||respuesta =='S')
            {

                do
                {
                    system("cls");
                    switch(menuModificacion())
                    {
                    case 1:
                        system("cls");
                        printf("----------------------------------------------------------\n");
                        validacion = utn_getCadena(aux.name,20,0,"Ingrese el nuevo nombre del empleado : ","Error : Dato incorrecto,reingrese datos\n");
                        if(validacion != -1)
                        {
                            strcpy(list[indice].name,aux.name);
                            system("cls");
                            printf("----------------------------------------------------------\n");
                            printf("Nombre Agregado con exito\n");
                            printf("----------------------------------------------------------\n");
                            system("pause");
                            break;
                        }
                        break;
                    case 2:
                          system("cls");
                        printf("----------------------------------------------------------\n");
                        validacion = utn_getCadena(aux.lastName,20,0,"Ingrese el nuevo apellido del empleado : ","Error : Dato incorrecto,reingrese datos\n");
                        if(validacion != -1)
                        {
                            strcpy(list[indice].lastName,aux.lastName);
                            system("cls");
                            printf("----------------------------------------------------------\n");
                            printf("Apellido Modificado con exito\n");
                            printf("----------------------------------------------------------\n");
                            system("pause");
                            break;
                        }
                        break;
                    case 3:
                          system("cls");
                        printf("----------------------------------------------------------\n");
                        validacion = utn_getFlotante(&aux.salary,0,"Ingrese el nuevo sueldo del empleado : ","Error : Dato incorrecto,reingrese datos\n",0,100000);
                        if(validacion != -1)
                        {
                            list[indice].salary = aux.salary;
                            system("cls");
                            printf("----------------------------------------------------------\n");
                            printf("Salario Modificado con exito\n");
                            printf("----------------------------------------------------------\n");
                            system("pause");
                            break;
                        }
                        break;
                    case 4:
                          system("cls");
                        printf("----------------------------------------------------------\n");
                        validacion = utn_getEntero(&aux.sector,0,"Ingrese el nuevo Sector del empleado : ","Error : Dato incorrecto,reingrese datos\n",0,4);
                        if(validacion != -1)
                        {
                            list[indice].sector = aux.sector;
                            system("cls");
                            printf("----------------------------------------------------------\n");
                            printf("Sector Modificado con exito\n");
                            printf("----------------------------------------------------------\n");
                            system("pause");
                            break;
                        }
                        break;

                    case 5:
                        seguir = 'n';
                        break;
                    default :
                        system("cls");
                        printf("----------------------------------------------------------\n");
                        printf("La opcion elegida es incorrecta\n");
                        printf("----------------------------------------------------------\n");
                        system("pause");
                        break;

                    }

                }
                while(seguir == 's');

            }
            else if(respuesta == 'n'||respuesta == 'N')
            {
                system("cls");
                printf("----------------------------------------------------------\n");
                printf("El Empleado no sera modificado\n");
                printf("----------------------------------------------------------\n");
                system("pause");

            }
            else
            {
                system("cls");
                printf("----------------------------------------------------------\n");
                printf("La opcion elegida no es correcta,reingrese datos");
                printf("----------------------------------------------------------\n");
                system("pause");

            }
        }
    }


}
