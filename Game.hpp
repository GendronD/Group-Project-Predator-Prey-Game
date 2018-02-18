/*************************************************
 * Program Name: Game.hpp
 * Authors: Sheila Babayan, Becky Chao, Elizabeth
 * 	    Donao, Devin Gendron, Ronald Walters
 * Date: 2/19/2018
 * Description: This is the header file 
 * 		for the Game class used to run the
 * 		predator-prey simulation
*************************************************/
#ifndef GAME_HPP
#define GAME_HPP

//Game class declaration
class Game
{
   protected:
	int menuChoice;		//User's menu choice
	int steps;		//Steps to be taken during simulation

   public:
	Game();			//Constructor
	bool play_game();	//Runs the simulation
	~Game() {};		//Destructor
};
#endif
 

		
