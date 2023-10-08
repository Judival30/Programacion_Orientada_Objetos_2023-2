#include "pasajero.h"

Pasajero::Pasajero(const std::string& nombre, std::string& apellido, int edad, std::string& cedula, std::string& fechaNacimiento, std::string& genero, std::string& direccion, std::string& numTel, std::string& correo, std::string& nacionalidad, std::string& infoMedica, int numMaletasBodega)
    : Persona(nombre, apellido, edad, cedula, fechaNacimiento, genero, direccion, numTel, correo){
        this->numMaletasBodega = numMaletasBodega;
        this->nacionalidad = nacionalidad;
        this->infoMedica = infoMedica;
    }
int Pasajero::getNumMaletas(){
    return this->numMaletasBodega;
}