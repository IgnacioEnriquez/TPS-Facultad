#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "funcionesUTN.h"
#include "LinkedList.h"
#include "motos.h"
#include "parser.h"
#include "controller.h"

eMoto* moto_new()
{
    eMoto* nuevaMoto = (eMoto*) malloc(sizeof(eMoto));

    if(nuevaMoto != NULL)
    {
        nuevaMoto -> id = 0;
        nuevaMoto -> anio= 0;
        nuevaMoto ->precio = 0.0;
        strcpy(nuevaMoto ->marca, " ");

    }

    return nuevaMoto;
}
eMoto* moto_newParametros(char* idStr,char* anio,char* precio,char* marcaStr )
{

    eMoto*  nuevaMoto = moto_new();

    if(nuevaMoto != NULL)
    {
        if(moto_setId(nuevaMoto, atoi(idStr)) == 0)
        {

            if(moto_setMarca(nuevaMoto, marcaStr) == 0)
            {

                if(moto_setAnio(nuevaMoto,atoi(anio)) == 0)
                {

                    if(moto_setPrecio(nuevaMoto,atof(precio)) == 0)
                    {


                    }

                }
            }

        }
    }

    return nuevaMoto;
}
int moto_setId(eMoto* moto,int id)
{
    int retorno = -1;

    if( moto != NULL && id >= 0)
    {
        moto -> id = id;
        retorno = 0;
    }

    return retorno;

}
int moto_setMarca(eMoto* moto,char* marca)
{
    int retorno = -1;

    if( moto != NULL && strlen(marca) >= 2 && strlen(marca) < 20)
    {
        strcpy(moto -> marca, marca);
        retorno = 0;

    }

    return retorno;
}
int moto_setAnio(eMoto* moto,int anio)
{
    int retorno = -1;

    if(moto != NULL && anio >= 0)
    {
        moto -> anio = anio;
        retorno = 0;

    }

    return retorno;
}
int moto_setPrecio(eMoto* moto,float precio)
{
    int retorno = -1;

    if(moto != NULL && precio >= 0)
    {

        moto ->precio = precio;
        retorno = 0;

    }

    return retorno;
}
int menu()
{
    int retorno;

    printf("1. Cargar los datos de los empleados desde el archivo motos.csv\n");
    printf("2. Alta de moto\n");
    printf("3. Modificar datos de la moto\n");
    printf("4. Baja de moto\n");
    printf("5. Listar motos\n");
    printf("6. Ordenar motos\n");
    printf("7. Guardar los datos de las motos en el archivo saveMotos.csv\n");
    printf("8. Eliminar todos los elementos de la lista'\n");
    printf("9. Salir\n\n");
    printf("Ingrese una opcion : ");
    fflush(stdin);
    scanf("%d",&retorno);


    return retorno;
}
int mostrarMoto( eMoto* moto)
{
    int retorno = -1;

    if( moto != NULL)
    {
        retorno = 0;
        printf(" %2d        %4d           %.2f        %s\n",moto ->id, moto -> anio, moto ->precio, moto ->marca);


    }
    return retorno;

}
int mostrarMotos(LinkedList* pArrayListMotos)
{
    int retorno = -1;
    int tam;
    int flag = 0;
    eMoto* auxMoto;


    if(pArrayListMotos != NULL)
    {
        tam = ll_len(pArrayListMotos);
        retorno = 0;
        printf(" Id        Anio            Precio         Marca\n");

        for(int i = 0; i < tam ; i++ )
        {
            auxMoto = (eMoto*) ll_get(pArrayListMotos,i) ;

            if(auxMoto !=  NULL )
            {

                mostrarMoto(auxMoto);
                flag = 1;

            }
        }


        if (flag== 0)
        {
            printf("No hay Motos\n\n");
        }
        printf(" \n\n");


    }
    return retorno;
}
int compararIdMotos(LinkedList* pArrayListMotos,int id)
{
    int retorno = 0;
    int cant;
    int auxId;

    eMoto* aux = moto_new();

    if(pArrayListMotos != NULL && id >= 0 )
    {
        cant = ll_len(pArrayListMotos);

        for(int i = 0; i< cant; i++)
        {
            aux = (eMoto*) ll_get(pArrayListMotos,i);

             moto_getId(aux,&auxId);

            if(id == auxId )
            {

            retorno = -1;
            break;

            }


        }

    }


    return retorno;


}
int moto_getId(eMoto* moto,int* id)
{
    int retorno = -1;

   if(moto != NULL && id != NULL)
   {
       *id = moto -> id;
       retorno = 0;
   }

   return retorno;

}
int moto_getPrecio(eMoto* moto,float* precio)
{

    int retorno = -1;

   if(moto != NULL && precio != NULL)
   {
       *precio = moto ->precio;
       retorno = 0;
   }

   return retorno;

}
int moto_getAnio(eMoto* moto,int* anio)
{
     int retorno = -1;

   if(moto != NULL && anio != NULL)
   {
       *anio = moto -> anio;
        retorno = 0;
   }

   return retorno;

}
int moto_getMarca(eMoto* moto,char* marca)
{
     int retorno = 1;

		if(moto != NULL && marca != NULL)
		{
			strcpy(marca, moto -> marca);
			retorno = 0;

		}

		return retorno;

}
void elegirModificacion(eMoto* aux)
{
    char seguir = 'S';
    char resp;
    char auxMarca[100];
    int auxInt;
    float auxFloat;

    do{
            system("cls");
            switch(menuModificacion())
            {

            case 1:

                if((utn_getCadena(auxMarca,100,0,"Ingrese la nueva marca que desea agregar : ","Error : Marca ingresasada de forma incorrecta,reingrese datos")) == 0)
                {

                    moto_setMarca(aux,auxMarca);
                    printf("Marca cambiada con exito\n");
                    system("pause");


                }

                break;

            case 2:

                if((utn_getFlotante(&auxFloat,0,"Ingrese el precio que desea ingresar : ","Error : Precio ingresado de forma incorrecta,reingrese datos",0,1000000)) == 0)
                {

                    moto_setPrecio(aux,auxInt);
                    printf("Precio cambiadas con exito\n");
                    system("pause");


                }

                break;

            case 3:

                 if((utn_getEntero(&auxInt,0,"Ingrese el nuevo Anio que desea agregar : ","Error : Anio ingresado de forma incorrecta,reingrese datos",0,1000000)) == 0)
                {

                    moto_setAnio(aux,auxInt);
                    printf("Anio cambiado con exito\n");
                    system("pause");


                }

                break;

            case 4:

                 if((utn_getEntero(&auxInt,0,"Ingrese el nuevo ID que desea agregar : ","Error : ID ingresado de forma incorrecta,reingrese datos",0,1000000)) == 0)
                {

                    moto_setId(aux,auxInt);
                    printf("ID cambiado con exito\n");
                    system("pause");


                }

                break;

            case 5:
                       printf("Desea salir de modificaciones? S/N : ");
                       fflush(stdin);
                       scanf("%c", &resp);

                        if(resp == 'S' || resp == 's')
                        {
                            seguir = 'N';
                        }
                        break;


            }


    }while(seguir == 'S');





}
int menuModificacion()
{
    int retorno;

    printf("1. Modificar Marca del empleado\n");
    printf("2. Modificar Anio del empleado\n");
    printf("3. Modificar Precio del empleado\n");
    printf("4. Modificar ID del empleado\n");
    printf("5. Salir\n\n");
    printf("Ingrese una opcion : ");
    fflush(stdin);
    scanf("%d",&retorno);

    return retorno;

}
int sortMotoMarca(void* x, void* y)
{
	int ordenDevuelto;
	char marcaUno[20];
	char marcaDos[20];

	moto_getMarca(x,marcaUno);
	moto_getMarca(y,marcaDos);

	if(strcmp(marcaUno,marcaDos) > 0)
	{

		ordenDevuelto = 1;

	}
	else if(strcmp(marcaUno,marcaDos) < 0)
	{

		ordenDevuelto = -1;

	}

	return ordenDevuelto;
}
