#include "Contacto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*#include <iostream>
using namespace std;*/

//AGENDA DISPERSION CERRADA//
class Agenda
{
    int n;
    int capacidad;
    Contacto * contactos;
    bool* ocupados;
    bool* borradas;


public:
    Agenda(int capacidad);
    ~Agenda();
    int obtenerPosicion (long telefono);
    string getContacto (long telefono);
    void introducirContacto (long telefono, string contacto);
    void eliminarContacto (long telefono);
    void imprimir();
    bool existeContacto (long telefono);
    int buscarContacto (long telefono);
    int buscarHueco (long telefono);
    bool isLlena();

};

