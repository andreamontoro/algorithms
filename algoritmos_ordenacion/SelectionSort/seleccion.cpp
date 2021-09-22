#include "seleccion.h"


//minimo: variable que guarda el minimo en una comparacion
void ordenacionSeleccion(int *array, int tamano){
    int minimo=0;
    for(int i=0; i<tamano-1; ++i){
        for(int j=i+1; j<tamano; ++j){
            if(array[i]>array[j]){
                minimo = array[j];
                array[j]=array[i];
                array[i]=minimo;
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