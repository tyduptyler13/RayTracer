
TARGET=RayTracer

CC=g++

FLAGS=-Wall -ansi -Wextra -pedantic -g -O2 -std=c++11

all: build

clean:
	rm -f *.o $(TARGET)

build: Math.o Render.o Objects.o RayTracer.cpp
	$(CC) $(FLAGS) -fopenmp Math.o Render.o Objects.o RayTracer.cpp -o $(TARGET)

Math.o: Vector4.o Vector3.o Matrix4.o Matrix3.o Ray.o RayCaster.o
	ld -r Vector4.o Vector3.o Matrix4.o Matrix3.o Ray.o RayCaster.o -o Math.o

Objects.o: Sphere.o Face4.o Face3.o
	ld -r Sphere.o Face4.o Face3.o -o Objects.o

Render.o: Scene.o Camera.o ImageTools.o
	ld -r Scene.o Camera.o -o Render.o ImageTools.o

Camera.o: Camera.cpp Camera.hpp
	$(CC) $(FLAGS) -fopenmp -c Camera.cpp

Vector4.o: Vector4.cpp Vector4.hpp
	$(CC) $(FLAGS) -c Vector4.cpp

Vector3.o: Vector3.hpp Vector3.cpp Matrix3.hpp Matrix4.hpp
	$(CC) $(FLAGS) -c Vector3.cpp 

Matrix4.o: Matrix4.cpp Matrix4.hpp Vector3.hpp
	$(CC) $(FLAGS) -c Matrix4.cpp

Matrix3.o: Matrix3.cpp Matrix3.hpp Vector3.hpp
	$(CC) $(FLAGS) -c Matrix3.cpp

Sphere.o: Sphere.cpp Sphere.hpp
	$(CC) $(FLAGS) -c Sphere.cpp

Scene.o: RayCaster.o Scene.cpp Scene.hpp
	$(CC) $(FLAGS) -c Scene.cpp

Ray.o: Ray.cpp Vector3.hpp Scene.hpp
	$(CC) $(FLAGS) -c Ray.cpp

RayCaster.o: RayCaster.cpp
	$(CC) $(FLAGS) -c RayCaster.cpp

Face3.o: Face3.hpp Face3.cpp
	$(CC) $(FLAGS) -c Face3.cpp

Face4.o: Face4.hpp Face4.cpp
	$(CC) $(FLAGS) -c Face4.cpp

ImageTools.o: ImageTools.hpp ImageTools.cpp
	$(CC) $(FLAGS) -c ImageTools.cpp
