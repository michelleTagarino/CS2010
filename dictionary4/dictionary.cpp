/* Lab Assignment #4: Dictionary 4 (Using overloaded operators) */

#include "dictionary.h"

/*
	constructor. size is the initial size of dictionary
*/
DICT::DICT(int size)
{
	d.resize(size);	// resize dictionary to specified size, otherwise it's size 0
}

/*
	LocateWord will either return the location of found word in dictionary or -1 if it's not found
*/
itr DICT::LocateWord(WORD w)
{
	auto start = d.begin();
	for(auto it = d.begin(); it->freq != 0; ++it) {
		if (it->w == w) 
			return distance(start, it);  // return location of word reoccurence
	}
	return -1;
}

/*
	insert() will insert the word WORD in the dictionary if it's not already there; 
	otherwise, it will increase its frequency by 1 ( this is what operator+() does below)
*/
void DICT::insert(WORD w)
{
	cout << "\ninserting word";
	ENTRY newWord = {w,1}; // create new word with freq=1;
	auto it = d.begin();   // insert at beginning of dictionary
	d.insert(it,newWord);
}

/*
	this overloaded addition operator will insert the word w in the dictionary if it's not already there;
	otherwise, it will increase its frequency by 1
*/
DICT DICT::operator+(WORD w)
{
	int pos; // pos is the index location of word
	if ((pos = LocateWord(w)) >= 0) {
		d[pos].freq++;
		cout << d[pos].freq;
		return *this;
	} else {
		insert(w); // if not in dictionay, insert word
		return *this;
	}
}

/*
	dump() will dump the first i words in dictionary to ostream o or all words if i = -1
*/
void DICT::dump(ostream &o, int region = -1)
{
	// Selection Sort
	int smallest, tmp2;
	WORD tmp;
	
	for (int i = 0; d[i].w != ""; i++) {
		smallest = i;
		for (int j = i+1; d[j].w != ""; j++) {
			if (d[smallest].w > d[j].w)
				smallest = j;	
		}
		tmp = d[smallest].w;        // swap words
		d[smallest].w = d[i].w;
		d[i].w = tmp;

		tmp2 = d[smallest].freq;    // swap frequencies
		d[smallest].freq = d[i].freq;
		d[i].freq = tmp2;
	}
	
	if (region == -1) { // dump all memory
		for (auto it = d.begin(); it->w != ""; it++) {
				o << it->w;
				o << "     " << it->freq << endl;
		}
	} else { // dump specified region of memory
		for (int i = 0; i < region; i++) {
			if (d[i].w != ""){  // don't print anything if nothing there				
				o << d[i].w;
				o << "     " << d[i].freq << endl;
			}
		}
	}
}

/*
	dump() re-written as an overloaded operator. 
	dumps the WHOLE dictionary.
*/
ostream &operator<<(ostream &o, DICT &d)
{
	cout << "\nwhy is my life shitty ";
	d.dump(o,-1); // o is cout
	return o;
}

/*
	GetNextWord() will return the next word in the input stream.
	  - if parameter == 0, word is a sequence of upper and lower case letters
	  - if parameter != 0, word is a sequence of everthing BUT upper and lower case letters.
*/
WORD GetNextWord(int value)
{
	WORD w;
	char ch;
	bool in = false; // used to indicate that a word went in

	while( cin.good() )
	{
		ch = cin.get();
		if (value == 0) {
			if ( isalpha(ch) ) { // function test if ch is A-Z, a-z
				w.push_back(ch);
				in = true;
			} else if (in) return w;
		} else {
			if ( !isalpha(ch) ) { // function test if ch is not a letter
				w.push_back(ch);
				in = true;
			} else if (in) return w;
		}
	}
}
