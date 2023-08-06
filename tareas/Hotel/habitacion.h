#ifndef Habitacion_h
#define Habitacion_h

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class Habitacion
{
private:
    int precio;
    bool estado;
    int numeroHab;
    string nombreHuesp;

public:
    Habitacion(int n);
    // sets
    void setOcupado();
    void setDesocupado();
    void setHuesped(string &n);
    // gets
    int getPrecio();
    bool getEstado();
    int getNumero();
    string getHuesped();
};

#endif