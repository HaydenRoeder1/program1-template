CFLAGS = -g -Wall -Wextra -DDEBUG -std=c++14
all: program1.o
	g++ $(CFLAGS) list.o planet.o star.o program1.o vector.o -o program4
program1.o: list.o planet.o star.o vector.o program1.cpp
	g++ -c $(CFLAGS) program1.cpp -o program1.o
planet.o: planet.cpp
	g++ -c $(CFLAGS) planet.cpp -o planet.o
star.o: star.cpp
	g++ -c $(CFLAGS) star.cpp -o star.o
list.o: list.cpp
	g++ -c $(CFLAGS) list.cpp -o list.o
vector.o: vector.cpp
	g++ -c $(CFLAGS) vector.cpp -o vector.o
clean:
	rm -rf *.o
run:
	rm -rf *.o
memcheck:
	rm -rf *.o

