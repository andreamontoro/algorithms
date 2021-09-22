//AGENDA SIN COLISION//
#include "Agenda.h"
#include "cassert"
#include "iostream"

using namespace std;

Agenda::Agenda(int capacidad){
	this->capacidad = capacidad;

	this->contactos = (Contacto*)malloc(sizeof(Contacto)* capacidad);


    this->ocupados=(bool*)malloc(sizeof(bool)* capacidad);
	memset(this->ocupados, 0, sizeof(bool)*capacidad);
	/*this->capacidad = capacidad;
	this->nombres =(string*)malloc(sizeof(string)* capacidad);
	memset(this->nombres, 0, sizeof(string)*capacidad);
    this->telefonos=(long*)malloc(sizeof(long)* capacidad);
	memset(this->telefonos, 0, sizeof(long)*capacidad);
    this->ocupados=(bool*)malloc(sizeof(bool)* capacidad);
	memset(this->ocupados, 0, sizeof(bool)*capacidad);*/
}

Agenda::~Agenda(){
	free(this->contactos);
	free(this->ocupados);
}

int Agenda::obtenerPosicion (long telefono){
	 return (int)(telefono%this->capacidad);
}

bool Agenda::existeContacto (long telefono){
	int posicion = obtenerPosicion(telefono);
	if(contactos[posicion].telefono == telefono && ocupados[posicion]==true){
		return true;
	}else 
		return false;
}

string Agenda::getContacto (long telefono){
	//assert(existeContacto(telefono));
	int posicion = obtenerPosicion(telefono);
	//cout << "Ocupados: ";
	/*if(ocupados[posicion] == true){
		cout << "true-ocupado" << endl;
	}else cout << "false-no ocupado" << endl;*/
	return(contactos[posicion].nombre);
}

void Agenda::introducirContacto (long telefono, string contacto){
	int posicion = obtenerPosicion(telefono);
	/*if(!this->ocupados[posicion]){
		this->telefonos[posicion] = telefono;
		strcpy(this->nombres[posicion],contacto);
		this->ocupados[posicion] = true;
	}else{

	}*/
	this->contactos[posicion].telefono = telefono;
	this->contactos[posicion].nombre = contacto;
	this->ocupados[posicion] = true;
}
void Agenda::eliminarContacto (long telefono){
	int posicion = obtenerPosicion(telefono);
	if(existeContacto(telefono) && (this->ocupados[posicion] ==true)){
		this->contactos[posicion].nombre = '\0';
		//cout << this->contactos[posicion].nombre << "nom" << endl;
		this->contactos[posicion].telefono = NULL;
		this->ocupados[posicion] =false;
	}else{
		cout << "No existe el contacto" << endl;
	}
	

}
void Agenda::imprimir(){
	for (int i=0; i<capacidad; i++){
		cout << "Posicion " << i << " | Ocupada: " << ocupados[i] << " | Telefono: " << contactos[i].telefono << " | Nombre: " << contactos[i].nombre << endl;
	}
}



