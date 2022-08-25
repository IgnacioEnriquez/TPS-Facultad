#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"



int opcionesCalc(float a,float b)
{

    int opcion;

    printf("********* Menu de opciones *********\n\n");
    printf(" 1 - Insertar 1er operando (A = %.2f)\n",a);
    printf(" 2 - Insertar 2do operando (B = %.2f)\n",b);
    printf(" 3 - Realizar todas las operaciones\n ");
    printf("4 - Mostrar operaciones realizadas\n ");
    printf("5 - Salir\n\n");
    printf("************************************\n\n");
    printf("Ingresa una opcion : ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;

}

float ingresarNum(char a[30])
{
    float numero;
    printf("%s",a);
    fflush(stdin);
    scanf("%f",&numero);

    return numero;

}

char validacion (char frase[50],char fraseError[50],char a,char b)
{

    char correcto;

    printf("\n%s ",frase);
    fflush(stdin);
    scanf("%c",&correcto);

    while(correcto != a && correcto != b)
    {
        printf("\n%s ",fraseError);
        fflush(stdin);
        scanf("%c",&correcto);

    }

    return correcto;


}
void resultados(float a,float b,float c,float d,float e)
{
    printf("El resultado de la suma es %.2f\n\n",a);
    printf("El resultado de la resta es %.2f\n\n",b);
    printf("El resultado de la multiplicacion es %.2f\n\n",c);
    printf("El resultado del factorial de A es %.lf\n\n",d);
    printf("El resultado del factorial de B es %.lf\n\n",e);
}
