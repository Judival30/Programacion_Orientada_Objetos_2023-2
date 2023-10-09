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
            cout << vuelos[i]->ciudadDestino << endl;
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
