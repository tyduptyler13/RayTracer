
TARGET=RayTracer

CC=g++

#Global flags. These will be passed into the sub directories
export SFLAGS=-O3

FLAGS=-Wall -ansi -Wextra -pedantic $(SFLAGS) -std=c++11

INCLUDE=-Irender -Iobjects -Imath

all: math/Math.o render/Render.o objects/Objects.o RayTracer.cpp FileParser.hpp
	$(CC) $(FLAGS) $(INCLUDE) -fopenmp math/Math.o render/Render.o objects/Objects.o RayTracer.cpp -o $(TARGET)

clean:
	rm -f *.o $(TARGET)
	cd math; $(MAKE) clean
	cd objects; $(MAKE) clean
	cd render; $(MAKE) clean

math/Math.o: FORCE
	cd math; $(MAKE)

objects/Objects.o: FORCE
	cd objects; $(MAKE)

render/Render.o: FORCE
	cd render; $(MAKE)

FORCE:
