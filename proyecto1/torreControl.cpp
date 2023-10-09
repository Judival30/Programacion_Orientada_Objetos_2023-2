#include "torreControl.h"

TorreControl::TorreControl()
{
    PuertaEmbarque puerta1(1);
    PuertaEmbarque puerta2(2);
    PuertaEmbarque puerta3(3);

    puertas.push_back(puerta1);
    puertas.push_back(puerta2);
    puertas.push_back(puerta3);
}

void TorreControl::registrarAeronave(Aeronave *aeronave)
{
    aeronaves.push_back(aeronave);
}
void TorreControl::registrarAvion(Aeronave *aeronave)
{
    aviones.push_back(aeronave);
}
/**
 * The function "enviarMensaje" in the "TorreControl" class sends a message to all aircrafts except the
 * one that is the sender.
 *
 * The mensaje parameter is a constant reference to a string, which represents the
 * message that will be sent to the aeronaves.
 * The parameter "emisor" is a pointer to an object of type "Aeronave". It represents the
 * aircraft that is sending the message.
 */
void TorreControl::enviarMensaje(const string &mensaje, Aeronave *emisor)
{
    for (auto &aeronave : aeronaves)
    {
        if (aeronave != emisor)
        {
            aeronave->recibirMensaje(mensaje);
        }
    }
}

void TorreControl::asignarPuertaDeEmbarque(Aeronave *aeronave, int puerta)
{
    aeronave->asignarPuertaDeEmbarque(puerta);
}

bool TorreControl::disponibilidadNaves()
{
    if (aeronaves.size() == 0)
        return false;
    else
        return true;
}

void TorreControl::mostrarAviones()
{

    for (int i = 0; i < aeronaves.size(); i++)
    {
        printf("%d.\n", i + 1);
        aeronaves[i]->printInfo();
    }
}

void TorreControl::seleccionarAeronave(Vuelos *v)
{
    for (auto &aeronave : aeronaves)
    {
        if (aeronave->estado)
        {
            aeronave->agregarVuelo(v);
            for (int i = 0; i < puertas.size(); i++)
            {
                if (puertas[i].disponibilidad)
                {
                    this->asignarPuertaDeEmbarque(aeronave, puertas[i].identificacion);
                    break;
                }
            }
            break;
        }
    }
}
int generarNumeroAleatorio()
{
    // Inicializa la semilla del generador de números aleatorios
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Genera un número aleatorio entre 10,000 y 100,000
    int numeroAleatorio = std::rand() % 90001 + 10000;

    return numeroAleatorio;
}

void TorreControl::simulacion()
{
    for (auto &aeronave : aeronaves)
    {
        if (aeronave->tieneVuelos())
        {
            aeronave->despegar();
            int pos1 = generarNumeroAleatorio();
            int pos2 = generarNumeroAleatorio();
            string n = "Lat: ";
            string m = "Lat: ";
            string tmp = to_string(pos1);
            n += tmp;
            n += m;
            tmp = to_string(pos2);
            n += tmp;
            aeronave->actualizarPosicion(n);
        }
    }
    for (auto &aeronave : aeronaves)
    {
        if (aeronave->tieneVuelos())
        {
            aeronave->aterrizar();
            aeronave->eliminarVuelo();
            puertas.pop_back();
        }
    }
}
