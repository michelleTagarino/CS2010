/*	Assignment #2: Dictionary (using C++ strings) */

#include "dictionary.h"

DICT dictionary;  //dictionary  
int myCount[MAX];   //tracks word frequencies
WORD word;
int wordCnt;

int main (void) {
    int pos;

    while (1) {

       word = GetNextWord();
       if ( 0 == word.length() )  {
           DumpDictionary(dictionary,myCount);
           break;
       }
       if ((pos = LocateWord(dictionary,word)) >=  0 ) 
           myCount[pos]++;
       else
           if (!InsertWord(dictionary,word)) cout << "dictionary full " << word << " cannot be added\n";
    }
    return 0;
}
