#include "aeropuerto.h"

Aeropuerto::Aeropuerto()
{
    vuelos = {};
}

void Aeropuerto::agregarDestino(Vuelos *v)
{
    vuelos.push_back(v);
}

void Aeropuerto::printDestinos()
{
    if (vuelos.size() == 0)
        printf("No hay vuelos\n");
    else
    {
        for (int i = 0; i < vuelos.size(); i++)
        {
            cout << i + 1 << "." << endl;
            vuelos[i]->printVuelo();
        }
    }
}

Aeropuerto *Aeropuerto::instancia = nullptr;

Aeropuerto &Aeropuerto::obtenerInstancia()
{
    if (!instancia)
    {
        instancia = new Aeropuerto();
    }
    return *instancia;
}

bool Aeropuerto::disponibilidadVuelos()
{
    if (vuelos.size() == 0)
        return false;
    else
        return true;
}

bool Aeropuerto::disponibilidadAeronaves()
{
    return torreControl.disponibilidadNaves();
}

void Aeropuerto::asignarVuelo()
{
    for (int i = 0; i < vuelos.size(); i++)
    {
        torreControl.seleccionarAeronave(vuelos[i]);
    }
}

Vuelos *Aeropuerto::obtenerVuelo(int pos)
{
    return vuelos[pos];
}
