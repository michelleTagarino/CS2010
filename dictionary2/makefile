# Michelle Tagarino
# makefile for the dictionary program (Assignment #2)

main : dictionary2.o main.o
	g++ dictionary2.o main.o -o main

dictionary2.o : dictionary2.cpp
	g++ -c dictionary2.cpp

main.o : main.cpp
	g++ -c main.cpp

clean:
	rm *.o main
