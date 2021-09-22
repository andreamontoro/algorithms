#include "Ordenacion.h"

void ordenarArray (int *array, int tamano){
    int max;
    for(int i=0; i<tamano; ++i){
        for(int j=i+1; j < tamano; ++j){
        if(array[j]>array[i]){
            max=array[j];
            array[j]=array[i];
            array[i]=max;
        }
        }
    }
    

}
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}

void imprimir(int * array, int tamano){
    if(tamano>=10){
        cout << "<Demasiados elementos para mostrar>" << endl;
        return;
    }
    cout << "Mostrando array..." << endl;
    for(int i=0; i<tamano; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}