#include "Ordenacion.h"
#include <time.h>

int main(){
    int tamano=0, *array, *array2;
    do{
    cout << "Introduce tamano del array (mayor o igual que 1)..." << endl;
    cin >> tamano;
    }while(tamano<1);
    
    array = new int[tamano];
    array2 = new int[tamano];

    srand(time(NULL));
    for(int i=0; i<tamano; ++i){
            array[i] = rand() % 10;
    }
    memcpy(array2, array, sizeof(int)*tamano);
    imprimir(array, tamano);
    //int *arrayOrdenado;
    unsigned long start=clock();
	ordenarArray(array, tamano);
	unsigned long end=clock();
    cout << "Clocks de inicio por ordenacion propia: " << start << endl;
    cout << "Clocks de fin por ordenacion propia: " << end << endl;
    cout << "CLOCKS_PER_SEC: " << CLOCKS_PER_SEC << endl;
    cout << "Con ordenacion propia he tardado "  << std::fixed << std::setw( 11 )<<std::setprecision( 7 ) << (end-start)/(double)CLOCKS_PER_SEC << " segundos en ordenarlo" << endl;
    cout << "El vector resultado es: " << endl;
    imprimir(array, tamano);

    start=clock();
	qsort(array2, tamano, sizeof(int), cmpfunc);
	end=clock();
    cout << "Clocks de inicio por ordenacion por Qsort: " << start << endl;
    cout << "Clocks de fin por ordenacion Qsort: " << end << endl;
    cout << "CLOCKS_PER_SEC: " << CLOCKS_PER_SEC << endl;
    cout << "Con ordenacion por Qsort he tardado "  << std::fixed << std::setw( 11 )<<std::setprecision( 7 ) << (end-start)/(double)CLOCKS_PER_SEC << " segundos en ordenarlo" << endl;
    cout << "El vector resultado es: " << endl;
    imprimir(array2, tamano);
    delete [] array;
    delete [] array2;
    
    

}

//LIBERARRRRR MEMORIA!!!!!!!!!!!!!!