# Author: Michelle Tagarino	ID: 5029967	
# Makefile for Dictionary Assignment #4 (Final Assignment)

driver : dictionary.o driver.o
	g++ dictionary.o driver.o -o driver

dictionary.o : dictionary.cpp
	g++ -std=c++11 -mmacosx-version-min=10.10 -c dictionary.cpp

driver.o : driver.cpp
	g++ -std=c++11 -mmacosx-version-min=10.10 -c driver.cpp

clean :
	rm *.o driver
