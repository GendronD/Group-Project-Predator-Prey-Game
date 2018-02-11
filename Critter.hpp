#ifndef CRITTER_HPP
#define CRITTER_HPP

class Critter
{
	protected:
		int daysAlive;
		int xPos;
		int yPos;
		char Symbol;
	private:
		virtual void move(char**, int, int)= 0;
		virtual void breed(char**, int, int)= 0;
		virtual void getSymbol();
};

#endif
