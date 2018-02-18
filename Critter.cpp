/*********************************************************************
 * Program name: Group Project 1 - Group 8 - Critter.cpp
 * Authors: Sheila Babayan, Becky Chao, Elizabeth Donato, 
 * Devin Gendron, Ronald Walters
 * Date: 2/19/2018
 * Description: This is the implementation file for our Critter class. It 
 * contains the functions for Critter objects.
 **********************************************************************/
#include "Critter.hpp"

//critter constructor
Critter::Critter()
{
	daysAlive = 0;
	symbol = ' ';
}

//getter
char Critter::getSymbol()
{
	return symbol;
}

//move function for critters
void Critter::move(Critter*** board, int row, int col)
{
	symbol = ' ';
}

//breed function for critters
void Critter::breed(Critter*** board, int row, int col)
{
	symbol = ' ';
}
//starve function - applies to doodlebugs only
void Critter::starve(Critter***)
{

}

Critter::~Critter()
{}
