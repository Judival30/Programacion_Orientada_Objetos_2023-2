from torreControl import TorreControl
import streamlit as st
from vuelos import Vuelos 


class Aeropuerto:
    instancia = None

    def __init__(self):
        
        if 'vuelos' not in st.session_state:
            st.session_state['vuelos'] = {}
            self.vuelos = {}
        else:
            self.vuelos = st.session_state['vuelos']
            
        if 'torreDeControl' not in st.session_state:
            self.torreControl = TorreControl()
            st.session_state['torreDeControl'] = self.torreControl 
        else:
            self.torreControl = st.session_state['torreDeControl']

        if "aerolinea" not in st.session_state:
            st.session_state["aerolinea"]={}
            self.aerolinea={}
        else:
            self.aerolinea=st.session_state["aerolinea"]
        
        if "pasajeros" not in st.session_state:
            st.session_state["pasajeros"]={}
            self.pasajeros={}
        else:
            self.pasajeros=st.session_state["pasajeros"]
        

    @classmethod
    def obtenerInstancia(cls):
        if cls.instancia is None:
            cls.instancia = cls()
        return cls.instancia

    def agregarDestino(self, id, vuelo : Vuelos):
        self.vuelos[id] = vuelo
        st.session_state['vuelos'] = self.vuelos

    def printDestinos(self):
        l=[]
        for i in self.vuelos:
            l.append(self.vuelos[i].printVuelo())
        return l
    
    def printDestinosReserva(self):
        l=[]
        for i in self.vuelos:
            if(self.vuelos[i].disponible()):
                l.append(self.vuelos[i].printVuelo())
        return l
    
    def printAerolineasVuelos(self):
        d={}
        for key in self.aerolinea:
            l=[]
            for i in range(len(self.aerolinea[key].vuelos)):
                l.append(self.aerolinea[key].vuelos[i].printVuelo())
            d[key]=l
        return d
    
    def printPasajeros(self):
        l = []
        for i in self.pasajeros:
            l.append(self.pasajeros[i].to_dict())
        return l

    def disponibilidadVuelos(self):
        return bool(self.vuelos)

    def disponibilidadAeronaves(self):
        return self.torreControl.disponibilidadNaves()
    
    def disponibilidadAerolineas(self):
        return bool(self.aerolinea)

    def asignarVuelo(self):
        for vuelo in self.vuelos:
            self.torreControl.seleccionarAeronave(self.vuelos[vuelo])

    def obtenerVuelo(self, pos):
        return self.vuelos[pos]

    def agregarAeronave(self,id, nave):
        self.torreControl.aeronaves.append(nave)
        st.session_state["torreDeControl"]=self.torreControl

    def agregarAerolinea(self, nombre, aerolinea):
        self.aerolinea[nombre]=aerolinea
        st.session_state["aerolinea"]=self.aerolinea

    def agregarPasajero(self, pasajero, nombre):
        self.pasajeros[nombre] = pasajero
        st.session_state["pasajeros"]=self.pasajeros

    def asignVueloAerolinea(self,nombre,vuelo):
        self.aerolinea[nombre].agregarVuelo(vuelo)