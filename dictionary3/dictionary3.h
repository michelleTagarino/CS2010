/* Header File for Assignment #3 */

#ifndef DICTIONARY3
#define DICTIONARY3

#include <cstdio>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

const int MAX = 100;

typedef string STRING;
typedef bool BOOL;
typedef string WORD;

/*
	structure describing a word entry in the dictionary
*/
typedef struct entry {
      int count;                  //frequency count for a particular word
      WORD w;                     //the word itself
      struct entry *nextWord;     //pointer to next entry
} ENTRY;

/*
	structure describing the dictionary
*/
typedef struct dict {
     int maxEntries;		//maximum number of entries allowed
     int numWords;		//number of words in the dictionary
     ENTRY *Words;		//pointer to the entries in the dictionary
} DICT;

ENTRY *LocateWord(DICT&,WORD);	//searches dictionary, returns pointer to entry if found
BOOL FullDictionary(DICT&);	//returns true if dictionary is full
BOOL InsertWord(DICT&,WORD);	//inserts word, returns true if word was inserted
WORD GetNextWord(void);		//returns next word of text file
void DumpDictionary(DICT&);	//prints dictionary, words are in ascending order

#endif
