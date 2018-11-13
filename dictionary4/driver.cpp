/* Lab Assignment #4: Dictionary 4 (Using overloaded operators) */

#include "dictionary.h"

DICT dictionary(MAX);  //your dictionary 
WORD word;        // 

int main (void) {
    int pos;

    while (1) {
       word = GetNextWord(0);
       if ( 0 == word.length() )  {
           cout << "\ndumping whole dictionary..." << endl;
           cout << dictionary << endl;
           cout << "dumping first 5 words in dictionary..." << endl;
           dictionary.dump(cout,5);
           break;
       }
       if ((dictionary.LocateWord(word)) >=  0 ) 
           cout << "word '" << word << "' already in dictionary\n";
       dictionary = dictionary + word;
    }
    return 0;
}
