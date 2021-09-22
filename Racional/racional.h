//#pragma once

#ifndef _RACIONAL_H
#define _RACIONAL_H
class Racional{
    private:
        int numerador;
        int denominador;
    public:
    Racional();
    Racional(int numerador, int denominador);
    void setNumerador(int numerador);
    int getNumerador();
    void setDenominador(int denominador);
    int getDenominador();
    Racional operator +(Racional r2);
    Racional operator -(Racional r2);
    Racional operator *(Racional r2);
};


#endif