/*********************************************************************
 * Program name: Group Project 1 - Group 8 - Critter.hpp
 * Authors: Sheila Babayan, Becky Chao, Elizabeth Donato, 
 * Devin Gendron, Ronald Walters
 * Date: 2/19/2018
 * Description: This is the header file for our Critter class. It contains 
 * the information and methods for our Critter object. Some of the methods
 * are virtual because their implementation will be handled by the
 * two child classes.
 **********************************************************************/
#ifndef CRITTER_HPP
#define CRITTER_HPP
#include <stdlib.h>
#include <iostream>

class Critter
{
	protected:
		int daysAlive;
		int xPos;
		int yPos;
		char symbol;
	public:
		Critter();
		virtual void move(Critter***, int, int);
		virtual void breed(Critter***, int, int);
		virtual char getSymbol();
		~Critter();
};

#endif
