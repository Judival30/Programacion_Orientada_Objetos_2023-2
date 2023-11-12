
from todoView import TodoView
from aeropuerto import Aeropuerto
from avion import Avion
from vuelos import Vuelos
import streamlit as st
import requests
import json


class TodoController:
    def __init__(self):
        self.aeropuerto = Aeropuerto()
        self.view = TodoView()
        if 'taskCount' not in st.session_state:
            st.session_state['taskCount'] = 0
        if 'aeronavesC' not in st.session_state:
            st.session_state['aeronavesC'] = 0
        #if 'option' not in st.session_state:
        #    st.session_state['option'] = 'Ver todas las tareas'

    def showMenu(self):
        option = self.view.menu()
        st.session_state['option'] = option
        if option == "Modificar Vuelos":
            self.createNewVuelo()
        elif option == "Consultar información":
            self.showMenuConsulta()
        elif option == "Agregar Naves":
            self.showMenuAeronaves()
        elif option == "Simular":
            self.obtenerSimulacion()
        """elif option == 'Marcar una tarea como completada':
            self.checkTask()
        elif option == 'Eliminar una tarea':
            self.removeTask() """
    
    def showMenuConsulta(self):
        option =self.view.menuConsultar()
        st.session_state['opcionConsulta'] = option
        if option=="Vuelos":
            self.listAllVuelos()
        elif option=="Puertas de Embarque":
            st.text("Proximamente")
        elif option=="Aeronaves":
            self.listAllAeronaves()

    
    def showMenuAeronaves(self):
        option =self.view.menuNaves()
        st.session_state['opcionAvion'] = option
        if option=="Avión":
            self.createNewAvion()
        elif option=="Helicóptero":
            st.text("Proximamente")
        elif option=="Jet":
            st.text("Proximamente")

    def increaseTaskCount(self):
        st.session_state['taskCount'] = st.session_state['taskCount'] + 1
        return st.session_state['taskCount']
    
    def increaseAeronavesCount(self):
        st.session_state['aeronavesC'] = st.session_state['aeronavesC'] + 1
        return st.session_state['aeronavesC']

    def createNewVuelo(self):
        data = self.view.addNewVuelo()
        if data:
            taskId = self.increaseTaskCount()
            newVuelo = Vuelos(data["id"], data["fecha"], data["ciudadDestino"], data["hora"])
            self.aeropuerto.agregarDestino(taskId, newVuelo)

    def createNewAvion(self):
        data = self.view.addNewAvion()
        if data:
            taskId = self.increaseAeronavesCount()
            newAvion = Avion(taskId, data["marca"], data["numPasajeros"], self.aeropuerto.torreControl, data["modelo"], data["velMax"], data["anoFab"], data["altitudMax"], data["numMotores"], data["categoria"] )
            self.aeropuerto.agregarAeronave(taskId, newAvion)
    def obtenerSimulacion(self):
        self.aeropuerto.asignarVuelo()
        l=self.aeropuerto.torreControl.simulacion()
        self.view.listAllSimulacion(l)

    def listAllVuelos(self):
        allVuelos = self.aeropuerto.printDestinos()
        self.view.listAllVuelos(allVuelos)
    
    def listAllAeronaves(self):
        allNaves = self.aeropuerto.torreControl.mostrarAeronaves()
        self.view.listAllAeronave(allNaves)
"""
    def removeTask(self):
        allTasks = self.model.getAllTasks()
        idToCheck = self.view.removeTask(allTasks)
        if idToCheck:
            self.model.removeTask(int(idToCheck))

    def checkTask(self):
        allTasks = self.model.getAllTasks()
        idToCheck = self.view.checkTask(allTasks)
        if idToCheck:
            self.model.checkTask(int(idToCheck))

    def getCountriesData(self):
        url = "https://restcountries.com/v3.1/name/colombia"
        response = requests.get(url)
        if response.status_code == 200:
            data = json.loads(response.text)
            print(data[0]['name']['common'])
        else:
            print("Error en la consulta de los datos") """