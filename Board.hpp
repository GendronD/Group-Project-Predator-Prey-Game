Board Header File:
#ifndef BOARD_HPP
#define BOARD_HPP
"Critter.hpp"

Class Board
{
	Private:
		//(if we want extra credit, use these)
		int rows = 0;
		int cols = 0;
		const int boardRows = 20;
		const int boardCols = 20;
		//char **board;	// needs to be a critter
		Critter ***board;
	Public:
    Board();  //default
    Board(int, int);  //overloard
    ~Board();  //destructor
		Void createBoard();
		Void printBoard();
		//(extra credit)
		Void setRows(int r);	//could use my inputval function for these -DG
		Void setColumns(int c);

		//gonna need this at some point?
		int getRandom(int min, int max);
};

#endif
