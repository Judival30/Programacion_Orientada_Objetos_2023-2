from aeronave import Aeronave


class Avion(Aeronave):
    def __init__(self,id, marca, capacidad, mediator,modelo,velMax,anoFab, alitudMax, numMotores, categoría):
        super().__init__(id, marca, capacidad, mediator,modelo,velMax,anoFab)
        self.altitudMax = alitudMax
        self.numMotores = numMotores
        self.categoria = categoría

    def getAltitudMax(self):
        return self.altitudMax

    def getCategoria(self):
        return self.categoria

    def getNumMotores(self):
        return self.numMotores

    def print_info(self):
        super().printInfo()

    def obtenerDatos(self):
        try:
            self.numMotores = int(input("Ingrese el número de motores: "))
            print()

            self.categoria = int(input("Ingrese la categoría: "))
            print()

            self.altitudMax = int(input("Ingrese la altitud máxima: "))
            print()

        except ValueError:
            print("Error: Debe ingresar un número entero.")
