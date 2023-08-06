#include "hotel.h"

Hotel::Hotel()
{
    for (int i = 0; i < 10; i++)
    {
        Habitacion n(i);
        habitaciones.push_back(n);
        Huesped h;
        huespedes.push_back(h);
    }
}

void Hotel::setNombre(string &n)
{
    nombre = n;
}

void Hotel::printInfoHotel()
{
    for (vector<Habitacion>::iterator it = habitaciones.begin(); it != habitaciones.end(); it++)
    {
        printf("_____________________________\n");
        cout << "Habitacion: " << (*it).getNumero() << endl
             << "Precio: " << (*it).getPrecio() << endl;

        if ((*it).getEstado())
        {
            cout << "Estado: Ocupado\n"
                 << endl
                 << "Cliente: " << huespedes[(*it).getNumero()].getName() << endl
                 << "Tel: " << huespedes[(*it).getNumero()].getTel() << endl;
        }
        else
            cout << "Estado: Desocupado" << endl;
    }
    printf("_____________________________\n");
}

void Hotel::reserva()
{
    string n;
    int t;
    // Ingresar datos
    cout << "\nIngrese su nombre: ";
    cin >> n;
    cout << "\nIngrese su numero telefonico: ";
    cin >> t;
    Huesped h(n, t);
    cout << "Confirmacion de datos:" << endl
         << "Nombre: " << h.getName() << endl
         << "Tel: " << h.getTel() << endl
         << "Disponivilidad en tarjeta: " << h.getDinero() << endl;
    // Proceso de reserva
    bool flag = true;
    while (flag)
    {
        int num;
        cout << "\nSeleccione la habitacion que desea reservar: ";
        cin >> num;
        if (num > 10)
            cout << "Seleccione una habitacion entre la 0 y la 9" << endl;
        else if (habitaciones[num].getEstado())
            cout << "Esta habitacion esta reservada, seleccione otra opcion" << endl;
        else if (h.getDinero() < habitaciones[num].getPrecio())
            cout << "El precio de esta habitación supera el monto en su tarjeta, seleccione otra opcion" << endl;
        else
        {
            huespedes[num] = h;
            habitaciones[num].setOcupado();
            h.setDinero(h.getDinero() - habitaciones[num].getPrecio());
            cout << "La reserva ha sido exitosa, disfrute su estadia" << endl;
            flag = false;
        }
    }
    cout << endl;
}