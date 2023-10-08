#ifndef PASAJERO
#define PASAJERO

#include <iostream>
#include "persona.h"
using namespace std;


class Pasajero : public Persona{
    private:
        string nacionalidad, infoMedica;
        int numMaletasBodega;
    public:
        Pasajero(const std::string& nombre, std::string& apellido, int edad, std::string& cedula, std::string& fechaNacimiento, std::string& genero, std::string& direccion, std::string& numTel, std::string& correo, std::string& nacionalidad, std::string& infoMedica, int NumMaletasBodega);
        int getNumMaletas();
};

#endif