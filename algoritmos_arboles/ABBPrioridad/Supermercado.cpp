#include "Supermercado.h"
#include<iostream>
using namespace std;


Supermercado::Supermercado(int n){
    ColaPrioridad* super =(ColaPrioridad*)malloc(sizeof(ColaPrioridad)*n);
    this->cajas = super;
    this->n_cajas =n;
}
void Supermercado::nuevoUsuario(int n,int id){
    this->cajas[n].encolar(id);
} 
void Supermercado::cerrarCaja(int n){
    //Si la caja esta vacia o no existe
    if(this->cajas[n].estaVacia() || n>n_cajas-1){
        cout << "la caja está vacia, CERRADA!" << endl;
        return;
    }else{
        int valorDesencolado=0, i=0;
        while(!cajaVacia(n)){
            valorDesencolado = cajas[n].desencolar();
            //cout << "valor desencolado: " << valorDesencolado << endl;
        
            while(i<=n_cajas){
                //cout << "i" << i << endl;
                //cout << "n_cajas" << n_cajas << endl;
                if(i == n_cajas){
                    i=0;
                }   
                if(i!=n && !(cajas[i].estaVacia())){
                    cajas[i].encolar(valorDesencolado);
                    //cout << "encolando en la caja " << i << endl;
                    ++i;
                    break;
                }else{
                    ++i;
                    continue;
                }
                break;
            }   
        }
    }
}  
int Supermercado::atenderUsuario(int n){
    if(n>n_cajas || n<0){
        cout << "No existe la caja" << n << endl;
        return -1;
    }
    int usuarioAtendido = this->cajas[n].desencolar();
    return usuarioAtendido;
    
}
bool Supermercado::cajaVacia(int n){
    if(this->cajas[n].estaVacia()) return true;
    return false;
    
}