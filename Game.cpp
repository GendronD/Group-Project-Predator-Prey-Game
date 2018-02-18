/*************************************************
 * Program Name: Game.cpp
 * Authors: Sheila Babayan, Becky Chao, Elizabeth
 * 	    Donao, Devin Gendron, Ronald Walters
 * Date: 2/19/2018
 * Description: This is the implementation file 
 * 		for the Game class used to run the
 * 		predator-prey simulation
*************************************************/
#include "Game.hpp"
#include "Menu.hpp"
#include "UserInput.hpp"
#include "Board.hpp"
#include <iostream>

/*************************************************
 * 		Game::Game			*
 * 						*
 * This is the constructor for the game class.	*
 * 						*
 * Accepts: Nothing				*
 * 						*
 * Returns: Nothing				*
*************************************************/
Game::Game()			
{
   //Establishes random generator seed
   unsigned seed;		
   seed = time(0);
   srand(seed);

   steps = 0;
}

/*************************************************
 * 		Game::play_game			*
 * 						*
 * This function runs the simulation.		*
 * 						*
 * Accepts: Nothing				*
 * 						*
 * Returns: bool (exit status of simulation	*
*************************************************/
bool Game::play_game()
{
   //Instantiates needed objects
   Menu userMenu;
   UserInput gameInfo;
   Board *gameboard;

   bool playGame = true;

   //Displays menu and gets user's choice
   menuChoice = userMenu.get_choice();

   switch(menuChoice)
   {
      case 0: std::cout << "\nYou have chosen to exit the program.  Good Bye." << std::endl << std::endl;
   	      playGame = false;
	      break;

      case 1: std::cout << "\nA default board will be created." << std::endl << std::endl;
	      gameboard = new Board();
    	      break;

      case 2: std::cout << "\nI need some information to generate your custom simulation." << std::endl;
	      int rows = gameInfo.prompt_rows();
	      int cols = gameInfo.prompt_cols();
	      int ants = gameInfo.prompt_ants();
	      int doodles = gameInfo.prompt_doodles();
	      steps = gameInfo.prompt_rows();
	      gameboard = new Board(rows, cols, ants, doodles);
              break; 
   }

   if(playGame)
   {
	//Prints gameboard
	std::cout << "\nInitializing gameboard.  Doodlebugs start your engines!" << std::endl;
	gameboard ->printBoard();

	//Runs simulation
	gameboard ->simulation(steps);
   }

   return playGame;
}


		
