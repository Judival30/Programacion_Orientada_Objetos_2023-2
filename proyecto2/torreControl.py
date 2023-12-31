from mediadorTrafico import MediadorTrafico
from puertaEmbarque import PuertaEmbarque
from aeronave import Aeronave
from vuelos import Vuelos
import streamlit as st


class TorreControl(MediadorTrafico):
    def __init__(self):
        self.aeronaves = []
        self.aviones = []
        self.puertas = [PuertaEmbarque(i) for i in range(1, 7)]
        self.cont = 0

    def registrarAeronave(self, aeronave: Aeronave):
        self.aeronaves.append(aeronave)

    def registrarAvion(self, aeronave: Aeronave):
        self.aviones.append(aeronave)

    def enviarMensaje(self, mensaje, emisor: Aeronave):
        s = ""
        for aeronave in self.aeronaves:
            if aeronave != emisor:
                s += aeronave.recibirMensaje(mensaje) + ","

        print(s)
        return s

    def asignarPuertaDeEmbarque(self, aeronave: Aeronave, puerta, cod, hora):
        aeronave.asignarPuertaDeEmbarque(puerta, cod, hora)
        self.puertas[puerta - 1].disponibilidad = False

    def disponibilidadNaves(self):
        return bool(self.aeronaves)

    def mostrarAeronaves(self):
        x=[]
        for i in range(len(self.aeronaves)):
            x.append(self.aeronaves[i].printInfo())
        return x

    def seleccionarAeronave(self, vuelo : Vuelos):
        if self.cont == len(self.aeronaves):
            self.cont = 0
        for j in range(self.cont, len(self.aeronaves)):
            if self.aeronaves[j].estado:
                self.aeronaves[j].agregarVuelo(vuelo)
                flag = True
                for i in range(len(self.puertas)):
                    if self.puertas[i].disponibilidad:
                        self.asignarPuertaDeEmbarque(self.aeronaves[j], self.puertas[i].ident, vuelo.identificacion, vuelo.hora)
                        flag = False
                        break
                break
        self.cont += 1

    def simulacion(self):
        def generarNumeroAleatorio():
            import random
            return random.randint(10000, 100000)
        lista2=[]

        for aeronave in self.aeronaves:
            
            if aeronave.tieneVuelos():
                for i in range(len(aeronave.vuelos)):
                    x=aeronave.despegar()
                    pos1 = generarNumeroAleatorio()
                    pos2 = generarNumeroAleatorio()
                    n = "Lat: " + str(pos1) + " Lon: " + str(pos2)
                    y=aeronave.actualizarPosicion(n)
                    z=aeronave.aterrizar()
                    lista=[x,y,z]
                    lista2.append(lista)

                for i in range(len(aeronave.vuelos)):
                    aeronave.eliminarVuelo()
        

        for puerta in self.puertas:
            puerta.disponibilidad = True
        return lista2

    def mostrarPuertas(self):
        l=[]
        for puerta in self.puertas:
            estado = "disponible" if puerta.disponibilidad else "no disponible"
            x=(f"Puerta #{puerta.identificacion} {estado}")
            l.append(x)
        return l
    
    def listPuertas(self):
        l = []
        for i in range(len(self.puertas)):
            l.append(self.puertas[i].to_dictPE())
        return l
