/*********************************************************************
 * Program name: Group Project 1 - Group 8 - Doodlebug.hpp
 * Authors: Sheila Babayan, Becky Chao, Elizabeth Donato, 
 * Devin Gendron, Ronald Walters
 * Date: 2/19/2018
 * Description: This is the header file for our Doodlebug child class. 
 * It contains the information and methods for Doodlebug objects.
 **********************************************************************/
#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP
#include "Critter.hpp"

class Doodlebug: public Critter
{
	private:
		int daysStarving;
	public:
		Doodlebug(int, int, int, int);
		void move(Critter***, int, int);
		void breed(Critter***, int, int);
		void starve(Critter***);
};

#endif
