import pygame

# MODULOS

pygame ## Contains high-level Pygame functions
pygame.cursors ## Loads cursor images
pygame.display ## Accesses the display
pygame.draw ## Draws shapes, lines, and points
pygame.event ## Manages external events
pygame.font ## Uses system fonts
pygame.image ## Loads and saves an image
pygame.joystick ## Uses joysticks and similar devices
pygame.key ## Reads key presses from the keyboard
pygame.mixer ## Loads and plays sounds
pygame.mouse ## Manages the mouse
pygame.rect ## Manages rectangular areas
pygame.sndarray ## Manipulates sound data
pygame.sprite ## Manages moving images
pygame.surface ## Manages images and the screen
pygame.surfarray ## Manipulates image pixel data
pygame.time ## Manages timing and frame rate
pygame.transform ## Resizes and moves images

# CAPITULO 3: INTRODUCCION A PYGAME

from pygame.locals import *
from sys import exit

# FUNCIONES PRINCIPALES


pygame.init() 
pygame.sound.init()
## - Inicializa todos los modulos de pygame, entre ellos esta el sound, image, mixer, etc.
## - Cada modulo se puede inicializar en separado segun la segunda linea


X = 1080
Y = 720
SCREEN = pygame.display.set_mode((X,Y),0,32) 
## - Crea la ventana en la cual se mostrara el juego y prodemos interactuar con ella usando la variable SCREEN
## - El primer parametro es una tupla, con las cordenadas xy de tamaño de la ventana
## - El segundo parametro sera la forma de apertura, estas pueden ser:
FULLSCREEN ### Creates a display that fills the entire screen.
DOUBLEBUF  ### Creates a “double-buffered” display. Recommended for HWSURFACE or OPENGL.
HWSURFACE  ### Creates a hardware-accelerated display (must be combined with the FULLSCREEN flag).
OPENGL     ### Creates an OpenGL renderable display.
RESIZABLE  ### Creates a resizable display.
NOFRAME    ### Removes the border and title bar from the display
## - El tercer parametro es la cantidad de bits que se utiliza para crear los colores empleados en la ventana
## cuantos mas bits, mejor calidad de imagen.


pygame.display.set_caption("Hello, World!")

## Establece el titulo de la ventana previamente abierta


background = pygame.image.load("Folder/image1.jpg").convert()
mouse_cursor = pygame.image.load("Folder/image2.jpg").convert_alpha()
## - pygame.image.load carga la imagen encontrada en la carpeta enviada como argumento
## - convert() convierte la imagen en el mismo tipo que el display, debido que si tienen las mismas propiedades
## se cargara mas rapido.
## - convert_alpha() es similar al convert(), con la diferencia de que podria ser translucido o completamente invisible


while True:
    for event in pygame.event.get():
        if event.type == QUIT:
            exit()
## - While true, provoca un bucle infinito en el que solo saldremos si rompemos el mismo por un break u otro motivo suficiente
## - El ciclo for, es el ciclo denominado "Ciclo de eventos", el cual determinara cuando ocurra algun evento dentro del programa.
## Estos eventos pueden ser, tocar una tecla o recibir informacion del internet, los cuales estan esperando a ser atendidos.
## Entonces, lo que esta sucediendo en este for loop, es que estamos sacando de la cola cada evento que ocurrio desde el ultimo refresh
## del display, y atendiendolos segun corresponda con ifs anidados.
## En este caso, nuestro unico evento es cuando un usuario cierra la ventana, los demas son ignorados.


    SCREEN.blit(background, (0,0))
## - Utilizando nuestra variable de display, actualizamos su imagen utilizando una imagen previamente convertida y cargada (Como se mostro en la linea 59).
## - Su primer parametro establece la imagen seleccionada.
## - Su segundo parametro establece la posicion de la imagen, en este caso es (0,0) lo que significa que estara cargando desde el punto arriba a la izquierda del display.
## - En otras palabras, estamos dibujando la imagen por cada frame ocurrido dentro del bucle WHILE TRUE.


    x, y = pygame.mouse.get_pos()
    x -= mouse_cursor.get_width()/2
    y -= mouse_cursor.get_height()/2
    SCREEN.blit(mouse_cursor, (x, y))

## - pygame.mouse.get_pos() nos devolvera una tupla con la posicion del mouse en cada momento que es solicitado.
## - las dos lineas siguientes corresponden para ajustar, segun el tamaño de la imagen, la posicion en la que se debe dibujar la misma imagen.
## - La ultima linea dibuja la imagen segun la posicion obtenida anteriormente.

    pygame.display.update()