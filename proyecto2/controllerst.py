from aeropuerto import Aeropuerto
from vuelos import Vuelos

from view import AeropuertoView
import streamlit as st

class AeropuertoController:
    def __init__(self,aeropuerto: Aeropuerto):
        self.aeropuerto=aeropuerto
        self.aeropuerto_view = AeropuertoView()
        if 'taskCount' not in st.session_state:
            st.session_state['taskCount'] = 0

    def increaseTaskCount(self):
        st.session_state['taskCount'] = st.session_state['taskCount'] + 1
        return st.session_state['taskCount']

    def ejecutar(self):
        num=0
        flag=True
        #Vista(?)
        rad=st.sidebar.radio("Opciones",["Inicio","Modificar Vuelos","Agregar Naves","Simular","Reservar vuelo","Consultar información"])
        #fin
        if rad=="Inicio":
            st.title("Aeropuerto Alfonso Bonilla")
            st.header("Bienvenido")
        if rad=="Modificar Vuelos":
            self.agregar_vuelos()
        elif rad=="Agregar Naves":
            self.agregar_naves()
        elif rad=="Simular":
            self.aeropuerto.asignarVuelo()
            l=self.aeropuerto.torreControl.simulacion()
            st.header("Simulación")
            if len(l)==0:
                st.text("No hay vuelos disponibles para simulación")
            else:
                for i in range(0,len(l),1):
                    for j in range (0,len(l[i])):
                        st.text(l[i][j])
        elif rad=="Reservar vuelo":
            if self.aeropuerto.disponibilidadVuelos():
                self.reserva()
            else:
                st.text("No hay vuelos")

        elif rad=="Consultar información":
            selec=st.selectbox("Opciones",["Vuelos","Puertas","Aeronaves"])
            if selec=="Vuelos":
                st.header("Destinos")
                data =self.aeropuerto.printDestinos()
                if data:
                    st.table(data)
                else:
                    st.info("No hay tareas Vuelos hasta el momento", icon="ℹ️")
            elif selec=="Puertas":
                st.header("Puertas")
                y=self.aeropuerto.torreControl.mostrarPuertas()
                for i in range (0,len(y),1):
                    st.text(y[i])
            elif selec=="Aeronaves":
                st.header("Aviones")
                z=self.aeropuerto.torreControl.mostrarAviones()
                for i in range (0,len(z),1):
                    st.text(z[i])

    def agregar_vuelos (self):
        st.header("Agregue un vuelo")
        id=st.text_input("Ingrese la identificación del vuelo:",value="")
        fecha=st.text_input("Ingrese la fecha del vuelo (YYYY-MM-DD):",value="")
        ciudadDestino=st.text_input("Ingrese la ciudad de destino:",value="")
        hora = st.text_input("Ingrese la hora del vuelo (Hs:Ms):",value="")
        if st.button("Guardar"):
            tmp = Vuelos(id, fecha, ciudadDestino, hora)
            self.aeropuerto.agregarDestino(tmp)
            st.text("Vuelo agregado exitosamente")
            #TEMPORAL
            st.text(id)
            st.text(fecha)
            st.text(ciudadDestino)
            st.text(hora)
            st.session_state['tasks'] = self.increaseTaskCount()
            self.tasks[] = tmp
        st.session_state['taskCount'] = self.tasks[0]
        print(self.tasks)

    def agregar_naves (self):
        #tmp
        st.text("AGREGAR NAVES")
    def reserva(self):
        #tmp
        st.text("RESERVA")
    




def main():
    aeropuerto= Aeropuerto()
    controller=AeropuertoController(aeropuerto)
    controller.ejecutar()

main()