
# All of the math objects can be built from here.

CC=g++

FLAGS=-Wall -ansi -Wextra -pedantic $(SFLAGS) -std=c++11

# Need to have all of the directories indexed.
INCLUDE=-I../render -I../objects -I.

all: Math.o

clean:
	@rm -f *.o; echo "Cleaned math!"

Math.o: Vector3.hpp Vector3.cpp Vector4.cpp Vector4.cpp Ray.hpp Ray.cpp RayCaster.hpp RayCaster.cpp
	$(CC) $(FLAGS) $(INCLUDE) -c Math.cpp	
