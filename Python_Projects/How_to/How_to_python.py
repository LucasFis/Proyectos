## Listas
Lista = [] ## Lista vacia
Lista = ['H','o', 'l', 'a',' ', 'M', 'u', 'n', 'd', 'o', '!'] ## Lista conteniendo 11 caracteres 
Lista[0] ## Contenido en la posicion 0 de la lista ('H')
Lista[-1] ## Contenido en la ultima posicion de la lista ('!')

Lista[:2] ## Otra lista que empieza desde el comienzo de la lista inicial y termina luego de dos elementos
Lista[2:] ## Otra lista que empieza desde la segunda posicion y termina en el final de la lista inicial
Lista[::2] ## Otra lista que imprime cada N pasos, en este caso, cada dos pasos
Lista[::-1] ## Caso particular del anterior, invierte toda la lista

Lista_strings = ["Hola","Mundo","!"] ## Lista de Lista de caracteres o una lista de strings.
Lista_Concatenacion = ["Adios", "Mundo"]

Lista_strings.append("!!!") ## Agrega el elemento "!!!" al final de la lista de strings

del Lista_strings[-1] ## Elimina el ultimo elemento de la lista ("!!!")

Lista_strings = Lista_strings + Lista_Concatenacion ## Concatenacion de listas

Lista_strings.sort() ## Ordena la lista en su orden alfabetico (en el caso de strings y caracteres)

Lista_strings.pop(-1) ## Emite y elimina el ultimo elemento

Lista_strings.count("Mundo") ## Retorna el numero de elementos repetidos enviados en el argumento, en este caso 2.

Lista_strings.extend(["!", "ODNUM","OLAH"]) ## Similar a la concatenacion, extiende la lista en la cantidad y elementos enviadas en su argumento.

Lista_strings.index("Mundo") ## Retornara la posicion del primer elemento que coincida con el argumento

Lista_strings.insert(2,"Hello?") ## Inserta el elemento en la siguiente posicion del index enviado en el argumento.

Lista_strings.remove("Hello?") ## Remueve el primer elemento que coincida con el argumento

tupla = ("Lucas", 20) ## Una tupla que intenta interpretar el nombre y la edad de una persona
    ## Las tuplas no pueden cambiar, debido que lo que se busca lograr con las tuplas es un
    ## Vinculo entre las propiedades dentro de ella.

## tupla.append("EE") No esta permitido

Nombre,edad = tupla ## Unpacking
                    ## Se le asigna a la variable Nombre = "Lucas" y edad = 20.

## Las listas y tuplas tienen una relacion, ambas se pueden transformar en la otra

lista_persona = list(tupla) ## Retorna ["Lucas",20]
tupla_persona = tuple(lista_persona) ## Retornara ("Lucas",20)

Diccionary = {
    "name" : "Lucas", ## Key : Value
    "Age" : 20
}

Diccionary["name"] ## Retornara "Lucas"
Diccionary["Direccion"] = "conesa 960" ## Agrega un elemnto key-value al diccionario

def for_loop(Number): ## Define una funcion.
    for elem in range(1,Number):
        print(elem)
    
def for_loop(min=1, max=10): ## Define una funcion con parametros estandarizados, aqui se permite no poner los parametros que estan estandarizados.
    for elem in range(min,max):
        print(elem)

class Tank(object): ## Crea una clase tanque, con los atributos name, alive, ammo y armor
    def __init__(self, name): ## Self actua como una bandera que indica cual objeto se debe inicializar
        self.name = name      ## En este caso, seria el objeto creado a partir de la clase Tank
        self.alive = True
        self.ammo = 5
        self.armor = 60
    
    def __str__(self):
        if self.alive:
            return f"Tanque: {self.name}, municion: {self.ammo}, armadura: {self.armor}"
        else:
            return f"El tanque {self.name} esta abatido"

Tanque = Tank("matador") ## Instancia (Crea) un objeto de la clase Tank.

print(Tanque)