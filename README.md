# Predator-Prey-Game
CS 162 - Group Project: Predator Prey Game

PseudoCode:

Set up the gameboard
FUNCTION: MENU

*Print message stating we did the extra credit*

As the user whether they want a standard (20x20, set # critters) gameboard or whether they want to set the size and # critters themselves
	If static:
Dynamically generate a 2D array of chars, size 20x20 (“board”?)
Each array element will be a pointer to a Critter 
World initialized with 5 doodle bugs & 100 ants (rand Loc)
	Doodle Bug = “X”
	Ant = “O”
User input val for number of steps
	If user-generated:
		Prompt Menu for user input:
			User input val for x & y columns
			User input val for number of ants/doodlebugs/etc*
(controlled by board size)
			User input val for number of steps
			//


Ask the user to enter the number of time steps to run
Input validation: Must be an integer greater than 0 
	If the input is good, save this in an int (“numSteps”?)

Place the Critters
For ( 1 to 5 doodlebugs)
	Get random x/y values;
		Check if values are taken
		If taken, get new values
	Set bugs at x/y value;
For ( 1 to 100 ants)
	Get random x/y values;
		Check if values are taken
		If taken, get new values
	Set ants at x/y value;
Run the game
While there are still moves left in the game, do this… (thinking do/while loop here)
	Move the doodlebugs
	Breed the doodlebugs
	Starve the doodlebugs
	Move the ants
	Breed the ants
	Print updated board
	Decrement numMoves
Play again or exit
Ask the user to enter another number of time steps to run, or to enter “0” to exit
Input validation: Must be an integer
	If they enter 0, exit the program
If they enter a different int, save this in numSteps and go back the the play function
