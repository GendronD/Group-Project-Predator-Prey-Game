#ifndef ANT_HPP
#define ANT_HPP
#include "critter.hpp"

class Ant: public Critter
{
	public:
		Ant(int, int, int);
		virtual void move(Critter**, int, int);
		virtual void breed(Critter**, int, int);
};

#endif
