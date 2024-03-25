/*  Name - Thaw Zin Phyo
	Date - 17th Jan 2024
	Program - Flipping card game where a user needs to find all matching pairs
*/
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
const int LENGTH = 4;
using namespace std;

// Function prototypes
void InitializeCards(int cards[][LENGTH]);
void ShowCards(int cards[][LENGTH], bool faceup[][LENGTH]);
// you may have more function prototypes

// ======================
//     main function
// ======================
int main()
{
	ofstream fileout;
	fileout.open("output.txt");
	//check if output file has been successfully created
	if(!fileout)									
	{
		cout << "Failed to create output file";
	}

	string playername;
	cout << "Welcome to the game!" << endl;
	cout << "Please enter your full name: " ;
	getline(cin, playername);
	cout << "Find the matching pairs on the board." << endl;

	//initialize array to 0
	int deck1[LENGTH][LENGTH]	= {0};				
	InitializeCards(deck1);

	//initialize bool array to false
	bool deck2[LENGTH][LENGTH] = {false};			
	
	char userinput{};
	bool playgame = true;
	//check if game has been won by matching all pairs
	bool gameresult = false;
	//keep track of tries
	int timesplayed = 0;
	while(playgame)
	{
		ShowCards(deck1, deck2);
		int card1x, card1y;						//variable for card 1 position
		int card2x, card2y;						//variable for card 2 position
		cout << "Enter the row and column for the first card: ";
		cin  >> card1x;
		cin  >> card1y;
		while(card1x > LENGTH - 1 || card1y > LENGTH - 1)
		{
			cout << "Please enter valid row and column numbers." << endl;
			cout << "Enter the row and column for the first card: ";
			cin  >> card1x;
			cin  >> card1y;
		}
		cout << "Enter the row and column for the second card: ";
		cin  >> card2x;
		cin  >> card2y;
		while(card2x > LENGTH -1 || card2y > LENGTH - 1)
		{
			cout << "Please enter valid row and column numbers." << endl;
			cout << "Enter the row and column for the second card: ";
			cin  >> card2x;
			cin  >> card2y;
		}
		deck2[card1x][card1y] = true;
		deck2[card2x][card2y] = true;
		if(deck1[card1x][card1y] == deck1[card2x][card2y])
		{
			cout << "Found a match.Flipping cards face up." << endl;
		}
		else
		{
			ShowCards(deck1, deck2);
			cout << "Match not found.Flipping cards face down." << endl;
			deck2[card1x][card1y] = false;
			deck2[card2x][card2y] = false;
		}

		timesplayed += 1;
		//Asks user if they wanna continue playing
		cout << "Enter 'q' to quit or press any key to continue.... ";
		cin  >> userinput;
		if(userinput == 'q')	
		{
			playgame = false;
		}
	}

	for(int i = 0; i < LENGTH ; i++)
	{
		for(int j = 0; j < LENGTH; j++)
		{
			if(deck2[i][j]== true)
			{
				gameresult = true;
			}
			else
			{
				gameresult = false;
			}
		}
	}

	if(playgame == false)
	{
		if(gameresult == true)
		{
			fileout << playername << " played " << timesplayed
			 << "  times to win the game." << endl;
		}
		else
		{
			fileout << "Don't give up.";
		}
	}
}


// InitializeCards
// Places pairs of numbers in the 2D array and then
// randomly shuffles them.
// ======================
//Notice that when you pass a 2D-array to a function, you MUST specify the number of columns
void InitializeCards(int cards[][LENGTH])
{
	//seed rand() - remember to always do this before using rand()
	// also make sure to include the <time.h> library.
	srand(time(NULL));
	int x1, y1, x2, y2;
	int i;
	int temp;

	// Place pairs in known locations -   this is how our array looks like after
	cards[0][0] = 1; cards[0][1] = 1;//   1  1  2  2
	cards[0][2] = 2; cards[0][3] = 2;
	cards[1][0] = 3; cards[1][1] = 3;//   3  3  4  4
	cards[1][2] = 4; cards[1][3] = 4;
	cards[2][0] = 5; cards[2][1] = 5;//   5  5  6   6
	cards[2][2] = 6; cards[2][3] = 6;
	cards[3][0] = 7; cards[3][1] = 7;//   7  7  8   8
	cards[3][2] = 8; cards[3][3] = 8;

	// Now that 2D has been initialized with 8 pairs, we want to shuffle the board so
	// that the pairs aren't right next to each other
	for (int i = 0; i < 30; i++) {
		//Get set of random coordinates and swap
		//First random coordinate on our 2d "grid"
		y1 = rand() % LENGTH;
		x1 = rand() % LENGTH;
		//Second random coordinate of our 2d "grid"
		y2 = rand() % LENGTH;
		x2 = rand() % LENGTH;

		//Now we swap value at (x1, y1) with value at(x2, y2)
		temp = cards[x1][y1];
		cards[x1][y1] = cards[x2][y2];
		cards[x2][y2] = temp;
		//Note: just like with 1D arrays, modifying an n-dimensional array inside
		// a function will change the array itself
	}
}

// ======================
// ShowCards
// Generates a display on the screen.  If faceup=false,
// an * is output, otherwise the card in that slot is output.
// ======================
//receives a 2D array of int type and 2D array of bool type
//returns nothing
//shows the game board by displaying cards
void ShowCards(int cards[][LENGTH], bool faceup[][LENGTH]) 
{
	for(int i = 0; i < LENGTH; i++)
	{
		for(int j = 0; j < LENGTH; j++)
		{
			if(faceup[i][j] == 1)
			{
				cout << cards[i][j] << " ";
			}
			else
			{
				cout << "*" << " ";
			}
		}
		cout << endl;
	}
}

//Run with invalid input for rows/cols
/*
Welcome to the game!
Please enter your full name: Thaw
Find the matching pairs on the board.
* * * *
* * * *
* * * *
* * * *
Enter the row and column for the first card: 3 4
Please enter valid row and column numbers.
Enter the row and column for the first card: 4 4
Please enter valid row and column numbers.
Enter the row and column for the first card: 6 2
Please enter valid row and column numbers.
Enter the row and column for the first card: 0 1
Enter the row and column for the second card: 4 4
Please enter valid row and column numbers.
Enter the row and column for the second card: 2 2
* 4 * *
* * * *
* * 1 *
* * * *
Match not found.Flipping cards face down.
Enter 'q' to quit or press any key to continue.... * *
*/



//Run with three inputs with valid values
/*
Welcome to the game!
Please enter your full name: abc
Find the matching pairs on the board.
* * * *
* * * *
* * * *
* * * *
Enter the row and column for the first card: 0 0
Enter the row and column for the second card: 1 2
7 * * *
* * 3 *
* * * *
* * * *
Match not found.Flipping cards face down.
Enter 'q' to quit or press any key to continue.... b
* * * *
* * * *
* * * *
* * * *
Enter the row and column for the first card: 0 3
Enter the row and column for the second card: 3 1
* * * 2
* * * *
* * * *
* 5 * *
Match not found.Flipping cards face down.
Enter 'q' to quit or press any key to continue.... b
* * * *
* * * *
* * * *
* * * *
Enter the row and column for the first card: 2 1
Enter the row and column for the second card: 3 3
* * * *
* * * *
* 1 * *
* * * 4
Match not found.Flipping cards face down.
Enter 'q' to quit or press any key to continue.... * * 
*/


//Run with one input with quit choice
/*
Welcome to the game!
Please enter your full name: def
Find the matching pairs on the board.
* * * *
* * * *
* * * *
* * * *
Enter the row and column for the first card: 0 0
Enter the row and column for the second card: 1 0
1 * * *
8 * * *
* * * *
* * * *
Match not found.Flipping cards face down.
Enter 'q' to quit or press any key to continue.... q
*/
