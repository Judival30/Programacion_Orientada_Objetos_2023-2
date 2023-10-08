#include "vuelos.h"

Vuelos::Vuelos(int a, string cd, string h, int id){

    fecha = "30/12/2023";
    ciudadOrigen = "CLO";
    ciudadDestino = cd;
    numPasajeros = 0;
    capacidad = a;
    hora = h;
    identificacion = id;
}

void Vuelos::agregarPasajero(){
    if(numPasajeros < capacidad)
        numPasajeros++;
    else
        printf("Vuelo lleno\n");
}

void Vuelos::printVuelo(){
    cout << "Fecha: " << fecha << endl << "Hora " << hora << endl <<"Ciudad de origen: " << ciudadOrigen << endl << "Ciudad de destino " << ciudadDestino << endl; 
}