from abc import ABC, abstractmethod


class MediadorTrafico():

    def registrarAeronave(self, aeronave):
        pass

    def enviarMensaje(self, mensaje, emisor):
        pass

    def asignarPuertaDeEmbarque(self, aeronave, puerta, cod, hora):
        pass
