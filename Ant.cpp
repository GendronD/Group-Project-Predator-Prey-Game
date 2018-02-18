/*********************************************************************
 * Program name: Group Project 1 - Group 8 - Ant.cpp
 * Authors: Sheila Babayan, Becky Chao, Elizabeth Donato, 
 * Devin Gendron, Ronald Walters
 * Date: 2/19/2018
 * Description: This is the implementation file for our Ant child class. 
 * It contains the functions for Ant objects.
 **********************************************************************/
#include "Ant.hpp"
#include "Critter.hpp"

//constructor for ant objects, with params for row, column, and alive status
Ant::Ant(int row, int col, int alive)
{
	xPos = row;
	yPos = col;
	symbol = 'O';
	daysAlive = alive;
}


/*********************************************************************
function move()
- generates a random number to start moving the ant in 1 of 4 directions
- takes the board and the numbers of rows and columns as parameters
- checks if ant can move
- increments the # days the ant has been alive
**********************************************************************/
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

/*********************************************************************
function breed()
- takes the board and the numbers of rows and columns as parameters
- checks if ant is old enough to breed. If so:
- generates a random number and breeds in that direction
**********************************************************************/
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
			spot = rand() %4;
			//Check if that direction has already been checked
			if (ary[spot] != 0)
			{
				int test = ary[spot];
				switch (test)
				{	
					case 1:
					{
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

//ant destructor
Ant::~Ant()
{}

