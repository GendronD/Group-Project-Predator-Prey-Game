#include "Critter.hpp"

Critter::Critter()
{
	daysAlive = 0;
	symbol = ' ';
}

char Critter::getSymbol()
{
	return symbol;
}

void Critter::move(Critter*** board, int row, int col)
{
	symbol = ' ';
}

void Critter::breed(Critter*** board, int row, int col)
{
	symbol = ' ';
}
