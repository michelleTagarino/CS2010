/* Assignment #2: Dictionary (using C++ strings) */

#include "dictionary.h"

/* 
  adds word to dictionary , if word can't be added returns false else returns true
*/
BOOL InsertWord(DICT dict, WORD word)
{
	if (FullDictionary(dict)) return 0;
	
	dict[wordCnt] = word;
	myCount[wordCnt]++;
	wordCnt++;
	return 1;
}

/* 
  will sort the dictionary, and display the contents
*/
void DumpDictionary(DICT dict, int count[]) 
{
	WORD temp;
	int freqTemp;
	int smallest; //the "smallest" word in the dictionary

	//Selection Sort
	for (int i=0; i < wordCnt-1; i++) {
		smallest = i; 
		for (int j=i+1; j < wordCnt; j++) {
			if (dict[smallest] > dict[j]) {
				smallest = j;
			}
		}
		//move the smallest word to the front of the dictionary
		temp = dict[smallest];
		dict[smallest] = dict[i];
		dict[i] = temp;

		//also swap corresponding frequencies
		freqTemp = count[smallest];
		count[smallest] = count[i];
		count[i] = freqTemp;
	}

	cout << "-----------DICTIONARY-----------\n";
	cout << "WORD-------------------FREQUENCY\n";
	for (int i=0; i < wordCnt; i++) {
		printf("%-15s %16d\n",  dict[i].c_str(), count[i]);		
	}
}

/* 
   will retrieve next word in input stream. Word is defined just as in assignment #1 
   returns a WORD or empty string if no more words in input stream
*/
WORD GetNextWord(void)
{
	BOOL in = 0;
	WORD myString;
	char ch;
	while ( cin.good() ) {

		ch = cin.get();
		if ( isalpha(ch) ) {
			myString.push_back(tolower(ch));
			in = 1; //char was added to string
		}
		else if (in) {
			return myString;
		}
	}
	return "";
}

/* 
   if dictionary is full, return 1 else 0 
*/
BOOL FullDictionary(DICT dict) 
{
	if (wordCnt >= MAX) return 1;
	return 0;
}

/*
   will determine if dictionary contains word. if found, returns position else returns value < 0
*/
int LocateWord(DICT dict, WORD word)
{
	for (int i=0; i < wordCnt; i++) {
		if (dict[i] == word) return i;
	}
	return -1;
}
