//Board Header File:
#ifndef BOARD_HPP
#define BOARD_HPP
#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include <stdlib.h>

class Board
{
	private:
		//(if we want extra credit, use these)
		int rows;
		int cols;	
		//char **board;	// needs to be a critter
		Critter ***board;
	public:
		Board();  //default
		Board(int, int);  //overloard
		~Board();  //destructor
		void createBoard();
		void printBoard();
		//(extra credit)
		void setRows(int r);	//could use my inputval function for these -DG
		void setColumns(int c);

		//gonna need this at some point?
	//	int getRandom(int min, int max);
};

#endif
