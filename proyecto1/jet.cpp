#include "jet.h"

JetPrivado::JetPrivado(const string &marca, int capacidad, MediadorTrafico *mediator) : Aeronave(marca, capacidad, mediator)
{
    propietario = "";
    listaServicios.clear();
    listaDestinos.clear();
}

string JetPrivado::getPropietario()
{
    return this->propietario;
}

void JetPrivado::printInfo()
{
    Aeronave::printInfo();
}
