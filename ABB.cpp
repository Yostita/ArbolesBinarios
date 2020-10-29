/*----------------------------------*/
/*  Practica 9. José Luis Bellosta  */
/*----------------------------------*/

#include "ABB.h"
#include "assertdomjudge.h"
#include "iostream"

using namespace std;

ABB::ABB() {
	raiz = NULL;
	n = 0;
}

void ABB::insertar(int nuevoElemento) {
	Nodo *nodo = new Nodo;
	nodo->contenido = nuevoElemento;
	nodo->padre = NULL;
	nodo->hijoIzquierdo = NULL;
	nodo->hijoDerecho = NULL;

	if (n == 0) {
		raiz = nodo;
	}else {
		Nodo *padre = buscarHueco(raiz, nuevoElemento); 

		if (nuevoElemento <= padre->contenido) {
			padre->hijoIzquierdo = nodo;
		}else {
			padre->hijoDerecho = nodo;
		}
		nodo->padre = padre;
	}
	n++;
}

Nodo* ABB::buscar(int elementoABuscar) {
	return(buscarRecursivo(raiz, elementoABuscar));
}

void ABB::eliminar(int elementoAEliminar) {
	assertdomjudge(n > 0);

	Nodo* temp = buscar(elementoAEliminar);
	eliminarNodo(temp);
	n--;

	if (n == 0) {
		raiz = NULL;
	}
}

void ABB::imprimir()
{
	if (raiz == NULL)
		cout << "VACIO" << endl;
	else
		imprimirRecorrido(raiz);
}

bool ABB::esABB() {
	if (esSubABB(raiz)) {
		return true;
	}
	return false;
}

bool ABB::esAVL() {
	if (raiz == NULL) {
		return true;
	}
	else {
		return esABB() && esSubAVL(raiz);
	}
}


ABB::~ABB() {
	if (raiz != NULL && n!=0) {
		eliminarSubarbol(raiz);
	}
}

void ABB::eliminarSubarbol(Nodo *raizSubarbol) {
	assertdomjudge(raizSubarbol != NULL);

	if (raizSubarbol->hijoIzquierdo != NULL) {
		eliminarSubarbol(raizSubarbol->hijoIzquierdo);
	}

	if (raizSubarbol->hijoDerecho != NULL) {
		eliminarSubarbol(raizSubarbol->hijoDerecho);
	}

	Nodo *padre = raizSubarbol->padre; 

	if (padre != NULL) {
		if (padre->hijoIzquierdo == raizSubarbol) {
			padre->hijoIzquierdo = NULL;
		}
		if (padre->hijoDerecho == raizSubarbol) {
			padre->hijoDerecho = NULL;
		}
	}

	delete raizSubarbol;
}

Nodo* ABB::buscarHueco(Nodo *raizSubarbol, int elementoAInsertar) {
	assertdomjudge(raizSubarbol != NULL);

	if (elementoAInsertar <= raizSubarbol->contenido) {
		if (raizSubarbol->hijoIzquierdo != NULL) {
			return (buscarHueco(raizSubarbol->hijoIzquierdo, elementoAInsertar));
		}else 
			return (raizSubarbol);
	}else
		if (raizSubarbol->hijoDerecho != NULL) {
			return (buscarHueco(raizSubarbol->hijoDerecho, elementoAInsertar));
		}else 
			return (raizSubarbol);
}
Nodo* ABB::buscarRecursivo(Nodo *raizSubarbol, int elementoABuscar) {
	if (raizSubarbol == NULL) {
		return (NULL);
	}else
		if (raizSubarbol->contenido == elementoABuscar) {
			return (raizSubarbol);
		}else
			if (elementoABuscar < raizSubarbol->contenido) {
				return (buscarRecursivo(raizSubarbol->hijoIzquierdo, elementoABuscar));
			}else
				return (buscarRecursivo(raizSubarbol->hijoDerecho, elementoABuscar));
}

Nodo* ABB::buscarMaximo(Nodo *raizSubarbol) {
	assertdomjudge(raizSubarbol != NULL);

	if (raizSubarbol->hijoDerecho == NULL) {
		return (raizSubarbol);
	}else 
		return (buscarMaximo(raizSubarbol->hijoDerecho));
}

Nodo* ABB::buscarMinimo(Nodo *raizSubarbol) {
	assertdomjudge(raizSubarbol != NULL);

	if (raizSubarbol->hijoIzquierdo == NULL) {
		return (raizSubarbol);
	}else
		return (buscarMinimo(raizSubarbol->hijoIzquierdo));
}

void ABB::eliminarNodo(Nodo *nodoParaEliminar) {
	Nodo* temp = NULL;
	if (nodoParaEliminar != NULL) {
		if (nodoParaEliminar->hijoIzquierdo == NULL && nodoParaEliminar->hijoDerecho == NULL) {
			Nodo* padre = nodoParaEliminar->padre;
			if (padre != NULL) {
				if (padre->hijoIzquierdo == nodoParaEliminar) padre->hijoIzquierdo = NULL;
				if (padre->hijoDerecho == nodoParaEliminar) padre->hijoDerecho = NULL;
			}
			delete nodoParaEliminar;
		}
		else {
			if (nodoParaEliminar->hijoIzquierdo != NULL && nodoParaEliminar->hijoDerecho != NULL) {
				if (alturaNodo(nodoParaEliminar->hijoDerecho) > alturaNodo(nodoParaEliminar->hijoIzquierdo)) {
					temp = nodoParaEliminar->hijoDerecho;
				}
				else {
					temp = nodoParaEliminar->hijoIzquierdo;
				}
			}
			else if (nodoParaEliminar->hijoIzquierdo == NULL && nodoParaEliminar->hijoDerecho != NULL) {
				temp = buscarMinimo(nodoParaEliminar->hijoDerecho);
			}
			else {
				temp = buscarMaximo(nodoParaEliminar->hijoIzquierdo);
			}
			nodoParaEliminar->contenido = temp->contenido;
			eliminarNodo(temp);
		}
	}
}

int ABB::alturaNodo(Nodo* raizSubarbol) {
	if (raizSubarbol == NULL) {
		return -1;
	}
	else {
		if (alturaNodo(raizSubarbol->hijoIzquierdo) > alturaNodo(raizSubarbol->hijoDerecho)) {
			return 1 + alturaNodo(raizSubarbol->hijoIzquierdo);
		}
		else {
			return 1 + alturaNodo(raizSubarbol->hijoDerecho);
		}
	}
}

void ABB::imprimirRecorrido(Nodo *raizSubarbol)
{
	assertdomjudge(raizSubarbol != NULL);

	cout << raizSubarbol->contenido << endl;
	if (raizSubarbol->hijoIzquierdo != NULL)
	{
		cout << "I";
		imprimirRecorrido(raizSubarbol->hijoIzquierdo);
		cout << endl;
	}
	if (raizSubarbol->hijoDerecho != NULL)
	{
		cout << "D";
		imprimirRecorrido(raizSubarbol->hijoDerecho);
		cout << endl;
	}
}

bool ABB::esSubABB(Nodo *raizSubarbol) {
	if (raizSubarbol != NULL) {
		if ((raizSubarbol->hijoIzquierdo == NULL || raizSubarbol->contenido > raizSubarbol->hijoIzquierdo->contenido)
			&& (raizSubarbol->hijoDerecho == NULL || raizSubarbol->contenido < raizSubarbol->hijoDerecho->contenido)) {
			return esSubABB(raizSubarbol->hijoDerecho);
		}
		else {
			return false;
		}

	}
	return true;
}

bool ABB::esSubAVL(Nodo* raizSubarbol) {  
	if (raizSubarbol->hijoIzquierdo == NULL && raizSubarbol->hijoDerecho == NULL) {
		return true;
	}
	else if (raizSubarbol->hijoIzquierdo != NULL && raizSubarbol->hijoDerecho == NULL) {
		return alturaNodo(raizSubarbol->hijoIzquierdo) == 0;
	}
	else if (raizSubarbol->hijoIzquierdo == NULL && raizSubarbol->hijoDerecho != NULL) {
		return alturaNodo(raizSubarbol->hijoDerecho) == 0;
	}
	else {
		return esSubAVL(raiz->hijoIzquierdo) && esSubAVL(raiz->hijoDerecho);
	}
}

void ABB::leerArbol()
{
	raiz = leerSubarbol(NULL);
}

Nodo * ABB::leerSubarbol(Nodo *padre)
{
	int contenido;
	cin >> contenido;
	if (contenido >= 0)
	{
		Nodo *arbol = new Nodo;
		arbol->contenido = contenido;
		arbol->hijoIzquierdo = leerSubarbol(arbol);
		arbol->hijoDerecho = leerSubarbol(arbol);
		arbol->padre = padre;
		return arbol;
	}
	else
	{
		return NULL;
	}
}