
from todoView import TodoView
from aeropuerto import Aeropuerto
from jet import JetPrivado
from helicoptero import Helicoptero
from avion import Avion
from vuelos import Vuelos
from pasajero import Pasajero
from aerolinea import Aerolinea
import streamlit as st
import requests
import json


class TodoController:
    def __init__(self):
        self.aeropuerto = Aeropuerto()
        self.view = TodoView()
        if 'taskCount' not in st.session_state:
            st.session_state['taskCount'] = 1
        if 'aeronavesC' not in st.session_state:
            st.session_state['aeronavesC'] = 0
        if 'pasajeroC' not in st.session_state:
            st.session_state['pasajeroC'] = 0
        if 'listaJets' not in st.session_state:
            st.session_state['listaJets'] = 0
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
        elif option == "Reservar vuelo":
            self.createNewPasajero()
        elif option == "Añadir aerolíneas":
            self.createNewAerolinea()
        elif option == "Consultar país":
            self.consultarPais()
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
            self.createNewHelicoptero()
        elif option=="Jet":
            self.createNewJet()
#-----------------------------------------------------------------------------------------------------#
    def increaseTaskCount(self):
        st.session_state['taskCount'] = st.session_state['taskCount'] + 1
        return st.session_state['taskCount']
    
    def increaseAeronavesCount(self):
        st.session_state['aeronavesC'] = st.session_state['aeronavesC'] + 1
        return st.session_state['aeronavesC']
    
    def increasePasajeroCount(self):
        st.session_state['pasajeroC'] = st.session_state['pasajeroC'] + 1
        return st.session_state['pasajeroC']

#-----------------------------------------------------------------------------------------------------#
    def createNewVuelo(self):
        flag=self.aeropuerto.disponibilidadAerolineas()
        data = self.view.addNewVuelo(flag,self.aeropuerto.aerolinea)
        if data:
            taskId = self.increaseTaskCount()
            newVuelo = Vuelos(data["id"], data["fecha"], data["ciudadDestino"], data["hora"])
            self.aeropuerto.agregarDestino(taskId, newVuelo)
            self.aeropuerto.asignVueloAerolinea(data["aerolinea"],newVuelo)

    def createNewAvion(self):
        data = self.view.addNewAvion()
        if data:
            taskId = self.increaseAeronavesCount()
            newAvion = Avion(taskId, data["marca"], data["numPasajeros"], self.aeropuerto.torreControl, data["modelo"], data["velMax"], data["anoFab"], data["altitudMax"], data["numMotores"], data["categoria"] )
            self.aeropuerto.agregarAeronave(taskId, newAvion)

    def createNewJet(self):
        data = self.view.addNewJet()
        if data:
            taskId = self.increaseAeronavesCount()
            newJet = JetPrivado(taskId, data["marca"], data["numPasajeros"], self.aeropuerto.torreControl, data["modelo"], data["velMax"], data["anoFab"], data["propietario"], data["servicios"], data["destinos"] ) 
            self.aeropuerto.agregarAeronave(taskId, newJet)

    def createNewHelicoptero(self):
        data = self.view.addNewHelicoptero()
        if data:
            taskId = self.increaseAeronavesCount()
            newHelicoptero = Helicoptero(taskId, data["marca"], data["numPasajeros"], self.aeropuerto.torreControl, data["modelo"], data["velMax"], data["anoFab"], data["numRotores"], data["maxElevacion"], data["uso"] )
            self.aeropuerto.agregarAeronave(taskId, newHelicoptero)

    def createNewPasajero(self):
        dispo = self.aeropuerto.disponibilidadVuelos()
        d = self.view.addNewPasajero(dispo)
        if d:
            taskId = self.increasePasajeroCount()
            newPasajero = Pasajero(d["nombre"], d["apellido"], d["edad"], d["cedula"], d["fechaNacimiento"], d["genero"], d["direccion"], d["numTel"], d["correo"], d["nacionalidad"], d["infoMedica"], d["numMaletasBodega"])
            index = self.listAllVuelosReserva()
            if index:
                newPasajero.asignarVuelo(self.aeropuerto.vuelos[index])
                self.view.listVuelos(d[index])

    def createNewAerolinea(self):
        data=self.view.addNewAerolinea()
        if data:
            newAerolinea= Aerolinea(data["nombre"])
            self.aeropuerto.agregarAerolinea(data["nombre"],newAerolinea)
#-----------------------------------------------------------------------------------------------------#

    def listAllVuelosReserva(self):
        allVuelos = self.aeropuerto.printDestinosReserva()
        index = self.view.listAllVuelosReserva(allVuelos)
        return index

    def obtenerSimulacion(self):
        self.aeropuerto.asignarVuelo()
        l=self.aeropuerto.torreControl.simulacion()
        self.view.listAllSimulacion(l)

    def listAllVuelos(self):
        allVuelos = self.aeropuerto.printAerolineasVuelos()
        self.view.listAllVuelos(allVuelos)
    
    def listAllAeronaves(self):
        allNaves = self.aeropuerto.torreControl.mostrarAeronaves()
        self.view.listAllAeronave(allNaves)

    def getCountriesData(self,country : str):
        url = f"https://restcountries.com/v3.1/name/{country}"
        response = requests.get(url)
        if response.status_code == 200:
            data = json.loads(response.text)
            return data
            #print(data[0]['name']['common'])
        else:
            return ("Error en la consulta de los datos")

    def getCountriesData2(self,data):
        d={}
        d["name"]=data[0]["name"]["official"]
        d["capital"]=data[0]["capital"]
        cur = ""
        i=0
        for key in data[0]["currencies"]:
            cur = key
            i+=1
            if i>=1:
                break
        d["currency"]=data[0]["currencies"][cur]["name"]
        d["region"]=data[0]["region"]
        d["population"]=data[0]["population"]
        d["flag"]=data[0]["flags"]["png"]
        return d
    
    def consultarPais(self):
        x=self.getCountriesData(self.view.askCountry())
        if x!="Error en la consulta de los datos":
            d=self.getCountriesData2(x)
            self.view.listCountries(d)
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