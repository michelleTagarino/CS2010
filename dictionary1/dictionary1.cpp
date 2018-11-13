#include <cstdio>
#include <cctype>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*


		Author: Michelle Tagarino ID# 5029967
		Assignment #1: Dictionary
		Purpose: Create a dictionary that will read a text file and build a dictionary of words using a
				 two-dimensional char array. It reads from the text file by using the < operator from the 
				 command line. Example: "./prog < file.dat". Words that occur more than once are not
				 repeated in the dictionary. The frequency of each word is also counted. 


*/

const int WORDLEN  = 30;	// maximum word length
const int NUMWORDS = 40;	// maximum number of words
const int BUFFLEN  = 100;	// maximum buffer length
char buffer[BUFFLEN];
char dictionary[NUMWORDS][WORDLEN];
int  frequency[NUMWORDS];	//frequency of each word
bool dictOverload = false;	//checks if there are too many words in file
bool wordOverload = false;	//checks if word is too long
int ptrWord = 0;	// points to current word in dictionary 
int wordCnt = 0;	// number of words so far
int *ptrFreq = frequency;

/*	FUNCTION PROTOTYPES	*/
void dumpDict();	/* dumps the dictionary */
int searchDict();	/* checks if word is already in dictionary */
void addToDict();	/* adds word to dictionary */

/*
	dumps the dictionary
	displays the restrictions (max number of words and max word length)
	if the word is too long, display error message
*/
void dumpDict() {

	printf(">>>>>>>>>>>>>>>>>>>>>>>>> DICTIONARY <<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
	printf("This dictionary holds up to %2d words.\n", NUMWORDS);
	printf("Words can be no longer than %2d letters.\n\n", WORDLEN);
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
	if(dictOverload) {
			printf("FYI - Dictionary overload\n");
			printf("      Dumping only the first %2d words\n\n", NUMWORDS);
	}
	printf ("WORD                           FREQUENCY\n");
	printf ("----------------------------------------\n");
	for (int i=0; i < wordCnt; i++) {
		 printf ("%-30s %9d\n", dictionary[i], frequency[i]);
	}
	if (wordOverload)
		printf("\nFYI - Word(s) excluded for exceeding length\n");
}

/*
	searches dictionary
	if word is already in dictionary return location of that word
	otherwise return -1
*/
int searchDict() {

	for (int i=0; i <= wordCnt; i++) {
		if ( strcmp(dictionary[i],buffer) ==0 ) {
			return i;
			break;
		}
	}
	return -1;
}

/*
	adds each character from buffer 
*/
void addToDict() {
	
	for (int i=0; i <= strlen(buffer); i++) {
		if( i==strlen(buffer) )	
			dictionary[ptrWord][i] = '\0';
		else 
			dictionary[ptrWord][i] = buffer[i];
	}
}

int main() {

	char ch;
	while( cin.good() ) {

		//put word in buffer
		for (int i=0; i<BUFFLEN; i++) {
			ch = cin.get();
			if ( isalpha(ch) ) {
				buffer[i] = tolower(ch); //convert each letter to lowercase
			}
			else { 
				if ( strlen(buffer) >= WORDLEN ) { //word longer than 30, don't add to dict
					wordOverload = true;
					break;
				}
				if ( searchDict() == -1 ) { //if word not in dict, add it
					addToDict();
					*ptrFreq  = 0;						
					*ptrFreq += 1;
					*ptrFreq++;
					wordCnt++;
					ptrWord++;		
					break;
				}
				else {
					int location = searchDict();
					frequency[location]++;
					break;				
				}
			}
		}
		//clear buffer
		for (int i=0; i<WORDLEN; i++) {
		buffer[i] = '\0';
		}
		if (wordCnt >= NUMWORDS) {
			dictOverload = true;
			break;
		}
	}
	dumpDict();
	return 0;
}
