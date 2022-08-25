#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include "ArrayEmployees.h"
#include "ABM.h"
#include "Menus.h"

int elegirSector()
{

    int sector;
    char seguir = 's';

    do
    {
        system("cls");
        switch(menuSector())
        {

        case 1:
            sector = 1;
            seguir = 'n';
            break;
        case 2:
            sector = 2;
            seguir = 'n';
            break;
        case 3:
            sector = 3;
            seguir = 'n';
            break;
        case 4:
            sector = 4;
            seguir = 'n';
            break;
        default:
            system("cls");
            printf("----------------------------------------------------------\n");
            printf("La opcion elegida es incorrecta,reingrese datos\n");
            printf("----------------------------------------------------------\n");
            system("pause");
            sector = -1;
            seguir = 'n';
            break;

        }

    }
    while(seguir == 's');


    return sector;
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
                printf("----------------------------------------------------------\n");
                printf("%s", msgError);
                printf("----------------------------------------------------------\n");
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
                printf("----------------------------------------------------------\n");
                printf("%s", msgError);
                printf("----------------------------------------------------------\n");
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
                printf("----------------------------------------------------------\n");
                printf("%s", msgError);
                printf("----------------------------------------------------------\n");
                system("pause");
            }
            retry--;

        }
        while(retry>=0);
    }

    return isOk;
}

void elegirOrdenamiento(Employee* list,int length)
{

    system("cls");
    switch(menuAscODesc())
    {

    case 1:
        sortEmployees(list,length,1);
        break;

    case 2:
        sortEmployees(list,length,0);
        break;

    default:
        printf("----------------------------------------------------\n");
        printf("Opcion elegida incorrecta");
        printf("----------------------------------------------------\n");
        system("pause");
        break;

    }

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
        retorno= 0;
        *pResultado = num;
    }
    return retorno;
}

void mostrarEmpleado(Employee list)
{
    printf("---------------------------------------------------------------\n");
    printf("%2d     %10s    %10s         %.2f         %d\n", list.id, list.name, list.lastName, list.salary, list.sector);
    printf("---------------------------------------------------------------\n");
}

void informes(Employee* list,int length)
{
    char seguir = 's';

    do
    {
        system("cls");
        switch(menuInformes())
        {
        case 1:
            system("cls");
            elegirOrdenamiento(list,length);
            printEmployees(list,length);
            seguir = 'n';
            system("pause");
            break;
        case 2:
            system("cls");
            ordenamientoSalario(list,length);
            seguir = 'n';
            system("pause");
            break;
        case 3:
            seguir = 'n';
            break;
        default:
            printf("La opcion elegida no es correcta,reingrese datos");
            system("pause");



        }


    }
    while(seguir == 's');

}
void ordenamientoSalario(Employee* list,int length)
{
    float acumuladorSueldos = 0;
    int cantidadSueldos = 0;
    float promedioSueldos = 0;
    int flag = 0;
    int flag2 = 0;

    for(int i = 0; i<length; i++)
    {
        if(list[i].isEmpty == 0)
        {
            acumuladorSueldos+=list[i].salary;
            cantidadSueldos++;

        }
    }
    if(cantidadSueldos != 0){

    promedioSueldos = acumuladorSueldos / cantidadSueldos;

    }
    for(int i = 0; i<length; i++)
    {
        if(list[i].salary > promedioSueldos && list[i].isEmpty == 0)
        {
            flag2 = 1;

            if(flag == 0)
            {
                printf("------- Lista de Empleados Que Superaron el Promedio --------\n");
                printf("ID         NOMBRE       APELLIDO         SUELDO        SECTOR\n");
                flag = 1;

            }
            mostrarEmpleado(list[i]);
        }

    }
    if(flag2 == 0)
    {
        printf("---------------------------------------------------------------\n");
        printf("No hay empleados que superen el salario promedio\n");
        printf("---------------------------------------------------------------\n");
    }

    printf("---------------------------------------------------------------\n");
    printf("El total de salario es %f\n",acumuladorSueldos);
    printf("---------------------------------------------------------------\n");
    printf("El promedio de sueldos es %f\n",promedioSueldos);
    printf("---------------------------------------------------------------\n");


}
