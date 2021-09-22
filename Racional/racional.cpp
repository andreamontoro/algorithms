#include "racional.h"

Racional::Racional(){
    this->numerador = 0;
    this->denominador = 1;

}
Racional::Racional(int numerador, int denominador){
    this->numerador = numerador;
    this->denominador = denominador;
}
void Racional::setNumerador(int numerador){
    this->numerador = numerador;
}
int Racional::getNumerador(){
    return this->numerador;
}
void Racional::setDenominador(int denominador){
    this->denominador = denominador;
}
int Racional::getDenominador(){
    return this->denominador;
}
//prerrequisito: denominador r2 == this denominador
Racional Racional::operator +(Racional r2){
    Racional resultado;
    if(r2.denominador == this->denominador){
        resultado.numerador = r2.numerador+this->numerador;
        resultado.denominador = r2.denominador;
    } else{
        resultado.denominador = r2.denominador*this->denominador;
        Racional mcd(r2.numerador*this->denominador, r2.denominador*this->denominador);
        Racional mcd2(this->numerador*r2.denominador, r2.denominador*this->denominador);
        //resultado.numerador = mcd.numerador + mcd2.numerador;
        //resultado.denominador = mcd.denominador;
        resultado = mcd + mcd2; // vuelve a entrar a la funcion ya son iguales, RECURSIVIDAD
    }
    return resultado;
    
}
Racional Racional::operator -(Racional r2){
    Racional resultado;
    if(r2.denominador == this->denominador){
        resultado.numerador = r2.numerador-this->numerador;
        resultado.denominador = r2.denominador;
    } else{
        resultado.denominador = r2.denominador*this->denominador;
        Racional mcd(r2.numerador*this->denominador, r2.denominador*this->denominador);
        Racional mcd2(this->numerador*r2.denominador, r2.denominador*this->denominador);
        //resultado.numerador = mcd.numerador + mcd2.numerador;
        //resultado.denominador = mcd.denominador;
        resultado = mcd - mcd2; // vuelve a entrar a la funcion ya son iguales, RECURSIVIDAD
    }
    return resultado;
}
Racional Racional::operator *(Racional r2){
    Racional resultado;
    resultado.denominador = r2.denominador*this->denominador;
    resultado.numerador = r2.numerador*this->numerador;
    return resultado;

}
