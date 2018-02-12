/*********************************************************************
 * Program name: Group Project 1 - Group 8 - game.hpp
 * Authors: Sheila Babayan, Becky Chao, Elizabeth Donato, 
 * Devin Gendron, Ronald Walters
 * Date: 2/19/2018
 * Description: This is the header file for our Game class. It contains 
 * the information about our game object, plus the utility functions
 * needed to run the game.
 **********************************************************************/
 
#ifndef GAME_HPP
#define GAME_HPP

#include <sstream>
#include <iostream>
using std::cout;
using std::endl;

class Game
{
	private:
        char **board;	
	public:
        Game();
        ~Game();
        
        //starting menu options
        void startMenu();
        
        //appears to be where the gameboard gets made
        void simulation();
        
        int inputValidation();
        

};

#endif
