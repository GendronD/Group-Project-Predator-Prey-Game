#include "Ant.hpp"
#include "Critter.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

Ant::Ant(int row, int col, int alive)
{
	xPos = row;
	yPos = col;
	symbol = 'O';
	daysAlive = alive;
}

void Ant::move(Critter ***board, int rows, int columns)
{
	int move = rand() % 4 + 1;
	
	switch (move)
	{
		case 1://If space is empty and not wall, Move North
		if (yPos-1 >=0)
		{
			if(board[xPos][yPos -1]->getSymbol() ==' ')
			{
				board[xPos][yPos -1] = new Ant(xPos,yPos - 1, ++daysAlive);
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
				board[xPos-1][yPos] = new Ant(xPos-1,yPos, ++daysAlive);
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
				board[xPos][yPos +1] = new Ant(xPos,yPos + 1, ++daysAlive);
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
				board[xPos+1][yPos] = new Ant(xPos+1, yPos, ++daysAlive);
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

void Ant::breed(Critter ***board, int rows, int columns)
{
	char ary[4] = {1, 2, 3, 4};
	int count = 0;
	int spot;

	//check if ant has lived long enough
	if (daysAlive >= 3)
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
							board[xPos][yPos-1] = new Ant(xPos, yPos-1, 0);
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
							board[xPos+1][yPos] = new Ant(xPos+1, yPos, 0);
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
							board[xPos][yPos+1] = new Ant(xPos, yPos+1, 0);
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
							board[xPos-1][yPos] = new Ant(xPos-1, yPos, 0);
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

