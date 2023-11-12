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

    def disponibilidadVuelos(self):
        return bool(self.vuelos)

    def disponibilidadAeronaves(self):
        return self.torreControl.disponibilidadNaves()

    def asignarVuelo(self):
        for vuelo in self.vuelos:
            self.torreControl.seleccionarAeronave(vuelo)

    def obtenerVuelo(self, pos):
        return self.vuelos[pos]

    def agregarAeronave(self,id, nave):
        self.torreControl.aeronaves.append(nave)
        st.session_state["torreDeControl"]=self.torreControl
