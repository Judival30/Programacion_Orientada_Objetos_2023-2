from vuelos import Vuelos


class Aerolinea():

    def __init__(self,nombre):
        self.nombre=nombre

        self.vuelos=[]

    def getNombre(self):
        return self.nombre()
    
    def getVuelos(self):
        return self.vuelos()
    
    def agregarVuelo(self,vuelo):
        self.vuelos.append(vuelo)
