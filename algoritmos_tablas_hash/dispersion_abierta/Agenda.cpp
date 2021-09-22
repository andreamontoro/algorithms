

//AGENDA DISPERSION ABIERTA//
#include "Agenda.h"
#include "cassert"
#include "iostream"

using namespace std;

Agenda::Agenda(int capacidad){
	this->capacidad = capacidad;
    this->n =0;
	this->listaContactos = new ListaEnlazada[capacidad];
    //memset(this->contactos->telefono, 0, sizeof(long)*capacidad);
    //memset(this->contactos->nombre, "", sizeof(Contacto)*capacidad);
    
	
}

Agenda::~Agenda(){
	delete[]listaContactos;
	
}

int Agenda::obtenerPosicion (long telefono){
	 return (int)(telefono%this->capacidad);
}


string Agenda::getContacto (long telefono){
	//assert(existeContacto(telefono));
	int posicion = obtenerPosicion(telefono);
	//cout << "Ocupados: ";
	/*if(ocupados[posicion] == true){
		cout << "true-ocupado" << endl;
	}else cout << "false-no ocupado" << endl;*/
	Contacto cont;
	cont.telefono = telefono;
	int posicionListaEnlazada = buscarContacto(telefono);
	return(listaContactos[posicion].getValor(posicionListaEnlazada).nombre);

}

//???
void Agenda::introducirContacto (long telefono, string contacto){
	
            //cout << "dentro de introducir" << endl;
        int posicion = obtenerPosicion(telefono);

		Contacto cont;
		cont.nombre = contacto;
		cont.telefono = telefono;
		this->listaContactos[posicion].insertar(this->listaContactos[posicion].getN(),cont);
        
        ++n;
	
}
//PROBLEMAS POR QUE BUSCAR RECIBE UN CONTACTO SEGUN EL CODIGO DADO EN CLASE, PERO ELIMINAR CONTACTO SOLO RECIBE EL TELEFONO.
void Agenda::eliminarContacto (long telefono){
	int posicion = obtenerPosicion(telefono);
	if(listaContactos[posicion].getN()>0){
		
		if(existeContacto(telefono)){
			int posicionEnListaEnlazada = buscarContacto(telefono);
			this->listaContactos[posicion].eliminar(posicionEnListaEnlazada);
			--n;
		}else{
			cout << "No existe el contacto" << endl;
		}
		
        
	}else{
		cout << "No existe el contacto" << endl;
	}
	

}
int Agenda::buscarContacto (long telefono){
	cout << "buscarContacto telefono: " << telefono << endl;
    int posicion = obtenerPosicion(telefono);
	cout << "buscarContacto posicion: " << posicion << endl;
	Contacto cont;
	cont.telefono =telefono;
	cont.nombre ="";
	int posicionEnListaEnlazada = this->listaContactos[posicion].buscar(cont);
	cout << "posicion en lista enlazada " << posicionEnListaEnlazada << endl;
    return posicionEnListaEnlazada;
    
}


void Agenda::imprimir(){
	for (int i=0; i<capacidad; i++){
		for(int j=0; j<listaContactos[i].getN();++j){
		cout << "Posicion " << i << j<<" | Telefono: " << listaContactos[i].getValor(j).telefono << " | Nombre: " << listaContactos[i].getValor(j).nombre << endl;
		}
	}
}



bool Agenda::existeContacto(long telefono){
    if(buscarContacto(telefono)){
        return true;
    }else return false;
}





