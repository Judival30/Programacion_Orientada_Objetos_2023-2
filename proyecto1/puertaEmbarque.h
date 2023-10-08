#ifndef PUERTA_EMBARQUE
#define PUERTA_EMBARQUE 

#include <iostream>
#include <vector>
#include "vuelos.h"
using namespace std;

class PuertaEmbarque{
    public:
        int identificacion;
        bool disponibilidad;
        //vector<Vuelos> historialVuelos;

        PuertaEmbarque(int nombre) ;

        void anunciarEmbarque(const string& puerta);
};


#endif 