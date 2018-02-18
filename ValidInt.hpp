/************************************************
 * Program Name: ValidInput.hpp
 * Author: Elizabeth Donato
 * Date: 2-9-2018
 * Description: This is the header file
 * 		for the ValidInt class.
*************************************************/

#ifndef VALIDINT_HPP
#define VALIDINT_HPP

#include <string>

//ValidInt Class Declaration
class ValidInt
{
   private:
	bool goodInput;
	int testInt;

   public:
	ValidInt();
	bool is_valid_int(std::string);
	bool is_valid_int_range(std::string, int, int);
	int get_int();
	~ValidInt() {};
};

#endif
