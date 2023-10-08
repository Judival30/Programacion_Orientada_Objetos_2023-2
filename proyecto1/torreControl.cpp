#include "torreControl.h"

    
void TorreControl::registrarAeronave(Aeronave* aeronave)  {
    aeronaves.push_back(aeronave);
}

/**
 * The function "enviarMensaje" in the "TorreControl" class sends a message to all aircrafts except the
 * one that is the sender.
 * 
 * @param mensaje The mensaje parameter is a constant reference to a string, which represents the
 * message that will be sent to the aeronaves.
 * @param emisor The parameter "emisor" is a pointer to an object of type "Aeronave". It represents the
 * aircraft that is sending the message.
 */
void TorreControl::enviarMensaje(const string& mensaje, Aeronave* emisor)  {
    for (auto& aeronave : aeronaves) {
        if (aeronave != emisor) {
            aeronave->recibirMensaje(mensaje);
        }
    }
}

void TorreControl::asignarPuertaDeEmbarque(Aeronave* aeronave, const string& puerta)  {
    aeronave->asignarPuertaDeEmbarque(puerta);
}