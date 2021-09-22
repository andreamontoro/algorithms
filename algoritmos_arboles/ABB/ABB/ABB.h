#pragma once
#include "Nodo.h"

// �rbol binario de b�squeda. 
class ABB
{
	Nodo *raiz; 
	int n; 
public:

	//Contructor de un ABB
	// Complejidad temporal y espacial: O(1)
	ABB();

	// Complejidad temporal: O(lgn) en el mejor caso, O(n) en el peor
	// Complejidad espacial: O(lgn) en el mejor caso, O(n) en el peor
	void insertar (int nuevoElemento);

	// Complejidad temporal: O(lgn) en el mejor caso, O(n) en el peor
	// Complejidad espacial: O(lgn) en el mejor caso, O(n) en el peor
	Nodo *buscar(int elementoABuscar);

	// Complejidad temporal: O(lgn) en el mejor caso, O(n) en el peor
	// Complejidad espacial: O(lgn) en el mejor caso, O(n) en el peor
	void eliminar (int elementoAEliminar);

	// Complejidad temporal: O(n), siendo n el numero de nodos, tanto en el peor como mejor caso
	// Complejidad espacial: O(lgn) en el mejor caso, O(n) en el peor caso
	void imprimir();

	bool esABB();
	bool esAVL();
	void leerArbol();

	// Complejidad temporal: O(n), siendo n el numero de nodos, tanto en el peor como en el mejor caso
	// Complejidad espacial: O(lgn) en el mejor de los casos, O(n) en el peor
	~ABB();

protected:

	// Complejidad temporal: O(n), siendo n el numero de nodos, tanto en el peor como en el mejor caso
	// Complejidad espacial: O(lgn) en el mejor de los casos, O(n) en el peor
	void eliminarSubarbol (Nodo *raizSubarbol);

	// Complejidad temporal: O(lgn) en el mejor de los casos, O(n) en el peor, n es el numero de nodos existentes
	// Complejidad espacial: O(lgn) en el mejor de los casos, O(n) en el peor
	Nodo *buscarHueco(Nodo *raizSubarbol, int elementoAInsertar);

	// Complejidad temporal: O(lgn) en el mejor caso, O(n) en el peor, n es el numero de nodos existentes
	// Complejidad espacial: O(lgn) en el mejor caso, O(n) en el peor
	Nodo *buscarRecursivo (Nodo *raizSubarbol, int elementoABuscar);

	// Complejidad temporal: O(lgn) en el mejor caso, O(n) en el peor, n es el numero de nodos existentes
	// Complejidad espacial: O(lgn) en el mejor caso, O(n) en el peor
	Nodo *buscarMaximo (Nodo *raizSubarbol);

	// Complejidad temporal: O(lgn) en el mejor caso, O(n) en el peor, n es el numero de nodos existentes
	// Complejidad espacial: O(lgn) en el mejor caso, O(n) en el peor
	Nodo *buscarMinimo (Nodo *raizSubarbol);

	// Complejidad temporal: O(lgn) en el mejor caso, O(n) en el peor, n es el numero de nodos existentes que empieza
	//en el nodo auxiliar que usamos.
	// Complejidad espacial: O(lgn) en el mejor caso, O(n) en el peor
	void eliminarNodo (Nodo *nodoParaEliminar);

	// Complejidad temporal: O(n), tanto en el peor como en el mejor de los casos
	// Complejidad espacial: O(lgn) en el mejor de los casos O(n) en el peor
	// siendo n es el numero de nodos
	int alturaNodo(Nodo *raizSubarbol);
	// Complejidad temporal: O(n), tanto en el peor como en el mejor de los casos
	// Complejidad espacial: O(lgn) en el mejor de los casos O(n) en el peor
	// siendo n es el numero de nodos
	void imprimirRecorrido(Nodo *raizSubarbol);
	//complejidad O(2n) dos veces la llamda a la funcion que se va a realizar n veces hasta llegar al final
	bool esSubABB(Nodo *raizSubarbol);
	//complejidad O(n^2) la complejidad de altura nodo por la complejidad de AVL.
	bool esSubAVL(Nodo *raizSubarbol);
	Nodo * leerSubarbol(Nodo *padre);	
};

