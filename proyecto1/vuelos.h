#ifndef VUELOS
#define VUELOS

#include <iostream>

#include "tripulante.h"
#include "pasajero.h"
#include<vector>
using namespace std;

class Persona;
class Tripulante;

class Vuelos{
    public:
        int identificacion, capacidad, numPasajeros;
        string fecha, ciudadOrigen, ciudadDestino, hora;
        vector<Tripulante> tripulantes;

        Vuelos(int a, string cD, string h, int id);

        void agregarPasajero();

        void printVuelo();
};

#endif