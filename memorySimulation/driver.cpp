/* Lab Assignment #3: Memory Simulation (using vectors) */

#include "memory.h"

int main(void)
{ 
	int size = 200;
	memory m(size); // Create memory block of 200 elements

	int j = 0;

	for (int i = 0; i < size; i++) {
		m.store_integer(i, j); // Store value j (multiples of 3) into memory location i
		j += 3;
	}
	
	m.dump_memory(); // Dump all of memory
	
	printf("\n\n");
	m.dump_memory(26,19); // Dump 19 elements starting at location 26

	int i = m.retrieve_integer(54); // Retrieve integer from location 54
	printf("\nInteger Retrieved: %d\n\n",i); // Print the integer that was just retrieved

	m.copy_region(1,10,5); // Copy 5 elements starting at location
                           // and place it starting at location 10
	m.dump_memory(); // Dump all of memory again
		
	return 0;
}
