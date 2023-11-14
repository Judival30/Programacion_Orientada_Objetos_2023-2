from mediadorTrafico import MediadorTrafico
from vuelos import Vuelos

""" from tripulante import Tripulante  """



class Aeronave:
    def __init__(self, id, marca, capacidad, mediator :MediadorTrafico,modelo,velMax,anoFab):
        self.id=id
        self.mediador = mediator
        self.puerta_de_embarque = ""
        self.marca = marca
        self.modelo = modelo
        self.velMax = velMax
        self.capacidad = capacidad
        self.anoFab = anoFab
        self.vuelos= [] 
        self.estado = True
        self.sillasDispo = 0
        self.tripulantes = []

    def printInfo(self):
        
        data = {
            "marca":  self.marca,
            "capacidad": self.capacidad,
        }
        if(self.estado):
            data["estado"] = "En servicio"
        else:
            data["estado"] = "Totalmente asignada"
        return data


    def enviarMensaje(self, mensaje):
        s = self.mediador.enviarMensaje(mensaje, self)
        return s

    def despegar(self):
        x = str(self.marca)+": Despegando.,"
        x += (self.enviarMensaje(" Despegando "+ str(self.marca)))
       
        return x

    def aterrizar(self):
        y =(str(self.marca) +" Aterrizando.,")
        y += self.enviarMensaje(" Aterrizando " + str(self.marca))
        return y
    
    def actualizarPosicion(self, mensaje):
        z = str(self.marca) + ": Actualizando posición a " + mensaje + ","
        z += self.enviarMensaje(" Nueva posición: "+ str(self.marca) + " " + mensaje)
        return z
    
    def recibirMensaje(self, mensaje):
        w = (str(self.marca)+ " recibió mensaje: " + mensaje +",")
        return w
    
    def asignarPuertaDeEmbarque(self, puerta, cod, hora):
        y = str(self.marca) + " se dirige a la puerta de embarque: " + str(puerta) + " para el vuelo #" + str(cod)+ " Hora:" + str(hora)
        return y
    def agregarVuelo(self, v : Vuelos):
        flag = self.estado
        
        if len(self.vuelos) < 3 and flag:
            self.vuelos.append(v)
        else:
            self.estado = False
        if len(self.vuelos) == 3:
            self.estado = False

    def agregarTripulante(self, t):
        self.tripulantes.append(t)

    def eliminarVuelo(self):
        self.vuelos.pop()

    def tieneVuelos(self):
        return len(self.vuelos) > 0

    def getCapacidad(self):
        return self.capacidad

    def setModelo(self, s):
        self.modelo = s

    def setNombre(self, s):
        self.nombre = s

    def setAutonomia(self, i):
        self.autonom
