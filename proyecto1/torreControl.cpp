#include "torreControl.h"

TorreControl::TorreControl()
{
    PuertaEmbarque puerta1(1);
    PuertaEmbarque puerta2(2);
    PuertaEmbarque puerta3(3);
    PuertaEmbarque puerta4(4);
    PuertaEmbarque puerta5(5);
    PuertaEmbarque puerta6(6);

    puertas.push_back(puerta1);
    puertas.push_back(puerta2);
    puertas.push_back(puerta3);
    puertas.push_back(puerta4);
    puertas.push_back(puerta5);
    puertas.push_back(puerta6);
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
    puertas[puerta - 1].disponibilidad = false;
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
            bool flag = true;
            for (int i = 0; i < puertas.size() && flag; i++)
            {
                if (puertas[i].disponibilidad)
                {
                    this->asignarPuertaDeEmbarque(aeronave, puertas[i].identificacion);
                    flag = false;
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

    int num1 = rand() % 90001 + 10000;
    int num2 = rand() % 90001 + 10000;
    // Genera un número aleatorio entre 10,000 y 100,000
    int numeroAleatorio = std::rand() % num1 + num2; // [0, 90000] + 10000 = [10000, 100000]

    return numeroAleatorio;
}

void TorreControl::simulacion()
{
    int pos1, pos2;

    for (auto &aeronave : aeronaves)
    {
        if (aeronave->tieneVuelos())
        {
            aeronave->despegar();
            pos1 = generarNumeroAleatorio();
            pos2 = generarNumeroAleatorio();
            string n = "Lat: ";
            string m = " Lon: ";
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
        }
    }
    for (int i = 0; i < puertas.size(); i++)
    {
        puertas[i].disponibilidad = true;
    }
}
