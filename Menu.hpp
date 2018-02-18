/*************************************************
 * Program Name: Menu.hpp
 * Authors: Sheila Babayan, Becky Chao, Elizabeth
 * 	    Donao, Devin Gendron, Ronald Walters
 * Date: 2/19/2018
 * Description: This is the header file 
 * 		for the Menu class 
*************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include "ValidInt.hpp"
#include <string>

//Menu class declaration
class Menu
{
   protected:
	bool firstMenu;		//Indicates if this is the first time the simulation is being run
	int userChoice;		//User's menu choice
	ValidInt userInput;	//Used for input validation
	std::string testString;	//Used for input validation
	bool validInput;	//Indicates if valid input has been entered
	int lowest;		//Lowest menu choice
	int highest;		//Highest menu choice

   public:
	Menu();			//Constructor
	int get_choice();	//Displays menu and gets user's choice
	~Menu() {};		//Destructor
};
#endif
 

		
