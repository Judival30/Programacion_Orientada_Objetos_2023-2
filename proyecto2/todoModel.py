import streamlit as st

class TaskModel:
    def __init__(self, id, date, description):
        self.id = id
        self.date = date
        self.description = description
        self.state = "Pendiente"

    def setDate(self, date):
        self.date = date

    def setDescription(self, description):
        self.description = description

    def setState(self, state):
        self.state = state


class TodoModel:
    def __init__(self):
        if 'tasks' not in st.session_state:
            st.session_state['tasks'] = {}
            self.tasks = {}
        else:
            self.tasks = st.session_state['tasks']

    #C - Create
    def addNewTask(self, id, task):
        self.tasks[id] = task
        st.session_state['tasks'] = self.tasks

    #R - Read
    def getAllTasks(self):
        return self.tasks
            #st.session_state)['tasks']

    #U - Update
    def checkTask(self, taskid):
        self.tasks[taskid].setState("Completada")

    #D - Delete
    def removeTask(self, taskid):
        del(self.tasks[taskid])
