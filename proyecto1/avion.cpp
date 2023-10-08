#include "avion.h"

Avion::Avion(const string &marca, int capacidad, MediadorTrafico *mediator) : Aeronave(marca, capacidad, mediator)
{
}

int Avion::getAltitudMax()
{
    return this->altitudMax;
}

int Avion::getCategoria()
{
    return this->categoria;
}

int Avion::getNumMotores()
{
    return this->numMotores;
}