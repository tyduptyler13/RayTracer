
TARGET=RayTracer

CC=g++

export SFLAGS=-ffast-math -O3

FLAGS=-Wall -ansi -Wextra -pedantic $(SFLAGS) -std=c++11

INCLUDE=-Irender -Iobjects -Imath

all: Math.o Render.o Objects.o RayTracer.cpp
	$(CC) $(FLAGS) $(INCLUDE) -fopenmp Math.o Render.o Objects.o RayTracer.cpp -o $(TARGET)

clean:
	rm -f *.o $(TARGET)
	cd math; $(MAKE) clean
	cd objects; $(MAKE) clean
	cd render; $(MAKE) clean

Math.o: FORCE
	cd math; $(MAKE)

Objects.o: FORCE
	cd objects; $(MAKE)

Render.o: FORCE
	cd render; $(MAKE)

FORCE:
