import streamlit as st

class TodoView:
    def __init__(self):
        st.title("Lista de tareas pendientes")

    def menu(self):
        st.header("Menú de opciones")
        option = st.selectbox("Opciones",["Inicio","Modificar Vuelos","Agregar Naves","Simular","Reservar vuelo","Consultar información"])
        return option

    def menuConsultar(self):
        st.subheader("¿Qué deseas consultar?")
        option = st.selectbox("Opciones",["Vuelos","Puertas de Embarque","Aeronaves"])
        return option
    
    def menuNaves(self):
        st.subheader("¿Qué tipo de nave deseas crear?")
        option = st.selectbox("Opciones",["Avión","Helicóptero","Jet"])
        return option

    def addNewVuelo(self):
        st.header("Modulo de creación de Vuelos")
        id=st.number_input("Ingrese la identificación del vuelo:",min_value=1,step=1)
        fecha=st.date_input("Ingrese la fecha del vuelo (YYYY-MM-DD):")
        ciudadDestino=st.text_input("Ingrese la ciudad de destino:",value="")
        hora = st.time_input("Ingrese la hora del vuelo (Hs:Ms):")
        createTarea = st.button("Crear un nuevo vuelo", type="primary")
        if createTarea:
            return {
                "id": id,
                "fecha": fecha,
                "ciudadDestino":ciudadDestino,
                "hora" : hora
            }
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
        
    def listAllVuelos(self, vuelos):
        st.subheader("Módulo de visualización de Vuelos")
        data = vuelos
        if data:
            st.table(data)
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
        if len(l)==0:
            st.info("No hay Aeronaves creadas hasta el momento", icon="ℹ️")
        else:
            for i in range(0,len(l),1):
                
                for j in range (0,len(l[i])):
                    st.subheader(l[i][j])
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