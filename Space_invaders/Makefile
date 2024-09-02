GCC = g++

start: main.o invaders.o map.o list.o shields.o ship.o
	$(GCC) -g main.o invaders.o map.o list.o shields.o ship.o -o main.exe

main.o: main.cpp
	$(GCC) -g -c main.cpp -o main.o

invaders.o: invaders.cpp invaders.h
	$(GCC) -g -c invaders.cpp -o invaders.o 

map.o: map.cpp map.h
	$(GCC) -g -c map.cpp -o map.o

list.o: list.cpp list.h
	$(GCC) -g -c list.cpp -o list.o

shields.o: shields.cpp shields.h
	$(GCC) -g -c shields.cpp -o shields.o

ship.o: ship.cpp ship.h
	$(GCC) -g -c ship.cpp -o ship.o

clean: 
	del *.o *.exe