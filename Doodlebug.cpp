/*********************************************************************
 * Program name: Group Project 1 - Group 8 - Doodlebug.cpp
 * Authors: Sheila Babayan, Becky Chao, Elizabeth Donato, 
 * Devin Gendron, Ronald Walters
 * Date: 2/19/2018
 * Description: This is the implementation file for our Doodlebug child 
 * class. It contains the functions for Doodlebug objects.
 **********************************************************************/
#include "Doodlebug.hpp"
#include <iostream>
//constructor take parameters for row, column, alive status, and starving status
Doodlebug::Doodlebug(int row, int col, int alive, int starve)
{
	xPos = row;
	yPos = col;
	symbol = 'X';
	daysAlive = alive;
	daysStarving = starve;
	moved = 0;
}

/*********************************************************************
function move()
- checks for adjoining ants and eats them if they exist
- generates a random number and moves the doodlebug in that direction,
if it's possible to move
- increments daysAlive and daysStarving
**********************************************************************/
void Doodlebug::move(Critter ***board, int rows, int columns)
{
	int count = 0;
	//Check if there is an ant next to bug, if so eat it
	while (count < 5 && moved == 0)
	{
		switch (count)
		{
			case 0:
				if (xPos-1 >=0)
				{
					if (board[xPos-1][yPos]->getSymbol() == 'O')
					{
						delete board[xPos-1][yPos];
						board[xPos-1][yPos] = new Doodlebug(xPos-1, yPos, ++daysAlive, 0);
						delete board[xPos][yPos];
						board[xPos][yPos] = new Critter();
						count = 5;
						moved = 1;
						break;
					}
					count++;
					break;
				}
				count++;
				break;
		
			case 1:
				if (xPos+1 < rows)
				{
					if (board[xPos+1][yPos]->getSymbol() == 'O')
					{
						delete board[xPos+1][yPos];
						board[xPos+1][yPos] = new Doodlebug(xPos+1, yPos, ++daysAlive, 0);
						delete board[xPos][yPos];
						board[xPos][yPos] = new Critter();
						count = 5;
						moved = 1;
						break;
					}
					count++;
					break;
				}
				count++;
				break;

			case 2:
				if (yPos-1 >= 0)
				{
					if (board[xPos][yPos-1]->getSymbol() == 'O')
					{
						delete board[xPos][yPos-1];
						board[xPos][yPos-1] = new Doodlebug(xPos, yPos-1, ++daysAlive, 0);
						delete board[xPos][yPos];
						board[xPos][yPos] = new Critter();
						count = 5;
						moved = 1;
						break;
					}
					count++;
					break;
				}
				count++;
				break;

			case 3:
				if (yPos+1 < columns)
				{
					if (board[xPos][yPos+1]->getSymbol() == 'O')
					{
						delete board[xPos][yPos+1];
						board[xPos][yPos+1] = new Doodlebug(xPos, yPos+1, ++daysAlive, 0);
						delete board[xPos][yPos];
						board[xPos][yPos] = new Critter();
						count = 5;
						moved = 1;
						break;
					}
					count++;
					break;
				}
				count++;
				break;
		
			case 4:
				int move = rand() % 4 + 1;
	
				switch (move)
				{
					case 1://If space is empty and not wall, Move North
					if (xPos-1 >=0)
					{
						if(board[xPos-1][yPos]->getSymbol() ==' ')
						{
							delete board[xPos-1][yPos];
							board[xPos-1][yPos] = new Doodlebug(xPos-1, yPos, ++daysAlive, ++daysStarving);
							delete board[xPos][yPos];
							board[xPos][yPos] = new Critter();
						}	
						else
						{
							daysAlive++;
							daysStarving++;
						}
					}
					else
					{
						daysAlive++;
						daysStarving++;
					}
					count++;
					moved = 1;
					break;
		
					case 2://If space is empty and not wall, Move West	
					if (yPos-1 >= 0)
					{
						if (board[xPos][yPos-1]->getSymbol() ==' ')
						{
							delete board[xPos][yPos-1];
							board[xPos][yPos-1] = new Doodlebug(xPos,yPos-1, ++daysAlive, ++daysStarving);
							delete board[xPos][yPos];
							board[xPos][yPos] = new Critter();
						}
						else
						{
							daysAlive++;
							daysStarving++;
						}
					}
					else
					{
						daysAlive++;
						daysStarving++;
					}
					count++;
					moved = 1;
					break;
		
					case 3://If space is empty and not wall, Move South	
					if (xPos+1 < rows)
					{
						if (board[xPos+1][yPos]->getSymbol() ==' ')
						{	
							delete board[xPos+1][yPos];
							board[xPos+1][yPos] = new Doodlebug(xPos+1,yPos, ++daysAlive, ++daysStarving);
							delete board[xPos][yPos];
							board[xPos][yPos] = new Critter();
						}
						else
						{
							daysAlive++;
							daysStarving++;
						}
					}
					else
					{
						daysAlive++;
						daysStarving++;
					}
					count++;
					moved = 1;
					break;
		
					case 4://if space is empty and not wall, Move East	
					if (yPos+1 < columns)
					{
						if(board[xPos][yPos+1]->getSymbol() ==' ')
						{
							delete board[xPos][yPos+1];
							board[xPos][yPos+1] = new Doodlebug(xPos, yPos+1, ++daysAlive, ++daysStarving);
							delete board[xPos][yPos];
							board[xPos][yPos] = new Critter();
						}
						else
						{
							daysAlive++;
							daysStarving++;
						}
					}
					else
					{
						daysAlive++;
						daysStarving++;
					}
					count++;
					moved = 1;
					break;
			}
		}
	}
}

/*********************************************************************
function breed()
- checks if doodlebug is old enough to breed. If so:
- generates a random number and check if that direction is free. If so,
doodlebug breeds in the random direction. If not, doodlebug tries to
breed in a new direction
**********************************************************************/
void Doodlebug::breed(Critter ***board, int rows, int columns)
{
	char ary[4] = {1, 2, 3, 4};
	int count = 0;
	int spot;
	std::cout << "Days alive: "<< daysAlive << std::endl;
	//check if doodlebug has lived long enough
	if (daysAlive >= 8)
	{
		while (count < 4)	
		{
			//Use array to grab random direction
			spot = rand() %4;
			//Check if that direction has already been checked
			if (ary[spot] != 0)
			{
			//	cout << ary[spot];
				int test = ary[spot];
				switch (test)
				{	
					case 1:
					{
					//if empty and not wall, breed north
					if (xPos-1 >= 0)
					{
						if (board[xPos-1][yPos]->getSymbol() == ' ')
						{
							delete board[xPos-1][yPos];
							board[xPos-1][yPos] = new Doodlebug(xPos-1, yPos, 0, 0);
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
					if (yPos+1 < columns)
					{
						if (board[xPos][yPos+1]->getSymbol() == ' ')
						{
							delete board[xPos][yPos+1];
							board[xPos][yPos+1] = new Doodlebug(xPos, yPos+1, 0, 0);
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
					if (xPos+1 < rows)
					{
						if(board[xPos+1][yPos]->getSymbol() == ' ')
						{
							delete board[xPos+1][yPos];
							board[xPos+1][yPos] = new Doodlebug(xPos+1, yPos, 0, 0);
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
					if (yPos-1 >= 0)
					{
						if (board[xPos][yPos-1]->getSymbol() == ' ')
						{
							delete board[xPos][yPos-1];
							board[xPos][yPos-1] = new Doodlebug(xPos, yPos-1, 0, 0);
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
/*********************************************************************
function starve()
- checks if doodlebug hasn't eaten in 3 days
- if so, starves the doodlebug
**********************************************************************/
void Doodlebug::starve(Critter ***board)
{
	if (daysStarving == 3)
	{
		delete board[xPos][yPos];
		board[xPos][yPos] = new Critter();
	}
}

//destructor
Doodlebug::~Doodlebug()
{}



