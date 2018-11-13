/* Assignment #3: Dictionary (using dynamic memory allocation) */

#include "dictionary3.h"

/* 
  adds word to dictionary , if word can't be added returns false else returns true
*/
BOOL InsertWord(DICT &dict, WORD word)
{
	if (FullDictionary(dict)) return false;
	
	ENTRY *newWord = new ENTRY;

	newWord->count = 1;

	newWord->w = word;
	newWord->nextWord = dict.Words;

	dict.Words = newWord;
	dict.numWords++;

	return true;
}

/* 
  will sort the dictionary, and display the contents
*/
void DumpDictionary(DICT &dict) 
{
	ENTRY *smallest; //the "smallest" word so far
	ENTRY *i;
	ENTRY *j, *tmp;	

	//Selection Sort
	for (i = dict.Words; i != 0; i = i->nextWord) {
		smallest = i;
		for (j = i->nextWord; j != 0; j = j->nextWord) {
			//search for smallest word so far
			if ((smallest->w) > (j->w)) {
				smallest = j;
			}

		}
		swap(smallest->w, i->w);		//swap words
		swap(smallest->count, i->count);	//swap frequencies
	}

	//Dump Sorted Dictionary
	i = dict.Words;

	cout << "-----------DICTIONARY-----------\n";
	cout << "WORD-------------------FREQUENCY\n";
	
	for (j = i->nextWord; j != 0; j = j->nextWord) {
		printf("%-15s %16d\n", (i->w).c_str(), i->count);
		delete i;		
		i = j;
	}
	printf("%-15s %16d\n", (i->w).c_str(), i->count);
	delete i;
}

/*
   will retrieve next word in input stream. Word is defined just as in assignment #1 
   returns WORD or empty string if no more words in input stream
*/
WORD GetNextWord(void)
{
	BOOL in = false;
	WORD myString;
	char ch;
	while ( cin.good() ) {

		ch = cin.get();
		if ( isalpha(ch) ) {
			myString.push_back(tolower(ch));
			in = true; //char was added to string
		}
		else if (in) {
			return myString;
		}
	}
	return "";
}

/* 
   if dictionary is full, return true else false 
*/
BOOL FullDictionary(DICT &dict)
{
	if (dict.numWords == MAX) return true;
	return false;
}

/*
   will determine if dictionary contains word. if found, returns pointer to entry else returns 0
*/
ENTRY *LocateWord(DICT &dict, WORD word)
{
	ENTRY *ptr = dict.Words;
	for (int i=0; i < dict.numWords; i++) {
		if (ptr->w == word) return ptr;
		else ptr = ptr->nextWord;
	}
	return 0;
}
