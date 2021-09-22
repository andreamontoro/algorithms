

//AGENDA DISPERSION CERRADA//
#include "Agenda.h"
#include "cassert"
#include "iostream"

using namespace std;

Agenda::Agenda(int capacidad){
	this->capacidad = capacidad;
    this->n =0;
	this->contactos = new Contacto[capacidad];
    //memset(this->contactos->telefono, 0, sizeof(long)*capacidad);
    //memset(this->contactos->nombre, "", sizeof(Contacto)*capacidad);
    this->ocupados = new bool[capacidad];
    //this->ocupados=(bool*)malloc(sizeof(bool)* capacidad);
	memset(this->ocupados, 0, sizeof(bool)*capacidad);
    //this->borradas=(bool*)malloc(sizeof(bool)* capacidad);
    this->borradas= new bool[capacidad];
	memset(this->borradas, 0, sizeof(bool)*capacidad);
	
}

Agenda::~Agenda(){
	delete[]contactos;
	delete[]ocupados;
    delete[]borradas;
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
	return(contactos[posicion].nombre);
}

void Agenda::introducirContacto (long telefono, string contacto){
        if(n<capacidad){
            cout << "dentro de introducir" << endl;
        int posicion = buscarHueco(telefono);
        cout << "posicion: " << posicion << endl;
        this->contactos[posicion].telefono = telefono;
	    this->contactos[posicion].nombre = contacto;
	    this->ocupados[posicion] = true;
        this->borradas[posicion] = false;
        ++n;
        }else cout << "No se pueden introducir mas valores" << endl;
	
}
void Agenda::eliminarContacto (long telefono){
	int posicion = buscarContacto(telefono);
	if(posicion!=-1){
		this->contactos[posicion].nombre = ""; //poner a cadena vacia
		//cout << this->contactos[posicion].nombre << "nom" << endl;
		this->contactos[posicion].telefono = -1;
		this->ocupados[posicion] =false;
        this->borradas[posicion] = true;
        --n;
	}else{
		cout << "No existe el contacto" << endl;
	}
	

}

void Agenda::imprimir(){
	for (int i=0; i<capacidad; i++){
		cout << "Posicion " << i << " | Ocupada: " << ocupados[i] << " | Telefono: " << contactos[i].telefono << " | Nombre: " << contactos[i].nombre << " | Borrada: " << borradas[i] << endl;
	}
}

int Agenda::buscarContacto (long telefono){
    int posicion = obtenerPosicion(telefono);
    if(ocupados[posicion]){
        if(contactos[posicion].telefono == telefono){
            return posicion;
        }else{
            int posicionInicial = posicion;
            posicion++;
            while(ocupados[posicion] && (contactos[posicion].telefono != telefono && posicion != posicionInicial))
                posicion=(++posicion)%capacidad;
            if(this->contactos[posicion].telefono == telefono) return posicion;
            else{
                cout << "no se ha encontrado" << endl;
                return -1;
            } 
        }
    }else
    {
        cout << "no se ha encontrado" << endl;
        return -1;
    }
    
}

bool Agenda::existeContacto(long telefono){
    if(buscarContacto(telefono)!=-1){
        return true;
    }else return false;
}

int Agenda::buscarHueco (long telefono){ 
        cout << "dentro de buscharHueco" << endl;
        int posicion = obtenerPosicion(telefono);
        cout << "primera posicion" << posicion << endl;
        while(ocupados[posicion]){
            posicion=(++posicion)%capacidad;
            cout << "---posicion" << posicion << endl;
        }
        return posicion;
}

bool Agenda::isLlena(){
    if(capacidad == n){
        return true;
    } else return false;
}

