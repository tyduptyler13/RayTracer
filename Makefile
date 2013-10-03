
TARGET=RayTracer

CC=g++

FLAGS=-Wall -ansi -Wextra -pedantic -g -Og -std=c++11

all: build

clean:
	rm -f *.o $(TARGET)

build: Math.o Scene.o RayTracer.cpp
	$(CC) $(FLAGS) Math.o Scene.o RayTracer.cpp -o $(TARGET)
	
RayCaster.o: RayCaster.cpp
	$(CC) $(FLAGS) -c RayCaster.cpp

Math.o: Vector4.o Vector3.o Matrix4.o Matrix3.o Ray.o Sphere.o
	ld -r Vector4.o Vector3.o Matrix4.o Matrix3.o Ray.o Sphere.o -o Math.o

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
