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
		//specific to doodlebugs
		int daysStarving;
	public:
		//constructor with parameters
		Doodlebug(int, int, int, int);
		
		//move the doodlebugs
		void move(Critter***, int, int);
		//breed the doodlebugs
		void breed(Critter***, int, int);
		//starve the doodlebugs
		void starve(Critter***);
		
		//destructor
		~Doodlebug();
};

#endif
