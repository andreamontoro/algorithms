#ifndef __BURBUJA__H__
#define __BURBUJA__H__
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

//Ordenacion por el metodo de burbuja (de menor a mayor).
//Comparar elemento  con el siguiente y acorta los extremos a comparar.
//Aux: variable auxiliar para realizar el cambio de elementos.
void ordenacionBurbuja(int * array, int tamano);

//Impresion del array, necesita el array y tamano.
void imprimirArray(int *array, int tamano);

//Rellenar array, necesita el array y tamano
void rellenarArray(int *arrar, int tamano);








#endif  