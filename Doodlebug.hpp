#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP
#include "Critter.hpp"

class Doodlebug: public Critter
{
	private:
		int daysStarving;
	public:
		Doodlebug(int, int);
		virtual void move(char**, int, int);
		virtual void breed(char**, int, int);
		void starve(char**);
};

#endif
