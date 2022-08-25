#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "Funciones.h"
#include "dataWarehouse.h"
#include "ABM.h"

int main()
{
   
   Employee empleados[999];
   char seguir = 's';
   int flag;
   int id = 0;

   initEmployees(empleados,999);

   do
    {
      switch(menu())
      {
    case 1:
        altaEmpleado(empleados,&flag,999,id);
        if(flag == 1)
        {
            id++;
        }
        break;
    case 2:
        if(flag == 1)
        {
        modificarEmpleado(empleados,999);
        break;
        }
        else
        {
            printf("----------------------------------------------------\n");
            printf("Debe dar de alta un empleado para usar esta opcion\n");
            printf("----------------------------------------------------\n");
            system("pause");
            break;
        }
    case 3:
        if(flag == 1)
        {
        bajaEmpleado(empleados,999);
        break;
        }
        else
        {
        printf("----------------------------------------------------\n");
        printf("Debe dar de alta un empleado para usar esta opcion\n");
        printf("----------------------------------------------------\n");
        system("pause");
        break;
        }
    case 4:
        if(flag == 1)
        {
        informes(empleados,999);
        break;
        }
        else
        {
        printf("----------------------------------------------------\n");
        printf("Debe dar de alta un empleado para usar esta opcion\n");
        printf("----------------------------------------------------\n");
        system("pause");
        break;
        }

    case 5:
        seguir = 'n';
        break;

    default:
        printf("----------------------------------------------------\n");
        printf("Opcion elegida incorrecta\n");
        printf("----------------------------------------------------\n");
        system("pause");
      }


    system("cls");
    }while(seguir == 's');





    return 0;
}

