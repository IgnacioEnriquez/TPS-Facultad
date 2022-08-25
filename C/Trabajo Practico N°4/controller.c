#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "LinkedList.h"
#include "motos.h"
#include "parser.h"
#include "controller.h"
#include "funcionesUTN.h"

/** \brief Carga los datos de las motos desde el archivo data.csv.
 *
 * \param file char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* file, LinkedList* pArrayListMotos)
{
    FILE* f = fopen(file,"r");
    int retorno;


    retorno = parser_MotosFromText(f,pArrayListMotos);


    fclose(f);

    return retorno;
}
int controller_ListMotos(LinkedList* pArrayListMotos)
{

    mostrarMotos(pArrayListMotos);

    return 0;
}
int controller_addMoto(LinkedList* pArrayListMotos)
{
    char resp;
    int retorno = -1;
    eMoto* pAux = moto_new();

    printf("Desea aniadir un empleado a la lista? S/N : ");
    fflush(stdin);
    scanf("%c",&resp);

    if( resp == 'S' || resp == 's' )
    {
        if((utn_getCadena(pAux->marca,20,0,"Ingrese la marca de la moto: ","Error : Ingrese un nombre validado\n") == 0))
        {

            if(moto_setMarca(pAux,pAux->marca) == 0)
            {

                if((utn_getEntero(&pAux->anio,0,"Ingrese el anio de la moto: ","Error: anio incorrecto,reingrese datos",1910,2020) == 0))
                {

                    if(moto_setAnio(pAux,pAux->anio) == 0)
                    {

                        if((utn_getFlotante(&pAux->precio,0,"Ingrese precio de la moto: ","Error : Precio incorrecto,reingrese datos",0,1000000) == 0))
                        {

                            if(moto_setPrecio(pAux,pAux->precio) == 0)
                            {

                                if((utn_getEntero(&pAux->id,0,"Ingrese el ID de la moto: ","Error: ID incorrecto,reingrese datos",0,1000000) == 0))
                                {


                                    if(moto_setId(pAux,pAux-> id) == 0)
                                    {

                                        if((compararIdMotos(pArrayListMotos, pAux->id)) == 0)
                                        {

                                            system("cls");
                                            ll_add(pArrayListMotos,pAux);
                                            printf("Moto agregado con exito");


                                        }
                                        else
                                        {
                                            printf("La moto con este ID ya existe,reingrese datos");
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
int controller_editMotos(LinkedList* pArrayListMotos)
{
    int retorno = -1;
    int cant;
    int validacion;
    int auxId;
    char resp;
    eMoto* aux;

    cant = ll_len(pArrayListMotos);

    if(cant > 0 && pArrayListMotos != NULL)
    {

        if((utn_getEntero(&auxId,0,"Ingrese el ID de la moto :  ","Error: ID incorrecto,reingrese datos",0,1000000)) == 0)
        {

            validacion = compararIdMotos(pArrayListMotos,auxId);

            if(validacion == -1)
            {

                for(int i = 0; i < cant; i++)
                {
                    aux = (eMoto*)ll_get(pArrayListMotos,i);

                    if(aux->id == auxId)
                    {
                        mostrarMoto(aux);
                        printf("Desea modificar esta Moto? S/N : ");
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
int controller_removeMoto(LinkedList* pArrayListMotos)
{
    int retorno = -1;
    int cant;
    eMoto* aux;
    int auxId;
    char resp;

    cant = ll_isEmpty(pArrayListMotos);

    if(cant == 0  && pArrayListMotos != NULL)
    {
        if((utn_getEntero(&auxId,0,"Ingrese el ID de la moto que desea eliminar : ","Error : Reingrese Datos",0,1000000000)) == 0)
        {
            if(compararIdMotos(pArrayListMotos,auxId) == -1)
            {

                for(int i = 0; i < ll_len(pArrayListMotos); i++)
                {
                    aux = (eMoto*)ll_get(pArrayListMotos,i);

                    if(aux->id == auxId)
                    {
                        mostrarMoto(aux);
                        printf("Desea eliminar esta Moto? S/N : ");
                        fflush(stdin);
                        scanf("%c", &resp);

                        if(resp == 'S' || resp == 's')
                        {

                            ll_remove(pArrayListMotos,i);
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
        printf("No hay Motos para eliminar\n");
        system("pause");


    }




    return retorno;
}
int controller_saveAsText(char* file, LinkedList* pArrayListMotos)
{
    int todoOk = 1;

    FILE* pf;
    char auxMarca[20];
    int auxId;
    float auxPrecio;
    int auxAnio;
    int tam = ll_len(pArrayListMotos);
    eMoto* pMoto;


    pf = fopen(file, "w");


    if(pf != NULL)
    {

        for(int i = 0; i < tam; i++)
        {
            pMoto = ll_get(pArrayListMotos, i);

            if((moto_getId(pMoto, &auxId)==0) &&
                    (moto_getMarca(pMoto, auxMarca)==0) &&
                    (moto_getAnio(pMoto, &auxAnio)==0) &&
                    (moto_getPrecio(pMoto, &auxPrecio)==0))
            {
                fprintf(pf, "%d,%d,%f,%s\n", auxId, auxAnio, auxPrecio, auxMarca);
                todoOk = 0;
            }
        }
        fclose(pf);
        printf("Archivo guardado con exito\n");
        system("pause");
    }


    return todoOk;
}
int controller_sortMoto(LinkedList* pArrayListMotos)
{
    int retorno = 1;
    char respuesta;

    system("cls");

    printf("Desea ordenar las motos por su marca? S/N: ");
    fflush(stdin);
    scanf("%c",&respuesta);

    if(respuesta == 'S' || respuesta == 's')
    {
        if((ll_sort(pArrayListMotos, sortMotoMarca, 1))== 0)
        {
            ll_sort(pArrayListMotos, sortMotoMarca, 1);
            printf("La lista se ordeno correctamente");
            system("pause");
        }
        else
        {
             printf("La lista no se pudo ordenar correctamente");
            system("pause");

        }

    }

    return retorno;
}
int controller_deleteAll(LinkedList* pArrayListMotos)
{
    int retorno = 1;
    char respuesta;
    int validacion;

    printf("Desea eliminar todos los elementos de la lista? S/N: ");
    fflush(stdin);
    scanf("%c",&respuesta);

    if(respuesta == 'S' || respuesta == 's')
    {
        validacion = ll_clear(pArrayListMotos);

        if( validacion == 0 )
        {
            system("cls");
            printf("Lista eliminada correctamente\n");
            system("pause");
        }
        else
        {
            system("pause");
            printf("No se pudo eliminar la lista\n");
            system("pause");
        }
    }



    return retorno;
}
