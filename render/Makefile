
CC=g++

FLAGS=-Wall -ansi -Wextra -pedantic -g -std=c++11

INCLUDE=-I../objects -I../math -I.

all: Render.o
	cp Render.o ..

clean:
	@rm -f *.o; echo "Cleaned render!"

Render.o: Scene.o Camera.o ImageTools.o
	ld -r Scene.o Camera.o ImageTools.o -o Render.o

Camera.o: Camera.cpp Camera.hpp
	$(CC) $(FLAGS) $(INCLUDE) -fopenmp -c Camera.cpp

Scene.o: Scene.cpp Scene.hpp
	$(CC) $(FLAGS) $(INCLUDE) -c Scene.cpp

ImageTools.o: ImageTools.hpp ImageTools.cpp
	$(CC) $(FLAGS) -c ImageTools.cpp
