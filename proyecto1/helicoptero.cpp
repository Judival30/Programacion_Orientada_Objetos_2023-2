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