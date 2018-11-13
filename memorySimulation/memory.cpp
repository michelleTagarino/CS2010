/* Lab Assignment #3: Memory Simulation (using vectors) */

#include "memory.h"

/*
	Constructor with default size 100.
*/
memory::memory(int size)
{	
	mem_size = size;
	mem_block.resize(size);
}

/*
	Stores an integer value at specific location in memory.
*/
void memory::store_integer(int mem_addr, int integer)
{
	auto it = mem_block.begin();
	mem_block.insert(it + mem_addr, integer);
}

/*
	Retrieves an integer from a specific location in memory and returns the integer value.
*/
int memory::retrieve_integer(int mem_addr)
{
	return mem_block[mem_addr];
}

/*
	Copies a region of memory starting at the source location and places
	that copied region at the start of the destination location in memory.
*/
void memory::copy_region(int source, int destination, int region)
{
	vector<int> tmp(mem_block);

	for (int i = destination; i < region + destination; i++, source++) {
		tmp[i] = mem_block[source];
	}
	for (int i = 0; i < mem_size; i++) { //deep copy
		mem_block[i] = tmp[i];
	}
}

/*
	Dumps all the memory.
*/
void memory::dump_memory()
{
	int row_num = 0;
	printf("MEMORY\n");
	printf("   |    0");
	for (int i = 1; i <= 9; i++) {
		printf("%5d", i);
	}
	printf("\n------------------------------------------------------");
	for (int i = 0; i < mem_size; i++) {
		if (i % 10 == 0) {
			printf("\n%3d|", row_num);
			row_num += 10;
		}
		printf("%5d", mem_block[i]);
	}
	printf("\n");
}

/*
	Dumps only a specific range of memory
*/
void memory::dump_memory(int mem_addr, int range)
{
	int row_num = 0;
	printf("MEMORY: (BETWEEN LOCATION %2d & LOCATION %2d)\n", mem_addr, mem_addr+range);
	printf("   |    0");
	for (int i = 1; i <= 9; i++) {
		printf("%5d", i);
	}
	printf("\n------------------------------------------------------");
	for (int i = 0; i < mem_size; i++) {
		if (i % 10 == 0) {
			printf("\n%3d|", row_num);
			row_num += 10;
		}
		if (i < mem_addr || i > mem_addr+range) printf("     ");
		else printf("%5d", mem_block[i]);
	}
	printf("\n");
}
