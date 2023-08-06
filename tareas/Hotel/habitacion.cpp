#include "habitacion.h"

Habitacion::Habitacion(int n)
{
    // Generar un número aleatorio entre 100 y 600
    precio = rand() % 501 + 100; // Rango: 600 - 100 + 1 = 501
    estado = false;
    numeroHab = n;
    nombreHuesp = "";
}

void Habitacion::setOcupado()
{
    estado = true;
}
void Habitacion::setDesocupado()
{
    estado = false;
}
void Habitacion::setHuesped(string &n)
{
    nombreHuesp = n;
}
int Habitacion::getPrecio()
{
    return precio;
}

bool Habitacion::getEstado()
{
    return estado;
}
int Habitacion::getNumero()
{
    return numeroHab;
}
