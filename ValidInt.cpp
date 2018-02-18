/************************************************
 * Program Name: ValidInt.cpp
 * Author: Elizabeth Donato
 * Date: 2-9-2018
 * Description: This is the implementation file  
 * 		for the ValidInt class.
*************************************************/

#include "ValidInt.hpp"
#include <string>
#include <sstream>
#include <iostream>

/*************************************************
 *	ValidInt::ValidInt			*
 *						*
 * This is the constructor fot the ValidInt 	*
 * class.					*
 * 						*
 * Accepts: Nothing				*
 * 						*
 * Returns: Nothing				*
*************************************************/
ValidInt::ValidInt()
{
   //Default setting of goodInput is false.  The variable will only be changed 
   //to true if valid input is entered.
   goodInput = false;

   //Sets test integer to default value of 0
   testInt = 0;
} 

/*************************************************
 * 	ValidInt::is_valid_int			*
 * 						*
 * This function determines if the user 	*
 * has entered a valid integer.			*
 *						*
 * Accepts: string (user-entered input)		*
 * 						*
 * Returns: bool (status of input validation)	*
*************************************************/ 
bool ValidInt::is_valid_int (std::string inputString)
{
   //variables to test input
   char c;
   std::istringstream testStream(inputString);

   //if input is not an integer, displays an error message and boolean value is not changed
   if(!(testStream >> testInt) || (testStream >> std::ws && testStream.get(c)))
   {
	std::cout << "\nYou have not entered a valid integer." << std::endl;	   
   }
   
   //If input is an integer, boolean value is changed to indicate valid input
   //and value in string is converted to integer. 
   else
   {
   	goodInput = true;
   	testInt = std::stoi(inputString);
   }

   return goodInput;
}


/*************************************************
 * 	ValidInt::is_valid_int_range		*
 * 						*
 * This function determines if the user 	*
 * has entered a valid integer in the 		*
 * specified range.				*
 *						*
 * Accepts: string (user-entered input)		*
 * 						*
 * Returns: bool (status of input validation)	*
 * 	    int (lower range boundary)		*
 * 	    int (upper range boundary)		*
*************************************************/ 
bool ValidInt::is_valid_int_range (std::string inputString, int lowValue, int highValue)
{
   //variables to test input
   char c;
   std::stringstream testStream(inputString);

   //if input is not an integer in the specified range, displays an error message and boolean value is not changed
   if(!(testStream >> testInt) || (testStream >> std::ws && testStream.get(c)) ||
     (testInt < lowValue) || (testInt > highValue))
   {
	std::cout << "\nYou have not entered a valid integer in the specified range." << std::endl;
   }

   else 
   {
	//If integer input is within specified range, boolean value is changed to indicate valid inupt
	//and value in string is converted to integer.
  	goodInput = true;
   	testInt = std::stoi(inputString);
   }

   return goodInput;
}

/*************************************************
 * 	ValidInt::get_int			*
 * 						*
 * This function returns the user-entered	*
 * integer.					*
 * 						*
 * Accepts: Nothing				*
 *						*
 * Returns: int (validated, user-entered value)	*
*************************************************/
int ValidInt::get_int()
{
   return testInt;  
}
