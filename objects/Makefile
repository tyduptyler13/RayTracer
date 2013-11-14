
CC=g++

FLAGS=-Wall -ansi -Wextra -pedantic -g -std=c++11

INCLUDE=-I../math -I../render

all: Objects.o
	cp Objects.o ..

clean:
	@rm -f *.o; echo "Cleaned objects!"

Objects.o: Sphere.o Face4.o Face3.o
	ld -r Sphere.o Face4.o Face3.o -o Objects.o

Face3.o: Face3.hpp Face3.cpp
	$(CC) $(FLAGS) $(INCLUDE) -c Face3.cpp

Face4.o: Face4.hpp Face4.cpp
	$(CC) $(FLAGS) $(INCLUDE) -c Face4.cpp

Sphere.o: Sphere.cpp Sphere.hpp
	$(CC) $(FLAGS) $(INCLUDE) -c Sphere.cpp
