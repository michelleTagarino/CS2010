/* Header file for Dictionary Assignment #4 (Final Assignment) */

#ifndef DICTIONARY
#define DICTIONARY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>

#define MAX 100

using namespace std;
using std::string;

typedef string WORD;
typedef int itr;
 
struct ENTRY {
  WORD w;
  int freq;
};

class DICT {
private:
	vector <ENTRY> d;

public :
	DICT(int = 0);
	itr LocateWord(WORD);
	void insert(WORD);
	DICT operator+ (WORD);
	void dump (ostream &o, int);
	friend ostream &operator<<(ostream &, DICT &);
};

ostream &operator<<(ostream &, DICT &);
WORD GetNextWord(int);


#endif
