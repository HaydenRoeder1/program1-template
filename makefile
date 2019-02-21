CFLAGS = -g -Wall -Wextra -DDEBUG -std=c++14
all: program1.o
	g++ $(CFLAGS) list.o planet.o starlist.o program1.o vector.o -o program4
program1.o: list.o planet.o starlist.o vector.o program1.cpp
	g++ -c $(CFLAGS) program1.cpp -o program1.o
planet.o: Planet.cpp
	g++ -c $(CFLAGS) Planet.cpp -o planet.o
starlist.o: Starlist.cpp
	g++ -c $(CFLAGS) Starlist.cpp -o starlist.o
list.o: List.cpp
	g++ -c $(CFLAGS) List.cpp -o list.o
vector.o: Vector.cpp
	g++ -c $(CFLAGS) Vector.cpp -o vector.o
clean:
	rm -rf *.o
run:
	rm -rf *.o
memcheck:
	rm -rf *.o

