#include "puertaEmbarque.h"

PuertaEmbarque::PuertaEmbarque(int nombre) : identificacion(nombre)
{
    disponibilidad = true;
}

void PuertaEmbarque::anunciarEmbarque(const string &puerta)
{
    cout << "Anuncio de embarque en " << identificacion << " - Puerta " << puerta << endl;
}