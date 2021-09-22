#include "ListaContigua.h"
 
ListaContigua::ListaContigua(int incremento){
        this->n=0;
        this->incremento = incremento;
        this->capacidad = incremento;
        this->vector = (int*)malloc(sizeof(int)*capacidad);
   
 
}
 
    int ListaContigua::getValor(int posicion){
        return (this->vector[posicion]);
    }
 
    void ListaContigua::setValor(int posicion, int nuevoValor){ 
            this->vector[posicion] = nuevoValor;
       
    }
 
    int ListaContigua::getN(){
        return this->n;
    }
 
    int ListaContigua::getCapacidad(){
        return this->capacidad;
    }
    
    void ListaContigua::insertar(int posicion, int nuevoValor){
        //Si la lista esta llena, numero de elementos igual a capacidad maxima de elementos
        //ampliamos la memoria del vector con incremento
        if (this->n == this->capacidad) {
            //cout << "nentr< " << capacidad << " " << incremento << endl;
            this->vector = (int*)realloc(this->vector, sizeof(int)*(this->capacidad + this->incremento));
            this->capacidad += this->incremento;
        }
        //si la posicion en la que se quiere insertar en mayor que la capacidad actual hay que redimensionar de nuevo
        if(posicion>=capacidad){
            //cout << "caso 2 " << capacidad << " " << posicion << endl;
            this->vector = (int*)realloc(this->vector, sizeof(int)*(this->incremento + posicion));
            this->capacidad = posicion + incremento;
        }
        //Si se quiere insertar en un campo al que se le ha dado un valor, hay que mover la lista para hacer hueco
        if(posicion<n){
            //cout << "caso 3 " << capacidad << " " << posicion  << "  " << n<< endl;
            memmove(&(this->vector[posicion + 1]), &(this->vector[posicion]), sizeof(int)*(this->n - posicion));
            this->n++;
        }else{
            n=posicion+1;
        }
        // Metemos el nuevo elemento
       
        setValor(posicion, nuevoValor);
    }
 
    void ListaContigua::eliminar(int posicion){
        if(posicion > n){
            cout << "No es posible realizar la operacion" << endl;
            return;
        }
        // Tapamos el hueco dejado por el elemento eliminado. Para ello, desplazamos a la izquierda los
        // elementos que hay a partir de posicion+1 hasta el final
        memmove(&vector[posicion], &vector[posicion + 1], sizeof(int)*(this->n - posicion - 1));
        n--;
 
        // Si la capacidad restante es superrior a 2*incremento, la reducimos en incremento unidades
        if (this->capacidad - this->n == 2 * this->incremento) {
            this->vector = (int*)realloc(this->vector, sizeof(int)*(this->capacidad - this->incremento));
            this->capacidad -= this->incremento;
        }
 
    }
 
    void ListaContigua::concatenar(ListaContigua *listaAConcatenar){
        // el tamaño de una es "n" y el de la otra es "m", el tamaño total es n+m
    int m = listaAConcatenar->getN();
 
    //ampliamos la capacidad para asegurarnos de que los nuevos elementos quepan
    this->capacidad += m;
 
    // Vamos insertando al final elemento a elemento.
    for (int i = 0; i < m; i++) {
        insertar(this->n, listaAConcatenar->getValor(i));
    }
    }
 
    int ListaContigua::buscar(int elementoABuscar){
            for(int i=0; i< this->capacidad; ++i){
                if(getValor(i)==elementoABuscar)
                    return i;
               
            }
            return -1;
    }
 
    ListaContigua::~ListaContigua(){
        free(this->vector);
    }