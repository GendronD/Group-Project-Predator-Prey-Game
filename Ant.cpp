#include "Ant.hpp"
#include <stdlib.h>

Ant::Ant(int row, int col, int alive)
{
	xPos = row;
	yPos = col;
	symbol = 'O';
	daysAlive = alive;
}

void Ant::move(char **board, int rows, int columns)
{
	int move = rand() % 4 + 1;
	
	switch (move)
	{
		case 1://If space is empty and not wall, Move North
		if (board[xPos][yPos -1].getSymbol() ==' ' && yPos-1 >= 0)
		{
			Ant(xPos,yPos - 1, daysAlive++);
			Critter(xPos, yPos);
		}
		break;
	
		case 2://If space is empty and not wall, Move West	
		if (board[xPos-1][yPos].getSymbol ==' ' && xPos-1 >= 0)
		{
			Ant(xPos-1,yPos, daysAlive++);
			Critter(xPos,yPos);
		}
		break;

		case 3://If space is empty and not wall, Move South	
		if (board[xPos][yPos +1].getSymbol ==' ' && yPos+1 < rows)
		{
			Ant(xPos,yPos + 1, daysAlive++);
			Critter(xPos, yPos);
		}
		break;

		case 4://if space is empty and not wall, Move East	
		if (board[xPos+1][yPos].getSymbol() ==' ' && xPos+1 < columns)
		{
			Ant(xPos+1, yPos, daysAlive++);
			Critter(xPos, yPos);
		}
		break;
	}
}

void Ant::breed(char **board, int rows, int columns)
{
	int ary[4] = {1, 2, 3, 4};
	int count = 0;
	int spot;

	//check if ant has lived long enough
	if (daysAlive >= 3)
	{

		//Make sure there is an empty space adjacent
		if (board[xPos][yPos-1].getSymbol() ==' ' || board[xPos][yPos+1].getSymbol() == ' ' ||
			board[xPos-1][yPos].getSymbol() == ' ' || board[xPos+1][yPos].getSymbol() == ' ')
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
							Ant(xPos, yPos-1, 0);
							count = 4;
							daysAlive = 0;
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
							Ant(xPos+1, yPos, 0);
							count = 4;
							daysALive = 0;
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
						if (board[xPos][yPos+1].getSymbol == ' ' &&
							yPos+1 < rows)
						{
							Ant(xPos, yPos+1, 0);
							count = 4;
							daysAlive = 0;
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
							Ant(xPos-1, yPos, 0);
							count = 4;
							daysAlive = 0;
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
