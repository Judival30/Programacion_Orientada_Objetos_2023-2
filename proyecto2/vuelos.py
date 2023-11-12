""" from tripulante import Tripulante
from pasajero import Pasajero """


class Vuelos:
    def __init__(self, id, fecha, ciudad_destino, hora):
        self.identificacion = id
        self.capacidad = 100  # Puedes establecer la capacidad deseada
        self.num_pasajeros = 0
        self.fecha = fecha
        self.ciudad_origen = "CLO"
        self.ciudad_destino = ciudad_destino
        self.hora = hora
        self.tripulantes = []
        self.estado = True

    def agregarPasajero(self):
        if self.num_pasajeros < self.capacidad:
            self.num_pasajeros += 1
        else:
            print("Vuelo lleno")

    def printVuelo(self):
        data = {"Fecha:": self.fecha, "Hora:": self.hora, "Ciudad de origen:": self.ciudad_origen,"Ciudad de destino:": self.ciudad_destino}
        return data

    def disponible(self):
        return self.estado
