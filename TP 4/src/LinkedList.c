#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

static Node* getNode(LinkedList *this, int nodeIndex);
static int addNode(LinkedList *this, int nodeIndex, void *pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void) {

	LinkedList *this = NULL;

	this = (LinkedList*) malloc(sizeof(LinkedList));

	if (this != NULL) {

		this->size = 0;
		this->pFirstNode = NULL;

	}
	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList *this) {
	int returnAux = -1;

	if (this != NULL) {

		returnAux = this->size;

	}
	return returnAux;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList *this, int nodeIndex) {

	if (this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)) {

		Node *pNode = NULL;

		pNode = this->pFirstNode;

		for (int i = 0; i < nodeIndex; i++) {

			pNode = pNode->pNextNode;
		}

		return pNode;

	}

	else {

		return NULL;
	}
}
/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList *this, int nodeIndex) {

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
static int addNode(LinkedList *this, int nodeIndex, void *pElement) {
	int returnAux = -1;

	Node *pNode = NULL;
	Node *pNodeAux = NULL;

	if (this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)) {

		pNode = (Node*) malloc(sizeof(Node));

		if (pNode != NULL) {

			pNode->pElement = pElement;

			if (nodeIndex == 0) {

				pNode->pNextNode = this->pFirstNode;

				this->pFirstNode = pNode;

			}

			else {

				pNodeAux = getNode(this, nodeIndex - 1);

				pNode->pNextNode = pNodeAux->pNextNode;

				pNodeAux->pNextNode = pNode;

			}

			this->size++;

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
int test_addNode(LinkedList *this, int nodeIndex, void *pElement) {
	return addNode(this, nodeIndex, pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList *this, void *pElement) { //A diferencia de addNode, solo agrega al final (no se elige index)
	int returnAux = -1;

	if (this != NULL) {

		if (addNode(this, ll_len(this), pElement) == 0) {

			returnAux = 0;

		}
	}

	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList *this, int index) {
	void *returnAux = NULL;

	Node *pNode = NULL;

	if (this != NULL && index >= 0 && index < ll_len(this)) {

		pNode = getNode(this, index);

		if (pNode != NULL) {

			returnAux = pNode->pElement;
		}

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
int ll_set(LinkedList *this, int index, void *pElement) {
	int returnAux = -1;

	Node *pNode;

	if (this != NULL && index >= 0 && index < ll_len(this)) {

		pNode = getNode(this, index);

		if (pNode != NULL) {

			pNode->pElement = pElement;

			returnAux = 0;
		}

	}

	return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList *this, int index) {
	int returnAux = -1;

	Node *pNode = NULL;
	Node *pNodeAux = NULL;

	if (this != NULL && index >= 0 && index <= ll_len(this)) {

		pNode = getNode(this, index);

		if (pNode != NULL) {

			if (index == 0) {

				this->pFirstNode = pNode->pNextNode;
			}

			else {

				pNodeAux = getNode(this, index - 1);

				pNodeAux->pNextNode = pNode->pNextNode;

			}

			free(pNode);

			this->size--;

			returnAux = 0;

		}
	}

	return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList *this) {
	int returnAux = -1;

	if (this != NULL) {

		int len = ll_len(this);

		while (len) { // Se hace siempre en el indice 0 para no perder la referencia del next node

			ll_remove(this, 0);
			len--;
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
int ll_deleteLinkedList(LinkedList *this) {
	int returnAux = -1;

	if (this != NULL) {

		if (ll_clear(this) == 0) {

			free(this);

			returnAux = 0;
		}

	}

	return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList *this, void *pElement) {
	int returnAux = -1;

	if (this != NULL) {

		for (int i = 0; i < ll_len(this); i++) {

			if (ll_get(this, i) == pElement) {

				returnAux = i;
				break;

			}

		}

	}

	return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si la lista NO esta vacia
 ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList *this) {
	int returnAux = -1;

	if (this != NULL) {

		returnAux = 0;

		if (ll_len(this) == 0) { //returnAux = ll_len(this)? 0 : 1; (Condicional lineal)

			returnAux = 1;
		}

	}

	return returnAux;
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
int ll_push(LinkedList *this, int index, void *pElement) {
	int returnAux = -1;

	if (this != NULL && index >= 0 && index <= ll_len(this)) {

		if (addNode(this, index, pElement) == 0) {

			returnAux = 0;
		}

	}

	return returnAux;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList *this, int index) {

	void *returnAux = NULL;

	void *pElement;

	if (this != NULL && index >= 0 && index <= ll_len(this)) {

		pElement = ll_get(this, index);

		if (pElement != NULL && ll_remove(this, index) == 0) {

			returnAux = pElement;
		}
	}

	return returnAux;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 1) Si contiene el elemento
 ( 0) si No contiene el elemento
 */
int ll_contains(LinkedList *this, void *pElement) {
	int returnAux = -1;

	if (this != NULL) {

		returnAux = 0;

		if (ll_indexOf(this, pElement) != -1) {

			returnAux = 1;
		}
	}

	return returnAux;
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
int ll_containsAll(LinkedList *this, LinkedList *this2) {
	int returnAux = -1;

	if (this != NULL && this2 != NULL) {

		returnAux = 1;

		Node *pNode;

		for (int i = 0; i < ll_len(this2); i++) {

			pNode = (Node*) ll_get(this, i);

			if (ll_contains(this, pNode) == 0) {

				returnAux = 0;

				break;
			}

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
LinkedList* ll_subList(LinkedList *this, int from, int to) {

	LinkedList *cloneArray = NULL;

	Node *pNode;

	if (this != NULL && from >= 0 && from <= ll_len(this) && to >= from
			&& to <= ll_len(this)) {

		cloneArray = ll_newLinkedList();

		if (cloneArray != NULL) {

			for (int i = from; i < to; i++) {

				pNode = ll_get(this, i);

				if (pNode != NULL) {

					ll_add(cloneArray, pNode);
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
LinkedList* ll_clone(LinkedList *this) {
	LinkedList *cloneArray = NULL;

	Node *pNode;

	if (this != NULL) {

		cloneArray = ll_newLinkedList();

		if (cloneArray != NULL) {

			for (int i = 0; i < ll_len(this); i++) {

				pNode = ll_get(this, i);

				if (pNode != NULL) {

					ll_add(cloneArray, pNode);
				}

			}

		}

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
int ll_sort(LinkedList *this, int (*pFunc)(void*, void*), int order) {
	int returnAux = -1;
	void *pElement1;
	void *pElement2;

	if (this != NULL && pFunc != NULL && (order == 0 || order == 1)) {

		for (int i = 0; i < ll_len(this) - 1; i++) {
			for (int j = i + 1; j < ll_len(this); j++) {
				pElement1 = ll_get(this, i);
				pElement2 = ll_get(this, j);

				if ((pFunc(pElement1, pElement2) > 0 && order == 1)
						|| (pFunc(pElement1, pElement2) < 0 && order == 0)) {
					ll_set(this, i, pElement2);
					ll_set(this, j, pElement1);
				}
			}
		}
		returnAux = 0;
	}

	return returnAux;

}
/**
 * Toma los elementos de la lista, los pasa por una funcion
 * recibida por parametro y los incorpora modificados
 * @param this Puntero a la lista
 * @param pFunc Funcion a utilizar
 * @return Puntero a la Lista
 */
LinkedList* ll_map(LinkedList *this, void (*pFunc)(void *Element)) {

	void *pElement;

	if (this != NULL && pFunc != NULL) {

		for (int i = 0; i < ll_len(this); i++) {

			pElement = ll_get(this, i);

			pFunc(pElement);

			ll_set(this, i, pElement);

		}

	}

	return this;
}

/**
 * Filtra los elementos de una lista
 * @param this Puntero a la Lista a filtrar
 * @param pFunc Funcion con la condicion para filtrar (Devuelve 1 Si el elemento CUMPLE la condicion y 0 si NO CUMPLE)
 * @return Puntero a la nueva Lista filtrada
 */
LinkedList* ll_filter(LinkedList *this, int (*pFunc)(void *pElement)) {

	void *pElement = NULL;

	LinkedList *filteredList = NULL;

	if (this != NULL && pFunc != NULL) {

		filteredList = ll_newLinkedList();

		if (filteredList != NULL) {

			for (int i = 0; i < ll_len(this); i++) {

				pElement = ll_get(this, i);

				if(pFunc(pElement)==1){

					ll_add(filteredList,pElement);


				}

			}
		}

	}

	return filteredList;

}


