GCC = g++ 

start: password.o utils.o
	$(GCC) password.o utils.o -o main.exe
password.o: password.cpp
	$(GCC) -c password.cpp

utils.o: utils.cpp utils.h
	$(GCC) -c utils.cpp

clean: utils.o password.o
	del *.o *.exe