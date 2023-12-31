#include "vuelos.h"

Vuelos::Vuelos()
{
    ciudadOrigen = "CLO";
    estado = true;
}

Vuelos::Vuelos(int id, const string &fecha, const string &ciudadDestino, const string &hora)
    : identificacion(id), fecha(fecha),
      ciudadDestino(ciudadDestino), hora(hora),
      numPasajeros(0)
{
    ciudadOrigen = "CLO";
    estado = true;
}

void Vuelos::agregarPasajero()
{
    if (numPasajeros < capacidad)
        numPasajeros++;
    else
        printf("Vuelo lleno\n");
    if (numPasajeros == capacidad)
        estado = false;
}

void Vuelos::printVuelo()
{
    cout << "Fecha: " << fecha << endl
         << "Hora " << hora << endl
         << "Ciudad de origen: " << ciudadOrigen << endl
         << "Ciudad de destino " << ciudadDestino << endl;
}

bool Vuelos::disponible()
{
    return estado;
}
/*
Vuelos obtenerDatosVuelo()
{
    int id, capacidad, numPasajeros;
    string fecha, ciudadOrigen, ciudadDestino, hora, ej;

    try
    {
        cout << "Ingrese la identificacion del vuelo: ";
        cin >> ej;
        id = stoi(ej);
    }
    catch (const invalid_argument &e)
    {
        cerr << "Error argumento invalido " << e.what() << "Ingrese un numero entero" << endl;
        cin >> id;
    }

    cin.ignore(); // Limpiar el buffer de entrada

    cout << "Ingrese la fecha del vuelo (YYYY-MM-DD): ";
    getline(cin, fecha);

    cout << "Ingrese la ciudad de destino: ";
    getline(cin, ciudadDestino);

    cout << "Ingrese la hora del vuelo (HH:MM): ";
    getline(cin, hora);

    // Crear y devolver un objeto Vuelos con los datos ingresados
    Vuelos tmp(id, fecha, ciudadDestino, hora);
    return tmp;
} */