/* Header File for Assignment #2 */

#ifndef DICTIONARY
#define DICTIONARY

#include <cstdio>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;
using std::string;

#define MAX 100

typedef int BOOL;
typedef string WORD;
typedef WORD DICT[MAX];

extern int wordCnt;		//tracks word frequencies
extern int myCount[MAX];	//holds the frequencies of each word

int LocateWord(DICT, WORD);
BOOL FullDictionary(DICT);
BOOL InsertWord(DICT,WORD);
WORD GetNextWord(void);
void DumpDictionary(DICT ,int[]);

#endif
