/* Assignment #3: Dictionary (using dynamic memory allocation) */

#include "dictionary3.h"

DICT dictionary = {MAX,0,0};
WORD word;

int main (void) 
{
    ENTRY *pos;

    while (1) {

       word = GetNextWord();
       if ( word.empty() )  {
           DumpDictionary(dictionary);
           break;
       }

       if ((pos = LocateWord(dictionary,word)) > (void *) NULL ) 
           pos->count++;
       else
           if (!InsertWord(dictionary,word)) cout << "dictionary full" << word <<  "cannot be added\n";
    }
    return 0;
}
