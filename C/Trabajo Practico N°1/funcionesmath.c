#include <stdio.h>
#include <stdlib.h>
#include "funcionesmath.h"

void sumar(float *a,float b,float c)
{
    float resultado;
    resultado = b+c;

    *a = resultado;

}
void restar(float *a, float b, float c)
{
    float resultado;
    resultado = b-c;

    *a = resultado;



}
void dividir(float *a, float b, float c)
{
    float resultado;

    resultado = b/c;

    *a = resultado;

}
void multiplicar(float *a,float b,float c)
{
    float resultado;
    resultado = b*c;

    *a = resultado;

}
double factorizar(double b)
{

    double resultado;

    if(b < 0 || b >= 22 )
    {
        resultado = -1;

    }
    else if( b > 0 && b < 22)
    {
        resultado = b*(factorizar(b-1));

    }
    else
    {
        resultado = 1;

    }

    return resultado;



}
