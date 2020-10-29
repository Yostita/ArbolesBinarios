/*----------------------------------*/
/*  Practica 9. José Luis Bellosta  */
/*----------------------------------*/

#pragma once
#include "Nodo.h"

// �rbol binario de b�squeda. 
class ABB
{
	Nodo *raiz;
	int n;
public:
	//Constructor
	//Precondicion : ninguna
	//Complejidad Temporal : O(1)
	//Complejidad Espacial : O(1)
	ABB();

	//Introduce un elemnto en el arbol
	//Precondicion : ninguna
	//Complejidad Temporal : O(lgn), en el peor caso O(n)
	//Complejidad Espacial : O(lgn), en el peor caso O(n)
	void insertar(int nuevoElemento);

	//Busca el elemento a buscar dentro del arbol
	//Precondicion : ninguna
	//Complejidad Temporal : O(lgn), en el peor caso O(n)
	//Complejidad Espacial : O(lgn), en el peor caso O(n)
	Nodo *buscar(int elementoABuscar);

	//Elimina el primer nodo que encuentre apartir de el elementoAEliminar
	//Precondicion : que n sea mayor que 0
	//Complejidad Temporal : O(lgn), en el peor caso O(n)
	//Complejidad Espacial : O(lgn), en el peor caso O(n)
	void eliminar(int elementoAEliminar);

	void imprimir();

	//Comprueba si el arbol es ABB o no
	//Precondicion : ninguna
	//Complejidad Temporal : O(1)
	//Complejidad Espacial : O(1)
	bool esABB();

	//Comprueba si el arbol es AVL o no
	//Precondicion : ninguna
	//Complejidad Temporal : O(1)
	//Complejidad Espacial : O(1)
	bool esAVL();

	void leerArbol();

	//Destructor
	//Precondicion : ninguna
	//Complejidad Temporal : O(n)
	//Complejidad Espacial : O(lgn), en el peor caso O(n)
	~ABB();

protected:
	//Elimina de forma recursiva los nodos del subarbol
	//Precondicion : que el nodo no este vacio
	//Complejidad Temporal : O(n)
	//Complejidad Espacial : O(lgn), en el peor caso O(n)
	void eliminarSubarbol(Nodo *raizSubarbol);

	//Busca un hueco donde poder añadir un nuevo nodo
	//Precondicion : que el nodo no este vacio
	//Complejidad Temporal : O(lgn), en el peor caso O(n)
	//Complejidad Espacial : O(lgn), en el peor caso O(n)
	Nodo *buscarHueco(Nodo *raizSubarbol, int elementoAInsertar);

	//Busca un hueco donde poder añadir un nuevo nodo
	//Precondicion : ninguna
	//Complejidad Temporal : O(lgn), en el peor caso O(n)
	//Complejidad Espacial : O(lgn), en el peor caso O(n)
	Nodo *buscarRecursivo(Nodo *raizSubarbol, int elementoABuscar);

	//Busca el maximo del arbol 
	//Precondicion : que el nodo no este vacio
	//Complejidad Temporal : O(lgn), en el peor caso O(n)
	//Complejidad Espacial : O(lgn), en el peor caso O(n)
	Nodo *buscarMaximo(Nodo *raizSubarbol);

	//Busca el minimo del arbol
	//Precondicion : que el nodo no este vacio
	//Complejidad Temporal : O(lgn), en el peor caso O(n)
	//Complejidad Espacial : O(lgn), en el peor caso O(n)
	Nodo *buscarMinimo(Nodo *raizSubarbol);

	//Elimina el nodo nodoParaEliminar
	//Precondicion : ninguna
	//Complejidad Temporal : O(lgn), en el peor caso O(n)
	//Complejidad Espacial : O(lgn), en el peor caso O(n)
	void eliminarNodo(Nodo *nodoParaEliminar);

	//Calcula de forma recursiva la altura del arbol
	//Precondicion : ninguna
	//Complejidad Temporal : O(lgn), en el peor caso O(n)
	//Complejidad Espacial : O(lgn), en el peor caso O(n)
	int alturaNodo(Nodo *raizSubarbol);

	void imprimirRecorrido(Nodo *raizSubarbol);

	//Comprueba de forma recursiva si el arbol es ABB o no
	//Precondicion : ninguna
	//Complejidad Temporal : O(lgn), en el peor caso O(n)
	//Complejidad Espacial : O(lgn), en el peor caso O(n)
	bool esSubABB(Nodo *raizSubarbol);

	//Comprueba de forma recursiva si el arbol es AVL o no
	//Precondicion : ninguna
	//Complejidad Temporal : O(lgn), en el peor caso O(n)
	//Complejidad Espacial : O(lgn), en el peor caso O(n)
	bool esSubAVL(Nodo *raizSubarbol);

	Nodo * leerSubarbol(Nodo *padre);
};