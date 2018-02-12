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
			case 1://Move North
			if (board[xPos][yPos -1].getSymbol() == ' ' && yPos-1 >= 0)
			{
				board[xPos][yPos - 1] = Doodlebug(xPos, yPos-1, ++daysAlive, ++daysStarving);
				board[xPos][yPos] = Critter(xPos, yPos);
			}
			else
			{
				daysAlive++;
			}
			break;
	
			case 2://Move West	
			if (board[xPos-1][yPos].getSymbol() ==' ' && xPos-1 >= 0)
			{
				board[xPos-1][yPos] = Doodlebug(xPos-1, yPos, ++daysAlive, ++daysStarving);
				board[xPos][yPos] = Critter(xPos, yPos);
			}
			else
			{
				daysAlive++;
			}
			break;

			case 3://Move South	
			if (board[xPos][yPos +1].getSymbol() ==' ' && yPos+1 < rows)
			{
				board[xPos][yPos + 1] = Doodlebug(xPos, yPos+1, ++daysAlive, ++daysStarving);
				board[xPos][yPos] = Critter(xPos, yPos);
			}
			else
			{
				daysAlive++;
			}
			break;

			case 4://Move East	
			if (board[xPos+1][yPos].getSymbol() ==' ' && xPos+1 < columns)
			{
				board[xPos+1][yPos] = Doodlebug(xPos+1, yPos, ++daysAlive, ++daysStarving);
				board[xPos][yPos] = Critter(xPos, yPos);
			}
			else
			{
				daysAlive++;
			}
			break;
		}
	}
}

void Doodlebug::breed(Critter **board, int rows, int columns)
{
	int ary[4] = {1, 2, 3, 4};
	int count = 0;
	int spot;

	//check if ant has lived long enough
	if (daysAlive >= 8)
	{

		//Make sure there is an empty space adjacent
		if (board[xPos][yPos-1].getSymbol() ==' ' || board[xPos][yPos+1].getSymbol() == ' ' ||
			board[xPos-1][yPos].getSymbol() ==' ' || board[xPos+1][yPos].getSymbol() == ' ')
		{
			do
			{
				//Use array to grab random direction
				spot = rand() %4;
				//Check if that direction has already been checked
				if (ary[spot] != 0)
				{
					switch (ary[spot])
					{	
						case 1:
						//if empty and not wall, breed north
						if (board[xPos][yPos-1].getSymbol() == ' ' &&
							yPos-1 >= 0)
						{
							board[xPos][yPos-1] = Doodlebug(xPos, yPos-1, 0, 0);
							count = 4;
							break;
						}
						
						//Otherwise mark direction checked
						//and search again
						else
						{
							ary[0]= 0;
							count++;
							break;
						}
						case 2:	
						//if empty and not wall, breed East
						if (board[xPos+1][yPos].getSymbol() == ' ' &&
							xPos+1 < columns)
						{
							board[xPos+1][yPos] = Doodlebug(xPos+1, yPos, 0, 0);
							count = 4;
							break;
						}

						//Otherwise mark direction checked
						//and search again
						else
						{
							ary[1]= 0;
							count++;
							break;
						}
						
						case 3:
						//if empty and not wall, breed South
						if (board[xPos][yPos+1].getSymbol() == ' ' &&
							yPos+1 < rows)
						{
							board[xPos][yPos+1] = Doodlebug(xPos, yPos+1, 0, 0);
							count = 4;
							break;
						}

						//Otherwise mark direction checked
						//and search again
						else
						{
							ary[2]= 0;
							count++;
							break;
						}

						case 4:
						//if empty and not wall, breed West
						if (board[xPos-1][yPos].getSymbol() == ' ' &&
							xPos-1 >= 0)
						{
							board[xPos-1][yPos] = Doodlebug(xPos-1, yPos, 0, 0);
							count = 4;
							break;
						}
						//Otherwise mark direction checked
						//and search again
						else
						{
							ary[3]= 0;
							count++;
							break;
						}
					}
				}
			}
			while (count <= 3);
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

