#include "helicoptero.h"

Helicoptero::Helicoptero(const string &marca, int capacidad, MediadorTrafico *mediator) : Aeronave(marca, capacidad, mediator)
{
}

int Helicoptero::getNumRotores()
{
    return this->numRotores;
}
int Helicoptero::getMaxElevacion()
{
    return this->maxElevacion;
}
string Helicoptero::getUso()
{
    return this->uso;
}

void Helicoptero::printInfo()
{
    Aeronave::printInfo();
}

void Helicoptero::obtenerDatos()
{
    cout << "Ingrese el numero de rotores: ";
    cin >> this->numRotores;
    cout << endl;
    cout << "Ingrese la maxima elevacion: ";
    cin >> this->maxElevacion;
    cout << endl;
    cout << "Ingrese el tipo de uso: ";
    cin >> this->uso;
    cout << endl;
}