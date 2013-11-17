
CC=g++

FLAGS=-Wall -ansi -Wextra -pedantic -g -std=c++11

INCLUDE=-I../math -I../render -I.

all: Objects.o
	cp Objects.o ..

clean:
	@rm -f *.o; echo "Cleaned objects!"

Objects.o: Sphere.o Face3.o Object.o
	ld -r Sphere.o Face3.o Object.o -o Objects.o

Face3.o: Face3.hpp Face3.cpp
	$(CC) $(FLAGS) $(INCLUDE) -c Face3.cpp

Sphere.o: Sphere.cpp Sphere.hpp
	$(CC) $(FLAGS) $(INCLUDE) -c Sphere.cpp

Object.o: Object.hpp Object.cpp
	$(CC) $(FLAGS) $(INCLUDE) -c Object.cpp
