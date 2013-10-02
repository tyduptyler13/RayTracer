
TARGET=RayTracer

CC=g++

FLAGS=-Wall -ansi -Wextra -pedantic -g -O2 -std=c++11

all: build

clean:
	rm *.o $(TARGET)

build: Scene.o RayTracer.cpp
	$(CC) $(FLAGS) RayTracer.cpp -o $(TARGET)
	
RayCaster.o: Vector4.o Vector3.o Matrix4.o Matrix3.o Sphere.o Ray.o RayCaster.cpp
	$(CC) $(FLAGS) -c RayCaster.cpp

Vector4.o: Vector4.cpp
	$(CC) $(FLAGS) -c Vector4.cpp

Vector3.o: Vector3.cpp
	$(CC) $(FLAGS) -c Vector3.cpp 

Matrix4.o: Matrix4.cpp
	$(CC) $(FLAGS) -c Matrix4.cpp

Matrix3.o: Matrix3.cpp
	$(CC) $(FLAGS) -c Matrix3.cpp

Sphere.o: Sphere.cpp
	$(CC) $(FLAGS) -c Sphere.cpp

Scene.o: RayCaster.o Scene.cpp
	$(CC) $(FLAGS) -c Scene.cpp

Ray.o: Ray.cpp
	$(CC) $(FLAGS) -c Ray.cpp
