#ifndef Hotel_H
#define Hotel_H

#include <iostream>
#include <vector>
#include <list>
#include "habitacion.h"
#include "huesped.h"

using namespace std;

class Hotel
{

private:
    string nombre;
    vector<Habitacion> habitaciones;
    vector<Huesped> huespedes;

public:
    Hotel();
    void setNombre(string &n);
    void printInfoHotel();
    // acciones
    void reserva();
};

#endif