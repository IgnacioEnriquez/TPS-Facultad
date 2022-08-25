#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "LinkedList.h"
#include "motos.h"
#include "parser.h"
#include "controller.h"

/****************************************************
    Menu:
     1. Cargar los datos de las motos desde el archivo motos.csv
     2. Alta de moto
     3. Modificar datos de moto
     4. Baja de moto
     5. Listar motos
     6. Ordenar motos
     7. Guardar los datos de los motos en el archivo saveMotos.csv.
     8. Eliminar todos los elementos de la lista
     9. Salir
*****************************************************/

int main()
{
    LinkedList* listaMotos = ll_newLinkedList();
    char seguir = 'S';
    char aux;


    do
     {
         switch(menu())
         {

         case 1:
                if((controller_loadFromText("motos.csv",listaMotos)) == 0)
                {
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
         case 2 :
            controller_addMoto(listaMotos);
            break;

         case 3:
            controller_editMotos(listaMotos);
            break;

         case 4:
             controller_removeMoto(listaMotos);
             break;

        case 5:
            controller_ListMotos(listaMotos);
            system("pause");
            break;
        case 6:
            controller_sortMoto(listaMotos);
            break;

        case 7:
            controller_saveAsText("saveMotos.csv",listaMotos);
            break;

        case 8:
            controller_deleteAll(listaMotos);
            break;

        case 9:
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



     }while(seguir == 'S');


   ll_deleteLinkedList(listaMotos);

}
