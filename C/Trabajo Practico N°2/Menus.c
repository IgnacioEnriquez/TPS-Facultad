#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include "ArrayEmployees.h"
#include "ABM.h"
#include "Menus.h"

int menuModificacion()
{
    int opcion;

    printf("---------------- Menu de Modificaciones ----------------\n\n");
    printf("              1 - Modificar Nombre \n\n");
    printf("              2 - Modificar Apellido\n\n");
    printf("              3 - Modificar Salario\n\n");
    printf("              4 - Modificar Sector\n\n");;
    printf("              5 - Salir \n\n");
    printf("--------------------------------------------------------\n\n");
    printf("Ingresa una opcion : ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}
int menuInformes()
{
    int opcion;

    printf("---------------- Menu de Informes ---------------- \n\n");
    printf(" 1 - Ordenar Alfabeticamente por Apellido y Sector \n");
    printf(" 2 - Total y Promedio de salarios\n");
    printf(" 3 - Salir \n\n");
    printf("--------------------------------------------------\n\n");
    printf("Ingresa una opcion : ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;

}
int menuAscODesc()
{
    int opcion;

    printf("********* Menu de Informes *********\n\n");
    printf(" 1 - Ordenar De Manera Ascendente por Apellido y Sector \n");
    printf(" 2 - Ordenar De Manera Descendente por Apellido y Sector \n\n");
    printf("************************************\n\n");
    printf("Ingresa una opcion : ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;

}
int menu()
{
    int opcion;

    printf("----------------- Menu de opciones -----------------\n\n");
    printf(" 1 - Alta Empleado \n\n");
    printf(" 2 - Modificar Empleado\n\n");
    printf(" 3 - Baja Empleado\n\n");
    printf(" 4 - Informar\n\n");;
    printf(" 5 - Salir\n\n");
    printf("----------------------------------------------------\n\n");
    printf("Ingresa una opcion : ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;

}
int menuSector()
{

    int opcion;

    printf("----------------------------------\n");
    printf("         Eliga un sector : \n");
    printf("----------------------------------\n");
    printf("      Opcion 1 = Sector 1 \n");
    printf("      Opcion 2 = Sector 2\n");
    printf("      Opcion 3 = Sector 3\n");
    printf("      Opcion 4 = Sector 4\n");
    printf("----------------------------------\n");
    printf("Ingresa una opcion : ");
    fflush(stdin);
    scanf("%d",&opcion);
    printf("-------------------------------------\n");
    return opcion;

}
