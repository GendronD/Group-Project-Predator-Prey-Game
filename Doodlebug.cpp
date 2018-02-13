#include "Doodlebug.hpp"
#include <stdlib.h>
using namespace std;

Doodlebug::Doodlebug(int row, int col, int alive, int starve)
{
	xPos = row;
	yPos = col;
	symbol = 'X';
	daysAlive = alive;
	daysStarving = starve;
}

void Doodlebug::move(Critter **board, int rows, int columns)
{
	//Check if there is an ant next to bug, if so eat it
	if (board[xPos][yPos-1].getSymbol() == "O" ||board[xPos][yPos+1].getSymbol() == "O" ||
		board[xPos-1][yPos].getSymbol() == "O" ||board[xPos+1][yPos].getSymbol() == "O")
	{
		if (board[xPos][yPos-1].getSymbol() == "O")
		{
			board[xPos][yPos-1] = Doodlebug(xPos, yPos-1, ++daysAlive, 0);
			board[xPos][yPos] = Critter(xPos, yPos);
		}
		
		if (board[xPos][yPos+1].getSymbol() == "O")
		{
			board[xPos][yPos+1] = Doodlebug(xPos, yPos+1, ++daysAlive, 0);
			board[xPos][yPos] = Critter(xPos, yPos);
		}
		
		if (board[xPos-1][yPos].getSymbol() == "O")
		{
			board[xPos-1][yPos] = Doodlebug(xPos-1, yPos, ++daysAlive, 0);
			board[xPos][yPos] = Critter(xPos, yPos);
		}
		
		if (board[xPos+1][yPos].getSymbol() == "O")
		{
			board[xPos+1][yPos] = Doodlebug(xPos+1, yPos, ++daysAlive, 0);
			board[xPos][yPos] = Critter(xPos, yPos);
		}
	}
	
	//if no ants are next to bug, move randomly
	else
	{
		int move = rand() % 4 + 1;
	
		switch (move)
		{
			case 1://If space is empty and not wall, Move North
			if (yPos-1 >=0)
			{
				if(board[xPos][yPos -1]->getSymbol() ==' ')
				{
					board[xPos][yPos -1] = new Doodlebug(xPos,yPos - 1, ++daysAlive);
					board[xPos][yPos] = new Critter();
				}	
				else
				{
					daysAlive++;
				}
			}
			else
			{
				daysAlive++;
			}
			break;

			case 2://If space is empty and not wall, Move West	
			if (xPos-1 >= 0)
			{
				if (board[xPos-1][yPos]->getSymbol() ==' ')
				{
					board[xPos-1][yPos] = new Doodlebug(xPos-1,yPos, ++daysAlive);
					board[xPos][yPos] = new Critter();
				}
				else
				{
					daysAlive++;
				}
			}
			else
			{
				daysAlive++;
			}
			break;

			case 3://If space is empty and not wall, Move South	
			if (yPos+1 < rows)
			{
				if (board[xPos][yPos +1]->getSymbol() ==' ')
				{	
					board[xPos][yPos +1] = new Doodlebug(xPos,yPos + 1, ++daysAlive);
					board[xPos][yPos] = new Critter();
				}
				else
				{
					daysAlive++;
				}
			}
			else
			{
				daysAlive++;
			}
			break;

			case 4://if space is empty and not wall, Move East	
			if (xPos+1 < columns)
			{
				if(board[xPos+1][yPos]->getSymbol() ==' ')
				{
					board[xPos+1][yPos] = new Doodlebug(xPos+1, yPos, ++daysAlive);
					board[xPos][yPos] = new Critter();
				}
				else
				{
					daysAlive++;
				}
			}
			else
			{
				daysAlive++;
			}
			break;
		}
	}
}

void Doodlebug::breed(Critter ***board, int rows, int columns)
{
	char ary[4] = {1, 2, 3, 4};
	int count = 0;
	int spot;

	//check if doodlebug has lived long enough
	if (daysAlive >= 8)
	{
		while (count < 4)	
		{
			//Use array to grab random direction
		//	cout << "grabbing random number\n";
			spot = rand() %4;
		//	cout << spot << endl;
			//Check if that direction has already been checked
			if (ary[spot] != 0)
			{
			//	cout << "Checking array\n";
			//	cout << ary[spot];
				int test = ary[spot];
				switch (test)
				{	
					case 1:
					{
				//	cout << "running case 1\n";
					//if empty and not wall, breed north
					if (yPos-1 >= 0)
					{
						if (board[xPos][yPos-1]->getSymbol() == ' ')
						{
							board[xPos][yPos-1] = new Doodlebug(xPos, yPos-1, 0);
							count = 4;
							daysAlive = 0;	
						}
						else
						{
							ary[0] = 0;
							count++;
						}
					}
					
					//Otherwise mark direction checked
					//and search again
					else
					{
						ary[0]= 0;
						count++;
					}
					break;
					}
					case 2:	
					{
				//	cout << "running case 2\n";
					//if empty and not wall, breed East
					if (xPos+1 < columns)
					{
						if (board[xPos+1][yPos]->getSymbol() == ' ')
						{
							board[xPos+1][yPos] = new Doodlebug(xPos+1, yPos, 0);
							count = 4;
							daysAlive = 0;
						}
						else
						{
							ary[1] = 0;
							count++;
						}
					}

					//Otherwise mark direction checked
					//and search again
					else
					{
						ary[1]= 0;
						count++;
					}
					break;
					}
					case 3:
					{
				//	cout << "running case 3\n";
					//if empty and not wall, breed South
					if (yPos+1 < rows)
					{
						if(board[xPos][yPos+1]->getSymbol() == ' ')
						{
							board[xPos][yPos+1] = new Doodlebug(xPos, yPos+1, 0);
							count = 4;
							daysAlive = 0;
						}
						else
						{
							ary[2] = 0;
							count++;
						}
					}

					//Otherwise mark direction checked
					//and search again
					else
					{
						ary[2]= 0;
						count++;
					}
					break;
					}

					case 4:
					{
				//	cout << "running case 4\n";
					//if empty and not wall, breed West
					if (xPos-1 >= 0)
					{
						if (board[xPos-1][yPos]->getSymbol() == ' ')
						{
							board[xPos-1][yPos] = new Doodlebug(xPos-1, yPos, 0);
							count = 4;
							daysAlive = 0;
						}
						else
						{
							ary[3] = 0;
							count++;
						}
					}

					//Otherwise mark direction checked
					//and search again
					else
					{
						ary[3]= 0;
						count++;
					}
					break;	
					}
				}
			}
		}
	}

}

void Doodlebug::starve(Critter **board)
{
	if (daysStarving == 3)
	{
		board[xPos][yPos] = Critter(xPos, yPos);
	}
}

