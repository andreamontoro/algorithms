#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
 
class ListaContigua
{
    int *vector;
 
    int n;
 
    int capacidad;
 
    int incremento;
 
 
public:
 
    ListaContigua(int incremento);
    //Funcion que devuelve el valor de una posicion
    int getValor(int posicion);
    //Funcion que en una posicion le da un valor
    void setValor(int posicion, int nuevoValor);
    //Funcion que devuelve los elementos de la lista
    int getN();
    //Funcion que devuelve la capacidad maxima de la lista
    int getCapacidad();
    //Funcion que insertar en una posicion un valor
    void insertar(int posicion, int nuevoValor);
    //Funcion que elemina un elemento de la lista
    void eliminar(int posicion);
    //Funcion que concatena dos listas
    void concatenar(ListaContigua *listaAConcatenar);
    //Funcion que busca en la lista un elemento
    int buscar(int elementoABuscar);
    //Funcion que libera memoria
    ~ListaContigua();
};