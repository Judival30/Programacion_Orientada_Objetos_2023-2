#include "tripulante.h"

Tripulante::Tripulante(string& nombre, string& apellido, int edad, string& cedula, string& fechaNacimiento, string& genero, string& direccion, string& numTel, string& correo, string& cargo, int xp, int hrsDiarias)
: Persona(nombre, apellido, edad, cedula, fechaNacimiento, genero, direccion, numTel, correo){
    this->cargo = cargo;
    this->xp = xp;
    this->hrsDiarias = hrsDiarias;
}

string Tripulante::getCargo(){
    return this->cargo;
}

int Tripulante::getHorasDiarias(){
    return this->hrsDiarias;
}

int Tripulante::getXp(){
    return this->xp;
}