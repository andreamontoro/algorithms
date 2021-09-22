#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

// Estructura que representa un nodo de una lista enlazada
struct Nodo
{
	int elemento; // El elemento que guarda el nodo
	Nodo *siguienteNodo; // Puntero al siguiente nodo de la lista enlazada
};

