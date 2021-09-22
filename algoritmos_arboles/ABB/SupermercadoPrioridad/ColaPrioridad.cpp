#include "ColaPrioridad.h"
#include<iostream>
using namespace std;

void ColaPrioridad::encolar(int nuevoElemento){
    if(this->vector.getN()==0){
        this->vector.insertar(0,nuevoElemento); //en memoria complejidad n+1 por el realloc
    }else{
        this->vector.insertarAlFinal(nuevoElemento);
        int posicionNuevoNodo = this->vector.getN()-1;
        int posicionPadre = float(posicionNuevoNodo*0.5) -0.5;
        //cout << "posNEWNODO: " << posicionNuevoNodo << endl;
        //cout << "posPadre: " << posicionPadre << endl;
        while(this->vector.getValor(posicionPadre) > this->vector.getValor(posicionNuevoNodo) && posicionNuevoNodo >0){
            
            int aux= this->vector.getValor(posicionPadre);
            this->vector.setValor(posicionPadre,this->vector.getValor(posicionNuevoNodo));
            this->vector.setValor(posicionNuevoNodo, aux);

            posicionNuevoNodo = posicionPadre;
            posicionPadre = float(posicionNuevoNodo*0.5) -0.5;
            /*cout << "aux" << aux << endl;
            cout << "posNEWNODO: " << posicionNuevoNodo << endl;
            cout << "posPadre: " << posicionPadre << endl;*/
        }
    }
    /*for(int i=0; i<vector.getN(); ++i){
        cout << vector.getValor(i) << endl;
    }*/
}

int ColaPrioridad::desencolar(){
    int cima = this->vector.getValor(0);
    this->vector.setValor(0,this->vector.getValor(vector.getN()-1));
    this->vector.eliminarAlFinal();
    /*for(int i=0; i<vector.getN(); ++i){
        cout << vector.getValor(i) << endl;
    }*/
    //cout << "______________________-" << endl;
    reestructurar();
    /*for(int i=0; i<vector.getN(); ++i){
        cout << vector.getValor(i);
    }*/
    return cima;
}

bool ColaPrioridad::estaVacia(){
    if(this->vector.getN() <=0)return true;
    return false;
}

void ColaPrioridad::reestructurar(){
    int padre=0, hijoIzq=1, hijoDer=2, hijoSeleccionado=padre;
    bool salir = false;
    while(!salir){
        hijoSeleccionado=padre;
        //cout << "dentro de while" << endl;
        if(this->vector.getN()>hijoIzq && (this->vector.getValor(hijoIzq) < this->vector.getValor(hijoSeleccionado))){
            //cout << "dentro de 1 if" << endl;
            //this->vector.setValor(hijoSeleccionado, this->vector.getValor(hijoIzq));
            hijoSeleccionado = hijoIzq;
        }
            //cout << "dentro deelse" << endl;
            if(this->vector.getN()>hijoDer && (this->vector.getValor(hijoDer) < this->vector.getValor(hijoSeleccionado))){
            //cout << "dentro de 2 if" << endl;
            //this->vector.insertar(hijoSeleccionado, this->vector.getValor(hijoDer));
            hijoSeleccionado = hijoDer;
            }
        
         //cout << "hijo selecc despues de if: " << hijoSeleccionado;
        if(hijoSeleccionado == padre) salir=true;
        else{
            //cout << "dentro de 2 else" << endl;
            int aux= this->vector.getValor(padre);
            this->vector.setValor(padre,this->vector.getValor(hijoSeleccionado));
            this->vector.setValor(hijoSeleccionado,aux);
        }
        padre=hijoSeleccionado;
        hijoIzq=2*padre+1;
        hijoDer=2*padre+2;
        /*cout << "hijo selecc: " << hijoSeleccionado;
        cout << "|   padre" << padre << endl;*/
    }
}