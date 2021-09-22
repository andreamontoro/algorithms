#include "ABB.h"
#include "assertdomjudge.h"
#include "iostream"
#include <math.h>

using namespace std;

void ABB::imprimir()
{
  if(raiz==NULL)
    cout<<"VACIO"<<endl;
  else   
      imprimirRecorrido(raiz);    
}

void ABB::imprimirRecorrido(Nodo *raizSubarbol)
{
  cout<<raizSubarbol->contenido<<endl;
  if(raizSubarbol->hijoIzquierdo!=NULL)
    {
      cout<<"Izq";
      imprimirRecorrido(raizSubarbol->hijoIzquierdo);
      cout<<endl;
    }
  if(raizSubarbol->hijoDerecho!=NULL)
    {
      cout<<"Der";
      imprimirRecorrido(raizSubarbol->hijoDerecho);
      cout<<endl;
    }
}

void ABB::leerArbol()
{
  raiz=leerSubarbol(NULL);
}

Nodo * ABB::leerSubarbol(Nodo *padre)
{
  int contenido;
  cin>>contenido;
  if(contenido>=0)
    {
      Nodo *arbol=new Nodo;
      arbol->contenido=contenido;
      arbol->hijoIzquierdo=leerSubarbol(arbol);
      arbol->hijoDerecho=leerSubarbol(arbol);
      arbol->padre=padre;
      return arbol;
    }
  else
    {
      return NULL;
    }
}


ABB::ABB(){
  this->raiz = NULL;
  this->n=0;
}


void ABB::insertar (int nuevoElemento){
    // Creamos el nuevo nodo que va a contener al elemento
	Nodo *nuevoNodo = new Nodo;
	nuevoNodo->contenido = nuevoElemento;
	nuevoNodo->padre = NULL;
	nuevoNodo->hijoIzquierdo = NULL;
	nuevoNodo->hijoDerecho = NULL;

	// Si esta vacio, lo metemos en la raiz
	if (n == 0) {
		raiz = nuevoNodo;
  }

	// En caso contrario, buscamos el hueco
	else {
		// Buscamos el hueco
		Nodo *padreDelHueco = buscarHueco(raiz, nuevoElemento); // Puntero al nodo que es el padre del hueco

		// Metemos el nuevo nodo como hijo izquierdo o derecho
		if (nuevoElemento <= padreDelHueco->contenido) padreDelHueco->hijoIzquierdo = nuevoNodo;
		else padreDelHueco->hijoDerecho = nuevoNodo;

		// Hacemos que el nuevo nodo apunte al padre
		nuevoNodo->padre = padreDelHueco;
	}

	// Incrementamos el numero de nodos
	n++;
}


Nodo *ABB::buscar(int elementoABuscar){
    return(buscarRecursivo(raiz, elementoABuscar));
  }


void ABB::eliminar (int elementoAEliminar){
    Nodo *nodoParaEliminar = buscar(elementoAEliminar);
	eliminarNodo(nodoParaEliminar);
	n--;
}
	
	
ABB::~ABB(){
    if (raiz != NULL) eliminarSubarbol(raiz);
}


void ABB::eliminarSubarbol (Nodo *raizSubarbol){
    assert(raizSubarbol != NULL);

	// Primero eliminamos los hijos, si hay
	if (raizSubarbol->hijoIzquierdo != NULL) eliminarSubarbol(raizSubarbol->hijoIzquierdo);
	if (raizSubarbol->hijoDerecho != NULL) eliminarSubarbol(raizSubarbol->hijoDerecho);

	// Eliminamos la referencia desde el padre. Hay que averiguar si  
	// el nodo era su hijo der o izq
	Nodo *padre = raizSubarbol->padre; // Guardamos primero quien es el padre
	if (padre != NULL) {
		if (padre->hijoIzquierdo == raizSubarbol) padre->hijoIzquierdo = NULL;
		if (padre->hijoDerecho == raizSubarbol) padre->hijoDerecho = NULL;
	}

	// Eliminamos la raiz	
	delete raizSubarbol;
}


Nodo * ABB::buscarHueco(Nodo *raizSubarbol, int elementoAInsertar){
    assert(raizSubarbol != NULL);

	if (elementoAInsertar <= raizSubarbol->contenido)
		if (raizSubarbol->hijoIzquierdo != NULL) return (buscarHueco(raizSubarbol->hijoIzquierdo, elementoAInsertar));
		else return (raizSubarbol);
	else
		if (raizSubarbol->hijoDerecho != NULL) return (buscarHueco(raizSubarbol->hijoDerecho, elementoAInsertar));
		else return (raizSubarbol);
}


Nodo * ABB::buscarRecursivo (Nodo *raizSubarbol, int elementoABuscar){
    if (raizSubarbol == NULL) return (NULL); // Elemento no encontrado
	else
		if (raizSubarbol->contenido == elementoABuscar)
			return (raizSubarbol); // Elemento encontrado en la raiz
		else if (elementoABuscar < raizSubarbol->contenido)
			return (buscarRecursivo(raizSubarbol->hijoIzquierdo, elementoABuscar)); // Seguimos buscando por la izquierda
		else
			return (buscarRecursivo(raizSubarbol->hijoDerecho, elementoABuscar)); // Seguimos buscando por la derecha
}


Nodo * ABB::buscarMaximo (Nodo *raizSubarbol){
    // Vamos por la rama derecha hasta que no podamos 
	assert(raizSubarbol != NULL);
	if (raizSubarbol->hijoDerecho == NULL) return (raizSubarbol);
	else return (buscarMaximo(raizSubarbol->hijoDerecho));
}


Nodo * ABB::buscarMinimo (Nodo *raizSubarbol){
    // Vamos por la rama izquierda hasta que no podamos t(n)=1+t(n/2) O(n)=loh(n)
	assert(raizSubarbol != NULL);
	if (raizSubarbol->hijoIzquierdo == NULL) return (raizSubarbol);
	else return (buscarMinimo(raizSubarbol->hijoIzquierdo));
}


void ABB::eliminarNodo (Nodo *nodoParaEliminar){
    Nodo *nodoDesdeDondeCopiar = NULL; // Nodo cuyo contenido se copiar en nodoParaEliminar, si ste ultimo tiene hijos

	if (nodoParaEliminar != NULL) {

		// Si no tenemos hijos (somos un nodo hoja), se elimina
		if (nodoParaEliminar->hijoIzquierdo == NULL && nodoParaEliminar->hijoDerecho == NULL) {
			
			// Eliminamos primero la referencia desde el padre. Hay que averiguar si  
			// el nodo era su hijo derecho o izquierdo
			Nodo *padre = nodoParaEliminar->padre; // Guardamos primero quien es el padre
			if (padre != NULL) {
				if (padre->hijoIzquierdo == nodoParaEliminar) padre->hijoIzquierdo = NULL;
				if (padre->hijoDerecho == nodoParaEliminar) padre->hijoDerecho = NULL;
			}
			
			//liberamos la memoria del nodo
			delete nodoParaEliminar;
		}

		else {
			// Si no, si tenemos dos hijos. Cogemos el maximo de la izquierda o el minimo de la derecha segun lo que hicimos la ultima vez
			if (nodoParaEliminar->hijoIzquierdo != NULL && nodoParaEliminar->hijoDerecho != NULL) {

				if (alturaNodo(nodoParaEliminar->hijoDerecho) >= alturaNodo(nodoParaEliminar->hijoIzquierdo)) { //O(n)
					//O(n)+Olog(n)
					nodoDesdeDondeCopiar = buscarMinimo(nodoParaEliminar->hijoDerecho); //Olog(n)
				}
				else {
					nodoDesdeDondeCopiar = buscarMaximo(nodoParaEliminar->hijoIzquierdo);
					
				}
			}

			// si tenemos solo el hijo derecho
			else if (nodoParaEliminar->hijoIzquierdo == NULL && nodoParaEliminar->hijoDerecho != NULL) {
				nodoDesdeDondeCopiar = buscarMinimo(nodoParaEliminar->hijoDerecho);
				
			}

			// si no solo tenemos el hijo izquierdo
			else { // nodoParaEliminar->getHijoIzquierdo() != NULL && nodoParaEliminar->getHijoDerecho() == NULL
				nodoDesdeDondeCopiar = buscarMaximo(nodoParaEliminar->hijoIzquierdo);
				
			}

			//lo copiamos en el hueco dejado por nodoParaEliminar
			nodoParaEliminar->contenido = nodoDesdeDondeCopiar->contenido;

			// Borramos recursivamente el nodoDesdeDondeCopiar
			eliminarNodo(nodoDesdeDondeCopiar); //llamada t(n)=t(n/2) +n + log(n)

		} 

	} 
}
	//La altura de un arbol se calcula, con la mayor altura entre los dos hijos +1;
	int ABB::alturaNodo(Nodo *raizSubarbol){
		int altIzq, altDer, max;
		if(raizSubarbol==NULL) //Si el nodo esta vacio
			return 0;
		else{
			altIzq = alturaNodo(raizSubarbol->hijoIzquierdo);
			altDer = alturaNodo(raizSubarbol->hijoDerecho);
		}//Escogemos la mayor altura de entre los dos hijos
		if(altIzq>altDer){
			max=altIzq;
		}else 
			max = altDer;
		//Una vez seleccionada la altura maxima, para hallar la altura final debemos sumarle 1.
		return max+1;

	}

	bool ABB::esSubABB(Nodo *raizSubarbol){
		if(raizSubarbol == NULL || ((raizSubarbol->hijoIzquierdo==NULL)&&(raizSubarbol->hijoDerecho==NULL))){ //si es NULL o no tiene hijos es ABB o ha llegado al final
			return true;
		}
		//si existe el hijo izquierdo
		else if(raizSubarbol->hijoIzquierdo!=NULL){ 
				//si existe el hijo derecho
				if(raizSubarbol->hijoDerecho!=NULL){
					//si el hijo izq es menor que el padre y el hijo der es mayor que el padre entonces es un ABB
					if(raizSubarbol->hijoIzquierdo->contenido <= raizSubarbol->contenido && raizSubarbol->hijoDerecho->contenido > raizSubarbol->contenido){
						return esSubABB(raizSubarbol->hijoIzquierdo) && esSubABB(raizSubarbol->hijoDerecho);
					}else{
						return false;
					}
				//si solo existe el hijo izquierdo y es menor que el padre es un ABB
				}else if(raizSubarbol->hijoIzquierdo->contenido <= raizSubarbol->contenido){
					return esSubABB(raizSubarbol->hijoIzquierdo);
				}
      
		}else{//si existe el derecho
				//si solo existe el hijo derecho
				if(raizSubarbol->hijoDerecho!=NULL){
					//si el hijo izq es menor que el padre y el hijo der es mayor que el padre entonces es un ABB
					if(raizSubarbol->hijoDerecho->contenido > raizSubarbol->contenido){
						return esSubABB(raizSubarbol->hijoDerecho);
					}else{
						return false;
					}
				}

		}
			return false;
		}
	bool ABB::esSubAVL(Nodo *raizSubarbol){ // mirar si sus niveles son iguales sui no no es avl (balanceo) altura de los nodos - altura de los hijos
		if(raizSubarbol == NULL || ((raizSubarbol->hijoIzquierdo==NULL)&&(raizSubarbol->hijoDerecho==NULL))){ //si es NULL o no tiene hijos es ABB
			return true;
		}else if(raizSubarbol->hijoIzquierdo!=NULL){
			if(raizSubarbol->hijoDerecho!=NULL){
				if(abs(alturaNodo(raizSubarbol->hijoIzquierdo) - alturaNodo(raizSubarbol->hijoDerecho))<2){
						return esSubAVL(raizSubarbol->hijoIzquierdo) && esSubAVL(raizSubarbol->hijoDerecho);
				}else
					return false;
				
			}else{
				return false;
			}
		}
		return false;
	}
	
	
	bool ABB::esABB(){
		return esSubABB(raiz);
	}
	bool ABB::esAVL(){
		if(esSubABB(raiz))
			return esSubAVL(raiz);
		else return false;
	}
	

