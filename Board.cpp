
#include "Board.hpp"
#include <iostream>
using namespace std;

//default constructor
Board::Board()
{
 	//Set standard size of board
	rows = 20;
	cols = 20;

	//Create the board itself
	board = new Critter**[rows];
	for (int x = 0; x < rows; x++)
	{
		board[x] = new Critter*[cols];
	}

	//Fill board with Critter objects
	for (int rw = 0; rw < rows; rw++)
	{
		for (int cl = 0; cl < cols; cl++)
		{
			board[rw][cl] = new Critter();
		}
	}
	
	//Place ants randomly on board
	for (int z = 0; z < 5; z++)
	{
		int randRowA = rand() % rows;
		int randColA = rand() % cols;
		board[randRowA][randColA] = new Ant(randRowA, randColA, 0);
	}
	
	//Place doodlebugs randomly on board
	for (int d = 0; d < 5; d++)
	{
		int randRowD = rand() % rows;
		int randColD = rand() % cols;
		board[randRowD][randColD] = new Doodlebug(randRowD, randColD, 0, 0);
	}
}

//overloaded for custom rows/columns
Board::Board(int r, int c) : rows(r), cols(c)
{
  
}

//destructor
Board::~Board()
{
  
	for (int del = 0; del < rows; del++)
	{
		for (int pt = 0; pt < cols; pt++)
		{
			delete board[del][pt];
		}
		delete[] board[del];
	}
	delete [] board;
	board = NULL;
}

//setrows
void Board::setRows(int r)
{
	rows = r;
}

//setcols
void Board::setColumns(int c)
{
	cols = c;
}

//create board function... I don't think this is needed.<--RON
void Board::createBoard()
{
/*	//creates board
	for (int i = 0; i < boardCols; i++)
	{
		board[0][i] = '-';	//top row
	}

	for (int i = 0; i < boardRows; i++)
	{
		for (int j = 0; j < boardCols; j++)
		{
			if(j == 0)
			{
				board[i][j] = '|';	//left wall
			}
			else
			{
				board[i][j] = ' ';
			}
			if(j == boardCols - 1)
			{
				board[i][j] = '|';		//right side wall
			}
		}
	}
	
	for (int i = 0; i < boardCols; i++)
	{
		board[boardRows - 1][i] = '-';	//bottom row
	}*/
}

//print board function
void Board::printBoard()
{
	//system("clear");	//this creates a better flipbook effect for me

	std::cout << "\033[2J\033[1;1H";	//this does a poor job (at least on my mac) 

	//prints board
	for (int r = 0; r < rows+2; r++)
	{
		for (int c = 0; c < cols+2; c++)
		{
			if (r == 0 || r == rows+1)
			{
				cout << '-';
			}
			else if (c == 0 || c == cols+1)
			{
				cout << '|';
			}
			else
			{
				cout << board[r-1][c-1]->getSymbol();
			}
		}
		cout << "\n";
	}
	cout << "\n";
}

