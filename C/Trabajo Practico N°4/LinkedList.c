#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "motos.h"
#include "parser.h"
#include "controller.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void) //usado
{
    LinkedList* nuevaLista;

    nuevaLista = (LinkedList*) malloc (sizeof(LinkedList));

    if(nuevaLista != NULL)
    {
        nuevaLista ->size = 0;
        nuevaLista ->pFirstNode = NULL;

    }

    return nuevaLista;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this) //usado
{
    int cantidad = -1;

    if(this != NULL)
    {
        cantidad = this -> size;

    }

    return cantidad;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* nodo = NULL;

    if(this != NULL  && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {

        nodo =  this  -> pFirstNode;

        while(nodeIndex > 0)
        {
            nodo = nodo ->pNextNode;
            nodeIndex--;

        }

    }

    return nodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement) //usado
{
    int returnAux = -1;
    Node* nuevoNodo = NULL;
    Node* anterior = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        nuevoNodo = (Node*) malloc(sizeof(Node));

        if(nuevoNodo != NULL)
        {
            nuevoNodo -> pElement = pElement;
            nuevoNodo ->pNextNode = NULL;

            if(nodeIndex == 0)
            {
                nuevoNodo -> pNextNode = this -> pFirstNode;
                this -> pFirstNode = nuevoNodo;

            }
            else
            {
                anterior = getNode(this,nodeIndex - 1);
                nuevoNodo ->pNextNode = anterior -> pNextNode;
                anterior ->pNextNode = nuevoNodo;



            }
            this -> size++;
            returnAux = 0;



        }




    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement) //usado
{

    return addNode(this,ll_len(this), pElement);

}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index) //usado
{
    void* returnAux = NULL;
    Node* auxNode = NULL;


    auxNode = getNode(this,index);

    if(auxNode != NULL)
    {
        returnAux = auxNode ->pElement;

    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int isOk = -1;
    Node* pNodeAux;
    pNodeAux = getNode(this, index);

    if(pNodeAux != NULL)
    {
        pNodeAux->pElement = pElement;
        isOk = 0;
    }

    return isOk;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index) //usado
{
    int isOk = -1;
    Node* pNodeAux;
    Node* pPrevNode;
    Node* pNextNode;

    pNodeAux = getNode(this, index); //dir memo
    pNextNode = getNode(this, index + 1); //dir memo nodo siguiente al actual

    if(pNodeAux != NULL)//no valido pNextNode, porque puede ser NULL
    {
        if(index == 0)
        {
            this->pFirstNode = pNextNode; //nodo siguiente al actual = this->pFirstNode = pNodeAux->pNextNode
            free(pNodeAux);
            this->size--;
            isOk = 0;
        }
        else
        {
            pPrevNode = getNode(this, index - 1);
            if(pPrevNode != NULL)
            {
                pPrevNode->pNextNode = pNextNode;
                free(pNodeAux);
                this->size--;
                isOk = 0;
            }
        }
    }

    return isOk;
}
/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this) //
{
    int returnAux = -1;

    if(this != NULL)
    {

        while(ll_len(this) != 0)
        {

            ll_remove(this,0);

        }

        returnAux = 0;

    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this) //usado
{
    int isOk = -1;

    if (this != NULL && !ll_clear(this))
    {
        free(this);
        isOk = 0;
    }
    return isOk;
}
/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int indexNode = -1;
    Node* pNodeAux;

    if(this != NULL)
    {
        for(int i = 0; i < ll_len(this); i++)
        {
            pNodeAux = getNode(this, i);
            if(pNodeAux != NULL && pNodeAux->pElement == pElement)
            {
                indexNode = i;
                break;
            }
        }
    }

    return indexNode;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this) //usado
{
    int isEmpty = -1;

    if(this != NULL)
    {
        if(ll_len(this))
        {
            isEmpty = 0; //no esta vacia
        }
        else
        {
            isEmpty = 1;//esta vacia
        }
    }

    return isEmpty;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int isOk = -1;

    //if(this != NULL && index <= ll_len(this) && index >= 0)
    //{
    isOk = addNode(this, index, pElement);
    // }

    return isOk;
}



/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* pElement = NULL;

    if(this != NULL && index <= ll_len(this) && index >= 0)
    {
        pElement = ll_get(this, index);
        if(pElement != NULL)
        {
            ll_remove(this, index);
        }
    }

    return pElement;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{

    int exist = -1;

    if (this != NULL)
    {
        if (ll_indexOf(this, pElement) > -1)
        {
            exist = 1;
        }
        else
        {
            exist = 0;
        }
    }
    return exist;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int len = 0;

    void* pElem;

    if(this != NULL && this2 != NULL)
    {
        returnAux = 0;
        if(ll_len(this) >= ll_len(this2))
        {
            for(int i = 0; i < ll_len(this2); i++)
            {
                pElem = ll_get(this2, i);
                if(ll_contains(this, pElem) == 1)
                {
                    len++;
                }
                else
                {
                    break;
                }
            }
        }

        if(len == ll_len(this2))
        {
            returnAux = 1;
        }
    }

    return returnAux;
}
/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    Node* pNode;
    int indexNode = 0;

    if(this != NULL && from >= 0 && from <= ll_len(this) && to >= from && to <= ll_len(this))
    {
        cloneArray = ll_newLinkedList();//pido espacio

        if(cloneArray != NULL)
        {
            for(int i = from; i < to; i++)
            {
                pNode = getNode(this, i);
                if(pNode != NULL)
                {
                    addNode(cloneArray, i, pNode->pElement);
                    indexNode++;
                }
            }
        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
        cloneArray = ll_subList(this, 0, ll_len(this));//desde 0 hasta el tamanio de this
    }

    return cloneArray;
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int isOk = -1;
    void* pElement1;
    void* pElement2;

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1) )
    {
        for(int i = 0; i < ll_len(this) - 1 ; i++)
        {
            for(int j = i + 1; j < ll_len(this); j++)
            {
                pElement1 = ll_get(this, i);
                pElement2 = ll_get(this, j);

                //1. si el primer elemento es mas grande que el segundo, y el orden es ascendente, swapeo
                //2. si el primer elemento es mas chico que el segundo, y el orden es descendente, swapeo
                if((pFunc(pElement1, pElement2) > 0 && order == 1) || (pFunc(pElement1, pElement2) < 0 && order == 0))
                {
                    ll_set(this, i, pElement2); //copio el elemento 2 en el lugar del 1
                    ll_set(this, j, pElement1); //copio el elemento 1 en el lugar del 2
                }
            }
        }
        isOk = 0;
    }
    return isOk;
}
LinkedList* ll_filter(LinkedList* this,int (*pFunc)(void*))
{
    LinkedList* listaFiltrada = NULL;

    if(this != NULL && pFunc !=NULL)
    {
        listaFiltrada = ll_newLinkedList();

        if(listaFiltrada != NULL)
        {
            for(int i = 0; i < ll_len(this); i++)
            {
                if(pFunc(ll_get(this, i ) ) )
                {
                    ll_add(listaFiltrada,ll_get(this, i) );


                }


            }


        }

    }



    return listaFiltrada;
}

