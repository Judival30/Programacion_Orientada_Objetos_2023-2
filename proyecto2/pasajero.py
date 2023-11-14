from persona import Persona
from vuelos import Vuelos
""" from vuelos import Vuelos """


class Pasajero(Persona):
    def __init__(self, nombre="", apellido="", edad=0, cedula="", fechaNacimiento="", genero="", direccion="", numTel="", correo="", nacionalidad="", infoMedica="", numMaletasBodega=0):
        super().__init__(nombre, apellido, edad, cedula,
                         fechaNacimiento, genero, direccion, numTel, correo)
        self.nacionalidad = nacionalidad
        self.infoMedica = infoMedica
        self.numMaletasBodega = numMaletasBodega
        self.vuelo = []

    def getNumMaletas(self):
        return self.numMaletasBodega

    def asignarVuelo(self, vuelo : Vuelos):
        p = vuelo.printVuelo()
        self.vuelo.append(p)

    def to_dict(self):
        return {
            "Nombre": self.nombre,
            "Apellido": self.apellido,
            "Edad": self.edad,
            "Cedula": self.cedula,
            "FechaNacimiento": self.fechaNacimiento,
            "Genero": self.genero,
            "Direccion": self.direccion,
            "Celular": self.numTel,
            "Correo": self.correo,
            "Nacionalidad": self.nacionalidad,
            "Info Medica": self.infoMedica,
            "Num MaletasBodega": self.numMaletasBodega
        }

    def getInformacion(self):
        return self.vuelo
        
