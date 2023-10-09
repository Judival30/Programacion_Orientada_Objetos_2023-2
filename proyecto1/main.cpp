#include "aeropuerto.h"

#include <algorithm>

void printLinea();
void reserva();
void modificarAeropuerto();
void agregarNaves();

Aeropuerto &aeropuerto = Aeropuerto::obtenerInstancia();
Aeronave *jet = new JetPrivado("Jet", 100, &aeropuerto.torreControl);
Aeronave *Heli = new Helicoptero("Helicoptero", 6, &aeropuerto.torreControl);
Aeronave *avion = new Avion("Avion", 6, &aeropuerto.torreControl);

int main()
{
    bool salir = true;
    int selec;
    printLinea();
    while (salir)
    {
        printf("Bienvenido\n1. Modificar aeropuerto\n2. reservar vuelo\n3. Simular\n4. Salir.\n");
        cin >> selec;
        switch (selec)
        {
        case 1:
            modificarAeropuerto();
            break;
        case 2:
            if (!aeropuerto.disponibilidadVuelos())
                printf("No hay vuelos disponibles aun\n");
            else
            {
                reserva();
                printf("Seleccione el destino\n");
                aeropuerto.printDestinos();
            }
            break;
        case 3:
            aeropuerto.torreControl.simulacion();
            break;
        case 4:
            printf("Te esperamos para la proxima, saliendo...\n");
            salir = false;
        default:
            printf("Seleccion erronea, seleccione una opcion valida...\n");
            break;
        }
        printLinea();
    }
    printf("Hola perra\n");

    return 0;
}

void reserva()
{
    Pasajero pasajero;
    pasajero.obtenerDatosPasajero();
    printLinea();
    bool flag = true;
    while (flag) // verificar datos
    {
        pasajero.getInformacion();
        printf("Los datos son correctos?\n1. Si\n2. No\n");
        int s;
        cin >> s;
        switch (s)
        {
        case 1:
            flag = false;
            break;
        case 2:
            pasajero.obtenerDatosPasajero();
            break;
        default:
            flag = false;
            break;
        }
    }
}

void modificarAeropuerto()
{
    int cases;
    printLinea();
    printf("Menu:\n\n1.Agregar Vuelos\n2.Agregar Naves\n3.Salir\n");
    cin >> cases;
    printLinea();
    bool flag1 = true;
    switch (cases)
    {
    case 1:
        if (!aeropuerto.disponibilidadAeronaves())
        {
            printf("No hay aeronaves disponibles\n");
            break;
        }
        Vuelos *tmp;
        tmp->obtenerDatosVuelo();
        flag1 = true;
        while (flag1) // verificar datos
        {
            tmp->printVuelo();
            printf("Los datos son correctos?\n1. Si\n2. No\n");
            int s;
            cin >> s;
            switch (s)
            {
            case 1:
                flag1 = false;
                break;
            case 2:
                tmp->obtenerDatosVuelo();
                break;
            default:
                flag1 = false;
                break;
            }
            printLinea();
        }
        // AGREGAR VUELO A AVION
        aeropuerto.torreControl.seleccionarAeronave(tmp);
        aeropuerto.agregarDestino(tmp);
        break;
    case 2:
        agregarNaves();
        break;
    case 3:
        printf("saliendo\n");
        flag1 = false;
        break;
    default:
        printf("seleccion erronea, seleccione otra opcion\n");
        break;
    }
    printLinea();
}

void agregarNaves()
{
    int cases, capacidad;
    bool flag2 = true;
    printLinea();
    string n;
    Aeronave *tmp;
    while (flag2)
    {
        printf("Agregar: \n1. Avion\n2. Jet\n3. Helicotero\n4. Salir\n");
        cin >> cases;
        switch (cases)
        {
        case 1:
            printLinea();
            printf("Ingrese la marca del avion\n");
            cin >> n;
            printf("Ingrese la capacidad del avion\n");
            cin >> capacidad;
            tmp = new Avion(n, capacidad, &aeropuerto.torreControl);
            aeropuerto.torreControl.registrarAvion(tmp);
            // Falta especificar
            break;
        case 2:
            printLinea();
            printf("Ingrese la marca del Jet\n");
            cin >> n;
            printf("Ingrese la capacidad del Jet\n");
            cin >> n;
            tmp = new JetPrivado(n, capacidad, &aeropuerto.torreControl);
            // Falta especificar
            break;
        case 3:
            printLinea();
            printf("Ingrese la marca del Helicoptero\n");
            cin >> n;
            printf("Ingrese la capacidad del Helicoptero\n");
            cin >> n;
            tmp = new Helicoptero(n, capacidad, &aeropuerto.torreControl);
            // Falta especificar
            break;
        case 4:
            printf("saliendo\n");
            flag2 = false;
            break;
        default:
            printf("Seleccion erronea, seleccione una opcion valida...\n");
            break;
        }
        aeropuerto.torreControl.mostrarAviones();
        printLinea();
    }
}

void printLinea()
{
    printf("===========================================================================================\n\n");
}
