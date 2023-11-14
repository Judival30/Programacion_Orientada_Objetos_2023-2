from aeronave import Aeronave


class JetPrivado(Aeronave):
    def __init__(self,id, marca, capacidad, mediator,modelo,velMax,anoFab,propietario,servicios,destinos):
        super().__init__(id, marca, capacidad, mediator,modelo,velMax,anoFab)
        self.propietario = propietario
        self.listaServicios = servicios
        self.listaDestinos = destinos

    def getPropietario(self):
        return self.propietario

    def print_info(self):
        super().printInfo()

    def obtenerDatos(self):
        try:
            self.propietario = input("Ingrese el nombre del propietario: ")
            print()
        except Exception as e:
            print("Error:", e)
