#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP
#include "Critter.hpp"

class Doodlebug: public Critter
{
	private:
		int daysStarving;
	public:
		Doodlebug(int, int, int, int);
		virtual void move(Critter**, int, int);
		virtual void breed(Critter**, int, int);
		void starve(Critter**);
};

#endif
