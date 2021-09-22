    
    #include "ListaEnlazada.h"
	#include <iostream>
	using namespace std;
	

	
    
    Nodo * ListaEnlazada::getNodo (int posicion){
        Nodo *resultado = NULL; // Aqu� guardaremos el puntero al nodo resultado

	// Si el nodo que queremos buscar es igual que el �ltimo accedido
	if (posicion == posicionUltimoNodoAccedido && posicionUltimoNodoAccedido!=-1)
		resultado=punteroUltimoNodoAccedido;

	// Si el nodo que queremos buscar es el siguiente al �ltimo accedido
	else if (posicion == posicionUltimoNodoAccedido+1 && posicionUltimoNodoAccedido != -1) {
		resultado = punteroUltimoNodoAccedido->siguienteNodo;
	}

	// Si el nodo que queremos buscar es el anterior al �ltimo accedido
	else if (posicion == posicionUltimoNodoAccedido - 1 && posicionUltimoNodoAccedido != -1) {
		resultado = punteroUltimoNodoAccedido->anteriorNodo;
	}

	// Si el nodo no es contiguo al ultimo accedido, y se llega antes a �l iterando hacia delante
	else if (posicion <= n / 2) {
		resultado = lista; // Hacemos que el resultado apunte al primer nodo
		for (int i = 0; i < posicion; i++) resultado = resultado->siguienteNodo;
	}

	// Si el nodo no es contiguo al ultimo accedido, y se llega antes a �l iterando hacia atr�s
	else {
		resultado = lista->anteriorNodo; // Hacemos que el resultado apunte al �ltimo nodo
		for (int i = n-1; i > posicion; i--)
			resultado = resultado->anteriorNodo;
	}

	// Actualizamos los atributos del ultimo nodo accedido
	posicionUltimoNodoAccedido = posicion;
	punteroUltimoNodoAccedido = resultado;

	return (resultado);
        
    }



	ListaEnlazada::ListaEnlazada(){
        lista=NULL;
        n=0;
        posicionUltimoNodoAccedido = -1; // -1 significa que no se ha accedido aun a ninguno
	    punteroUltimoNodoAccedido = NULL; // NULL significa que no se ha accedido aun a ninguno
    }

	Contacto ListaEnlazada::getValor(int posicion){
        Nodo *nodoABuscar = getNodo(posicion);
	    return (nodoABuscar->elemento);
    }

	void ListaEnlazada::setValor(int posicion, Contacto nuevoValor){
		/*Nodo * nodoAAñadir = getNodo(posicion);
        nodoAAñadir->elemento.nombre = nuevoValor.nombre;
		nodoAAñadir->elemento.telefono = nuevoValor.telefono;*/
		getNodo(posicion)->elemento = nuevoValor;
    }

	int ListaEnlazada::getN(){
        return (n);
    }

	void ListaEnlazada::insertar (int posicion, Contacto nuevoValor){
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

	// Como hemos cambiado la configuracion de la lista, reseteamos el ultimo nodo accedido
	posicionUltimoNodoAccedido = -1; // -1 significa que no se ha accedido aun a ninguno
	punteroUltimoNodoAccedido = NULL; // NULL significa que no se ha accedido aun a ninguno
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
        // Como hemos cambiado la configuracion de la lista, reseteamos el ultimo nodo accedido
	    posicionUltimoNodoAccedido = -1; // -1 significa que no se ha accedido aun a ninguno
	    punteroUltimoNodoAccedido = NULL; // NULL significa que no se ha accedido aun a ninguno
    }

	void ListaEnlazada::concatenar(ListaEnlazada *listaAConcatenar){
        int m = listaAConcatenar->getN();
        for (int i = 0; i < m; i++) {
            insertar(this->n, listaAConcatenar->getValor(i));
        }
    }

	int ListaEnlazada::buscar(Contacto elementoABuscar){
         //cout << "n " << n << endl;
        for(int i=0; i< n; ++i){
				Contacto posibleContacto = getValor(i);
                if(posibleContacto.telefono == elementoABuscar.telefono)
                    return i;
               
            }
            return -1;
    }

	ListaEnlazada::~ListaEnlazada(){
        while(n>0) eliminar(0); 
    }