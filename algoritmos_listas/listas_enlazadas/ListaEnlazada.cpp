    
    #include "ListaEnlazada.h"
    
    Nodo * ListaEnlazada::getNodo (int posicion){
        Nodo *resultado = lista;
        for(int i=0; i<posicion; ++i)
		resultado=resultado->siguienteNodo;
	    return resultado;
        
    }



	ListaEnlazada::ListaEnlazada(){
        lista=NULL;
        n=0;
    }

	int ListaEnlazada::getValor(int posicion){
        Nodo *nodoABuscar = getNodo(posicion);
	    return (nodoABuscar->elemento);
    }

	void ListaEnlazada::setValor(int posicion, int nuevoValor){
        getNodo(posicion)->elemento = nuevoValor;
    }

	int ListaEnlazada::getN(){
        return (n);
    }

	void ListaEnlazada::insertar (int posicion, int nuevoValor){
        if(posicion>n){
            cout << "No es posible realizar la operacion" << endl;
            return;
        }
	    Nodo * nodoNuevo = new Nodo;
        Nodo * nodoAnterior = getNodo(posicion-1);
	    
	    if(posicion==0){ 
            //cout << "dntro de =0" << endl;
		    nodoNuevo->siguienteNodo=lista; 
		    lista=nodoNuevo;
            
	    }
        else if(posicion<=n){
            //cout << "dntro pos<n" << endl;
		    nodoNuevo->siguienteNodo=nodoAnterior->siguienteNodo; 
		    nodoAnterior->siguienteNodo=nodoNuevo;
	    }
        setValor(posicion, nuevoValor);
	    n++;
    }

	void ListaEnlazada::eliminar (int posicion){
        if(posicion>n){
            cout << "No es posible realizar la operacion" << endl;
            return;
        }
        Nodo * nodoAEliminar;
	    if(posicion == 0){
		    nodoAEliminar=lista;
		    lista=nodoAEliminar->siguienteNodo;
	    }
	    else if(posicion<=n){
		    Nodo * nodoAnterior=getNodo(posicion-1);
		    nodoAEliminar=nodoAnterior->siguienteNodo;
		    nodoAnterior->siguienteNodo=nodoAEliminar->siguienteNodo;
	    }
	    delete(nodoAEliminar);
        n--;
    }

	void ListaEnlazada::concatenar(ListaEnlazada *listaAConcatenar){
        int m = listaAConcatenar->getN();
        for (int i = 0; i < m; i++) {
            insertar(this->n, listaAConcatenar->getValor(i));
        }
    }

	int ListaEnlazada::buscar(int elementoABuscar){
         cout << "n " << n << endl;
        for(int i=0; i< n; ++i){
                if(getValor(i)==elementoABuscar)
                    return i;
               
            }
            return -1;
    }

	ListaEnlazada::~ListaEnlazada(){
        while(n>0) eliminar(0); 
    }