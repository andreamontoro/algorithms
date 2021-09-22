#pragma once
#include "Nodo.h"

class ListaEnlazada
{
	Nodo *lista;

	int n;

	Nodo * getNodo (int posicion);

public:


	ListaEnlazada();

	//Funcion que devuelve el valor de una posicion
    int getValor(int posicion);
    //Funcion que en una posicion le da un valor
    void setValor(int posicion, int nuevoValor);
    //Funcion que devuelve los elementos de la lista
    int getN();
    //Funcion que insertar en una posicion un valor 
	//Precondicion, la posicion tiene que estar dentro de "n"
    void insertar(int posicion, int nuevoValor);
    //Funcion que elemina un elemento de la lista
    void eliminar(int posicion);
    //Funcion que concatena dos listas
    void concatenar(ListaEnlazada *listaAConcatenar);
    //Funcion que busca en la lista un elemento
    int buscar(int elementoABuscar);
    //Funcion que libera memoria
    ~ListaEnlazada();

};






