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

void Avion::printInfo()
{
    Aeronave::printInfo();
}
void Avion::obtenerDatos()
{
    cout << "Ingrese el numero de motores: ";
    cin >> this->numMotores;
    cout << endl;
    cout << "Ingrese la categoria: ";
    cin >> this->categoria;
    cout << endl;
    cout << "Ingrese la altitud maxima: ";
    cin >> this->altitudMax;
    cout << endl;
}
