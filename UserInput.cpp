/************************************************
 * Program Name: UserInput.cpp
 * Author: Elizabeth Donato
 * Date: 1-27-2018
 * Description: This is the specification file  
   for the UserInput class that is used to get 
   information from the user about program 
   specifications.  This class can easily be 
   modified for use by different programs.
************************************************/

#include "UserInput.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

/*************************************************
 * 		UserInput::UserInput		*
 * 						*
 * This is the default constructor for the 	*
 * UserInput class.  It sets default values 	*
 * for user-entered values.  			*
 *						*
 *  Accepts: Nothing				*
 *						*
 *  Returns: Nothing				*
*************************************************/
UserInput::UserInput()
{
   myInt= 0;
   testString = "";
   validInput = false;
}
/*************************************************
 * 	UserInput::prompt_rows			*
 * 						*
 * This function gets the number of rows for  	*
 * the simulation grid from the user.		*
 *						*
 * Accepts: Nothing				*
 * 						*
 * Returns: int (user-entered input)		*
*************************************************/
int UserInput::prompt_rows()
{
   //Gets and validates user input
   while (!validInput)
   {
	//Establishes range for valid input
	lowest = 3;
	highest = 250;

	std::cout << "\nPlease enter the number of rows for the simulation grid." << std::endl;
	std::cout << "Please enter a number between 3 and 250:  ";
	std::getline(std::cin, testString);
	validInput = userInt.is_valid_int_range(testString, lowest, highest);
   }

   //Returns user's input to client program as an integer
   myInt = userInt.get_int();

   return myInt;
}

/*************************************************
 * 	UserInput::prompt_cols			*
 * 						*
 * This function gets the number of columns for *
 * the simulation grid from the user.		*
 *						*
 * Accepts: Nothing				*
 * 						*
 * Returns: int (user-entered input)		*
*************************************************/
int UserInput::prompt_cols()
{
   //Gets and validates user input
   while (!validInput)
   {
	//Establishes range for valid input
	lowest = 3;
	highest = 250;

	std::cout << "\nPlease enter the number of columns for the simulation grid." << std::endl;
	std::cout << "Please enter a number between 3 and 250:  ";
	std::getline(std::cin, testString);
	validInput = userInt.is_valid_int_range(testString, lowest, highest);
   }

   //Returns user's input to client program as an integer
   myInt = userInt.get_int();

   return myInt;
}

/*************************************************
 * 	UserInput::prompt_ants			*
 * 						*
 * This function gets the number of ants for  	*
 * the simulation grid from the user.		*
 *						*
 * Accepts: Nothing				*
 * 						*
 * Returns: int (user-entered input)		*
*************************************************/
int UserInput::prompt_ants()
{
   //Gets and validates user input
   while (!validInput)
   {
	//Establishes range for valid input
	lowest = 3;
	highest = 100;

	std::cout << "\nPlease enter the number of ants to be placed on the simulation grid." << std::endl;
	std::cout << "Please enter a number between 1 and 100:  ";
	std::getline(std::cin, testString);
	validInput = userInt.is_valid_int_range(testString, lowest, highest);
   }

   //Returns user's input to client program as an integer
   myInt = userInt.get_int();

   return myInt;
}

/*************************************************
 * 	UserInput::prompt_doodles		*
 * 						*
 * This function gets the number of doodlebugs	*
 * for the simulation grid from the user.	*
 *						*
 * Accepts: Nothing				*
 * 						*
 * Returns: int (user-entered input)		*
*************************************************/
int UserInput::prompt_doodles()
{
   //Gets and validates user input
   while (!validInput)
   {
	//Establishes range for valid input
	lowest = 3;
	highest = 100;

	std::cout << "\nPlease enter the number of doodlebugs to be placed on the simulation grid." << std::endl;
	std::cout << "Please enter a number between 1 and 100:  ";
	std::getline(std::cin, testString);
	validInput = userInt.is_valid_int_range(testString, lowest, highest);
   }

   //Returns user's input to client program as an integer
   myInt = userInt.get_int();

   return myInt;
}

/*************************************************
 * 	UserInput::prompt_steps			*
 * 						*
 * This function gets the number of steps	*
 * for the simulation grid from the user.	*
 *						*
 * Accepts: Nothing				*
 * 						*
 * Returns: int (user-entered input)		*
*************************************************/
int UserInput::prompt_steps()
{
   //Gets and validates user input
   while (!validInput)
   {
	//Establishes range for valid input
	lowest = 1;
	highest = 15000;

	std::cout << "\nPlease enter the number of steps to be taken during the simulation." << std::endl;
	std::cout << "Please enter a number between 1 and 15000:  ";
	std::getline(std::cin, testString);
	validInput = userInt.is_valid_int_range(testString, lowest, highest);
   }

   //Returns user's input to client program as an integer
   myInt = userInt.get_int();

   return myInt;
}

