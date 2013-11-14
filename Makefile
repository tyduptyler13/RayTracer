
TARGET=RayTracer

CC=g++

FLAGS=-Wall -ansi -Wextra -pedantic -g -std=c++11

INCLUDE=-Irender -Iobjects -Imath

all: Math.o Render.o Objects.o RayTracer.cpp
	$(CC) $(FLAGS) $(INCLUDE) -fopenmp Math.o Render.o Objects.o RayTracer.cpp -o $(TARGET)

clean:
	rm -f *.o $(TARGET)
	cd math; make clean
	cd objects; make clean
	cd render; make clean

Math.o: FORCE
	cd math; make

Objects.o: FORCE
	cd objects; make

Render.o: FORCE
	cd render; make

FORCE:
