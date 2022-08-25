#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    char seguir = 'S';
    int flagTxt = 0;
    int flagBinario = 0;
    char aux;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {

        switch(menu())
        {
        case 1:
            if(flagTxt == 0 && flagBinario == 0)
            {
                if((controller_loadFromText("data.csv",listaEmpleados)) == 0)
                {
                    flagTxt = 1;
                    system("cls");
                    printf("-------------------------------------------\n");
                    printf("Archivo cargado correctamente\n");
                    printf("-------------------------------------------\n");
                    system("pause");
                    break;
                }
                else
                {
                    system("cls");
                    printf("-------------------------------------------\n");
                    printf("Error al cargar el archivo");
                    printf("-------------------------------------------\n");
                    system("pause");
                    break;
                }
            }
            else
            {
                system("cls");
                printf("-------------------------------------------\n");
                printf("Ya cargo un archivo antes.\n");
                printf("-------------------------------------------\n");
                system("pause");


            }
            break;
        case 2:
            if(flagTxt == 0 && flagBinario == 0)
            {
                if((controller_loadFromBinary("data.bin",listaEmpleados)) == 0)
                {
                    flagBinario = 1;
                    system("cls");
                    printf("-------------------------------------------\n");
                    printf("Archivo cargado correctamente\n");
                    printf("-------------------------------------------\n");
                    system("pause");
                    break;
                }
                else
                {
                    system("cls");
                    printf("-------------------------------------------\n");
                    printf("Error al cargar el archivo");
                    printf("-------------------------------------------\n");
                    system("pause");
                    break;
                }
            }
            else
            {
                system("cls");
                printf("-------------------------------------------\n");
                printf("Ya cargo un archivo antes.\n");
                printf("-------------------------------------------\n");
                system("pause");

            }


            break;

        case 3:

            controller_addEmployee(listaEmpleados);
            break;

        case 4:

            controller_editEmployee(listaEmpleados);
            break;

        case 5:
            controller_removeEmployee(listaEmpleados);
            break;

        case 6 :
            controller_ListEmployee(listaEmpleados);
            system("pause");
            break;

        case 7:
            controller_sortEmployee(listaEmpleados);
            break;

        case 8:
            controller_saveAsText("data.csv",listaEmpleados);
            break;

        case 9:
            controller_saveAsBinary("data.bin",listaEmpleados);
            break;


        case 10:
            system("cls");
            printf("Desea salir del programa? S/N : ");
            fflush(stdin);
            scanf("%c",&aux);

            if(aux == 'S' || aux == 's')
            {
                seguir = 'N';
            }

            break;

        }

        system("cls");
    }
    while(seguir == 'S');



    ll_deleteLinkedList(listaEmpleados);

    return 0;
}
