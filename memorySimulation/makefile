# makefile for the memory simulation assignment (Lab Assignment #3)

driver : memory.o driver.o
	g++ memory.o driver.o -o driver

memory.o : memory.cpp
	g++ -std=c++11 -c memory.cpp

driver.o : driver.cpp
	g++ -std=c++11 -c driver.cpp

clean:
	rm *.o driver
