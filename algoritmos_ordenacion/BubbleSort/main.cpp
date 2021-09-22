#include "Burbuja.h"

//numElementos: numero de elementos a ordenar
//arrayInteger: el array que contendra esos elementos
int main(){
    int numElementos=0;
    int *arrayInteger;

    cout << "Introduzca la cantidad de elementos" << endl;
    cin >> numElementos;
    arrayInteger = new int [numElementos];
    cout << "Introduzca los " << numElementos <<  " elementos" << endl;
    rellenarArray(arrayInteger,numElementos);
    ordenacionBurbuja(arrayInteger, numElementos);

return 0;

}