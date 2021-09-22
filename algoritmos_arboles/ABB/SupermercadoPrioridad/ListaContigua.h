#pragma once

// Numero de posiciones en que se incrementa/decrementa la capacidad de la ListaContigua cada vez que es necesario
#define INCREMENTO 2

// Clase que representa a una lista contigua en memoria y cuya capacidad se redimensiona automaticamente
// de modo que el usuario no tiene que preocuparse por su capacidad
class ListaContigua
{
	// Puntero que apunta a la zona de memoria en donde empieza la ListaContigua
	int *vector;

	// Numero actual de elementos que tiene la ListaContigua
	// Precondicion: n>=0
	int n;

	// Capacidad actual de la ListaContigua
	// Precondiciones: capacidad >= n
	int capacidad;

	// Nos dice si la ListaContigua esta llena o no.
	// Retorno: verdadero si esta llena, falso si no esta llena
	// Complejidad temporal y espacial: O(1)
	bool isLlena();

public:

	// Constructor. Crea una ListaContigua de tamano 0
	// Complejidad temporal y espacial: O(1)
	ListaContigua();

	// Devuelve un elemento de la ListaContigua
	// Parametro: la posicion del elemento
	// Retorno: el elemento encontrado en esa posicion
	// Precondiciones: posicion en [0, n-1]
	// Complejidad temporal y espacial: O(1)
	int getValor(int posicion);

	// Modifica un elemento de la ListaContigua
	// Complejidad temporal y espacial: O(1)
	void setValor(int posicion, int nuevoValor);

	// Devuelve el tamano actual de la ListaContigua
	// Retorno: numero actual de elementos de la ListaContigua
	// Complejidad temporal y espacial: O(1)
	int getN(); 

	// Devuelve la capacidad actual de la ListaContigua
	// Retorno: numero maximo que actualmente podria contener la ListaContigua
	// Complejidad temporal y espacial: O(1)
	int getCapacidad(); 

	// Inserta un nuevo elemento en la ultima posicion de la ListaContigua, 
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(n)
	void insertarAlFinal (int nuevoValor);

	// Elimina el elemento de la ultima posicion de la ListaContigua,
	// disminuyendo posteriormente la capacidad si es necesario
	// Complejidad temporal: O(1)
	// Complejidad espacial: O(1)
	void eliminarAlFinal();

	// Inserta un nuevo elemento en una posicion de la lista, dejando primero un hueco para meterlo ahi
	// Los elementos que habia desde la posicion hasta el final de la ListaContigua se desplazaran una posicion a la derecha
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(n)
	void insertar(int posicion, int nuevoValor);

	// Elimina un elemento en una posicion dada.
	// Los elementos que hab�a desde posicion+1 hasta el final de la ListaContigua se desplazaran una posicion a la izquierda
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(n), por memmove()
	void eliminar(int posicion);

	// Concatena una lista al final de la lista actual. 
	// Cada uno de los elementos de la lista a concatenar se copian, en orden, al final de la lista actual
	// Complejidad temporal: O(n+m), siendo m = listaAConcatenar.getN()
	// Complejidad espacial: O(n+m), siendo m = listaAConcatenar.getN()
	void concatenar(ListaContigua *listaAConcatenar);

	// Busca la posicion de un elemento en la ListaContigua
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	int buscar(int elementoABuscar);

	// Destructor. Libera memoria
	// Complejidad temporal y espacial: O(1)
	~ListaContigua();
};








