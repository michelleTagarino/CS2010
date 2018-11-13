/* Header file for Lab Assignment #3 */

#ifndef	MEMORY
#define MEMORY

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iterator>

using namespace std;

class memory {
	private:
		int mem_size;
		vector<int> mem_block;

	public:
		memory(int=100); // Constructor with default size 100
		void store_integer(int, int);    // Stores integer at specified memory location
		int retrieve_integer(int);       // Retrieves integer from any memory location
		void copy_region(int, int, int); //	Copies region of memory to another location in memory
		void dump_memory();              // Dumps all the memory
		void dump_memory(int, int);      // Dumps only a specific range of memory
};

#endif

