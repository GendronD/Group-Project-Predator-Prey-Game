/*************************************************
 * Program Name: sim.cpp
 * Authors: Sheila Babayan, Becky Chao, Elizabeth
 * 	    Donato, Devin Gendron, Ronald Walters
 * Date: 2/19/2018
 * Descriptio: This is the client file for the
 * 	       predator prey simulation
*************************************************/ 	       

#include "Game.hpp"
#include <iostream>

int main()
{
   //Displays extra credit message
   std::cout << "\n\nExtra credit is implemented on this project." << std::endl << std::endl;

   //Instantiates a game object
   Game myGame;

   //Calls simulation
   bool play = true;

   while(play)
   {
      play = myGame.play_game();
   }

   return 0;
}
