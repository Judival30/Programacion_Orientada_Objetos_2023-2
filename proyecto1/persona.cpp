#include "persona.h"

Persona::Persona()
{
}

Persona::Persona(const string &nombre, string &apellido, int edad, string &cedula, string &fechaNacimiento, string &genero, string &direccion, string &numTel, string &correo)
{
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

string Persona::getNombre()
{
    return this->nombre;
}

int Persona::getEdad()
{
    return this->edad;
}

void Persona::getInformacion()
{
    cout << "Nombre: " << nombre << endl;
    cout << "Apellido: " << apellido << endl;
    cout << "Edad: " << edad << " años" << endl;
    cout << "Cédula: " << cedula << endl;
    cout << "Fecha de Nacimiento: " << fechaNacimiento << endl;
    cout << "Género: " << genero << endl;
    cout << "Dirección: " << direccion << endl;
    cout << "Número de Teléfono: " << numTel << endl;
    cout << "Correo Electrónico: " << correo << endl;
}
