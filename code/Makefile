OBJS = main.o Chromosome.o Simulation.o
CC = g++
STD = -std=c++17

all : main

main : $(OBJS)
	$(CC) $(OBJS) $(STD) -g -o ../Test
main.o : main.cpp
	$(CC) $(STD) -g -c main.cpp
Chromosome.o : Chromosome.cpp
	$(CC) $(STD) -g -c Chromosome.cpp
Simulation.o : Simulation.cpp
	$(CC) $(STD) -g -c Simulation.cpp

clean :
	rm *.o
