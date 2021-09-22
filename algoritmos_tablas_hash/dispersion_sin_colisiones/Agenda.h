#include "Contacto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*#include <iostream>
using namespace std;*/

//AGENDA SIN COLISION//
class Agenda
{
    int capacidad;
    Contacto * contactos;
    bool* ocupados;

public:
    Agenda(int capacidad);
    ~Agenda();
    int obtenerPosicion (long telefono);
    bool existeContacto (long telefono);
    string getContacto (long telefono);
    void introducirContacto (long telefono, string contacto);
    void eliminarContacto (long telefono);
    void imprimir();
};