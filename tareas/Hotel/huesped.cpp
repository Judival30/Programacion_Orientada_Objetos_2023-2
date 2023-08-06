#include "huesped.h"
Huesped::Huesped()
{
}
Huesped::Huesped(string &n, int t)
{
    nombre = n;
    dinero = rand() % 501 + 500; // Rango: 1000 - 500 + 1 = 501
    tel = t;
}

void Huesped::setTel(int n)
{
    tel = n;
}
void Huesped::setDinero(int n)
{
    dinero = n;
}
string Huesped::getName()
{
    return nombre;
}

int Huesped::getTel()
{
    return tel;
}
int Huesped::getDinero()
{
    return dinero;
}

void Huesped::checkOutHuesped()
{
    nombre = "";
    dinero = 0;
    tel = 0;
}