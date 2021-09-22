#include "seleccion.h"

//numElementos: numero de componentes del array
//arrayInteger: array de int
int main(){
    int numElementos=0;
    int *arrayInteger;

    cout << "Introduzca la cantidad de elementos" << endl;
    cin >> numElementos;
    arrayInteger = new int [numElementos];
    cout << "Introduzca los " << numElementos <<  " elementos" << endl;
    rellenarArray(arrayInteger,numElementos);
    ordenacionSeleccion(arrayInteger, numElementos);

return 0;

}