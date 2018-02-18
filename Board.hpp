/*********************************************************************
 * Program name: Group Project 1 - Group 8 - Board.hpp
 * Authors: Sheila Babayan, Becky Chao, Elizabeth Donato, 
 * Devin Gendron, Ronald Walters
 * Date: 2/19/2018
 * Description: This is the header file for our Board class. It contains 
 * the information and methods for our Board object.
 **********************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP
#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include <stdlib.h>
#include <iostream>
using std::cout;

class Board
{
private:
    int rows = 0;
    int cols = 0;
    int ants, dbugs;
    Critter ***board;
public:
    Board();  //default constructor
    Board(int, int, int, int);  //overloarded constructor
    ~Board();  //destructor
	
    void printBoard();	//display the current board
    void simulation(int);	//run the simulation		
};

#endif
