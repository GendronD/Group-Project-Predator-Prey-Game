#ifndef CRITTER_HPP
#define CRITTER_HPP

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
};

#endif
