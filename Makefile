CC = g++

all: gen_znstar_instances time_dislog

time_dislog: time_dislog.o dislog.o
	$(CC) -o time_dislog time_dislog.o dislog.o

time_dislog.o: time_dislog.cpp dislog.h
	$(CC) -c time_dislog.cpp -o time_dislog.o

gen_znstar_instances: gen_znstar_instances.o dislog.o
	$(CC) -o gen_znstar_instances gen_znstar_instances.o dislog.o

gen_znstar_instances.o: gen_znstar_instances.cpp dislog.h
	$(CC) -c gen_znstar_instances.cpp -o gen_znstar_instances.o

dislog.o: dislog.cpp dislog.h
	$(CC) -c dislog.cpp -o dislog.o
