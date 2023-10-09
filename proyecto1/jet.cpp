#include "jet.h"

JetPrivado::JetPrivado(const string &marca, int capacidad, MediadorTrafico *mediator) : Aeronave(marca, capacidad, mediator)
{
    propietario = "";
    listaServicios.clear();
    listaDestinos.clear();
    this->marca = marca;
    this->capacidad = capacidad;
}

string JetPrivado::getPropietario()
{
    return this->propietario;
}

void JetPrivado::printInfo()
{
    Aeronave::printInfo();
}
