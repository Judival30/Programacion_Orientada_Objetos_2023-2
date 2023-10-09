#include "pasajero.h"
Pasajero::Pasajero() {}

Pasajero::Pasajero(const string &nombre, string &apellido, int edad, string &cedula, string &fechaNacimiento, string &genero, string &direccion, string &numTel, string &correo, string &nacionalidad, string &infoMedica, int numMaletasBodega)
    : Persona(nombre, apellido, edad, cedula, fechaNacimiento, genero, direccion, numTel, correo)
{
    this->numMaletasBodega = numMaletasBodega;
    this->nacionalidad = nacionalidad;
    this->infoMedica = infoMedica;
}
Pasajero Pasajero::obtenerDatosPasajero()
{
    string nombre, apellido, cedula, fechaNacimiento, genero, direccion, numTel, correo, nacionalidad, infoMedica;
    int edad, numMaletasBodega;
    cin.ignore();
    cout << "Ingrese el nombre del pasajero: ";
    getline(cin, nombre);

    cout << "Ingrese el apellido del pasajero: ";
    getline(cin, apellido);

    cout << "Ingrese la edad del pasajero: ";
    cin >> edad;

    cin.ignore(); // Limpiar el buffer de entrada

    cout << "Ingrese la cédula del pasajero: ";
    getline(cin, cedula);

    cout << "Ingrese la fecha de nacimiento del pasajero: ";
    getline(cin, fechaNacimiento);

    cout << "Ingrese el género del pasajero: ";
    getline(cin, genero);

    cout << "Ingrese la dirección del pasajero: ";
    getline(cin, direccion);

    cout << "Ingrese el número de teléfono del pasajero: ";
    getline(cin, numTel);

    cout << "Ingrese el correo del pasajero: ";
    getline(cin, correo);

    cout << "Ingrese la nacionalidad del pasajero: ";
    getline(cin, nacionalidad);

    cout << "Ingrese la información médica del pasajero: ";
    getline(cin, infoMedica);

    cout << "Ingrese el número de maletas de bodega del pasajero: ";
    cin >> numMaletasBodega;

    Pasajero pasajero(nombre, apellido, edad, cedula, fechaNacimiento, genero, direccion, numTel, correo, nacionalidad, infoMedica, numMaletasBodega);
    *this = pasajero;
    return pasajero;
}

int Pasajero::getNumMaletas()
{
    return this->numMaletasBodega;
}

void Pasajero::asignarVuelo(Vuelos *v)
{
    if (v->disponible())
    {
        vuelo = v;
        printf("El vuelo se asigno de manera correcta\n");
    }
    else
        printf("El vuelo no se encuentra disponible\n");
}

void Pasajero::getInformacion()
{
    Persona::getInformacion();
    cout << "Numero de Maletas en Bodega: " << numMaletasBodega << endl;
    cout << "Nacionalidad: " << nacionalidad << endl;
    cout << "Informacion Medica: " << infoMedica;
}
