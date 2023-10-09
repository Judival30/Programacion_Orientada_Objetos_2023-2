#include "aeropuerto.h"

#include <algorithm>

void printLinea()
{
    printf("===========================================================================================\n\n");
}

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
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Aeropuerto &aeropuerto = Aeropuerto::obtenerInstancia();

    Aeronave *jet = new JetPrivado("Jet", 100, &aeropuerto.torreControl);
    Aeronave *Heli = new Helicoptero("Helicoptero", 6, &aeropuerto.torreControl);
    Aeronave *avion = new Avion("Avion", 6, &aeropuerto.torreControl);

    aeropuerto.torreControl.mostrarAviones();

    cout << endl;

    Vuelos *v1;
    Vuelos *v2;
    Vuelos *v3;
    Vuelos *v4;

    printf("Agregue vuelos\n");
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
    Vuelos *tmp = new Vuelos(id, fecha, ciudadDestino, hora);
    aeropuerto.agregarDestino(tmp);

    tmp->printVuelo();

    aeropuerto.agregarDestino(v1);
    aeropuerto.agregarDestino(v2);
    aeropuerto.agregarDestino(v3);
    aeropuerto.agregarDestino(v4);

    aeropuerto.asignarVuelo();

    aeropuerto.torreControl.simulacion();
    /*
        jet->despegar();
        Heli->despegar();
        Heli->despegar();

        jet->actualizarPosicion("Lat: 40.7128, Lon: -74.0060");
        Heli->actualizarPosicion("Lat: 34.0522, Lon: -118.2437");
        avion->actualizarPosicion("Lat: 51.5074, Lon: -0.1278");

        jet->aterrizar();
        Heli->aterrizar();
        avion->aterrizar();

        puerta1.anunciarEmbarque("Puerta 1");
        puerta2.anunciarEmbarque("Puerta 2");
        puerta3.anunciarEmbarque("Puerta 3"); */

    bool salir = true;
    int selec;
    printLinea();
    while (salir)
    {
        printf("Bienvenido a vuelaComoTuEx.com, ¿Deseas comprar un vuelo?\n1. Si\n2. No\n");
        cin >> selec;
        switch (selec)
        {
        case 1:
            printf("Seleccione el destino\n");
            aeropuerto.printDestinos();
            break;
        case 2:
            printf("Te esperamos para la proxima, saliendo...\n");
            salir = false;
        default:
            printf("Seleccion erronea, seleccione una opcion valida...\n");
            break;
        }
        printLinea();
    }
    printf("Hola perra\n");

    string nombrePasajero = "Juan";
    string apellidoPasajero = "Perez";
    int edadPasajero = 30;
    string cedulaPasajero = "1234567890";
    string fechaNacimientoPasajero = "01/01/1990";
    string generoPasajero = "Masculino";
    string direccionPasajero = "Calle Principal 123";
    string numTelPasajero = "555-123-4567";
    string correoPasajero = "juan@example.com";
    string nacionalidadPasajero = "Mexicana";
    string infoMedicaPasajero = "Ninguna";
    int numMaletasBodegaPasajero = 2;

    // Crear un objeto Pasajero usando el constructor
    Pasajero juanPerez(nombrePasajero, apellidoPasajero, edadPasajero, cedulaPasajero, fechaNacimientoPasajero, generoPasajero, direccionPasajero, numTelPasajero, correoPasajero, nacionalidadPasajero, infoMedicaPasajero, numMaletasBodegaPasajero);

    cout << "Nombre: " << juanPerez.getNombre() << endl;
    cout << "Edad: " << juanPerez.getEdad() << endl;
    cout << "Número de Maletas de Bodega: " << juanPerez.getNumMaletas() << endl;

    // Parámetros para crear un objeto Tripulante
    string nombreTripulante = "Ana";
    string apellidoTripulante = "Gomez";
    int edadTripulante = 28;
    string cedulaTripulante = "2345678901";
    string fechaNacimientoTripulante = "15/05/1995";
    string generoTripulante = "Femenino";
    string direccionTripulante = "Calle Secundaria 456";
    string numTelTripulante = "555-987-6543";
    string correoTripulante = "ana@example.com";
    string cargoTripulante = "Azafata";
    int xpTripulante = 3;
    int hrsDiariasTripulante = 8;

    // Crear un objeto Tripulante usando el constructor
    Tripulante ana(nombreTripulante, apellidoTripulante, edadTripulante, cedulaTripulante, fechaNacimientoTripulante, generoTripulante, direccionTripulante, numTelTripulante, correoTripulante, cargoTripulante, xpTripulante, hrsDiariasTripulante);

    /*     cout << "Nombre: " << ana.getNombre() << endl;
        cout << "Edad: " << ana.getEdad() << endl;
        cout << "Cargo: " << ana.getCargo() << endl;
        cout << "Experiencia: " << ana.getXp() << " años" << endl;
        cout << "Horas Diarias de Trabajo: " << ana.getHorasDiarias() << " horas" << endl; */

    return 0;
}
