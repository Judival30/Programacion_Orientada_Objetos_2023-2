#include "aeronave.h"

void Aeronave::enviarMensaje(const string &mensaje)
{
    mediador->enviarMensaje(mensaje, this);
}

Aeronave::Aeronave(const string &m, int c, MediadorTrafico *mediator)
{
    mediador = mediator;
    mediador->registrarAeronave(this);
    marca = m;
    modelo = "2019";
    capacidad = c;
    vuelos = {};
    estado = true;
    sillasDispo = 0;
}

Aeronave::Aeronave()
{
}
void Aeronave::despegar()
{
    cout << marca << ": Despegando." << endl;
    enviarMensaje("Despegando");
}

void Aeronave::aterrizar()
{
    cout << marca << ": Aterrizando." << endl;
    enviarMensaje("Aterrizando");
}

void Aeronave::actualizarPosicion(const string &mensaje)
{
    cout << marca << ": Actualizando posicion a " << mensaje << endl;
    enviarMensaje("Nueva posición: " + mensaje);
}

void Aeronave::recibirMensaje(const string &mensaje)
{
    cout << marca << " recibio mensaje: " << mensaje << endl;
}

void Aeronave::asignarPuertaDeEmbarque(const string &puerta)
{
    cout << marca << " se dirige a la puerta de embarque: " << puerta << endl;
    puerta_de_embarque = puerta;
}

void Aeronave::agregarVuelo(Vuelos &v)
{
    bool flag = estado;

    for (int i = 0; i < vuelos.size() && flag; i++)
    {
        if (v.identificacion == vuelos[i].identificacion)
            flag = false;
    }
    if (vuelos.size() < 3 && flag)
        vuelos.push_back(v);
    else
        printf("La aeronave esta totalmente asignada\n");
}

int Aeronave::getCapacidad()
{
    return this->capacidad;
}

void Aeronave::setModelo(const string s)
{
    this->modelo = s;
}

void Aeronave::setNombre(const string s)
{
    this->nombre = s;
}

void Aeronave::setAutonomia(int i)
{
    this->autonomia = i;
}

void Aeronave::setFabricacion(int i)
{
    this->fabricacion = i;
}

void Aeronave::setVelMax(int i)
{
    this->velMax = i;
}

void Aeronave::setSillasDispo(int i)
{
    this->sillasDispo = i;
}

void Aeronave::setEstado(bool b)
{
    this->estado = b;
}

string Aeronave::getMarca()
{
    return this->marca;
}

string Aeronave::getModelo()
{
    return this->modelo;
}

string Aeronave::getNombre()
{
    return this->nombre;
}

int Aeronave::getAutonomia()
{
    return this->autonomia;
}

int Aeronave::getFabricacion()
{
    return this->fabricacion;
}

int Aeronave::getVelMax()
{
    return this->velMax;
}

int Aeronave::getSillasDispo()
{
    return this->sillasDispo;
}

bool Aeronave::getEstado()
{
    return this->estado;
}