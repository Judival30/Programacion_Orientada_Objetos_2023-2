""" from vuelos import Vuelos """


class PuertaEmbarque:
    def __init__(self, nombre):
        self.ident = nombre
        self.disponibilidad = True
        self.historial_vuelos = []

    def anunciarEmbarque(self, puerta):
        print(
            f"Anuncio de embarque en {self.ident} - Puerta {puerta}")
        
    def to_dictPE(self):
        data = {
            "nombre": "Puerta #" + str(self.ident),
        }
        if self.disponibilidad:
            data["disponibilidad"] = "Disponible"
        else:
            data["disponibilidad"] = "No disponible"
        return data
