""" from tripulante import Tripulante
from pasajero import Pasajero """


class Vuelos:
    def __init__(self, id, fecha, ciudad_destino, hora,aerolinea):
        self.identificacion = id
        self.capacidad = 100  # Puedes establecer la capacidad deseada
        self.num_pasajeros = 0
        self.fecha = fecha
        self.ciudad_origen = "CLO"
        self.ciudad_destino = ciudad_destino
        self.hora = hora
        self.tripulantes = []
        self.tr = []
        self.estado = True
        self.aerolinea = aerolinea

    def agregarPasajero(self):
        if self.num_pasajeros < self.capacidad:
            self.num_pasajeros += 1
        else:
            self.estado = False
    
    def agregarTripulante(self, tripulantes, tr):
        self.tripulantes = tripulantes
        self.tr = tr

    def printVuelo(self):
        data = {"Aerolinea": self.aerolinea,"Ciudad de origen:": self.ciudad_origen,"Ciudad de destino:": self.ciudad_destino,"Fecha:": self.fecha, "Hora:": self.hora}
        if self.estado:
            data["Disponibilidad:"] = "disponible"
        else:
            data["Disponibilidad:"] = "Vuelo lleno"
        return data
    
    def printTripulantes(self):
        return self.tr
    def disponible(self):
        return self.estado
