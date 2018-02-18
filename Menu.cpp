/*************************************************
 * Program Name: Menu.cpp
 * Authors: Sheila Babayan, Becky Chao, Elizabeth
 * 	    Donao, Devin Gendron, Ronald Walters
 * Date: 2/19/2018
 * Description: This is the implementation file 
 * 		for the Menu class 
*************************************************/
#include "Menu.hpp"
#include "ValidInt.hpp"
#include <iostream>
	
/*************************************************
 * 		Menu::Menu			*
 * 						*
 * This is the constructor for the Menu class.	*
 * 						*
 * Accepts: Nothing				*
 * 						*
 * Returns: Nothing				*
*************************************************/
Menu::Menu()
{
   firstMenu = true;
   testString = "";
   validInput = false;			//Will change to true once valid input has been entered
   lowest = 0;
   highest = 2;
} 

/*************************************************
 * 		Menu::get_choice		*
 * 						*
 * This function displays a menu of options 	*
 * and gets the user's choice.			*
 * 						*
 * Accepts: Nothing				*
 * 						*
 * Returns: int (User's menu choice)		*
*************************************************/ 
int Menu::get_choice()
{
   //Gets and validates user's choice
   while(!validInput)
   {
	if(firstMenu)
	{
	   std::cout << "\nChoose an option from the menu or choose 0 to exit." << std::endl << std::endl;
	   std::cout << "Predator Prey Simulation Menu" << std::endl;
	   std::cout << "-----------------------------" << std::endl;
	   std::cout << "1. Run Standard Simulation" << std::endl;
	   std::cout << "2. Run Custom Simulation" << std::endl << std::endl;
	   std::cout << "0. Exit the Program" << std::endl << std::endl;
	   std::cout << "Please enter your choice:  " << std::endl << std::endl;
        }

	else
	{
	   std::cout << "\nWould you like to add more steps to this simulation?" << std::endl;
	   std::cout << "1. Yes" << std::endl;
	   std::cout << "2. No.  Exit the simulation." << std::endl;
  	}
	//Gets user's input
	std::getline(std::cin, testString);
	//Validates user's input
	validInput = userInput.is_valid_int_range(testString, lowest, highest);	
   }

   //Sets boolean value to indicate the simulation has already run once
   firstMenu = false;

   //Converts string entered by user to int
   userChoice = userInput.get_int();

   //Resets boolean variable to false so it is ready if menu is calle again
   validInput = false;

   //Returns user's choice to calling program
   return userChoice;
}

		
