
CC=g++

FLAGS=-Wall -ansi -Wextra -pedantic $(SFLAGS) -std=c++11

INCLUDE=-I../objects -I../math -I.

all: Render.o

clean:
	@rm -f *.o; echo "Cleaned render!"

Render.o: Scene.cpp Scene.hpp Camera.cpp Camera.hpp ImageTools.cpp ImageTools.hpp
	$(CC) $(FLAGS) $(INCLUDE) -fopenmp -c Render.cpp
