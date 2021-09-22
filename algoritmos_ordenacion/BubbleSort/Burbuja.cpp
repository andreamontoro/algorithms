#include "Burbuja.h"

void ordenacionBurbuja(int * array, int tamano){
    int aux=0;
    for(int z = 1; z < tamano; ++z) {
      for(int v = 0; v < (tamano - z); v++) {
         
         if(array[v] > array[v+1]){
            aux = array[v];
            array[v] = array[v + 1];
            array[v + 1] = aux; 
         }
      }
      imprimirArray(array,tamano);
    }
}


void imprimirArray(int *array, int tamano){
    for(int i=0; i<tamano; ++i){
        cout << array[i]<< " ";
    }
    cout << endl;
}

void rellenarArray(int *array, int tamano){
    for(int i=0; i<tamano; ++i){
        cin >> array[i];
    }
}