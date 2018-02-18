/*********************************************************************
 * Program name: Group Project 1 - Group 8 - Ant.hpp
 * Authors: Sheila Babayan, Becky Chao, Elizabeth Donato, 
 * Devin Gendron, Ronald Walters
 * Date: 2/19/2018
 * Description: This is the header file for our Ant child class. It contains 
 * the information and methods for Ant objects.
 **********************************************************************/
#ifndef ANT_HPP
#define ANT_HPP
#include "Critter.hpp"


class Ant: public Critter
{
	public:
		//constructor with params for row, column, and whether alive or not
		Ant(int, int, int);
		
		//function to move ants on the board
		void move(Critter***, int, int);
		
		//function to breed the ant
		void breed(Critter***, int, int);
		
		//destructor
		~Ant();
};

#endif
