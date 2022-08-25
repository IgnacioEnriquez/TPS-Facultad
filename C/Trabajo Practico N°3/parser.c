#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{

    Employee* pEmployee;
    int retorno = -1;
    int r;
    char var1[50];
    char var2[50];
    char var3[50];
    char var4[50];

    //if(pFile != NULL && pArrayListEmployee != NULL)
    if(pFile != NULL)
    {


        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        do
        {

            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);

            if(r == 4)
            {


                pEmployee = employee_newParametros(var1,var2,var3,var4);


                if(pEmployee != NULL)
                {

                    ll_add(pArrayListEmployee,pEmployee);
                    retorno = 0;

                }

            }


        }
        while (!feof(pFile));


    }

    free(pEmployee);

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = 1;

    Employee* pEmployee;

    if(pFile != NULL)
    {
        do
        {
            pEmployee = employee_new();

            if(fread(pEmployee, sizeof(Employee), 1, pFile) == 1)
            {
                ll_add(pArrayListEmployee, pEmployee);
                retorno = 0;
            }

        }
        while(!feof(pFile));

    }

    return retorno;
}
