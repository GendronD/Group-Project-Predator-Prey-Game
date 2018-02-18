/*********************************************************************
 * Program name: Group Project 1 - Group 8 - promptUser.hpp
 * Authors: Sheila Babayan, Becky Chao, Elizabeth Donato, 
 * Devin Gendron, Ronald Walters
 * Date: 2/19/2018
 * Description: This is the header file for our promptUser functions,
 * which are used to establish the parameters of the game (rows, columns,
 * number of bugs, steps in gameplay).
 **********************************************************************/

#ifndef PROMPTUSER_HPP
#define PROMPTUSER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <random>
#include <cmath>
#include <map>
#include <iomanip>


int inputValidation();   //checks user input - must be an integer within the specs

int promptRows();        //Prompt user for number of rows
int promptCols();        //Prompt user for number of columns
int promptAnts();        //Prompt user for number of ants (controlled by rows/cols)
int promptDoodles();     //Prompt user for number of doodlebugs (controlled by rows/cols)
int promptSteps();       //Prompt user for number of steps

#endif
