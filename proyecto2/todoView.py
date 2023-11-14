import streamlit as st
import pandas as pd

class TodoView:
    def __init__(self):
        st.title("Lista de tareas pendientes")
        if 'destinos' not in st.session_state:
            st.session_state['destinos'] = []
            self.destinos = []
        else:
            self.destinos = st.session_state['destinos']
        if 'servicios' not in st.session_state:
            st.session_state['servicios'] = []
            self.servicios = []
        else:
            self.servicios = st.session_state['servicios']

    def increaseJetsListas(self):
        st.session_state['listaJets'] = st.session_state['listaJets'] + 1
        return st.session_state['listaJets']
    
    def menu(self):
        st.sidebar.header("Menú de opciones")
        option = st.sidebar.selectbox("Opciones", ["Inicio", "Añadir aerolíneas","Modificar Vuelos", "Agregar Naves", "Simular", "Reservar vuelo", "Consultar información","Consultar país"])
        return option

    def menuConsultar(self):
        st.subheader("¿Qué deseas consultar?")
        option = st.selectbox("Opciones",["Vuelos","Puertas de Embarque","Aeronaves"])
        return option
    
    def menuNaves(self):
        st.subheader("¿Qué tipo de nave deseas crear?")
        option = st.selectbox("Opciones",["Avión","Helicóptero","Jet"], index=None)
        return option

    def addNewVuelo(self,flag,dicc):
        if flag:
            lista=[]
            for key in dicc:
                lista.append(key)
            st.header("Modulo de creación de Vuelos")
            aerolinea=st.selectbox("Con que aerolínea desea crear su vuelo",lista,index=None)
            id=st.number_input("Ingrese la identificación del vuelo:",min_value=1,step=1)
            fecha=st.date_input("Ingrese la fecha del vuelo (YYYY-MM-DD):")
            ciudadDestino=st.text_input("Ingrese la ciudad de destino:",value="")
            hora = st.time_input("Ingrese la hora del vuelo (Hs:Ms):")
            createTarea = st.button("Crear un nuevo vuelo", type="primary")
            if createTarea:
                st.success('se ha creado un vuelo exitosamente', icon="✅")
                return {
                    "id": id,
                    "aerolinea":aerolinea,
                    "fecha": fecha,
                    "ciudadDestino":ciudadDestino,
                    "hora" : hora
                }
        else:
            st.info("No hay Aerolíneas creadas hasta el momento", icon="ℹ️")

    def addNewAvion(self):
        marca = st.text_input("ingrese la marca del avión",value="")
        numPasajeros = st.number_input("ingrese la capacidad del avión",min_value=1,step=1)
        altitudMax= st.number_input("ingrese la altitud máxima del avión",min_value=1000,step=100)
        numMotores=st.number_input("ingrese la cantidad de motores del avión",min_value=1,max_value=4,step=1)
        categoria= st.selectbox("Elija una categoría",["Comercial","Carga"])
        modelo=st.text_input("ingrese el modelo del avión",value="")
        velMax= st.number_input("ingrese la velocidad máxima del avión",min_value=300,step=100)
        anoFab = st.number_input("ingrese el año de fabricación del avión",min_value=1990,max_value=2023,step=1)
        createTarea = st.button("Crear un nuevo avión", type="primary")
        if createTarea:
            st.success('se ha creado un avión exitosamente', icon="✅")
            return {
                "marca":marca,
                "numPasajeros":numPasajeros,
                "altitudMax":altitudMax,
                "numMotores":numMotores,
                "categoria":categoria,
                "modelo":modelo,
                "velMax":velMax,
                "anoFab":anoFab
            }
    def addNewHelicoptero(self):
        marca = st.text_input("ingrese la marca del helicóptero",value="")
        numPasajeros = st.number_input("ingrese la capacidad del helicóptero",min_value=1,step=1)
        modelo=st.text_input("ingrese el modelo del helicóptero",value="")
        velMax= st.number_input("ingrese la velocidad máxima del helicóptero",min_value=300,step=100)
        anoFab = st.number_input("ingrese el año de fabricación del helicóptero",min_value=1990,max_value=2023,step=1)
        numRotores = st.number_input("ingrese el número de rotores",min_value=1,max_value=5,step=1)
        maxElevacion = st.number_input("ingrese la capacidad máxima de elevación del helicóptero",min_value=1000,step=100)
        uso=st.selectbox("ingrese el tipo de uso de su helicóptero",["tráfico de drogas","político","de carga"])
        createTarea = st.button("Crear un nuevo helicóptero", type="primary")
        if createTarea:
            st.success('Se ha creado un Helicóptero exitosamente', icon="✅")
            return{
                "marca":marca,
                "numPasajeros":numPasajeros,
                "numRotores":numRotores,
                "maxElevacion":maxElevacion,
                "uso":uso,
                "modelo":modelo,
                "velMax":velMax,
                "anoFab":anoFab 
            }

    def addNewJet(self):
        key = self.increaseJetsListas()
        marca = st.text_input("ingrese la marca del jet",value="")
        numPasajeros = st.number_input("ingrese la capacidad del jet",min_value=1,step=1)
        modelo=st.text_input("ingrese el modelo del jet",value="")
        velMax= st.number_input("ingrese la velocidad máxima del jet",min_value=300,step=100)
        anoFab = st.number_input("ingrese el año de fabricación del jet",min_value=1990,max_value=2023,step=1)
        propietario=st.text_input("ingrese el propietario del jet",value="")
        servicios=st.text_input("Añada uno o más servicios para el jet",value="")
        if servicios:
            if len(self.servicios) >= 1:
                if servicios != self.servicios[len(self.servicios) - 1]:
                    self.servicios.append(servicios)
                    st.session_state["servicios"] = self.servicios
            else:
                self.servicios.append(servicios)
                st.session_state["servicios"] = self.servicios
        masServicios = st.button("Añadir más servicios", type="secondary")
        destinos=st.text_input("Añada uno o más destinos para el jet",value="")
        if destinos: 
            if len(self.destinos) >= 1:
                if destinos != self.destinos[len(self.destinos) - 1]:
                    self.destinos.append(destinos)
                    st.session_state["destinos"] = self.destinos
            else:
                self.destinos.append(destinos)
                st.session_state["destinos"] = self.destinos
        masDestinos = st.button("Añadir más destinos", type="secondary")
        createTarea = st.button("Crear un nuevo jet", type="primary")
        if createTarea:
            st.success('Se ha creado el jet exitosamente', icon="✅")
            data ={
                "marca":marca,
                "numPasajeros":numPasajeros,
                "propietario":propietario,
                "servicios":self.servicios,
                "destinos":self.servicios,
                "modelo":modelo,
                "velMax":velMax,
                "anoFab":anoFab 
            }
            st.session_state["destinos"] = []
            st.session_state["servicios"] = []
            return data
        
    def addNewAerolinea(self):
        st.header("Modulo de creación de Aerolineas")
        nombre=st.text_input("Ingrese el nombre de la aerolínea",value="")
        createAerolinea=st.button("Crear una nueva Aerolínea",type="primary")
        if createAerolinea:
            st.success('Se ha creado la aerolinea exitosamente', icon="✅")
            return {
                "nombre": nombre
            }

    def addNewPasajero(self, dispo):
        if dispo: 
            nombre = st.text_input("Ingrese el nombre del pasajero:",value="")
            apellido = st.text_input("Ingrese el apellido del pasajero: ",value="")
            edad = st.number_input("Ingrese la edad del pasajero: ",min_value=1,step=1)
            cedula = st.number_input("Ingrese la cédula del pasajero: ",min_value=1,step=None)
            fechaNacimiento = st.date_input("Ingrese la fecha de nacimiento del pasajero: ", value=None)
            genero = st.selectbox("Genero",["Masculino","Femenino", "Otro"])
            direccion = st.text_input("Ingrese la dirección del pasajero: ",value="")
            numTel = st.number_input("Ingrese el número de teléfono del pasajero: ",min_value=1,step= None)
            correo = st.text_input("Ingrese el correo del pasajero: ",value="")
            nacionalidad = st.text_input("Ingrese la nacionalidad del pasajero: ",value="")
            infoMedica = st.text_input("Ingrese la información médica del pasajero: ",value="")
            numMaletasBodega = st.number_input("Ingrese el número de maletas en la bodega: ",min_value=0,step=1)
            createTarea = st.button("Registrarse", type="primary")
            if createTarea:
                st.success('Se ha registrado correctamente el pasajero', icon="✅")
                return{
                    "nombre":nombre,
                    "apellido":apellido,
                    "edad":edad,
                    "edad":edad,
                    "cedula":cedula,
                    "fechaNacimiento":fechaNacimiento,
                    "genero":genero,
                    "direccion":direccion,
                    "numTel":numTel,
                    "correo":correo,
                    "nacionalidad":nacionalidad,
                    "infoMedica":infoMedica,
                    "numMaletasBodega":numMaletasBodega
                }
        else:
            st.info("No hay vuelos creados hasta el momento", icon="ℹ️")      
        
    def listVuelos(self, vuelos):
        data = vuelos
        if data:
            st.table(data)
        else:
            st.info("No hay vuelos creados hasta el momento", icon="ℹ️")   

    def listAllVuelos(self, vuelos):
        st.subheader("Módulo de visualización de Vuelos")
        data = vuelos
        if data:
            for key in data:
                st.subheader(key)
                d=data[key]
                st.table(d)
        else:
            st.info("No hay vuelos creados hasta el momento", icon="ℹ️")

    def listAllVuelosReserva(self, vuelos):
        st.subheader("Módulo de selección de Vuelos")
        data = vuelos
        
        if data:
            destinos = []
            for i in range(len(data)):
                destinos.append(str(i))
            st.table(data)
            selected_index = st.selectbox('Selecciona una fila', destinos)
            createTarea = st.button("Continuar", type="primary")
            if createTarea:
                return selected_index
        else:
            st.info("No hay vuelos creados hasta el momento", icon="ℹ️")
            
    def listAllAeronave(self, naves):
        st.subheader("Módulo de visualización de Aeronaves")
        data = naves
        if data:
            st.table(data)
        else:
            st.info("No hay Aeronaves creadas hasta el momento", icon="ℹ️")
    
    def listAllSimulacion (self, l):
        st.header("Simulación")
        st.text(l)
        if len(l)==0:
            st.info("No hay Aeronaves creadas hasta el momento", icon="ℹ️")
        else:
            for i in range(0,len(l),1):
                
                for j in range (0,len(l[i])):
                    s = l[i][j].split(",")
                    for k in range(len(s)):
                        st.write(s[k])


    def askCountry(self):
        x=st.text_input("Escriba el país que desea consultar")
        return x
    
    def listCountries(self,d):

        st.header(d["name"])
        st.subheader("Capital")
        st.write(d["capital"][0])
        st.subheader("Moneda")
        st.write(d["currency"])
        st.subheader("Región")
        st.write(d["region"])
        st.subheader("Población")
        st.write(d["population"])
        st.subheader("Bandera")
        st.image(d["flag"])
""" 
    def removeTask(self, tasks):
        st.header("Módulo de eliminación de tareas")
        data = []
        for task in tasks:
            singleTask = tasks[task]
            data.append(singleTask.id)
        taskId = st.selectbox('Seleccione el ID de la tarea a eliminar:', data)
        updateTarea = st.button("Eliminar esta tarea", type="primary")
        if updateTarea:
            return taskId

    def checkTask(self, tasks):
        st.header("Módulo de actualización de tareas")
        data = []
        for task in tasks:
            singleTask = tasks[task]
            data.append(singleTask.id)
        #taskId = st.number_input("Ingrese el ID de la tarea a completar:", min_value=1)
        taskId = st.selectbox('Seleccione el ID de la tarea a completar:', data)
        updateTarea = st.button("Marcar esta tarea como completada", type="primary")
        if updateTarea:
            return taskId


 """