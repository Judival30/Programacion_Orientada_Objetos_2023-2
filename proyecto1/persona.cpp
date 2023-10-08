#include "persona.h"

Persona::Persona(){
}

Persona::Persona(const string& nombre, string& apellido, int edad, string& cedula, string& fechaNacimiento, string& genero, string& direccion, string& numTel, string& correo){
    this->nombre = nombre;
    this->apellido = apellido;
    this->edad = edad;
    this->cedula = cedula;
    this->fechaNacimiento = fechaNacimiento;
    this->genero = genero;
    this->direccion = direccion;
    this->numTel = numTel;
    this->correo = correo;
}

string Persona::getNombre(){
    return this->nombre;
}

int Persona::getEdad(){
    return this->edad;
}

void Persona::mostrarInfo(){
    cout << "Nombre: " << this->nombre << ", Edad: " << this->edad << endl;
}