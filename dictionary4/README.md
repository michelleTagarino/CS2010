# Dictionary 4

This dictionary is an updated version of Dictionary 3. This updated version now includes overloaded operators and a vector< of structs>.

## Let's Get You Started

Clone the **CS2010** repository:

	$ git clone https://github.com/michelleTagarino/CS2010.git

To compile: 

	$ make

To run:

	$ ./driver < FILE (where FILE is a text file of your choice)

## The driver file will behave as follows:
- Print out the whole dictionary 
- Print out the first set of words in the dictionary (the number of words dumped is specified as an integer value in the second parameter).
- The parameter specified in the GetNextWord function (whether a 0 or !0) will output either letters or non-letters, respectively.
- When the parameter is not 0, the program will try to print out the ASCII value at the end/beginning of the attached FILE that is being read.