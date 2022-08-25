#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "LinkedList.h"
#include "motos.h"
#include "parser.h"
#include "controller.h"

/** \brief Parsea los datos los datos de las motos desde el archivo data.csv.
 *
 * \param pFile FILE*
 * \param pArrayListMotos LinkedList*
 * \return int
 *
 */
int parser_MotosFromText(FILE* pFile, LinkedList* pArrayListMotos)
{

    eMoto* pMoto;
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


                pMoto = moto_newParametros(var1,var2,var3,var4);


                if(pMoto != NULL)
                {

                    ll_add(pArrayListMotos,pMoto);
                    retorno = 0;

                }

            }


        }
        while (!feof(pFile));


    }

    free(pMoto);

    return retorno;
}
