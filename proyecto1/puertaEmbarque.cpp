#include "puertaEmbarque.h"

PuertaEmbarque::PuertaEmbarque(int nombre) : identificacion(nombre) {

}

void PuertaEmbarque::anunciarEmbarque(const string& puerta) {
    cout << "Anuncio de embarque en " << identificacion << " - Puerta " << puerta << endl;
}