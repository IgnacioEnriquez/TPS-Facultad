#include <stdio.h>
#include <stdlib.h>
#include "funcionesmath.h"
#include "funciones.h"






int main()
{
    float primerNum = 0;
    float segundoNum = 0;
    float suma;
    float resta;
    float division;
    float multiplicacion;
    double factorial1;
    double factorial2;
    char validar1;
    char validar2;
    char seguir = 's';
    int flagCalculo = 0;


    do
    {
        switch(opcionesCalc(primerNum,segundoNum))
        {
        case 1:

            validar1 = validacion("Desea ingresar el primer numero? s/n :","Error:Desea ingresar el primer numero? s/n : ",'s','n');
            printf("\n(Aviso! Solo se realizar factoriales menores a 22)\n");

            if(validar1 == 's')
            {
                primerNum = ingresarNum("\nIngrese el primer operando : ");
                break;
            }
            else
            {
                break;
            }

        case 2:
            validar2 = validacion("Desea ingresar el segundo numero? s/n : ","Error:Desea ingresar el segundo numero? s/n : ",'s','n');
            printf("\n(Aviso! Solo se realizara factoriales menores a 22)\n");

            if(validar2 == 's')
            {
                segundoNum = ingresarNum("\nIngrese el primer operando : ");
                break;
            }
            else
            {
                break;
            }

        case 3:

            sumar(&suma,primerNum,segundoNum);
            restar(&resta, primerNum, segundoNum);
            dividir(&division, primerNum, segundoNum);
            multiplicar(&multiplicacion, primerNum,segundoNum);
            factorial1 = factorizar(primerNum);
            factorial2 = factorizar(segundoNum);
            flagCalculo = 1;
            break;

        case 4:

            if(flagCalculo == 0)
            {
                printf("-------------------------------------------------");
                printf("\nDebe Realizar todas las operaciones primero\n");
                printf("-------------------------------------------------\n");
                system("pause");
                break;
            }
            else
            {
                if(segundoNum == 0)
                {
                    printf("\nNo es posible dividir por cero\n\n");
                    resultados(suma,resta,multiplicacion,factorial1,factorial2);

                }
                else
                {
                    printf("\nEl resultado de la division es %.2f\n\n",division);
                    resultados(suma,resta,multiplicacion,factorial1,factorial2);
                }

                flagCalculo = 0;
                system("pause");
                break;
            }

        case 5:
            seguir = 'n';
            break;

        default:
            printf("-------------------------------------------------");
            printf("\nNo es una opcion valida\n");
            printf("-------------------------------------------------\n");
            system("pause");
            break;

        }

        system("cls");


    }
    while (seguir == 's');



    return 0;
}










