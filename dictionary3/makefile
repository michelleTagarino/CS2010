# Michelle Tagarino
# makefile for the dictionary program using linked lists (Assignment #3)

main : dictionary3.o main.o
	g++ dictionary3.o main.o -o main

dictionary3.o : dictionary3.cpp
	g++ -c dictionary3.cpp

main.o : main.cpp
	g++ -c main.cpp

clean:
	rm *.o main
