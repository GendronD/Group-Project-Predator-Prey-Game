#include "RunGame.hpp"

// default constructor
RunGame::RunGame()
{
  
}

//overload needed??

//destructor
RunGame::~RunGame()
{
  
}

void RunGame::simulation()
{
	//dynamically allocate board space
	board = new char*[boardRows];
	for (int i = 0; i < boardRows; i++)
	{
		board[i] = new char[boardCols];
	}

	//creates board
	createBoard();

	for (int i = 0; i < steps; i++)
	{
		//moves critters
		moveFunc();

		//prints board
		printBoard();
	}

	//delete board
	for (int i = 0; i < 2; i++)
	{
		delete [] board[i];
	}
	delete [] board;
	board = NULL;
}
