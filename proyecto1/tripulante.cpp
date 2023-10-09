#include "tripulante.h"

Tripulante::Tripulante(string &nombre, string &apellido, int edad, string &cedula, string &fechaNacimiento, string &genero, string &direccion, string &numTel, string &correo, string &cargo, int xp, int hrsDiarias)
    : Persona(nombre, apellido, edad, cedula, fechaNacimiento, genero, direccion, numTel, correo)
{
    this->cargo = cargo;
    this->xp = xp;
    this->hrsDiarias = hrsDiarias;
}

void Tripulante::getInformacion()
{
    Persona::getInformacion();
    cout << "Cargo en el avion: " << cargo << endl;
    cout << "Años de experiencia: " << xp << endl;
    cout << "Horas diarias: " << hrsDiarias << endl;
}