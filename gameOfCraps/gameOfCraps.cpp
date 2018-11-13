#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int die();
int roll();
void playGame();
void rollToMakePoint (int);

int main()
{
	//srand() generates random numbers when program is executed and rand() function is called
	//time(NULL) allows numbers to be automatically obtained for the seed value
	srand(time(NULL)); 
	char ans;
	bool done = false;
	bool gameTracker=false;
	
	//Display instructions to user
	if (gameTracker == false)
	{
		cout << "Hi! Welcome to the Game of Craps." << endl << endl
			 << "The game is easy:" << endl
			 << "  Roll the pair of dice." << endl 
			 << "  If the sum of the dice is a 2, 3, or 12, you LOSE." << endl
			 << "  If the sum of the dice is either a 7 or 11, you WIN!" << endl
			 << "  If the sum is none of these numbers, then this will be your POINT." << endl
			 << "  This means you haven't lost yet. Keep rolling until you get this POINT again, then you will WIN!" << endl
			 << "  When you're 'making the point' DON'T roll a 7, otherwise you LOSE." << endl << endl;
	}
	
	while (done==false)
	{
		cout << "Are you ready to roll? (Y/N) ";
		cin >> ans;
		cout << endl;	 
	
		if (ans == 'y' || ans == 'Y') done = false; 
			else done = true;

		playGame();
		cout << endl << "Play Again (Y/N) ? ";
		cin >> ans;
		if (ans == 'y' || ans == 'Y') 
		{
			done = false;
			gameTracker = true;
		}
			else done = true;
	}
	return 0;
}
/****************************************************************************************************

NOW ENTERING FUNCTIONS

int die()  : This function rolls one die. Returns the value as an integer.

int roll() : This function rolls two die and adds their values. Returns the value as an integer.

void playGame() : This function makes the First Roll. Does not return any values.
The user's First Roll dictates whether they won the game, 
keep playing (to "make the point"), or lost the game.

void rollToMakePoint(int) : This function tries to "make the point".
The parameter (point) is the user's First Roll. 

*****************************************************************************************************/
int die()
{
	int die;
	die = 1+(rand() % 6);
	return die;
}
int roll()
{
	int die1 = die();
	int die2 = die();
	int roll = die1 + die2;
	cout << "You Rolled " << die1 << " + " << die2 << " = " << roll << endl;
	return roll;
}
void playGame()
{
	int firstRoll  = 0;
	int point      = 0;

	firstRoll = roll();
	
	switch (firstRoll)
	{
		case 2 : // CRAPS
				 cout << "Player Loses..." << endl;
				 break;
		case 3 : // CRAPS
				 cout << "Player Loses..." << endl;
				 break;
		case 4 : // MAKE POINT
				 point = firstRoll;
				 cout << "Your POINT is " << point << endl;
				 cout << "Score this again to WIN the game! Just don't roll a 7..." << endl;
				 rollToMakePoint(point);
				 break;
		case 5 : // MAKE POINT
				 point = firstRoll;
				 cout << "Your POINT is " << point << endl;
				 cout << "Score this again to WIN the game! Just don't roll a 7..." << endl;
				 rollToMakePoint(point);
				 break;
		case 6 : // MAKE POINT
				 point = firstRoll;
				 cout << "Your POINT is " << point << endl;
				 cout << "Score this again to WIN the game! Just don't roll a 7..." << endl;
				 rollToMakePoint(point);
				 break;
		case 7 : // WIN
				 cout << "You WIN!" << endl;
				 break;
		case 8 : // MAKE POINT
				 point = firstRoll;
				 cout << "Your POINT is " << point << endl;
				 cout << "Score this again to WIN the game! Just don't roll a 7..." << endl;
				 rollToMakePoint(point);
				 break;
		case 9 : // MAKE POINT
				 point = firstRoll;
				 cout << "Your POINT is " << point << endl;
				 cout << "Score this again to WIN the game! Just don't roll a 7..." << endl;
				 rollToMakePoint(point);
				 break;
		case 10: // MAKE POINT
				 point = firstRoll;
				 cout << "Your POINT is " << point << endl;
			 	 cout << "Score this again to WIN the game! Just don't roll a 7..." << endl;
				 rollToMakePoint(point);
				 break;
		case 11: // WIN
				 cout << "You WIN!" << endl;
				 break;
		case 12: // CRAPS
				 cout << "You Lose... Sorry!" << endl;
				 break;
	}
}
void rollToMakePoint (int point) 
{
	char input;
	bool done = false;
	int makePoint = 0;
	
	while (done==false)
	{
		cout << "Do You Want to Roll Again (Y/N) ? ";
		cin >> input;
			// The user may choose if he/she wants to keep playing.
			// If they want to quit playing, they may press any char key except for 'y' or 'Y'.
			if (input == 'y' || input == 'Y') done = false; 
				else 
				{
				done = true;
				break;
				}	
		// If subsequent rolls match the parameter (point), the user wins and the loop terminates.
		makePoint = roll();
		if (makePoint == point)
		{
			cout << "You WIN!" << endl;
			done = true;
		}
		// If the user rolls a 7, GAME OVER. The loop (and the function) terminates.
		else if (makePoint == 7)
		{
			cout << "You Lose... Sorry!" << endl;
			done = true;
		}
	}
}
