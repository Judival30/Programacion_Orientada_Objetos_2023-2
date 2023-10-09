#include "aeropuerto.h"

void agregarNaves(Aeropuerto &aeropuerto);
void reserva(Aeropuerto &aeropuerto);

void printLinea()
{
    printf("===========================================================================================\n\n");
}

int main()
{
    Aeropuerto &aeropuerto = Aeropuerto::obtenerInstancia();

    /*  Aeronave *jet = new JetPrivado("Jet", 100, &aeropuerto.torreControl);
     Aeronave *Heli = new Helicoptero("Helicoptero", 6, &aeropuerto.torreControl);
     Aeronave *avion = new Avion("Avion", 6, &aeropuerto.torreControl); */

    /*  Vuelos *tmp;
     tmp->obtenerDatosVuelo();

     printLinea();

     aeropuerto.agregarDestino(tmp);
     aeropuerto.asignarVuelo();
     aeropuerto.torreControl.simulacion(); */
    int cases, num;
    bool flag = true;
    printLinea();
    while (flag)
    {
        printf("Bienvenido\n1. Modificar vuelos\n2. Agregar naves\n3. Simular\n4. reservar vuelo\n5. Salir.\n");
        cin >> cases;
        cout << endl;
        bool flag2 = true;
        switch (cases)
        {
        case 1:
            while (flag2)
            {
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
                printf("Salir?\n1. Si\n");
                cin >> num;
                if (num == 1)
                    flag2 = false;
            }
        case 2:
            agregarNaves(aeropuerto);
            break;
        case 3:
            aeropuerto.asignarVuelo();
            aeropuerto.torreControl.simulacion();
            break;
        case 4:
            reserva(aeropuerto);
            break;
        default:
            flag = false;
            break;
        }
        printLinea();
    }

    return 0;
}

void agregarNaves(Aeropuerto &aeropuerto)
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
            // Falta especificar
            break;
        case 2:
            printLinea();
            printf("Ingrese la marca del Jet\n");
            cin >> n;
            printf("Ingrese la capacidad del Jet\n");
            cin >> capacidad;
            tmp = new JetPrivado(n, capacidad, &aeropuerto.torreControl);
            // Falta especificar
            break;
        case 3:
            printLinea();
            printf("Ingrese la marca del Helicoptero\n");
            cin >> n;
            printf("Ingrese la capacidad del Helicoptero\n");
            cin >> capacidad;
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

void reserva(Aeropuerto &aeropuerto)
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
        case 2:
            pasajero.obtenerDatosPasajero();
            break;
        default:
            flag = false;
            break;
        }
    }
    printf("Seleccione su vuelo\n");
    aeropuerto.printDestinos();
}