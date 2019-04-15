CC = g++

all: znstar

znstar: znstar.o
	$(CC) -o znstar znstar.o

znstar.o: znstar.cpp
	$(CC) -c znstar.cpp -o znstar.o
