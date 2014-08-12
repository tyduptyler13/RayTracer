
CC=g++

FLAGS=-Wall -ansi -Wextra -pedantic $(SFLAGS) -std=c++11

INCLUDE=-I../math -I../render -I.

all: Objects.o

clean:
	@rm -f *.o; echo "Cleaned objects!"

Objects.o: Face3.cpp Face3.hpp Sphere.cpp Sphere.hpp Object.cpp Object.hpp
	$(CC) $(FLAGS) $(INCLUDE) -c Objects.cpp
