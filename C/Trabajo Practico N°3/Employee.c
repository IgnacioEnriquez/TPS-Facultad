#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include "LinkedList.h"
#include "Employee.h"

Employee* employee_new()
{
    Employee* nuevoEmployee = (Employee*) malloc(sizeof(Employee));

    if(nuevoEmployee != NULL)
    {
        nuevoEmployee ->id = 0;
        nuevoEmployee ->horasTrabajadas = 0;
        nuevoEmployee ->sueldo = 0.0;
        strcpy(nuevoEmployee ->nombre, "");


    }

    return nuevoEmployee;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{

    Employee*  nuevoEmployee = employee_new();

    if(nuevoEmployee != NULL)
    {
        if(employee_setId(nuevoEmployee, atoi(idStr)) == 0)
    {

        if(employee_setNombre(nuevoEmployee, nombreStr) == 0)
            {

                if(employee_setSueldo(nuevoEmployee,atoi(sueldo)) == 0)
                {

                    if(employee_setHorasTrabajadas(nuevoEmployee,atoi(horasTrabajadasStr)) == 0)
                    {


                    }

                    }
            }

        }
    }

    return nuevoEmployee;
}
int employee_setId(Employee* emp,int id)
{
    int retorno = -1;

    if( emp != NULL && id >= 0)
    {
        emp -> id = id;
        retorno = 0;
    }

    return retorno;

}
int employee_setNombre(Employee* emp,char* nombre)
{
    int retorno = -1;

    if( emp != NULL && strlen(nombre) >= 2 && strlen(nombre) < 20)
    {
        strcpy(emp -> nombre, nombre);
        retorno = 0;

    }

    return retorno;
}
int employee_setHorasTrabajadas(Employee* emp,int horasTrabajadas)
{
    int retorno = -1;

    if(emp != NULL && horasTrabajadas >= 0)
    {
        emp -> horasTrabajadas = horasTrabajadas;
        retorno = 0;

    }

    return retorno;
}
int employee_setSueldo(Employee* emp,int sueldo)
{
    int retorno = -1;

    if(emp != NULL && sueldo >= 0)
    {

        emp ->sueldo = sueldo;
        retorno = 0;

    }

    return retorno;
}
int menu()
{
    int retorno;

    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir\n\n");
    printf("Ingrese una opcion : ");
    fflush(stdin);
    scanf("%d",&retorno);


    return retorno;
}
int mostrarEmpleado( Employee* emp)
{
    int retorno = -1;

    if( emp != NULL)
    {
        retorno = 0;
        printf(" %d    %10s           %d        %d\n",emp ->id, emp ->nombre, emp ->horasTrabajadas, emp ->sueldo);


    }
    return retorno;

}
int mostrarEmpleados(LinkedList* lista)
{
    int retorno = -1;
    int tam;
    int flag = 0;
    Employee* auxEmpleado;


    if(lista != NULL)
    {
        tam = ll_len(lista);
        retorno = 0;
        printf(" Id           Nombre         Horas Trabajadas       Sueldo\n");

        for(int i = 0; i < tam ; i++ )
        {
            auxEmpleado = (Employee*) ll_get(lista,i) ;

            if(auxEmpleado !=  NULL )
            {

                mostrarEmpleado(auxEmpleado);
                flag = 1;

            }
        }


        if (flag== 0)
        {
            printf("No hay personas\n\n");
        }
        printf(" \n\n");


    }
    return retorno;
}
int getInt(int* pAux)
{
    char auxString[400];
    int isOk = -1;

    if(getCadena(auxString, sizeof(auxString)) == 0 && isInt(auxString ) == 0)
    {
        *pAux = atoi(auxString); //to integer
        isOk = 0; //exito
    }
    return isOk;
}

int isInt(char *pAux)
{
    int isOk = -1;
    int i = 0;
    int stringLong = strlen(pAux);

    do
    {
        if(*(pAux + i) < '0' || *(pAux + i) > '9')
        {
            break;
        }

        i++;

    }
    while (i < stringLong);

    if(i == stringLong)
    {
        isOk = 0; //exito
    }

    return isOk;
}
int utn_getEntero(int* pEntero, int retry, char* msg, char*msgError, int min, int max)
{
    int isOk = -1;
    int auxInt;

    if(pEntero != NULL && msg != NULL && msgError != NULL && min <= max && retry >= 0)
    {
        do
        {
            retry--;
            printf("%s", msg);

            if(getInt(&auxInt) == 0 && auxInt >= min && auxInt <= max)
            {
                *pEntero = auxInt;
                isOk = 0; //exito
                break;
            }
            else
            {
                system("cls");
                printf("----------------------------------\n");
                printf("%s", msgError);
                printf("----------------------------------\n");
                system("pause");
            }
        }
        while(retry >= 0);
    }
    return isOk;
}
int utn_getFlotante(float* pFloat, int retry, char* msg, char*msgError, float min, float max)
{
    int isOk = -1;
    float auxFloat;

    if(pFloat != NULL&& msg != NULL && msgError != NULL && min <= max && retry >= 0)
    {
        do
        {
            retry--;
            printf("%s",msg);
            if(getFloat(&auxFloat) == 0 && auxFloat >= min && auxFloat <= max)
            {
                *pFloat= auxFloat;
                isOk = 0; //exito
                break;
            }
            else
            {
                system("cls");
                printf("----------------------------------\n");
                printf("%s", msgError);
                printf("----------------------------------\n");
                system("pause");
            }
        }
        while(retry >= 0);
    }
    return isOk;
}
int getFloat(float* pAux)
{
    char auxString[200];
    int isOk =-1;

    if(getCadena(auxString,200) == 0 && isFloat(auxString) == 0)
    {
        *pAux = atof(auxString); //to float
        isOk = 0; //exito
    }
    return isOk;
}

int isFloat(char* pAux)
{
    int isOk = -1;
    int i = 0;
    int dotCount=0;
    int stringLong = strlen(pAux);

    do
    {
        if(*(pAux + i) == '.')
        {
            dotCount++;
            if(dotCount == 2)
            {
                break;
            }
        }
        else if(*(pAux + i) < '0'|| *(pAux + i) > '9')
        {
            break;
        }

        i++;

    }
    while (i < stringLong);

    if(i == stringLong)
    {
        isOk = 0; //exito
    }
    return isOk;
}
int getCadena(char* pAux, int limit)
{
    char auxString[4000];
    int isOk = -1;

    if (pAux != NULL && limit > 0)
    {
        fflush(stdin);
        fgets(auxString,sizeof(auxString),stdin);

        if (auxString[strlen(auxString)-1]=='\n')
        {
            auxString[strlen(auxString)-1]='\0';
        }
        if(strlen(auxString)<= limit)
        {
            strncpy(pAux, auxString, limit);
            isOk=0; //exito
        }
    }

    return isOk;
}
int isChar(char str[])
{

    int isOk = 0; //exito

    for(int i = 0; str[i] != '\0'; i++)
    {
        //si no es espacio, si es menor a 'a' o may a 'z', si es men a 'A' o may a 'Z', NO es letra:
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            isOk = -1;
        }
    }

    return isOk;

}
int utn_getCadena(char *pAux, int limit, int retry, char* msg, char* msgError)
{
    int isOk = -1;
    char auxString[limit];

    if(pAux != NULL && msg != NULL && msgError != NULL && limit > 0 && retry >= 0)
    {
        do
        {
            printf("%s", msg);

            if(getCadena(auxString, limit) == 0 && isChar(auxString) == 0)
            {
                strncpy(pAux, auxString, limit);
                isOk = 0; //exito
                break;
            }
            else
            {
                system("cls");
                printf("----------------------------------\n");
                printf("%s", msgError);
                printf("----------------------------------\n");
                system("pause");
            }
            retry--;

        }
        while(retry>=0);
    }

    return isOk;
}
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo,char maximo, int reintentos)
{
    int retorno = -1;
    char aux;

    if(pResultado != NULL && mensaje!= NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {

        do
        {
            printf("%s",mensaje);
            scanf("%c",&aux);
            if(aux >= minimo && aux <= maximo)
            {
                *pResultado = aux;
                retorno = 0;
                break;
            }
            else
            {
                system("cls");
                printf("----------------------------------\n");
                printf("%s", mensajeError);
                printf("----------------------------------\n");
                system("pause");

            }
        }
        while(reintentos > 0);

    }
    return retorno;
}
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos)
{
    int retorno;
    int num;
    while(reintentos>0)
    {
        printf(mensaje);
        if(scanf("%d",&num)==1)
        {
            if(num<=maximo && num>=minimo)
                break;
        }
        fflush(stdin);
        reintentos--;
        printf(mensajeError);
    }
    if(reintentos==0)
    {
        retorno=-1;
    }
    else
    {
        retorno =0;
        *pResultado = num;
    }
    return retorno;
}
void employee_delete(Employee* emp)
{
    if(emp != NULL)
    {

        free(emp);

    }
}

int employee_getId(Employee* emp,int* id)
{
    int retorno = -1;

   if(emp != NULL && id != NULL)
   {
       *id = emp -> id;
       retorno = 0;
   }

   return retorno;

}
int employee_getSueldo(Employee* emp,int* sueldo)
{

    int retorno = -1;

   if(emp != NULL && sueldo != NULL)
   {
       *sueldo = emp ->sueldo;
       retorno = 0;
   }

   return retorno;

}
int employee_getHorasTrabajadas(Employee* emp,int* horasTrabajadas)
{
     int retorno = -1;

   if(emp != NULL && horasTrabajadas != NULL)
   {
       *horasTrabajadas = emp ->horasTrabajadas;
        retorno = 0;
   }

   return retorno;

}
int employee_getNombre(Employee* emp,char* nombre)
{
     int retorno = 1;

		if(emp != NULL && nombre != NULL)
		{
			strcpy(nombre, emp -> nombre);
			retorno = 0;

		}

		return retorno;

}
int compararIdEmpleado(LinkedList* pArrayListEmployee,int id )
{
    int retorno = 0;
    int cant;
    int auxId;

    Employee* aux = employee_new();

    if(pArrayListEmployee != NULL && id >= 0 )
    {
        cant = ll_len(pArrayListEmployee);

        for(int i = 0; i< cant; i++)
        {
            aux = (Employee*) ll_get(pArrayListEmployee,i);

             employee_getId(aux,&auxId);

            if(id == auxId )
            {

            retorno = -1;
            break;

            }


        }

    }


    return retorno;


}
int menuModificacion()
{
    int retorno;

    printf("1. Modificar Nombre del empleado\n");
    printf("2. Modificar Horas Trabajadas del empleado\n");
    printf("3. Modificar Sueldo del empleado\n");
    printf("4. Modificar ID del empleado\n");
    printf("5. Salir\n\n");
    printf("Ingrese una opcion : ");
    fflush(stdin);
    scanf("%d",&retorno);


    return retorno;

}
void elegirModificacion(Employee* aux)
{
    char seguir = 'S';
    char resp;
    char auxNombre[100];
    int auxInt;

    do{
            system("cls");
            switch(menuModificacion())
            {

            case 1:

                if((utn_getCadena(auxNombre,100,0,"Ingrese el nuevo nombre que desea agregar : ","Error : Nombre ingresado de forma incorrecta,reingrese datos")) == 0)
                {

                    employee_setNombre(aux,auxNombre);
                    printf("Nombre cambiado con exito\n");
                    system("pause");


                }

                break;

            case 2:

                if((utn_getEntero(&auxInt,0,"Ingrese las nuevas horas trabajadas que desea agregar : ","Error : Horas ingresadas de forma incorrecta,reingrese datos",0,1000000)) == 0)
                {

                    employee_setHorasTrabajadas(aux,auxInt);
                    printf("Horas Trabajadas cambiadas con exito\n");
                    system("pause");


                }

                break;

            case 3:

                 if((utn_getEntero(&auxInt,0,"Ingrese el nuevo sueldo que desea agregar : ","Error : Sueldo ingresado de forma incorrecta,reingrese datos",0,1000000)) == 0)
                {

                    employee_setSueldo(aux,auxInt);
                    printf("Sueldo cambiado con exito\n");
                    system("pause");


                }

                break;

            case 4:

                 if((utn_getEntero(&auxInt,0,"Ingrese el nuevo ID que desea agregar : ","Error : ID ingresado de forma incorrecta,reingrese datos",0,1000000)) == 0)
                {

                    employee_setId(aux,auxInt);
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
int sortEmployeeId(void* x, void* y)
{

		int ordenDevuelto;
		int idUno;
		int idDos;

		employee_getId(x,&idUno);
		employee_getId(y,&idDos);

		if(idUno>idDos)
		{

			ordenDevuelto = 1;

		}
		else if(idUno<idDos)
		{

			ordenDevuelto = -1;

		}



		return ordenDevuelto;



}

int sortEmployeeNombre(void* x, void* y)
{
	int ordenDevuelto;
	char nombreUno[20];
	char nombreDos[20];

	employee_getNombre(x,nombreUno);
	employee_getNombre(y,nombreDos);

	if(strcmp(nombreUno,nombreDos) > 0)
	{

		ordenDevuelto = 1;

	}
	else if(strcmp(nombreUno,nombreDos) < 0)
	{

		ordenDevuelto = -1;

	}



	return ordenDevuelto;
}
